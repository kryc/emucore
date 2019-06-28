TARGETS ?= gameboy gameboydebugger
CPP ?= g++
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
GBDBGOBJS := $(filter-out main.o,$(OBJS))
GBOBJS := $(filter-out debugger.o,$(OBJS))
DEPS := $(OBJS:.o=.d)  # one dependency file for each source

INC_DIRS := ../emucore/include/
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -Wall -Werror
LDFLAGS = 
LIBA = ../emucore/emulib.a

.PHONY: $(TARGET)
$(TARGETS): $(OBJS)
	g++ -o gameboy $(GBOBJS) $(LIBA) $(LDFLAGS)
	g++ -o gameboydebugger $(GBDBGOBJS) $(LIBA) $(LDFLAGS)

-include $(DEPS)   # include all dep files in the makefile

# rule to generate a dep file by using the C preprocessor
# (see man cpp for details on the -MM and -MT options)
%.d: %.cpp
	$(CPP) $(CPPFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(DEPS)

.PHONY: all
all: $(TARGETS)
