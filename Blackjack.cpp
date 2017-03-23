#include <iostream>
#include <vector>
#include <string>
#include "Jugador.h"
#include "PC_AI.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

bool cartaUsada(vector<int>, int);//verifica si nadie mas tiene esa carta
void getMano(vector<int>);//mustra las cartas del usuario o pc
int getPuntos(vector<int>);//devuelve los puntos de la pc o usuario

string palo[] = {"As de Trebol", "As de Corazones", "As de Diamantes", "As de Picas",//3
								"2 de Trebol", "2 de Corazones", "2 de Diamantes", "2 de Picas",//7
								"3 de Trebol", "3 de Corazones", "3 de Diamantes", "3 de Picas",//11
								"4 de Trebol", "4 de Corazones", "4 de Diamantes", "4 de Picas",//15
								"5 de Trebol", "5 de Corazones", "5 de Diamantes", "5 de Picas",//19
								"6 de Trebol", "6 de Corazones", "6 de Diamantes", "6 de Picas",//23
								"7 de Trebol", "7 de Corazones", "7 de Diamantes", "7 de Picas",//27
								"8 de Trebol", "8 de Corazones", "8 de Diamantes", "8 de Picas",//31
								"9 de Trebol", "9 de Corazones", "9 de Diamantes", "9 de Picas",//35
								"10 de Trebol", "10 de Corazones", "10 de Diamantes", "10 de Picas",//39,
								"J de Trebol", "J de Corazones", "J de Diamantes", "J de Picas",//43
								"Q de Trebol", "Q de Corazones", "Q de Diamantes", "Q de Picas",//47
								"K de Trebol", "K de Corazones", "K de Diamantes", "K de Picas",//51
								};
int valores[] = {11,11,11,11,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,
								8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
int main(){

  vector<int> cartasdejugadores;

  bool game = true;
  int cont_juego = 0;
  int win1 = 0, win2 = 0;
  while(game == true){
    string newgame;
		//if(cont_juego == 0){
			cout << "MENU" << endl
			<< "a. Nuevo juego" << endl
			<< "b. Salir" << endl;
			cin >> newgame;
		//}



    if(newgame == "a" || newgame == "A"){//entra al juego
      cout << "Ingrese nombre de jugador" << endl;
      string name;
      cin.ignore();
      getline(cin, name);

      Jugador* jugador = new Jugador(name);
  		PC_AI* pc_ai = new PC_AI();
      bool repetir = true;

      while(repetir == true){//el juego se repite hasta que el usuario ya no quiera apostar
        cout << "a. Apostar" << endl <<
        "b. Ver marcador" << endl <<
        "c. Salir" << endl;

        string opcion;
        cin >> opcion;

        if(opcion == "a" || opcion == "A"){//el jugador empieza y despues es turno de la pc

          bool apostar = true;

          while(apostar == true){//van a seguir las apuestas hasta que el jugador ya no quiera

            cout << endl << "Turno de " << jugador -> getNombre() << endl;
  					srand (time(NULL));
  					int carta1 = rand() % 52;
  					cartasdejugadores.push_back(carta1);


  					//cout << "Carta 1 " << carta1 << endl;
  					int carta2 = rand() % 52;
  					while(cartaUsada(cartasdejugadores, carta2) == false){//si esa carta ya esta usada, no se le puede dar al jugador
  						carta2 = rand() % 52;
  					}
  					cartasdejugadores.push_back(carta2);
  					//cout << "Carta 2 " << carta2 << endl;

  					//se le dan dos cartas al jugador
  					jugador -> addCard(carta1);
  					jugador -> addCard(carta2);

  					cartasdejugadores.push_back(carta1);
  					cartasdejugadores.push_back(carta2);



  					//se muestran las cartas del jugador
  					getMano(jugador -> getCartas());
  					cout << "Puntos de " << jugador -> getNombre() << ": " << getPuntos(jugador -> getCartas()) << endl;//puntos del jugador

  					bool win = false;//esto detecta si hay un ganador

            if(getPuntos(jugador -> getCartas()) == 21){//si el jugador tiene 21 con las primeras 2 cartas, gana
  						cout << "Blackjack! " << jugador -> getNombre() << " ha ganado" << endl;
  						win1++;
  						win = true;
  					}else if(getPuntos(jugador -> getCartas()) < 21 && win == false){//sino, se le da la opcion de agarrar mas cartas
  						bool agregarcartas = true;
  						while(agregarcartas == true){
  							cout << "Desea agregar otra carta[s/n] " << endl;
  							string otracarta;
  							cin >> otracarta;
  							if(otracarta == "s" || otracarta == "S"){
  								int card = rand() % 52;
  								while(cartaUsada(cartasdejugadores, card) == false){
  									card = rand() % 52;
  								}
  								jugador -> addCard(card);
  								cartasdejugadores.push_back(card);
  								getMano(jugador -> getCartas());
  								cout << "Puntos de " << jugador -> getNombre() << ": " << getPuntos(jugador -> getCartas()) << endl;
  								if(getPuntos(jugador -> getCartas()) > 21){
  									win = true;
  									cout << "La pc ha ganado" << endl;
  									win2++;
  									agregarcartas = false;
  								}else if(getPuntos(jugador -> getCartas()) == 21){
  									win = true;
  									cout << "Blackjack! " << jugador -> getNombre() << " ha ganado" << endl;
  									win1++;
  									agregarcartas = false;
  								}
  							}else{
  								agregarcartas = false;
  							}
  						}

  					}


            //turno de PC
  					if(win == false){
  						cout << endl << "Turno de PC" << endl;
  						int card = rand() % 52;
  						while(cartaUsada(cartasdejugadores, card) == false){
  							card = rand() % 52;
  						}
  						pc_ai -> addCard(card);
  						cartasdejugadores.push_back(card);
  						card = rand() % 52;
  						while(cartaUsada(cartasdejugadores, card) == false){
  							card = rand() % 52;
  						}
  						pc_ai -> addCard(card);
  						cartasdejugadores.push_back(card);

  						getMano(pc_ai -> getCartas());
  						cout << "Puntos de PC:" << getPuntos(pc_ai -> getCartas()) << endl;//puntos del PC_AI

  						bool win = false;//esto detecta si hay un ganador
  						if(getPuntos(pc_ai -> getCartas()) == 21){//si el pc_ai tiene 21 con las primeras 2 cartas, gana
  							cout << "Blackjack! " << "La pc ha ganado" << endl;
  							win2++;
  							win = true;
  						}else if(getPuntos(pc_ai -> getCartas()) < 21 && win == false){//sino, se le da la opcion de agarrar mas cartas
  							bool agregarcartas = true;
  							while(agregarcartas == true && win == false){
  								string otracarta;

  								//agregar carta a la pc solo si sus puntos son menores a los puntos del jugador

  								if(getPuntos(jugador -> getCartas()) > getPuntos(pc_ai -> getCartas())){
  									otracarta = "s";
  								}else if(getPuntos(jugador -> getCartas()) < getPuntos(pc_ai -> getCartas())){
  									cout << "Gano la pc" << endl;
  									win2++;
  									win = true;
  								}else{
  									cout << "PC y jugador tienen los mismos puntos" << endl;
  									win = true;
  								}
  								if(otracarta == "s" || otracarta == "S"){

  									while(getPuntos(jugador -> getCartas()) > getPuntos(pc_ai -> getCartas())){
  										cout << endl << "Se le agrega una carta mas a la pc" << endl;
  										int card = rand() % 52;
  										while(cartaUsada(cartasdejugadores, card) == false){
  											card = rand() % 52;
  										}
  										pc_ai -> addCard(card);
  										cartasdejugadores.push_back(card);
  										getMano(pc_ai -> getCartas());
  										cout << "Puntos de PC:" << getPuntos(pc_ai -> getCartas()) << endl;
  									}




  									if(getPuntos(pc_ai -> getCartas()) > 21){
  										win = true;
  										cout << jugador -> getNombre() << " ha ganado" << endl;
  										win1++;
  										agregarcartas = false;

  									}else if(getPuntos(pc_ai -> getCartas()) == 21){
  										win = true;
  										cout << "Blackjack! " << "La pc ha ganado" << endl;
  										win2++;
  										agregarcartas = false;

  									}else if(win == false){
  										int puntos_jugador, puntos_pc;
  										puntos_jugador = 21 - getPuntos(jugador -> getCartas());
  										puntos_pc = 21 - getPuntos(pc_ai -> getCartas());

  										if(puntos_jugador == puntos_pc){
  											cout << endl <<  "Empate" << endl;
  										}else if(puntos_jugador < puntos_pc){
  											cout << endl << "Ha ganado " << jugador -> getNombre() << endl;
  											win1++;
  											win = true;
  										}else{
  											cout << endl << "Ha ganado la pc" << endl;
  											win2++;
  											win = true;
  									}
  								}else{
  									agregarcartas = false;
  								}
  							}

  						}
  					}

  				}



            cout << "Desea seguir apostando [s/n]" << endl;
            string apos;
            cin >> apos;

            if(apos == "s" || apos == "S"){
              apostar = true;
              jugador -> clearCartas();
  						pc_ai -> clearCartas();
              cartasdejugadores.clear();
            }else{
              apostar = false;
              jugador -> clearCartas();
  						pc_ai -> clearCartas();
              cartasdejugadores.clear();
            }
          }

        }else if(opcion == "b" || opcion == "B"){
          if(win1 == 0 && win2 == 0){
            cout << "Nadie ha ganado aun" << endl;
          }else{
            cout << "Partidas ganadas de " << jugador -> getNombre() << ": " << win1 << endl;
    				cout << "Partidas ganadas de la pc: " << win2 << endl;
          }
        }else if(opcion == "c" || opcion == "C"){
          repetir = false;
          cartasdejugadores.clear();
          delete jugador;
      		delete pc_ai;
        }
        cout << endl;
      }

    }else if(newgame == "b" || newgame == "B"){//sale del juego
      game = false;
    }else{
      game = false;
    }


    cout << endl;
  }


  return 0;
}

bool cartaUsada(vector<int> cartas, int numerodecarta){//esta funcion es necesaria para asegurarse de que solo se entregan cartas que no estan siendo utilizadas
	bool cartadisponible = false;
	for(int i = 0; i < cartas.size(); i++){
		if(cartas[i] == numerodecarta){
			cartadisponible = false;
			break;
		}
		else{
			cartadisponible = true;
		}
	}
	return cartadisponible;
}


int getPuntos(vector<int> cartas){//retorna el total de puntos de jugador/pc, si encuentra un As, dependiendo de la situacion se agrega 1 o 11 puntos
  int total = 0, contAs = 0;

  for(int i = 0; i < cartas.size(); i++){
    if(valores[cartas[i]] == 11 && (total + 11 > 21)){
      total += 1;
    }else{
      total += valores[cartas[i]];
    }
  }

  return total;
}

void getMano(vector<int> cartas){//devuelve la mano del jugador o pc
	cout << "Cartas: ";
	for (int i = 0; i < cartas.size(); i++) {
		if(i != cartas.size()-1)
			cout << palo[cartas[i]] << ", ";
		else
			cout << palo[cartas[i]];
	}cout << endl;
}
