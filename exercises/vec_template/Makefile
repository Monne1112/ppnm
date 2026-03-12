CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O2

main: main.o vec.o
	$(CXX) $(CXXFLAGS) main.o vec.o -o main

main.o: main.cc vec.h
	$(CXX) $(CXXFLAGS) -c main.cc -o main.o

vec.o: vec.cc vec.h
	$(CXX) $(CXXFLAGS) -c vec.cc -o vec.o

clean:
	rm -f *.o main