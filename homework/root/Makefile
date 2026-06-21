CXX = g++
CXXFLAGS = -O2 -std=c++17

main: main.o roots.o
	$(CXX) $^ -o $@

main.o: main.cc matrix.h qr.h roots.h
roots.o: roots.cc roots.h matrix.h qr.h

clean:
	rm -f *.o main *.data *.png