CXX      ?= g++
CXXFLAGS += -Wall -Wextra -Werror -std=c++23 -O2
LDLIBS   += -lm

all: Out.txt
	cat $<

Out.txt: main
	./main > $@

main: main.o vec.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

main.o: main.cc vec.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

vec.o: vec.cc vec.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean test
clean:
	$(RM) main Out.txt *.o

test:
	@echo $(CXX)
	@echo $(RM)