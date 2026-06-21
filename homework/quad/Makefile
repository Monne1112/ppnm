CXX = g++
CXXFLAGS = -O2 -std=c++17

main: main.o integrate.o
	$(CXX) $^ -o $@

main.o: main.cc integrate.h
integrate.o: integrate.cc integrate.h

erf.data acc.data: main
	./main

erf.png: erf.data erf.gpi
	gnuplot erf.gpi

acc.png: acc.data acc.gpi
	gnuplot acc.gpi

plots: erf.png acc.png

clean:
	rm -f *.o main *.data *.png