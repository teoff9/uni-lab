lib/punti.o: lib/punti.cpp
	g++ -c lib/punti.cpp -o lib/punti.o

main.o: main.cpp
	g++ -c main.cpp

compila: main.o lib/punti.o
	g++ main.o lib/punti.o -o main.x

esegui: compila
	./main.x