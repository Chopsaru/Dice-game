diceGame: main.o Game.o Die.o loadedDie.o
	g++ -std=c++11 main.o Game.o Die.o loadedDie.o -o diceGame

main.o:	main.cpp
	g++ -c -std=c++11 main.cpp

Die.o: Die.hpp Die.cpp
	g++ -c -std=c++11 Die.cpp

loadedDie.o: loadedDie.hpp loadedDie.cpp
	g++ -c -std=c++11 loadedDie.cpp

Game.o: Game.hpp Game.cpp
	g++ -c -std=c++11 Game.cpp

clean:
	rm *.o diceGame
