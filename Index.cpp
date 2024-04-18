#include <iostream>
#include "functions.h"

using namespace std;

void menu();

int main() {

menu();
int eleccion;

while(1>0) {
cin >> eleccion;
switch(eleccion) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 0:
        char decision;
        cout << "Estas seguro que quieres salir? Y/N ";
        cin >> decision;
        while(decision != 'Y' || decision != 'N') {
        if(decision == 'Y'|| decision == 'y') {
            return 0;
        } if(decision == 'N' || decision == 'n') {
        break;
        }
            cout << "Ingresar caracter valido ";
            cin >> decision;
        }
        break;
    default:
        cout << "Letra o numero equivocado" << endl;
        break;
}
}

return 0;
}
