es1.o: es1.cpp
	g++ -c es1.cpp

../lib/sorting/sorting.o: ../lib/sorting/sorting.cpp
	g++ -c ../lib/sorting/sorting.cpp -o ../lib/sorting/sorting.o

es1.x: es1.o ../lib/sorting/sorting.o
	g++ es1.o ../lib/sorting/sorting.o -o es1.x

es1: es1.x
	./es1.x