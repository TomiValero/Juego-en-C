#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;

# include "rlutil.h"

///prototipo
int modo(int dados[], int maximopuntaje);


void ingreso(int dados[]){
    int i;
    srand(time(NULL));
    for( i=0; i<6; i++ ){
        dados[i]=(rand()%6)+1;
    }
   rlutil::anykey();
}

void mostrarDados(int dados[]){
    int i, p=0;
    for(i=0;i<6;i++){
        rlutil::locate(50+p,15);
        cout<<dados[i]<<"\t";
        p+=10;
    }
    cout<<endl;
}

int sumaDeDados(int dados[]){
    int i, o, iguales=0, puntaje=0;
     for(i=0;i<6;i++){
            iguales=0;
        for(o=0;o<6;o++){
            if(dados[i]==dados[o]&&o!=i){
                iguales++;
            }
        }
        if(iguales=1){
            for(i=0;i<6;i++){
                puntaje+=dados[i];
            }
        }
    }
    return puntaje;
}

int trio(int dados[]){
     int i, o, iguales=0, puntaje=0, maxpuntaje=0, repetido=0;
     bool band=true;
     for(i=0;i<6;i++){
            iguales=0;
        for(o=0;o<6;o++){
            if(dados[i]==dados[o]&&o!=i){
                iguales++;
            }
        }
        if(iguales>=2 && iguales<5){
            puntaje=dados[i] * 10;
        }
        if(puntaje>=maxpuntaje){
           maxpuntaje=puntaje;
        }
     }
    return maxpuntaje;
}

int sexteto(int dados[]){
    int i, o, iguales=0, puntaje=0;
     for(i=0;i<6;i++){
            iguales=0;
        for(o=0;o<6;o++){
            if(dados[i]==dados[o]&&o!=i){
                iguales++;
            }
        }
     }
        if(iguales>4){
                puntaje=dados[1]*50;
            }
    return puntaje;
}


int escalera(int dados[]){
int i, puntaje=0;
bool band=true;
     for(i=0;i<6;i++){
            if(dados[i]!=(i+1)){
                band=false;
            }
        }
    if(band==true){
            puntaje=500;
    }
    return puntaje;
}

bool seis(int dados[]){
int i, puntaje=0;
bool band=true;
     for(i=0;i<6;i++){
            if(dados[i]!=6){
                    band=false;
            }
        }
    return band;
}


int puntajeRond(int dados[]){
    int puntajeLanzamiento=0, i, puntajeRonda=0;
    string combo;
    bool borrar=false;
     ingreso(dados);
    for(i=0;i<3;i++){
            rlutil::locate(66,8);
        cout<<"LANZAMIENTO: "<<i+1<<endl;
        mostrarDados(dados);
       if(trio(dados)==0&&sexteto(dados)==0&&escalera(dados)==0){
            puntajeLanzamiento=sumaDeDados(dados);
            combo="SUMA";
        }else if(trio(dados)==0&&escalera(dados)==0){
            puntajeLanzamiento=sexteto(dados);
            combo="SEXTETO X";
        }else if(escalera(dados)==0){
             puntajeLanzamiento=trio(dados);
             combo="TRIO";
        } else {
            puntajeLanzamiento=escalera(dados);
            combo="ESCALERA";
        }

        if(seis(dados)==true){
            borrar=true;
            combo="SEXTETO 6";
            puntajeLanzamiento=0;
        }

        rlutil::locate(61,19);
        cout<<"COMBINACION DE LANZAMIENTO: "<<combo<<endl;
        rlutil::locate(63,20);
        cout<<"PUNTAJE DE LANZAMIENTO: "<<puntajeLanzamiento<<endl;
        cout<<endl;

        if(puntajeLanzamiento>puntajeRonda){
            puntajeRonda=puntajeLanzamiento;
        }
       ingreso(dados);
    }
        if(borrar==true){
            puntajeRonda=0;
        }


    return puntajeRonda;

}

int intermedio(string j1, string j2, string proximo, int puntaje1, int puntaje2, int ronda){
     system("cls");
    rlutil::locate(70,6);
    cout<<"RONDA: "<<ronda<<endl;
    rlutil::locate(65,7);
    cout<<"PROXIMO TURNO: "<<proximo<<endl;
    rlutil::locate(65,9);
    cout<<"PUNTAJE DE "<<j1<<" :"<<puntaje1<<endl;
    rlutil::locate(65,10);
    cout<<"PUNTAJE DE "<<j2<<" :"<<puntaje2<<endl;
    cout<<endl;
    rlutil::anykey();
    system("cls");
}

int intermedio1(string j1, int puntaje1, int ronda){
     system("cls");
    rlutil::locate(70,6);
    cout<<"RONDA: "<<ronda<<endl;
    rlutil::locate(65,7);
    cout<<"PUNTAJE DE "<<j1<<" :"<<puntaje1<<endl;
    rlutil::anykey();
    system("cls");
}

void unjugador(int dados[], int maximopuntaje){
    string nombre;
    int puntajeRonda=0, ronda=0, puntajeTotal=0;
    system("cls");
    rlutil::locate(65,6);
    cout<<"NOMBRE: ";
    cin>>nombre;
    system("cls");
    system("cls");
    cout<<endl;
    while(puntajeTotal<500){
        ronda++;
        puntajeRonda=0;
        intermedio1(nombre,puntajeTotal,ronda);
         rlutil::locate(55,5);
       cout<<"TURNO DE: "<<nombre<<" | "<<"RONDA "<<ronda<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
        puntajeRonda=puntajeRond(dados);
        puntajeTotal+=puntajeRonda;
        rlutil::locate(61,19);
        cout<<"                                            ";
        rlutil::locate(60,20);
         rlutil::setColor(15);
        cout<<"   PUNTAJE DE LA RONDA:     "<<puntajeRonda<<endl;
        rlutil::anykey();
        rlutil::setColor(9);
        rlutil::anykey();
        system("cls");
    }

    rlutil::locate(72,11);
        cout<<nombre;
        rlutil::locate(67,13);
        cout<<"RONDA: "<<ronda;
        rlutil::locate(67,14);
        cout<<"PUNTAJE: "<< puntajeTotal<<endl;
        if(puntajeTotal>maximopuntaje){
                    maximopuntaje=puntajeTotal;
                }
    rlutil::locate(66,12);
    cout<<"GANASTE LA PARTIDA!"<<endl;
    rlutil::anykey();
    modo(dados, maximopuntaje);

}

int puntajeDosJugador(int dados[], string nombre, int puntajeTotal,int ronda){
    int puntajeRonda=0;
        system("cls");
        rlutil::locate(55,5);
        cout<<"TURNO DE: "<<nombre<<" | "<<"RONDA "<<ronda<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
        puntajeRonda=puntajeRond(dados);
        puntajeTotal+=puntajeRonda;
          rlutil::locate(61,19);
        cout<<"                                            ";
         rlutil::locate(60,20);
         rlutil::setColor(15);
        cout<<"   PUNTAJE DE LA RONDA:     "<<puntajeRonda<<endl;
        rlutil::anykey();
        rlutil::setColor(9);
        system("cls");
    return puntajeTotal;
}

int dosjugadores(int dados[], int maximopuntaje){
    int ronda=0, puntajeTotal1=0, puntajeTotal2=0, puntajeRonda1=0, puntajeRonda2=0;
    string jugador1, jugador2;
    bool jugador1Gano=false, jugador2Gano=false, empate=false;
     system("cls");
        rlutil::locate(65,7);
        cout<<"NOMBRE 1: ";
        cin>>jugador1;
        rlutil::locate(65,8);
        cout<<"NOMBRE 2: ";
        cin>>jugador2;
        for(int i=0;i<100;i++){
            cout<<"-";
            }
        cout<<endl;
        system("cls");
    while(puntajeTotal1<500 && puntajeTotal2<500 && jugador1Gano==false && jugador2Gano==false){
        ronda++;
        intermedio(jugador1, jugador2, jugador1,puntajeTotal1,puntajeTotal2, ronda);
        puntajeTotal1=puntajeDosJugador(dados, jugador1, puntajeTotal1, ronda);
        if (puntajeTotal1>=500) {
            jugador1Gano=true;
        }
        intermedio(jugador1, jugador2, jugador2,puntajeTotal1,puntajeTotal2, ronda);
        puntajeTotal2=puntajeDosJugador(dados, jugador2, puntajeTotal2,ronda);
        if (puntajeTotal2>=500) {
            jugador2Gano=true;
        }
        if (puntajeTotal1>=500 && puntajeTotal2>=500) {
            empate=true;
        }
    }
    if (jugador1Gano==true && jugador2Gano==false) {
            rlutil::locate(70,6);
        cout<<jugador1<<" GANO!";
        rlutil::locate(70,7);
        cout<<"RONDA: "<<ronda;
        rlutil::locate(70,8);
        cout<<"PUNTAJE: "<< puntajeTotal1<<endl;
       if(puntajeTotal1>maximopuntaje){
                    maximopuntaje=puntajeTotal1;
                }
    } else if (jugador2Gano==true && jugador1Gano==false) {
            rlutil::locate(70,6);
        cout<<jugador2<<" GANO!";
        rlutil::locate(70,7);
        cout<<"RONDA: "<<ronda;
        rlutil::locate(70,8);
        cout<<"PUNTAJE: "<< puntajeTotal2<<endl;
         if(puntajeTotal2>maximopuntaje){
                    maximopuntaje=puntajeTotal2;
                }
    } else if (empate==true) {
         rlutil::locate(70,6);
        cout<<"EMPATARON EN LA RONDA: "<<ronda;
        rlutil::locate(70,7);
        cout<<jugador1<<" CON: "<<puntajeTotal1<<" PUNTOS";
        rlutil::locate(70,8);
        cout<<jugador2<<" CON: "<<puntajeTotal2<<" PUNTOS"<<endl;
        if(puntajeTotal1>puntajeTotal2){
                if(puntajeTotal1>maximopuntaje){
                    maximopuntaje=puntajeTotal1;
                }
        }else if(puntajeTotal2>maximopuntaje){
                    maximopuntaje=puntajeTotal2;
        }
    }
    rlutil::anykey();
     modo(dados, maximopuntaje);
}


int modo(int dados[], int maximopuntaje){
int jugadores;
system("cls");
rlutil::locate(63,5);
cout<<"MAXIMO PUNTAJE: "<< maximopuntaje<<endl;
rlutil::locate(65,6);
cout<<"INGRESE EL MODO: "<<endl;
rlutil::locate(65,7);
cout << "1. UN JUGADOR" << endl;
rlutil::locate(65,8);
cout << "2. DOS JUGADORES"<< endl;
rlutil::locate(65,9);
cout << "0. CERRAR JUEGO"<< endl;
rlutil::locate(63,10);
cout << "ELIJA UNA OPCION: ";
cin>>jugadores;
system("cls");
cout<<endl;
switch(jugadores){
    case 1:
    unjugador(dados, maximopuntaje);
    break;
    case 2:
    dosjugadores(dados, maximopuntaje);
    break;
    case 0:
    rlutil::locate(65,7);
    cout<<"GRACIAS POR JUGAR!";
    return 0;
    break;
    default:
        rlutil::locate(50,13);
        cout<<"OPCION INCORRECTA VUELVA A INGRESAR LA OPCION!";
        rlutil::anykey();
        modo(dados,maximopuntaje);
    break;
}
}


#endif // FUNCIONES_H_INCLUDED
