#include "Dealer.h"
#include <iostream>

using namespace std;

Dealer::Dealer(){
  wins = 0;

}

void Dealer::addCard(int points, string carta){
  wins = 0;
  cartas.push_back(carta);
  puntos.push_back(points);
}

int Dealer::getPuntos(){
  int total = 0, contAs = 0;

  /*for(int i = 0; i < this -> puntos.size(); i++){
    if(puntos[i] == 11 && contAs == 0 && (total + 11 > 21)){
      total += 1;
      contAs++;
    }else{
      total += puntos[i];
    }
  }*/

  for(int i = 0; i < this -> puntos.size(); i++){
    if(puntos[i] == 11 && (total + 11 > 21)){
      total += 1;
    }else{
      total += puntos[i];
    }
  }

}

  void Dealer::clearPuntos(){
    puntos.clear();
  }

  void Dealer::getBaraja(){
    cout << "Cartas: ";
    for (int i = 0; i < this -> cartas.size(); i++) {
      if(i != cartas.size()-1)
        cout << cartas[i] << ", ";
      else
        cout << cartas[i];
    }cout << endl;
  }

int Dealer::getWins(){

}
