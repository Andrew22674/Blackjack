#include "PC_AI.h"

PC_AI::PC_AI(){
  //wins = 0;
}


void PC_AI::addCard(int carta){
  cartas.push_back(carta);
}

void PC_AI::clearCartas(){
  cartas.clear();
}

/*int PC_AI::getWins(){
  return wins;
}

void PC_AI::addWin(){
  wins += 1;
}*/

vector<int> PC_AI::getCartas(){
  return cartas;
}

PC_AI::~PC_AI(){
  
}
