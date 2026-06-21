CXX = g++
CXXFLAGS = -O2 -std=c++17

main: main.o ode.o
	$(CXX) $^ -o $@

main.o: main.cc matrix.h ode.h
ode.o: ode.cc ode.h matrix.h

oscillator.data: main
	./main

oscillator.png: oscillator.data oscillator.gpi
	gnuplot oscillator.gpi

error.png: oscillator.data error.gpi
	gnuplot error.gpi

damped.png: oscillator.data damped.gpi
	gnuplot damped.gpi

plot: oscillator.png error.png damped.png

clean:
	rm -f *.o main *.data *.png