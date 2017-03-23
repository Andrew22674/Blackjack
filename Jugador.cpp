#include "Jugador.h"
#include <iostream>
using namespace std;

Jugador::Jugador(){
  //wins = 0;
}

Jugador::Jugador(string name){
  //wins = 0;
  nombre = name;
}

void Jugador::addCard(int carta){
  cartas.push_back(carta);
}


string Jugador::getNombre(){
  return nombre;
}

void Jugador::clearCartas(){
  cartas.clear();
}

/*int Jugador::getWins(){
  return wins;
}

void Jugador::addWin(){
  wins += 1;
}*/

vector<int> Jugador::getCartas(){
  return cartas;
}

Jugador::~Jugador(){

}
