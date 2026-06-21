CXX = g++
CXXFLAGS = -O2 -std=c++17

main: main.o minim.o
	$(CXX) $^ -o $@

main.o: main.cc matrix.h qr.h minim.h
minim.o: minim.cc minim.h matrix.h qr.h

clean:
	rm -f *.o main *.data *.png