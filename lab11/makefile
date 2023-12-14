es3.o: es3.cpp
	g++ -c es3.cpp

../lib/arrays/arrays.o: ../lib/arrays/arrays.cpp
	g++ -c ../lib/arrays/arrays.cpp -o ../lib/arrays/arrays.o

es3.x: es3.o ../lib/arrays/arrays.o
	g++ es3.o ../lib/arrays/arrays.o -o es3.x

es3: es3.x
	./es3.x

es4.o: es4.cpp
	g++ -c es4.cpp -o es4.o

../lib/stats/stats.o: ../lib/stats/stats.cpp
	g++ -c ../lib/stats/stats.cpp -o ../lib/stats/stats.o

es4.x: es4.o ../lib/arrays/arrays.o ../lib/stats/stats.o
	g++ es4.o ../lib/arrays/arrays.o -o es4.x

es4: es4.x
	./es4.x

es5.o: es5.cpp
	g++ -c es5.cpp -o es5.o

../lib/search/search.o: ../lib/search/search.cpp
	g++ -c ../lib/search/search.cpp -o ../lib/search/search.o

es5.x: es5.o ../lib/search/search.o
	g++ es5.o ../lib/search/search.o -o es5.x

es5: es5.x
	./es5.x