CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion
DEBUGFLAGS = -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 
LOCALFLAGS = -DLOCAL

DEBUG = false
ifeq ($(DEBUG),true)
	CXXFLAGS += $(DEBUGFLAGS)
endif

LOCAL = true
ifeq ($(LOCAL),true)
	CXXFLAGS += $(LOCALFLAGS)
endif

TARGET := problem_name
EXECUTE := ./$(TARGET)
CLEAN_TARGETS := $(TARGET)

#TARGET := problem_name.py
#EXECUTE := python3 ./$(TARGET)
#CLEAN_TARGETS :=

CASES := $(sort $(basename $(wildcard $(TARGET)*.in)))
TESTS := $(sort $(basename $(wildcard $(TARGET)*.out)))

all: $(TARGET)

clean:
	-rm -rf $(CLEAN_TARGETS) *.res

cleantest:
	-rm -rf *.in *.out

%: %.cpp # make a
	$(LINK.cpp) $< $(LOADLIBES) $(LDLIBS) -o $@

export TIME=\n  real\t%es\n  user\t%Us\n  sys\t%Ss\n  mem\t%MKB

run: $(TARGET) # make run TARGET=a
	\time $(EXECUTE)

%.res: $(TARGET) %.in # make a.res TARGET=a
	\time $(EXECUTE) < $*.in > $*.res
ifeq ($(DEBUG),true)
	@echo "Built with DEBUG flags enabled, code may be slower than normal"
endif

%.out: % # Cancel the builtin rule

__test_%: %.res %.out
	colordiff -ys $*.res $*.out

runs: $(patsubst %,%.res,$(CASES))

solve: runs # make solve TARGET=a

test: $(patsubst %,__test_%,$(TESTS)) # make test TARGET=a

.PHONY: all clean run test __test_% runs solve

.PRECIOUS: %.res
