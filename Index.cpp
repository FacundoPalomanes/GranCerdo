#include <iostream> // cout y comandos generales
#include <stdlib.h> // system pause, cls etc
#include "functions.h" // functions program
#include <cstdlib> // dado
#include <time.h> // estos dos son para el dado

using namespace std;

void menu();
void creditos();
bool cerrarJuego();
void tirarDados(string * ,string *);


int main() {
    //Inicializo la semilla
    srand(time(NULL));

    int eleccion,mayorPDV = 0;
    bool cerrar = false;
    string jugador1,jugador2,mejorJugador;


    while(cerrar != true) {
        menu();
        cin >> eleccion;
        switch(eleccion) {
            case 1:
                tirarDados(&jugador1,&jugador2);
                //Juego() 
                system("pause");
                break;
            case 2:
                // estadisticas(mejorJugador,mayorPDV); // this should be like this 
                break; // estadisticas
            case 3:
                creditos();
                break; // Cerditos  (Creditos)
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
