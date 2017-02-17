GTEST_LL = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread

all: iterators stl

iterators: iterator.cpp
	g++ -g -Wall iterator.cpp -o iterators 

stl: stl.cpp
	g++ -g -Wall -o stl stl.cpp $(GTEST_LL)