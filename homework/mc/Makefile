CXX = g++
CXXFLAGS = -O2 -std=c++17

main: main.o mc.o
	$(CXX) $^ -o $@

main.o: main.cc matrix.h mc.h
mc.o: mc.cc mc.h matrix.h

circle.data ellipsoid.data: main
	./main

circle.png: circle.data circle.gpi
	gnuplot circle.gpi

ellipsoid.png: ellipsoid.data ellipsoid.gpi
	gnuplot ellipsoid.gpi

plots: circle.png ellipsoid.png

clean:
	rm -f *.o main *.data *.png