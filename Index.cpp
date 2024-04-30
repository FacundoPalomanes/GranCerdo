#include <iostream> // cout y comandos generales
#include <stdlib.h> // system pause, cls etc
#include "functions.h" // functions program
#include <cstdlib> // dado
#include <time.h> // estos dos son para el dado

using namespace std;

void menu();
bool cerrarJuego();
void tirarDados(string * ,string *);


int main() {
    //Inicializo la semilla
    srand(time(NULL));

int eleccion;
bool cerrar = false;
string jugador1,jugador2;


while(cerrar != true) {
menu();
cin >> eleccion;
switch(eleccion) {
    case 1:
        tirarDados(&jugador1,&jugador2);
        system("pause");
        break;
    case 2:
        break;
    case 3:
        break;
    case 0:
        cerrar = cerrarJuego();
        break;
    default:
        cout << "Letra o numero equivocado" << endl;
        break;
    }
}
return 0;
}
