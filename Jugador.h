#pragma once

#include <vector>
#include <string>



using namespace std;

class Jugador{
private:
  string nombre;
  vector<int> cartas;
  //int wins;

public:
  Jugador();
  Jugador(string);

  //setters y getters
  void addCard(int);
  void clearCartas();
  //int getWins();
  string getNombre();
  //void addWin();
  vector<int> getCartas();

  virtual ~Jugador();
};
