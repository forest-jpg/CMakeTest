# Makefile for building the CMake project

# create a dependency graph of the project
dependency:
	cd build && cmake -G "MinGW Makefiles" .. -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ --graphviz=graph.dot && dot -Tpng graph.dot -o graph.png

# clean the build directory
prepare:
	rm -rf build
	mkdir build
	cd build
