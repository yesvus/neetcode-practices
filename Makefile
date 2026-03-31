CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

.PHONY: test demo clean

test: DynamicArrayTests
	./DynamicArrayTests

demo: importDemo
	./importDemo

DynamicArrayTests: DynamicArrayTests.cpp DynamicArray.cpp DynamicArray.h
	$(CXX) $(CXXFLAGS) DynamicArrayTests.cpp DynamicArray.cpp -o DynamicArrayTests

importDemo: importDemo.cpp DynamicArray.cpp DynamicArray.h
	$(CXX) $(CXXFLAGS) importDemo.cpp DynamicArray.cpp -o importDemo

clean:
	rm -f DynamicArrayTests importDemo
