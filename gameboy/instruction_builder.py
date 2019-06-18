import os,sys,re
import pandas as pd
from bs4 import BeautifulSoup

with open('/tmp/gameboy_opcodes.html') as fh:
	html_string = fh.read()


soup = BeautifulSoup(html_string, 'lxml') # Parse the HTML as a string
# table = soup.find_all('table')[0] # Grab the first table

# n_rows = 0
# n_columns = 0

# # Find number of rows and columns
# # we also find the column titles if we can
# for row in table.find_all('tr'):
# 	# Determine the number of rows in the table
# 	td_tags = row.find_all('td')
# 	if len(td_tags) > 0:
# 		n_rows+=1
# 		if n_columns == 0:
# 			# Set the number of columns for our table
# 			n_columns = len(td_tags)
			
# columns = range(0,n_columns)
# df = pd.DataFrame(columns = columns, index= range(0, n_rows))

ins = []

for tno,table in enumerate(soup.find_all('table')[:2]):
	row_marker = 0
	for row in table.find_all('tr')[1:]:
		column_marker = 0
		for column in row.find_all('td')[1:]:
			# df.iat[row_marker,column_marker] = column.get_text()
			# 0-operands	
			m = re.match(r'^(?P<operation>[A-Z]+)\s(?P<width>\d+)\xa0+(?P<cycles>\d+|\d+/\d+)\s(?P<flags>[\-ZNHC01 ]+)$', column.get_text(separator=u' ', strip=True))
			if m != None:
				ins.append( (m.groupdict(),column.get_text()) )
				continue
			# 1-operands
			m = re.match(r'^(?P<operation>[A-Z]+)\s(?P<operand1>[\(\)\w\+\-]+)\s(?P<width>\d+)\xa0+(?P<cycles>\d+|\d+/\d+)\s(?P<flags>[\-ZNHC01 ]+)$', column.get_text(separator=u' ', strip=True))
			if m != None:
				ins.append( (m.groupdict(),column.get_text()) )
				continue
			# 2-operands
			m = re.match(r'^(?P<operation>[A-Z]+)\s(?P<operand1>[\(\)\w\+\-]+),(?P<operand2>[\(\)\w\+\-]+)\s(?P<width>\d+)\xa0+(?P<cycles>\d+|\d+/\d+)\s(?P<flags>[\-ZNHC01 ]+)$', column.get_text(separator=u' ', strip=True))
			if m != None:
				ins.append( (m.groupdict(),column.get_text()) )
				continue

			ins.append( ({}, column.get_text()) )

all_methods = []


with open('ClassOperations.txt', 'wt') as fh:
	for ix,i in enumerate(ins):
		d = i[0]
		if 'operation' not in d:
			continue
		operation = d['operation']
		flags = d['flags'].replace(' ','')
		operands = []
		if 'operand1' in d:
			operands.append( d['operand1'] )
		if 'operand2' in d:
			operands.append( d['operand2'] )

		if len(operands) == 0:
			methname = d['operation']
		elif len(operands) == 1:
			methname = d['operation'] + '_' + re.sub(r'(\(|\))', '_', d['operand1']).replace('-', 'min').replace('+', 'pls')
		elif len(operands) == 2:
			methname = d['operation'] + '_' + re.sub(r'(\(|\))', '_', d['operand1']).replace('-', 'min').replace('+', 'pls') + '_' + re.sub(r'(\(|\))', '_', d['operand2']).replace('-', 'min').replace('+', 'pls')

		cycles = d['cycles'].split('/')
		if len(cycles) == 1:
			cycles.append(cycles[0])

		opstring = d['operation']
		if len(operands) > 0:
			opstring += ' ' + ','.join(operands)

		i[0]['methname'] = methname
		i[0]['flags'] = flags
		i[0]['operands'] = operands
		i[0]['cycles'] = cycles
		i[0]['opstring'] = opstring
		i[0]['instruction'] = ix if ix <= 0xff else (0xcb00 | ix)

		fh.write('\t/*{:>7s} */ ssize_t {:s}(const struct Opcode& Opcode, ssize_t Ticks, ssize_t& TicksRequired);\n'.format(hex(d['instruction']), methname))


print('##### CallbackTable #####')
with open('CallbackTable.txt', 'wt') as fh:
	for ix,i in enumerate(ins):
		d = i[0]
		if 'operation' not in d:
			continue

		fh.write('\t{{{:>7s}, {{{:<15s}, {:<19s}, {:s}, {:s}, {:s}}}}},\n'.format(hex(d['instruction']), '"'+d['opstring']+'"', '&Cpu::'+d['methname'], d['width'], d['cycles'][0], d['cycles'][1]))



print('##### FUNCTION IMPLEMENTATIONS #####')
with open('CpuOperations.cpp', 'wt') as fh:
	fh.write('#include "Cpu.hpp"\n\n')
	for ix,i in enumerate(ins):
		d = i[0]
		if 'operation' not in d:
			continue

		commentblock = "/*++\n Operation:\t{:s}\n Opcode:\t{:s}\n Width:\t\t{:s}\n Cycles:\t{:s}/{:s}\n Flags:\t\t{:s} --*/\n".format(d['opstring'], hex(d['instruction']), d['width'], d['cycles'][0], d['cycles'][1], ' '.join(d['flags']))

		code = "\tthrow std::runtime_error(\"Instruction {:s} not implemented\");".format(d['opstring'])

		# if len(d['operands']) == 1:
		# 	if d['operation'] == 'INC' or d['operation'] == 'DEC':
		# 		if d['operands'][0][0] == '(':
		# 			# Increment memory
		# 			code = '\tm_Memory[m_Registers.{:s}] = m_Memory[m_Registers.{:s}].Get() {:s} 1;'.format(d['operands'][0][1:-1], d['operands'][0][1:-1], '+' if d['operation'] == 'INC' else '-')
		# 			# Check the flags
		# 			if d['flags'][0] == 'Z':
		# 				code += '\n\tif( m_Memory[m_Registers.{:s}].Get() == 0 )\n\t\tm_Registers.F |= FLAG_ZERO;'.format(d['operands'][0][1:-1])
		# 			if d['flags'][2] == 'H':
		# 				code += '\n\tif( m_Memory[m_Registers.{:s}].Get() > 0x0f )\n\t\tm_Registers.F |= FLAG_HALF;'.format(d['operands'][0][1:-1])
		# 				code += '\n\telse\n\t\tm_Registers.F &= ~FLAG_HALF;'
		# 		else:
		# 			# Increment the register
		# 			code = '\tm_Registers.{:s}{:s};'.format(d['operands'][0], '++' if d['operation'] == 'INC' else '--')
		# 			# Check the flags
		# 			if d['flags'][0] == 'Z':
		# 				code += '\n\tif( m_Registers.{:s} == 0 )\n\t\tm_Registers.F |= FLAG_ZERO;'.format(d['operands'][0])
		# 			if d['flags'][2] == 'H':
		# 				code += '\n\tif( m_Registers.{:s} > 0x0f )\n\t\tm_Registers.F |= FLAG_HALF;'.format(d['operands'][0])
		# 				code += '\n\telse\n\t\tm_Registers.F &= ~FLAG_HALF;'
		# if len(d['operands']) == 2:
		# 	if d['operation'] == 'LD':
		# 		pass

		# if d['flags'][0] == '0':
		# 	code += '\n\tm_Registers.F &= ~FLAG_ZERO;'
		# elif d['flags'][0] == '1':
		# 	code += '\n\tm_Registers.F |= FLAG_ZERO;'
		# if d['flags'][1] == '0':
		# 	code += '\n\tm_Registers.F &= ~FLAG_SUB;'
		# elif d['flags'][1] == '1':
		# 	code += '\n\tm_Registers.F |= FLAG_SUB;'
		# if d['flags'][2] == '0':
		# 	code += '\n\tm_Registers.F &= ~FLAG_HALF;'
		# elif d['flags'][2] == '1':
		# 	code += '\n\tm_Registers.F |= FLAG_HALF;'
		# if d['flags'][3] == '0':
		# 	code += '\n\tm_Registers.F &= ~FLAG_CARR;'
		# elif d['flags'][3] == '1':
		# 	code += '\n\tm_Registers.F |= FLAG_CARR;'

		code += '\n\treturn Opcode.TickCount;'.format(d['cycles'][0])

		function = 'ssize_t\nCpu::{:s}(\n\tconst struct Opcode& Opcode,\n\tssize_t Tick,\n\tssize_t& TickCount\n\t)\n{:s}{{\n{:s}\n}}\n\n'.format(d['methname'], commentblock, code)

		fh.write( function )





