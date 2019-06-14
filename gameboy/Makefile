TARGET ?= gameboy
CPP ?= g++
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)  # one dependency file for each source

INC_DIRS := ../emucore/include/
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -Wall -Werror
LDFLAGS = 
LIBA = ../emucore/emulib.a

.PHONY: $(TARGET)
$(TARGET): $(OBJS)
	g++ -o $@ $^ $(LIBA) $(LDFLAGS)

-include $(DEPS)   # include all dep files in the makefile

# rule to generate a dep file by using the C preprocessor
# (see man cpp for details on the -MM and -MT options)
%.d: %.cpp
	$(CPP) $(CPPFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(DEPS)

.PHONY: all
all: $(TARGET)