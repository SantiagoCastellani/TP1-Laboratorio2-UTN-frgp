/// TRABAJO PRACTICO COLABORATIVO
/// LABORATORIO DE COMPUTACI�N 2
/// UTN - FRGP (PUENTES)
/// COMISI�N:

/// GRUPO N�:
/// INTEGRANTES:
    //  1):
    //  2):

#include "Menu.h"
#include "Funciones.h"

int main()
{
    //SetConsoleTitle("TRABAJO PRACTICO GRUPAL");
    //MenuPrincipal();
    char palabra[4];
    cin.getline(palabra,4);

    bool result = existeRegistro(palabra);
    if(result==true){
        cout<<"EXISTE"<<endl;
    } else {
        cout<<"NO EXISTE"<<endl;
    }
}
