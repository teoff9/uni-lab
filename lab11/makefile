es3.o: es3.cpp
	g++ -c es3.cpp

../lib/arrays/arrays.o: ../lib/arrays/arrays.cpp
	g++ -c ../lib/arrays/arrays.cpp -o ../lib/arrays/arrays.o

lib: ../lib/arrays/arrays.o

es3.x: es3.o ../lib/arrays/arrays.o
	g++ es3.o ../lib/arrays/arrays.o -o es3.x

es3: es3.x
	./es3.x