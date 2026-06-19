CXX = g++
CXXFLAGS = -O2 -std=c++17

main: main.o evd.o 
	$(CXX) $^ -o $@
hydrogen.exe: hydrogen.o evd.o
	$(CXX) $^ -o $@

main.o: main.cc matrix.h
evd.o: evd.cc evd.h
hydrogen.o: hydrogen.cc evd.h

convergence_dr.txt: hydrogen.exe
	for dr in 1 .9 .8 .7 .6 .5 0.4 0.3 0.2 0.15 0.1 0.05; do \
		./hydrogen.exe -rmax 10 -dr $$dr -mode energy; \
	done > $@

convergence_rmax.txt: hydrogen.exe
	for rmax in 1 2 3 4 5 6 8 10 12 15; do \
		./hydrogen.exe -rmax $$rmax -dr 0.1 -mode energy; \
	done > $@

wave0.txt: hydrogen.exe
	./hydrogen.exe -rmax 10 -dr 0.05 -mode wave > $@

convergence_dr.png: convergence_dr.txt convergence_dr.gpi
	gnuplot convergence_dr.gpi

convergence_rmax.png: convergence_rmax.txt convergence_rmax.gpi
	gnuplot convergence_rmax.gpi

wave0.png: wave0.txt wave0.gpi
	gnuplot wave0.gpi

plots: convergence_dr.png convergence_rmax.png wave0.png


clean:
	rm -f *.o *.exe *.txt *.png