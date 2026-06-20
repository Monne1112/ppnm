CXX = g++
CXXFLAGS = -O2 -std=c++17

main: main.o spline.o qspline.o
	$(CXX) $^ -o $@

main.o: main.cc spline.h qspline.h
spline.o: spline.cc spline.h
qspline.o: qspline.cc qspline.h

linear.data points.data quadratic.data qspline_cos.data: main
	./main

linear.png: linear.gpi linear.data points.data
	gnuplot linear.gpi

quadratic.png: quadratic.gpi quadratic.data
	gnuplot quadratic.gpi

qspline_cos.png: qspline_cos.gpi qspline_cos.data points.data
	gnuplot qspline_cos.gpi


plots: linear.png quadratic.png qspline_cos.png

clean:
	rm -f *.o main *.data *.png