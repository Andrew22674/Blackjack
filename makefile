Proyecto: Blackjack.o Jugador.o PC_AI.o
	g++ Blackjack.o Jugador.o PC_AI.o -o Proyecto

Blackjack.o: Blackjack.cpp Jugador.h PC_AI.h
	g++ -c Blackjack.cpp

Jugador.o: Jugador.cpp Jugador.h
	g++ -c Jugador.cpp

PC_AI.o: PC_AI.cpp PC_AI.h
	g++ -c PC_AI.cpp

clean:
	rm *.o Proyecto
