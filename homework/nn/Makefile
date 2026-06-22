CXX = g++
CXXFLAGS = -O2 -std=c++17

main: main.o ann.o minim.o
	$(CXX) $^ -o $@

main.o: main.cc matrix.h ann.h
ann.o: ann.cc ann.h minim.h matrix.h
minim.o: minim.cc minim.h qr.h matrix.h

ann.data points.data: main
	./main

ann.png: ann.data points.data ann.gpi
	gnuplot ann.gpi

plot: ann.png

clean:
	rm -f *.o main *.data *.png