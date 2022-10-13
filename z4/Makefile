CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic

__start__: ./test_macierzy
	./test_macierzy

obj:
	mkdir -p obj

./test_macierzy: obj obj/main.o obj/Complex.o 
	g++ -o ./test_macierzy obj/main.o obj/Complex.o

obj/main.o: src/main.cpp inc/SVector.hh inc/Complex.hh inc/SMatrix.hh inc/SSystem.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp


obj/Complex.o: src/Complex.cpp inc/Complex.hh
	g++ -c ${CXXFLAGS} -o obj/Complex.o src/Complex.cpp
