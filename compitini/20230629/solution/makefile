lib/lib.o: lib/lib.cpp
	g++ -c lib/lib.cpp -o lib/lib.o

main.o: main.cpp
	g++ -c main.cpp

compila: main.o lib/lib.o
	g++ main.o lib/lib.o -o main.x

esegui: compila
	./main.x