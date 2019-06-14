TARGET ?= gameboy
CPP ?= g++
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

INC_DIRS := ../emucore/include/
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) 
LDFLAGS = -lm
LIBA = ../emucore/emulib.a

.PHONY: $(TARGET)
$(TARGET): $(OBJS)
	g++ -o $@ $^ $(LIBA) $(LDFLAGS)

$(OBJS): $(SRCS)
	g++ -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: cleandep
cleandep:
	rm -f $(DEPS)

.PHONY: all
all: $(TARGET)