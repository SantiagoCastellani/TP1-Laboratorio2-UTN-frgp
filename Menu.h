#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <windows.h>
#include <iostream>

#include "graficos.h"
#include "Funciones.h"

using namespace std;

void menuPaises();
void menuCiudades();
void menuReportes();
void menuConfiguracion();

int MenuPrincipal(){
    int opc;

    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cAZUL,cGRIS_CLARO);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(12,3);
        cout << "-  MENU PRINCIPAL  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(13,5);
        cout << "   1 - PAISES" << endl;
        gotoxy(13,6);
        cout << "   2 - CIUDADES" << endl;
        gotoxy(13,7);
        cout << "   3 - REPORTES" << endl;
        gotoxy(13,8);
        cout << "   4 - CONFIGURACION" << endl;
        gotoxy(3,9);
        cout << "---------------------------------------" << endl;
        gotoxy(13,10);
        cout << "   0 - SALIR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            menuPaises();
            break;
        case 2:
            clrscr();
            menuCiudades();
            break;
        case 3:
            clrscr();
            menuReportes();
            break;
        case 4:
            clrscr();
            menuConfiguracion();
            break;
        case 0:
            cout << endl << endl;
            return 0;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            // Cambia el color de texto a blanco (12) y el fondo a rojo (4) antes de imprimir el texto.
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cAZUL,cGRIS_CLARO);
            break;
        }
    }
}

void menuPaises(){
    int opc;

    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cAZUL,cGRIS_CLARO);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(12,3);
        cout << "-  MENU PAISES  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(6,5);
        cout << "   1 - Agregar Pais" << endl;
        gotoxy(6,6);
        cout << "   2 - Listar Paises" << endl;
        gotoxy(6,7);
        cout << "   3 - Listar Paises x Superficie" << endl;
        gotoxy(6,8);
        cout << "   4 - Modificar Pais" << endl;
        gotoxy(3,9);
        cout << "---------------------------------------" << endl;
        gotoxy(13,10);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            cin.ignore();
            cargarPais();
            break;
        case 2:
            clrscr();
            leerPaises();
            system("pause");
            break;
        case 3:
            clrscr();
            listarPaises_Superficies();
            system("pause");
            break;
        case 4:
            clrscr();
            modificarPais();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            // Cambia el color de texto a blanco (12) y el fondo a rojo (4) antes de imprimir el texto.
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cAZUL,cGRIS_CLARO);
            break;
        }
    }
}

void menuCiudades(){
    int opc;

    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cAZUL,cGRIS_CLARO);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(12,3);
        cout << "-  MENU CIUDADES  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(6,5);
        cout << "   1 - Listar Ciudades x Pais" << endl;
        gotoxy(6,6);
        cout << "   2 - Modificar Codigo Pais" << endl;
        gotoxy(3,7);
        cout << "---------------------------------------" << endl;
        gotoxy(13,9);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            cin.ignore();
            mostrarCiudadesxPais();
            system("pause");
            break;
        case 2:
            clrscr();
            modificarCiudad();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            // Cambia el color de texto a blanco (12) y el fondo a rojo (4) antes de imprimir el texto.
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cAZUL,cGRIS_CLARO);
            break;
        }
    }
}

void menuReportes(){
    int opc;

    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cAZUL,cGRIS_CLARO);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(12,3);
        cout << "-  MENU REPORTES  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(5,5);
        cout << "   1 - Estadisticas x Continente" << endl;
        gotoxy(5,6);
        cout << "   2 - Total de Paises" << endl;
        gotoxy(5,7);
        cout << "   3 - Ciudad con Mayor Poblacion" << endl;
        gotoxy(3,8);
        cout << "---------------------------------------" << endl;
        gotoxy(13,9);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            totalesxContinente();
            system("pause");
            break;
        case 2:
            clrscr();
            totalesPais_Poblacion();
            break;
        case 3:
            clrscr();
            buscarMayorPoblacion();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            // Cambia el color de texto a blanco (12) y el fondo a rojo (4) antes de imprimir el texto.
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cAZUL,cGRIS_CLARO);
            break;
        }
    }
}

void menuConfiguracion(){
    int opcion;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\tCONFIGURACION"<<endl;
    cout<<" "<<endl;
    cout<<"\t1 - DESCARGAR Registro de PAISES (xls)"<<endl;
    cout<<" "<<endl;
    cout<<"\t2 - DESCARGAR Registro de CIUDADES (xls)"<<endl;
    cout<<" "<<endl;
    cout<<"\t3 - Realizar BACKUP de PAISES"<<endl;
    cout<<" "<<endl;
    cout<<"\t4 - Realizar BACKUP de CIUDADES"<<endl;
    cout<<" "<<endl;
    cout<<"\t5 - RESTAURAR Archivo de PAISES"<<endl;
    cout<<" "<<endl;
    cout<<"\t6 - RESTAURAR Archivo de CIUDADES"<<endl;
    cout<<" "<<endl;
    cout<<"\t0 - REGRESAR Al Menu Principal"<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\tElija una opcion: ";
    cin>>opcion;
    clrscr();
    switch(opcion){
    case 1:
        crearExcelPaises();
        system("pause");
        break;
    case 2:
        crearExcelCiudades();
        system("pause");
        break;
    case 3:
        backupPaises();
        system("pause");
        break;
    case 4:
        backupCiudades();
        system("pause");
        break;
    case 5:
        restaurarPaises();
        system("pause");
        break;
    case 6:
        restaurarCiudades();
        system("pause");
        break;
    case 0:
        return;
        break;
    default:
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"\tPareciera que no ha elegido ninguna opcion valida"<<endl;
        break;
    }
}




#endif // MENU_H_INCLUDED
