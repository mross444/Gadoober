output: main.o Dennis.o DungeonMan.o Item.o Game.o Room.o Room1.o Room2.o Room3.o Room4.o Room5.o checkInputValue.o 
	g++ main.o Dennis.o DungeonMan.o Item.o Game.o Room.o Room1.o Room2.o Room3.o Room4.o Room5.o checkInputValue.o -o output

main.o: main.cpp
	g++ -c main.cpp

Dennis.o: Dennis.cpp Dennis.hpp
	g++ -c Dennis.cpp

DungeonMan.o: DungeonMan.cpp DungeonMan.hpp
	g++ -c DungeonMan.cpp
	
Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp
	
Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp
	
Room.o: Room.cpp Room.hpp
	g++ -c Room.cpp
	
Room1.o: Room1.cpp Room1.hpp
	g++ -c Room1.cpp
	
Room2.o: Room2.cpp Room2.hpp
	g++ -c Room2.cpp
	
Room3.o: Room3.cpp Room3.hpp
	g++ -c Room3.cpp

Room4.o: Room4.cpp Room4.hpp
	g++ -c Room4.cpp

Room5.o: Room5.cpp Room5.hpp
	g++ -c Room5.cpp	

checkInputValue.o: checkInputValue.cpp checkInputValue.hpp
	g++ -c checkInputValue.cpp
	
clean:
	rm *.o output 