#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void numeroAleatorio(int *,int );
void reglas(string);
bool validacionTiradaDados(string *,string *,int *,int *);
void validacionTirada(int *, int, int *,int *,bool *, bool *, bool *, int *);
void menuJuego(string , string , int , int, string, int, int , int );
void pantallaFinal(string, string, int, int, int, int, int, int, int *, int *);
void mostrarDados(int *,int);


void tirarDados(string *jugador1, string *jugador2) {
    system("cls");
    cin.ignore();
    cout << "Ingresar el nombre del jugador ";
    std::getline(std::cin, *jugador1);
    cout <<"Ingresar el nombre del jugador ";   //pedimos nombres solo si no hay nombres ya puestos
    std::getline(std::cin, *jugador2);
    while(*jugador1 == *jugador2) {
        cout <<"Ingresaste el mismo nombre en ambos jugadores, por favor pon el segundo jugador distinto nombre ";
        std::getline(std::cin, *jugador2); //debug evitamos q se puedan enviar dos veces el mismo nombre y problemas distintos con el juego
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

void juego(string jugador1,string jugador2,string *mejorJugador,int *mayorPDV) {
    reglas("rondas");
    int trufasJugador1 = 0,trufasJugador2 = 0, trufasRonda = 0 ,oinksJugador1 = 0, oinksJugador2 = 0 ,mayLanzamientoJugador1 = 0,mayLanzamientoJugador2 = 0;

    int cantidadDados = 2;
    int dadosJugador1[cantidadDados] = {0,0}, dadosJugador2[cantidadDados] = {0,0};


    bool hundirse = false, cedeTurno = false,lanzarDevuelta = false;

    int lanzamientos = 0;
    string turno;
    char eleccion;

    for(int i = 1; i<=5;i++) {
        lanzamientos = 0;
        eleccion = 's';
        turno = jugador1;


        menuJuego(jugador1,jugador2,trufasJugador1,trufasJugador2,turno,i,trufasRonda,lanzamientos);

       while(eleccion == 's' || eleccion == 'S') {
        lanzamientos += 1;
        if(lanzamientos>=mayLanzamientoJugador1) {
            mayLanzamientoJugador1 = lanzamientos;
        }
        if((hundirse == true)||(trufasJugador1>=50&&trufasJugador2>=50)) {
            if(cantidadDados == 2) {
            cantidadDados = 3;
            cout << endl <<"De ahora en adelante, el juego pasa a ser con tres dados" << endl;
            }
        }

            numeroAleatorio(dadosJugador1,cantidadDados);

            menuJuego(jugador1,jugador2,trufasJugador1,trufasJugador2,turno,i,trufasRonda,lanzamientos); // muestra todo el menu del juego


            mostrarDados(dadosJugador1,cantidadDados); // esta function muestra los dados ya sean 2 o tres

            validacionTirada(dadosJugador1,cantidadDados,&trufasJugador1,&trufasRonda,&cedeTurno,&hundirse,&lanzarDevuelta,&trufasJugador2); // aca esta el cout de lo q sucedio y si puede continuar o no

        if(cedeTurno == false&&lanzarDevuelta == false) {
            cout << "Continuar? (S/N) ";
            cin >> eleccion;  //esto es por si se hunde que no tenga chance de elejir
        }
        if(cedeTurno == true) {
            eleccion = 'n';
            cedeTurno = false;
        } if(lanzarDevuelta == true) {
            eleccion = 's';
            lanzarDevuelta = false;
            oinksJugador1 += 1;
        }


         if (eleccion != 's' && eleccion != 'n') { // this function is for the user dont put any label strange
            while(eleccion == 's' || eleccion == 'n') {
                cout << endl << "Ingrese un caracter valido ";
                cin >> eleccion;
            }
        }

        // aca tendria q ir el guardar todas las estadisticas cuantos oinks y etc
       }
       trufasJugador1 += trufasRonda;
       trufasRonda = 0;

        lanzamientos = 0;
        eleccion = 's';
        turno = jugador2;


        menuJuego(jugador1,jugador2,trufasJugador1,trufasJugador2,turno,i,trufasRonda,lanzamientos);

       while(eleccion == 's' || eleccion == 'S') {
        lanzamientos += 1;
        if(lanzamientos>=mayLanzamientoJugador2) {
            mayLanzamientoJugador2 = lanzamientos;
        }
        if((hundirse == true)||(trufasJugador1>=50&&trufasJugador2>=50)) {
            if(cantidadDados == 2) {
            cantidadDados = 3;
            cout << endl <<"De ahora en adelante, el juego pasa a ser con tres dados" << endl;
            }
        }

            numeroAleatorio(dadosJugador2,cantidadDados);

            menuJuego(jugador1,jugador2,trufasJugador1,trufasJugador2,turno,i,trufasRonda,lanzamientos); // muestra todo el menu del juego


            mostrarDados(dadosJugador2,cantidadDados); // esta function muestra los dados ya sean 2 o tres

            validacionTirada(dadosJugador2,cantidadDados,&trufasJugador2,&trufasRonda,&cedeTurno,&hundirse,&lanzarDevuelta,&trufasJugador1); // aca esta el cout de lo q sucedio y si puede continuar o no
        if(cedeTurno == false&&lanzarDevuelta == false) {
            cout << "Continuar? (S/N) ";
            cin >> eleccion;  //esto es por si se hunde que no tenga chance de elejir
        }
        if(cedeTurno == true) {
            eleccion = 'n';
            cedeTurno = false;
        } if(lanzarDevuelta == true) {
            eleccion = 's';
            lanzarDevuelta = false;
            oinksJugador2 += 1;
        }


         if (eleccion != 's' && eleccion != 'n') { // this function is for the user dont put any label strange
            while(eleccion == 's' || eleccion == 'n') {
                cout << endl << "Ingrese un caracter valido ";
                cin >> eleccion;
            }
        }

        // aca tendria q ir el guardar todas las estadisticas cuantos oinks y etc
       }
       trufasJugador2 += trufasRonda;
       trufasRonda = 0;

    }
    cout << endl << "Ya terminaron el juego, ";
    system("pause");
    int PDVJug1 = 0,PDVJug2 = 0;
    pantallaFinal(jugador1,jugador2,trufasJugador1,trufasJugador2,oinksJugador1,oinksJugador2,mayLanzamientoJugador1,mayLanzamientoJugador2,&PDVJug1,&PDVJug2);

    if(PDVJug1>PDVJug2) {
        if(PDVJug1>*mayorPDV) {
            *mayorPDV = PDVJug1;
            *mejorJugador = jugador1;
        }
    } if(PDVJug2>PDVJug1) {
        if(PDVJug2>*mayorPDV) {
            *mayorPDV = PDVJug2;
            *mejorJugador = jugador2;
        }
    }
    //aca se tendria q mostrar el final quien gano


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

void validacionTirada(int dadosJugador[],int cantidadDados, int *trufasJugador,int *trufasRonda,bool *cedeTurno,bool *hundirse,bool *lanzarDevuelta, int *trufasEnemigas) {
    //validacion de tirada
    if(cantidadDados == 2) {
        if(dadosJugador[0] == 1 &&dadosJugador[1] == 1) { // si ambos son 1
            cout << endl << "El cerdo se hunde en el barro y pierdes todas las trufas acumuladas y las de la ronda actual y le cedes el turno al otro cerdo" << endl;
            *trufasJugador = 0;
            *trufasRonda = 0;
            *cedeTurno = true;
            *hundirse = true;
        }
        if((dadosJugador[0] != dadosJugador[1])&&((dadosJugador[0] == 1 && dadosJugador[1] != 1)||(dadosJugador[0] != 1 &&dadosJugador[1] == 1))) { //esto es si hay un solo numero 1 y el otro es uno random
            cout << "Pierdes todas las trufas de la ronda actual y cedes el turno " << endl;
            system("pause");
            *trufasRonda = 0;
            *cedeTurno = true;
        }
        if((dadosJugador[0] == dadosJugador[1])&&((dadosJugador[0] != 1)||(dadosJugador[1] != 1))) { // si hace un oink osea son el mismo numero
            cout << "¡Sumaste " << dadosJugador[0]*2*2 << " trufas!" << endl;
            cout << "El cerdo hizo un Oink y acumula trufas por el doble de la suma de las caras al total de la ronda" << endl;
            cout << "Como hiciste un oink estas obligado a tirar devuelta" << endl;
            system("pause");
            *trufasRonda += dadosJugador[0]*2*2;
            *lanzarDevuelta = true;
        } if((dadosJugador[0]!=dadosJugador[1])&&((dadosJugador[0] != 1)&&(dadosJugador[1] != 1))) {
            cout << "¡Sumaste " << dadosJugador[0]+dadosJugador[1] << " trufas!" << endl;
            cout << "El cerdo acumula trufas " << endl;
            *trufasRonda += (dadosJugador[0] + dadosJugador[1]);
        }

    }
    if(cantidadDados == 3) {
        if(dadosJugador[0] == 1 &&dadosJugador[1] == 1 && dadosJugador[2] == 1) {
            cout << endl << "Pierdes todas las trufas acumuladas y las de la ronda y los puntos se acumulan al otro jugador" << endl;
            *trufasEnemigas += (*trufasJugador + *trufasRonda);
            *trufasJugador = 0;
            *trufasRonda = 0;
            *cedeTurno = true;
        }
        if ((dadosJugador[0] == 1 && dadosJugador[1] == 1)||(dadosJugador[0] == 1 && dadosJugador[2] == 1)||(dadosJugador[1] == 1 && dadosJugador[2] == 1)) {
            cout << endl << "El cerdo se hunde en el barro y pierdes todas las trufas acumuladas y las de la ronda actual y le cedes el turno al otro cerdo" << endl;
            *trufasJugador = 0;
            *trufasRonda = 0;
            *cedeTurno = true;
            *hundirse = true;
        }
        if((dadosJugador[0] == 1 && dadosJugador[1] != 1 && dadosJugador[2] != 1)||(dadosJugador[1] == 1 && dadosJugador[0] != 1 && dadosJugador[2] != 1)||(dadosJugador[2] == 1 && dadosJugador[0] != 1 && dadosJugador[1] != 1)){
            cout << "Pierdes todas las trufas de la ronda actual y cedes el turno " << endl;
            system("pause");
            *trufasRonda = 0;           // esto tendria q funcionar si solo hay un numero con 1
            *cedeTurno = true;
        }
        if(((dadosJugador[0] == dadosJugador[1])&&(dadosJugador[1] == dadosJugador[2]))&&(dadosJugador[0] != 1)) { // comparo 0 con 1 y 1 con 2 y q el 0 sea distinto a numero 1
            cout << "¡Sumaste " << dadosJugador[0]*3*2 << " trufas!" << endl;
            cout << "El cerdo hizo un Oink y acumula trufas por el doble de la suma de las caras al total de la ronda" << endl;
            cout << "Como hiciste un oink estas obligado a tirar devuelta" << endl;
            system("pause");
            *trufasRonda += dadosJugador[0]*3*2; // esto lo hago asi para ahorrar codigo, seria lo mismo ej: (2*2*2)*3 = 2*3*2
            *lanzarDevuelta = true;
        }
        if(((dadosJugador[0] != 1)&&(dadosJugador[1] != 1)&&(dadosJugador[2] != 1))&&((dadosJugador[0]!=dadosJugador[1])&&(dadosJugador[1]!=dadosJugador[2])&&(dadosJugador[2]!=dadosJugador[0]))) { //suma normal de puntos
            cout << "¡Sumaste " << dadosJugador[0]+dadosJugador[1] << " trufas!" << endl;
            cout << "El cerdo acumula trufas " << endl;
            *trufasRonda += (dadosJugador[0] + dadosJugador[1] + dadosJugador[2]);
        }
    }
}

void pantallaFinal(string jugador1,string jugador2,int trufasJugador1, int trufasJugador2,int oinksJugador1,int oinksJugador2,int mayLanzamientoJugador1,int mayLanzamientoJugador2, int *pdvJug1, int *pdvJug2) {
    system("cls");
    if(trufasJugador1==trufasJugador2) {
    *pdvJug1 += 5;
    *pdvJug2 += 5;
}   if(trufasJugador1>trufasJugador2) {
    *pdvJug1 += 5;                           //mayor trufas totales
}if(trufasJugador2>trufasJugador1) {
    *pdvJug2 += 5;
}

*pdvJug1 += trufasJugador1/50;
*pdvJug2 += trufasJugador2/50; // tema un PDV cada 50 trufas

*pdvJug1 += 2*oinksJugador1;
*pdvJug2 += 2*oinksJugador2; // tema oinks

if(mayLanzamientoJugador1>mayLanzamientoJugador2) {
    *pdvJug1 += 3; // tema cerdo codicioso
}if(mayLanzamientoJugador2>mayLanzamientoJugador1) {
    *pdvJug2 += 3;
} if(mayLanzamientoJugador1==mayLanzamientoJugador2) {
    *pdvJug1 += 3;
    *pdvJug2 += 3;
}

//tema puntos arriba
//tema cout abajo
    cout << "GRAN CERDO" << endl;
    cout << "------------------------------------------------------------------------" << endl << endl;
    cout << "HITO                   "<< jugador1 <<"                     "<<jugador2 << endl;
    if(trufasJugador1>trufasJugador2) {
    cout << "Más trufas en total   5 PDV ("<< trufasJugador1 <<" trufas)        0 PDV ("<<trufasJugador2<<" trufas)" << endl;
    } if(trufasJugador2>trufasJugador1) {
    cout << "Más trufas en total   0 PDV ("<< trufasJugador1 <<" trufas)        5 PDV ("<<trufasJugador2<<" trufas)" << endl;
    }
    if(trufasJugador1==trufasJugador2) {
        cout << "Más trufas en total   5 PDV ("<< trufasJugador1 <<" trufas)        5 PDV ("<<trufasJugador2<<" trufas)" << endl;
    }
    cout << "Cada 50 trufas         "<< trufasJugador1/50 <<" PDV ("<< trufasJugador1 <<" trufas)        "<< trufasJugador2/50 <<" PDV ("<< trufasJugador2 <<" trufas)" << endl;
    cout << "Oinks                  "<< oinksJugador1*2 <<" PDV ("<< oinksJugador1 <<" Oinks)          "<< oinksJugador2*2 <<" PDV ("<< oinksJugador2 <<" Oinks)" << endl;
    if(mayLanzamientoJugador1>mayLanzamientoJugador2) {
        cout << "Cerdo codicioso        3 PDV ("<< mayLanzamientoJugador1 <<" lanzamientos)   0 PDV ("<<mayLanzamientoJugador2<<" lanzamientos)" << endl;
    } if(mayLanzamientoJugador2>mayLanzamientoJugador1) {
        cout << "Cerdo codicioso        0 PDV ("<< mayLanzamientoJugador1 <<" lanzamientos)   3 PDV ("<<mayLanzamientoJugador2<<" lanzamientos)" << endl;
    }if(mayLanzamientoJugador1==mayLanzamientoJugador2) {
        cout << "Cerdo codicioso        3 PDV ("<< mayLanzamientoJugador1 <<" lanzamientos)   3 PDV ("<<mayLanzamientoJugador2<<" lanzamientos)" << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
    cout << "TOTAL                  "<< *pdvJug1 <<" PDV                    "<< *pdvJug2 <<" PDV" << endl;
    if(*pdvJug1>*pdvJug2) {
        cout <<" GANADOR: "<<jugador1<<" con "<<*pdvJug1<<" puntos de victoria." << endl;
    }if(*pdvJug2>*pdvJug1) {
        cout <<" GANADOR: "<<jugador2<<" con "<<*pdvJug2<<" puntos de victoria." << endl;
    } if(*pdvJug1==*pdvJug2) {
        cout <<" EMPATE ENTRE: "<<jugador1<<" y "<<jugador2 << endl;
    }
string oink = "sada";
cout << "Ingrese Oink para continuar: ";
while(oink != "Oink") {
cin >> oink;
}
system("cls");

}


//cout functions

void mostrarDados(int dadosJugador[],int cantidadDados) {
    if(cantidadDados == 2) {
            cout << "Tiraste un " << dadosJugador[0] << " y un " << dadosJugador[1] << endl;
    }if(cantidadDados == 3) {
            cout << "Tiraste un " << dadosJugador[0] << ", un " << dadosJugador[1] << " y un " << dadosJugador[2] << endl;
   }
}

void menu() {
cout << "GRAN CERDO" << endl;
cout << "---------------------"<< endl;
cout << "1 - JUGAR" << endl;                // this is the menu in a function so i don't have it in the main code
cout << "2 - ESTADISTICAS" << endl;
cout << "3 - CERDITOS" << endl;
cout << "---------------------"<< endl;
cout << "0 - SALIR" << endl << endl;
}

void menuJuego(string jugador1, string jugador2, int trufasJugador1, int trufasJugador2, string turno, int rondas, int trufasRonda, int lanzamientos ) {
    if(lanzamientos == 0) {
        cout << "GRAN CERDO" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << jugador1 << ": " << trufasJugador1 << " trufas acumuladas       " << jugador2  <<": " << trufasJugador2 << " trufas acumuladas"<< endl << endl;
        cout << "TURNO DE " << turno << endl;
        cout << "+-------------------------+" << endl;
        cout << "| RONDAS #" << rondas << "               |" << endl;
        cout << "| TRUFAS DE LA RONDA: "<< trufasRonda << "   |" << endl; // this is going to be a function so i can put it and i dont care anymore
        cout << "| LANZAMIENTOS: " << lanzamientos+1 << "         |" << endl;
        cout << "+-------------------------+" << endl;

        cout << "El primer lanzamiento es obligatorio, " << endl;
        system("pause");
    }
    if(lanzamientos != 0) {
        cout << endl << "GRAN CERDO" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << jugador1 << ": " << trufasJugador1 << " trufas acumuladas       " << jugador2  <<": " << trufasJugador2 << " trufas acumuladas"<< endl << endl;
        cout << "TURNO DE " << turno << endl;
        cout << "+-------------------------+" << endl;
        cout << "| RONDAS #" << rondas << "               |" << endl;
        cout << "| TRUFAS DE LA RONDA: "<< trufasRonda << "   |" << endl;
        cout << "| LANZAMIENTOS: " << lanzamientos << "         |" << endl;
        cout << "+-------------------------+" << endl;
        cout << "Lanzamiento #" << lanzamientos << endl;
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
    cout << endl << "Equipo numero 8";
    cout << endl << "Martin Alberto Cardone: Legajo 24942";
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

// dato no menor al final del juego te das cuenta que los dados se podrian haber reutilizado es completamente inecesario hacer dos vectores de dados, cuando con uno era mas que suficiente
