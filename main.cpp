/// TRABAJO PRACTICO COLABORATIVO
/// LABORATORIO DE COMPUTACIÓN 2
/// UTN - FRGP (PUENTES)
/// COMISIÓN:

/// GRUPO N°:
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
