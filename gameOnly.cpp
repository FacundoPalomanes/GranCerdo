//este se desarrolla solamente para testear la function principal y poder debbugearla tranquilo
#include <iostream> // cout y comandos generales
#include <stdlib.h> // system pause, cls etc
#include <cstdlib> // dado
#include <time.h> // estos dos son para el dado

using namespace std;

void juego(string ,string ,string *, int *);
void menuJuego(string , string , int , int, string, int, int , int );
void numeroAleatorio(int *, int);
void validacionTirada(int *, int, int *,int *,bool *, bool *, bool *, int *);
void mostrarDados(int *,int);
void pantallaFinal(string, string, int, int, int, int, int, int, int *, int *);

int main() {
    srand(time(NULL)); //Inicializo la semilla

    string jugador1 = "jose", jugador2 = "pepe",mejorJugador;
    int mayorPDV = -1;

    juego(jugador1,jugador2,&mejorJugador,&mayorPDV);

}

void juego(string jugador1,string jugador2,string *mejorJugador,int *mayorPDV) {
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
            cout << "El cerdo hizo un Oink y acumula trufas por el doble de la suma de las caras al total de la ronda" << endl;
            cout << "Como hiciste un oink estas obligado a tirar devuelta" << endl;
            system("pause");
            *trufasRonda += dadosJugador[0]*2*2;
            *lanzarDevuelta = true;
        } if((dadosJugador[0]!=dadosJugador[1])&&((dadosJugador[0] != 1)&&(dadosJugador[1] != 1))) {
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
            cout << "El cerdo hizo un Oink y acumula trufas por el doble de la suma de las caras al total de la ronda" << endl;
            cout << "Como hiciste un oink estas obligado a tirar devuelta" << endl;
            system("pause");
            *trufasRonda += dadosJugador[0]*3*2; // esto lo hago asi para ahorrar codigo, seria lo mismo ej: (2*2*2)*3 = 2*3*2
            *lanzarDevuelta = true;
        }
        if(((dadosJugador[0] != 1)&&(dadosJugador[1] != 1)&&(dadosJugador[2] != 1))&&((dadosJugador[0]!=dadosJugador[1])&&(dadosJugador[1]!=dadosJugador[2])&&(dadosJugador[2]!=dadosJugador[0]))) { //suma normal de puntos
            cout << "El cerdo acumula trufas " << endl;
            *trufasRonda += (dadosJugador[0] + dadosJugador[1] + dadosJugador[2]);
        }
    }
}

void mostrarDados(int dadosJugador[],int cantidadDados) {
    if(cantidadDados == 2) {
            cout << "Tiraste un " << dadosJugador[0] << " y un " << dadosJugador[1] << endl;
    }if(cantidadDados == 3) {
            cout << "Tiraste un " << dadosJugador[0] << ", un " << dadosJugador[1] << " y un " << dadosJugador[2] << endl;
   }
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
while(oink != "Oink" || oink != "oink") {
cin >> oink;
}



}

void numeroAleatorio(int dados[],int rango) {
for(int i = 0; i<=rango-1; i++) {
        dados[i] = (rand()%6+1);
}
}

// dato no menor al final del juego te das cuenta que los dados se podrian haber reutilizado es completamente inecesario hacer dos vectores de dados, cuando con uno era mas que suficiente