#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class PC_AI{
private:
  vector<int> cartas;
  //int wins;

public:
  PC_AI();

  void addCard(int);
  //void addWin();
  vector<int> getCartas();
  //int getWins();
  void clearCartas();

  virtual ~PC_AI();

};
