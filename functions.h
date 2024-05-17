#include <iostream>

using namespace std;

void numeroAleatorio(int *,int );
void reglas(string);
bool validacionTiradaDados(string *,string *,int *,int *);
void menuJuego(string , string , int , int, string, int, int , int );
char validacionLanzamientos(int);

void tirarDados(string *jugador1, string *jugador2) {
    system("cls");

    cout << "Ingresar el nombre del jugador ";
    cin >> *jugador1;
    cout <<"Ingresar el nombre del jugador ";   //pedimos nombres solo si no hay nombres ya puestos
    cin >> *jugador2;
    while(*jugador1 == *jugador2) {
        cout <<"Ingresaste el mismo nombre en ambos jugadores, por favor pon el segundo jugador distinto nombre ";
        cin >> *jugador2;       //debug evitamos q se puedan enviar dos veces el mismo nombre y problemas distintos con el juego
    }

    system("cls");
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
        cout << endl << "El jugador 2 es: " << *jugador2 << endl;
        system("pause");
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

void juego(string *jugador1,string *jugador2,string *mejorJugador,int *mayorPDV) {
    reglas("rondas");
    int trufasJugador1 = 0,trufasJugador2 = 0, trufasRonda = 0 ,mayLanzamientoJugador1 = 0,mayLanzamientoJugador2 = 0;

    bool hundirse = false;
    

    int lanzamientos = 0;

    for(int i = 1; i<=5;i++) {
        lanzamientos = 0;
        char eleccion = 's';

       while(eleccion == 's' || eleccion == 'S') {
        lanzamientos += 1;
        string turno = *jugador1;
        menuJuego(*jugador1,*jugador2,trufasJugador1,trufasJugador2,turno,i,trufasRonda,lanzamientos); // oink siosi tirar y as 
        eleccion = validacionLanzamientos(lanzamientos);
        system("cls");
       }
    system("cls");

        
    }
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

char validacionLanzamientos(int lanzamientos) {
        if(lanzamientos == 1) {
            system("pause");
            return 's'; // para q el primer lanzamiento se haga 
        } if(lanzamientos != 1) {
            char eleccion = 'd';
            cout << endl << "¿Continuar? (S/N) ";
            while((eleccion != 'n' || eleccion != 'N')||(eleccion != 's' || eleccion != 'S')) {
                cin >> eleccion;
                if(eleccion == 'n' || eleccion == 'N') {
                    return 'n';                                                         // esta function hace que si juega la primera sea indiscutiblemente 
                } if(eleccion == 's' || eleccion == 'S') {                              // una 's' porque siempre tienen que jugar una y despues 
                    return 's';                                                         //pide en la segunda la eleccion, si es 'n' termina, si es 's' sigue lanzando
                } else {                                                                // y si no es ninguna de los dos pide un caracter valido
                    cout << endl << "Por favor ingrese un caracter valido " << endl;
                }
            }
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

void menuJuego(string jugador1, string jugador2, int trufasJugador1, int trufasJugador2, string turno, int rondas, int trufasRonda, int lanzamientos) {
    if(lanzamientos != 1) {
        cout << endl <<"GRAN CERDO" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << jugador1 << ": " << trufasJugador1 << " trufas acumuladas              " << jugador2 << ": " << trufasJugador2 << " trufas acumuladas" << endl << endl;
        cout << "Turno de " << turno << endl;
        cout << "+-------------------------+" << endl;
        cout << "| RONDAS #" << rondas << "               |" << endl;
        cout << "| TRUFAS DE LA RONDA: "<< trufasRonda << "   |" << endl;
        cout << "| LANZAMIENTOS: " << lanzamientos << "         |" << endl;
        cout << "+-------------------------+";
    } 
    if(lanzamientos == 1) {
        cout << endl <<"GRAN CERDO" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << jugador1 << ": " << trufasJugador1 << " trufas acumuladas              " << jugador2 << ": " << trufasJugador2 << " trufas acumuladas" << endl << endl;
        cout << "Turno de " << turno << endl;
        cout << "+-------------------------+" << endl;
        cout << "| RONDAS #" << rondas << "               |" << endl;
        cout << "| TRUFAS DE LA RONDA: "<< trufasRonda << "   |" << endl;
        cout << "| LANZAMIENTOS: " << lanzamientos << "         |" << endl;
        cout << "+-------------------------+";
        cout << endl << "La primera tirada es obligatoria, ";
    }
}

void reglas(string especificacion) {
    if(especificacion == "dados") {
        cout << "Bueno, Antes de comenzar, se debe determinar qui�n empieza. Para ello se lanzan dos dados y la persona que haya obtenido el mayor puntaje comienza" << endl;
        cout << "Si empatan en el puntaje, comienza qui�n que haya obtenido el dado m�s alto. Si empatan nuevamente vuelven a lanzar ambos dados otra vez hasta que se cumpla" << endl;
        cout << "la condici�n de que alguien comience primero." << endl;
    }
    if(especificacion == "rondas") {
        system("cls");
        cout << "El juego está compuesto por cinco rondas por participante y en cada ronda las personas disponen de  lanzamientos ilimitados. En cada lanzamiento se tiran los dados y se analizan los valores de las caras:" << endl;
        cout << "Si las caras son distintas entre sí y ninguna de ellas es un as: El cerdo acumula trufas al puntaje de la ronda por un valor equivalente a la suma de las caras. Por ejemplo: 5 y 3 → Acumula 8 trufas. Luego, puede decidir si volver a lanzar los dados o plantarse y ceder el turno al otro cerdo." << endl;
        cout << "Si las caras son iguales entre sí y no son ases: Entonces el cerdo hizo un Oink y  acumula trufas por el doble de la suma de las caras al total de la ronda. Por ejemplo: 4 y 4 → Acumula 16 trufas. También, está obligado a lanzar los dados una vez más." << endl;
        cout << "Si las caras son distintas entre sí y hay un as entre ellas: Pierde todas las trufas que venía acumulando en la ronda actual y automáticamente le cede el turno al otro cerdo." << endl;
        cout << "Si dos de las caras son iguales entre sí y son ases: El cerdo se hunde en el barro y pierde todas las trufas que venía acumulando en las rondas anteriores y la actual; y automáticamente le cede el turno al otro cerdo.NOTA: Pierde todas las trufas que venía acumulando hasta el momento incluyendo las de la ronda que venía jugando." << endl;
        cout << "Si se está lanzando con tres dados y tres de las caras son iguales entre sí y son ases: Aplica la misma quita de puntos que en el caso anterior pero dichos puntos se acumulan al otro cerdo en dicha ronda." << endl;
        cout << "El juego utiliza dos dados hasta que ambos cerdos superen (cada uno) las 50 trufas o alguno de ellos se hunda en el barro. A partir de allí, el juego se desarrolla con tres dados" << endl;
        system("pause");
        system("cls");
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

void estadisticas(string *mejorJugador,int *PDV) {
    system("cls");
    if(*PDV == -1) {
        cout << "No hay estadisticas" << endl;
    } else {
        cout << "El mejor jugador es " << *mejorJugador << " y tiene la cantidad de " << *PDV << " puntos de victoria" << endl;
    }
    system("pause");
    system("cls");
}