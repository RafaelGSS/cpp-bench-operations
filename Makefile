CXX ?= g++
LDFLAGS = -isystem ../benchmark/include -L../benchmark/build/src/
LDLIBS = -lbenchmark -lpthread 

CXXFLAGS= -std=c++17

SRC_DIRS ?= ./

SRCS := $(shell find $(SRC_DIRS) -name "*.cc" -or -name "*.c" -or -name "*.s")
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d) .ccls-cache/

app: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)
clean:
	$(RM) -rf app $(OBJS) $(DEPS)

-include $(DEPS)
