//Ejercicio:
//Autor:
//Fecha:
//Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>
#include<ctime>

using namespace std;

# include "Funciones.h"
# include "rlutil.h"


int main(){

    rlutil::setConsoleTitle("QUINIENTOS");
    rlutil::setColor(9);
    rlutil::setBackgroundColor(6);
    rlutil::hidecursor();
    int dados[6], maximopuntaje=0;
    modo(dados, maximopuntaje);
    ///mostrarDados(dados);
	cout<<endl;
	rlutil::anykey();
	return 0;
}
