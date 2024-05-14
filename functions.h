#include <iostream>

using namespace std;

void numeroAleatorio(int *,int );
void reglas(string);
bool validacionTiradaDados(string *,string *,int *,int *);

void tirarDados(string *jugador1, string *jugador2) {
    system("cls");

    cout << "Ingresar el nombre del jugador ";
    cin >> *jugador1;
    cout <<"Ingresar el nombre del jugador ";   //pedimos nombres solo si no hay nombres ya puestos
    cin >> *jugador2;

    reglas("dados"); // explicamos las reglas del juego
    bool finish = false;

    while(finish != true) {
        int const caras = 2;
        int dadosJugador1[caras] = {0,0},dadosJugador2[caras] = {0, 0}; // inicializamos los datos

        cout << endl << *jugador1 << " ";
        system("pause");
        numeroAleatorio(dadosJugador1,caras); // usamos la function para poner numeros aleatorios en el array del jugador1
        cout << "Has tirado un " << dadosJugador1[0] << " y un " << dadosJugador1[1];
        cout << endl << *jugador2 << " ";
        system("pause");
        numeroAleatorio(dadosJugador2,caras); // usamos la function para poner numeros aleatorios en el array del jugador2
        cout << "Has tirado un " << dadosJugador2[0] << " y un " << dadosJugador2[1];

        finish = validacionTiradaDados(jugador1,jugador2,dadosJugador1,dadosJugador2);

        }
        cout << endl << "El jugador 1 es: " << *jugador1;
        cout << endl << "El jugador 2 es: " << *jugador2;
}

bool validacionTiradaDados(string *jugador1,string *jugador2,int dadosJugador1[],int dadosJugador2[]) {
    int suma1,suma2,mayorJugador1,mayorJugador2;
    string cambiador;

    suma1 = dadosJugador1[0]+dadosJugador1[1];
    suma2 = dadosJugador2[0]+dadosJugador2[1];

    if(suma2>suma1) {
        cambiador = *jugador1;
        *jugador1 = *jugador2;    //si el jugador2 gana pasa a ser el 1 y si el 1 gana no hacemos nada porque ya lo habiamos puesto como el primero
        *jugador2 = cambiador;
        return true;
    } if(suma1>suma2) {
        return true;
    }
    if(suma1==suma2) {
        if(dadosJugador1[0]>dadosJugador1[1]) {
            mayorJugador1 = dadosJugador1[0];
        } if(dadosJugador1[1]>=dadosJugador1[0]) {
            mayorJugador1 = dadosJugador1[1];
        }
        if(dadosJugador2[0]>dadosJugador2[1]) {
            mayorJugador2 = dadosJugador2[0];
        } if(dadosJugador2[1]>=dadosJugador2[0]) {
            mayorJugador2 = dadosJugador2[1];
        }
        if(mayorJugador2>mayorJugador1) {
            cambiador = *jugador1;
            *jugador1 = *jugador2;    //si el jugador2 gana pasa a ser el 1 y si el 1 gana no hacemos nada porque ya lo habiamos puesto como el primero
            *jugador2 = cambiador;
            return true;
        } if(mayorJugador1>mayorJugador2) {
            return true;
        }
    }
    return false;
}

void numeroAleatorio(int dados[],int rango) {
for(int i = 0; i<=rango-1; i++) {
        dados[i] = (rand()%6+1);
}
}

bool cerrarJuego() {
    char decision;
    cout << "Estas seguro que quieres salir? Y/N ";
    cin >> decision;
    while(decision != 'Y' || decision != 'N') {
    if(decision == 'Y'|| decision == 'y') {
        return true;
    } if(decision == 'N' || decision == 'n') {              // this function returns a bool if the bool is true it gets out of the program
    system("cls");                                          // but if it is false the program didn't get close and if you put any other value
    return false;                                           // ask you to put a valid character
    }
        cout << "Ingresar caracter valido ";
        cin >> decision;
    }
}

//cout functions

void menu() {
cout << "GRAN CERDO" << endl;
cout << "---------------------"<< endl;
cout << "1 - JUGAR" << endl;                // this is the menu in a function so i don't have it in the main code
cout << "2 - ESTADISTICAS" << endl;
cout << "3 - CERDITOS" << endl;
cout << "---------------------"<< endl;
cout << "0 - SALIR" << endl << endl;
}

void reglas(string especificacion) {
    if(especificacion == "dados") {
        cout << "Bueno, Antes de comenzar, se debe determinar qui�n empieza. Para ello se lanzan dos dados y la persona que haya obtenido el mayor puntaje comienza" << endl;
        cout << "Si empatan en el puntaje, comienza qui�n que haya obtenido el dado m�s alto. Si empatan nuevamente vuelven a lanzar ambos dados otra vez hasta que se cumpla" << endl;
        cout << "la condici�n de que alguien comience primero." << endl;
    }
}

void creditos() {
    system("cls");
    cout << endl << "(Nombre del equipo)";
    cout << endl << "Martin Alberto Cardone: Legajo ????";
    cout << endl << "Facundo Palomanes: Legajo 28799";
    cout << endl << "Simon Theo Barrau: Legajo ????";           // hace falta el resto de Legajos
    cout << endl << "Caterina Fuster: Legajo ????"; 
    cout << endl << "Tadeo Marino Aguirre: Legajo ????" << endl;
    system("pause");
    system("cls");
}