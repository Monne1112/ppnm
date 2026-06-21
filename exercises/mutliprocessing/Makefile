CXX = g++
CXXFLAGS = -std=c++23 -O2 -Wall -Wextra -pthread

N = 100000000

all: main

main: main.cc
	$(CXX) $(CXXFLAGS) main.cc -o main

out.times: main
	> out.times
	> log.main
	for nthreads in 1 2 3 4 5 6 7 8; do \
		echo -n "$$nthreads " >> out.times; \
		/usr/bin/time --format "%e %U" --append --output out.times ./main -threads $$nthreads -terms $(N) >> log.main; \
	done

clean:
	rm -f main out.times log.main