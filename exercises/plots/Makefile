CXX = g++
CXXFLAGS += -Wall -Wextra -std=c++23 -O2
LDLIBS += -lm

all: fig1.svg fig2.svg fig3.svg

main: main.o
	$(CXX) $^ -o $@ $(LDLIBS)

out.data: main Makefile
	./main -xmin -3 -xmax 4 -dx 0.05 > out.data

fig1.svg: fig1.gpi out.data
	gnuplot fig1.gpi

fig2.svg: fig2.gpi out.data 
	gnuplot fig2.gpi

fig3.svg: fig3.gpi out.data
	gnuplot fig3.gpi

clean:
	rm -f main main.o out.data fig1.svg fig2.svg sgamma.data