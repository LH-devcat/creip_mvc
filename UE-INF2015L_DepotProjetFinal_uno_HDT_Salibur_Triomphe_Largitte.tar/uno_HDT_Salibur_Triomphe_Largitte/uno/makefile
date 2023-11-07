all: uno

uno: main.o sdlUno.o Partie.o Pioche.o Joueur.o Carte.o
	g++  -o bin/Release/uno obj/Release/src/Carte.o obj/Release/src/Joueur.o obj/Release/src/main.o obj/Release/src/Partie.o obj/Release/src/Pioche.o obj/Release/src/sdlUno.o  -lSDL2 -lSDL2_ttf -lSDL2_image -s

main.o: src/main.cpp
	g++ -Wall -I/usr/include/SDL2 -O2 -std=c++11 -Iinclude -Iuno/include -c src/main.cpp -o obj/Release/src/main.o

sdlUno.o: include/sdlUno.h src/sdlUno.cpp
	g++ -Wall -I/usr/include/SDL2 -O2 -std=c++11 -Iinclude -Iuno/include -c src/sdlUno.cpp -o obj/Release/src/sdlUno.o

Partie.o: include/Partie.h src/Partie.cpp
	g++ -Wall -I/usr/include/SDL2 -O2 -std=c++11 -Iinclude -Iuno/include -c src/Partie.cpp -o obj/Release/src/Partie.o

Pioche.o: include/Pioche.h src/Pioche.cpp
	g++ -Wall -I/usr/include/SDL2 -O2 -std=c++11 -Iinclude -Iuno/include -c src/Pioche.cpp -o obj/Release/src/Pioche.o

Joueur.o: include/Joueur.h src/Joueur.cpp
	g++ -Wall -I/usr/include/SDL2 -O2 -std=c++11 -Iinclude -Iuno/include -c src/Joueur.cpp -o obj/Release/src/Joueur.o

Carte.o: include/Carte.h src/Carte.cpp
	g++ -Wall -I/usr/include/SDL2 -O2 -std=c++11 -Iinclude -Iuno/include -c src/Carte.cpp -o obj/Release/src/Carte.o


clean:
		rm *.o
		
veryclean: clean rm *.out
