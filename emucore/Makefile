TARGET_LIB ?= emulib.a

BUILD_DIR ?= build
SRC_DIRS ?= .
CPP ?= g++

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)  # one dependency file for each source

INC_DIRS := include/
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) 
LDFLAGS = -lm 

.PHONY: emulib
emulib: $(OBJS)
	ar rvs emulib.a $(OBJS)

-include $(DEPS)   # include all dep files in the makefile

# rule to generate a dep file by using the C preprocessor
# (see man cpp for details on the -MM and -MT options)
%.d: %.c
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET_LIB)

.PHONY: cleandep
cleandep:
	rm -f $(DEPS)
