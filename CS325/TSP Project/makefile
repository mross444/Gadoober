output: main.o City.o TSP.o 
	g++ main.o City.o TSP.o

main.o: main.cpp
	g++ -c main.cpp

City.o: City.cpp City.hpp
	g++ -c City.cpp

TSP.o: TSP.cpp TSP.hpp
	g++ -c TSP.cpp
	
clean:
	rm *.o output 