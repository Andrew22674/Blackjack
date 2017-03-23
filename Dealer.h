#include <vector>
#include <string>

#ifndef DEALER_H
#define DEALER_H

using namespace std;

class Dealer{
private:
  vector<string> cartas;
  vector<int> puntos;
  int wins;

public:
  Dealer();

  void addCard(int, string);
  int getPuntos();
  void getBaraja();
  int getWins();
  void clearPuntos();

  ~Dealer();

};

#endif
