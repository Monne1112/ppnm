CXX = g++
CXXFLAGS = -O2 -std=c++17

main: main.o recover.o
	$(CXX) $^ -o $@

main.o: main.cc matrix.h recover.h
recover.o: recover.cc recover.h matrix.h


recover.data: main
	./main

recover.png: recover.data recover.gpi
	gnuplot recover.gpi

error.png: recover.data error.gpi
	gnuplot error.gpi

plot: recover.png error.png

clean:
	rm -f *.o main *.data *.png