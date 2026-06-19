CXX = g++
CXXFLAGS = -O2 -std=c++17

main: main.o lsfit.o
	$(CXX) $^ -o $@

main.o: main.cc matrix.h qr.h lsfit.h
lsfit.o: lsfit.cc lsfit.h qr.h matrix.h

fit.data: main
	./main > fit.data

thx.data:
	echo "1 117 6" > $@
	echo "2 100 5" >> $@
	echo "3 88 4" >> $@
	echo "4 72 4" >> $@
	echo "6 53 4" >> $@
	echo "9 29.5 3" >> $@
	echo "10 25.2 3" >> $@
	echo "13 15.2 2" >> $@
	echo "15 11.1 2" >> $@

fit.png: fit.data thx.data fit.gpi
	gnuplot fit.gpi

plot: fit.png

clean:
	rm -f *.o main *.data *.png