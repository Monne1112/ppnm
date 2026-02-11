CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
TARGET = main
OBJS = main.o sfuns.o gamma.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cc sfuns.h
	$(CXX) $(CXXFLAGS) -c main.cc

sfuns.o: sfuns.cc sfuns.h
	$(CXX) $(CXXFLAGS) -c sfuns.cc

gamma.o: gamma.cc sfuns.h
	$(CXX) $(CXXFLAGS) -c gamma.cc

clean:
	rm -f $(OBJS) $(TARGET)