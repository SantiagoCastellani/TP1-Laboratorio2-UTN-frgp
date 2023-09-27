#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// Colocar las Librerías que se utilizarán

#include <cstdio>
#include <string.h>

#include "Structs.h" // Librería con los Structs y constantes de los Archivos

#include "libxl.h"

using namespace libxl;

Pais reg;

/// --------------------------- PROTOTIPOS DE LAS FUNCIONES ---------------------------

// 1) --------------------------------------------------------------
bool existeRegistro(char *codigo);

// 2) --------------------------------------------------------------
void cargarPais();          // Cargo un registro de Struct.
void grabarPais(Pais reg);  // Grabo en Archivo.
void mostrarPaisDetalle(Pais reg);  // Muestra Toda la Informacion de un Pais

// 3) --------------------------------------------------------------
void leerPaises();          // Leo el Archivo.
void mostrarPais(Pais reg); // Recibo el Registro leido del archivo y lo muestro. Registro x Registro, sin uso de Vectores.

// 4) --------------------------------------------------------------
void mostrarCiudadesxPais();                  // Leo el archivo Ciudades. Dentro de la función se debe pedir al Usuario que ingrese el nombre del Pais.
struct Pais obtenerRegistroPais(char *pais);  // Recibe el codigo del Pais y busca su registro.
                                              // Revisar la opción de pedir primero el ingreso para obtener el Registro y luego leer el archivo Ciudades.
void mostrarCiudadesxPaisYCapital(char *codigo);

// 5) --------------------------------------------------------------
void listarPaises_Superficies();    // Leer y guardar los Registros en un Vector.
                                    // Calcular el Total de Superficie Mundial.
                                    // Mostrar dentro de la función misma, NOMBRE - SUPERFICIE - PORCENTAJE %

// 6) --------------------------------------------------------------
void totalesxContinente();          // Leo el archivo Paises. Dentro de la función se debe pedir al Usuario que ingrese el nombre del Pais.
                                    // Guardo en un vector los registros.
                                    // Calculo los totales y promedios. Muestro.
int menuContinentes();              // Agrego un menu para facilitar la eleccion del continente

// 7) --------------------------------------------------------------
void modificarPais();               // Pido el codigo de pais a modificar.
                                    // Verificar que exista.
                                    // Buscar registro (usar función respectiva).
                                    // Ingresar los nuevos valores y reemplazar.
void grabarModificado(Pais reg);    // Guardar Pais Modificado.
Pais buscarXCodigo(char *codigo);   // Devuelve un Pais sugun su codigo

// 8) --------------------------------------------------------------
void modificarCiudad();             // Pido el codigo de la ciudad a modificar.
bool existeRegistro(int id);        // Verifico si existe Registro. (SOBRECARGA DE FUNCIONES)
                                    // Ingreso codigo pais y verifico si existe
void grabarModificado(Ciudad reg);  // Guardar Ciudad Modificada. (SOBRECARGA DE FUNCIONES)
void mostrarCiudad(int id);         // Muestra una Ciudad segun su Id
struct Ciudad ciudadById(int id);   // Devuelve una Ciudad segun su Id

// 9) --------------------------------------------------------------
void totalesPais_Poblacion();       // Muestra la cantidad de Paises y la poblacion mundial

// 10) --------------------------------------------------------------
void buscarMayorPoblacion();        // Busca la Ciudad de mapoblación

/// ADICIONALES IMPORTANTES
int contarPaises();     // Cuenta el Nro de Registros de Pais
int contarCiudades();   // Cuenta el Nro de Registros de Ciudad

/// PUNTOS 11 y 12 (OPCIONALES)
/// COLOCAR AQUÍ LOS PROTOTIPOS DE LAS FUNCIONES

// 11) --------------------------------------------------------------
void backupPaises();
void backupCiudades();
void restaurarPaises();
void restaurarCiudades();

// 12) --------------------------------------------------------------
void crearExcelPaises();        // Genera un archivo Excel con los Registros de Paises
void crearExcelCiudades();        // Genera un archivo Excel con los Registros de Ciudades

/// --------------------------- DESARROLLO DE LAS FUNCIONES ---------------------------

// 1) --------------------------------------------------------------

// Funcion: EXISTE PAIS ? (By Codigo)
// Verifico si existe Registro.
bool existeRegistro(char codigo[]){
    int tam=0;
    bool existe = false;
    FILE *archivo;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    Pais pais;
    while(fread(&pais,sizeof(Pais),1,archivo)==1){
        if((strcmp(codigo,pais._codigo))==0){
            existe=true;
        }
    }
    fclose(archivo);
    return existe;
};

// 2) --------------------------------------------------------------

// Funcion: CARGAR PAIS
// Cargo un registro de Struct.
void cargarPais(){
    cout<<""<<endl;
    cout<<"- - - - - - - - - - - - - - - - -"<<endl;
    cout<<""<<endl;
    cout<<"\t***AGREGAR PAIS***"<<endl;
    cout<<""<<endl;
    cout<<" Ingrese NOMBRE: ";
    cin.getline(reg._nombre,45);
    cout<<" Ingrese CODIGO: ";
    cin.getline(reg._codigo,4);
    cout<<" Ingrese CODIGO 2: ";
    cin.getline(reg._codigo2,3);
    cout<<" Ingrese CONTINENTE: ";
    cin.getline(reg._continente,20);
    cout<<" Ingrese SUPERFICIE: ";
    cin>>reg._superficie;
    cout<<" Ingrese POBLACION: ";
    cin>>reg._poblacion;
    cout<<" Ingrese INDEPENDENCIA: ";
    cin>>reg._independencia;
    cout<<" Ingrese Expectativa de Vida: ";
    cin>>reg._expectativaDeVida;
    cout<<" Ingrese CODIGO de CAPITAL: ";
    cin>>reg._capital;
    cout<<""<<endl;
    cout<<"\tPais Cargado:"<<endl;
    mostrarPaisDetalle(reg);
    cout<<""<<endl;
    cout<<"- - - - - - - - "<<endl;
    system("pause");
    grabarPais(reg);
};

// Funcion: GUARDAR REGISTRO de PAIS
// Grabo en Archivo.
void grabarPais(Pais reg){
    FILE *archivo;
    archivo = fopen(ARCHIVO_PAISES,"ab");
    fwrite(&reg,sizeof(Pais),1,archivo);
    fclose(archivo);
};

// Funcion: MOSTRAR detalle de PAIS (By Pais)
void mostrarPaisDetalle(Pais reg){
    cout<<"\tNombre: "<<reg._nombre<<endl;
    cout<<"\tCapital: "<<reg._capital<<endl;
    cout<<"\tContinente: "<<reg._continente<<endl;
    cout<<"\tCodigo: "<<reg._codigo<<endl;
    cout<<"\tCodigo 2: "<<reg._codigo2<<endl;
    cout<<"\tSuperficie: "<<reg._superficie<<endl;
    cout<<"\tPoblacion: "<<reg._poblacion<<endl;
    cout<<"\tIndependencia: "<<reg._independencia<<endl;
    cout<<"\tExpectativa de Vida: "<<reg._expectativaDeVida<<endl;
};

// 3) --------------------------------------------------------------

// Funcion: LEER REGISTRO de PAISES
// Leo el Archivo.
void leerPaises(){
    FILE *archivo;
    Pais pais;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    cout<<" "<<endl;
    cout<<"\tLISTA de PAISES y su Codigo"<<endl;
    cout<<" "<<endl;
    while(fread(&pais,sizeof(Pais),1,archivo)==1){
        mostrarPais(pais);
    }
    cout<<" "<<endl;
    fclose(archivo);
};

// Funcion: MOSTRAR PAIS (By Pais) (Muestra solo el nombre, el codigo y el continente)
//(Mostrando toda la info, solo se veian los ultimos, por el tamaño de log que admite la consola)
// Recibo el Registro leido del archivo y lo muestro. Registro x Registro, sin uso de Vectores.
void mostrarPais(Pais reg){
    cout<<"\t"<<reg._nombre<<" - ("<<reg._codigo<<")"<<endl;
};


// 4) --------------------------------------------------------------

// Funcion: MOSTRAR CIUDAD (Pide un  Codigo de Pais)
// Leo el archivo Ciudades. Dentro de la función se debe pedir al Usuario que ingrese el codigo del Pais.
void mostrarCiudadesxPais(){
    char codigo[4];
    cout<<" "<<endl;
    cout<<" Ingrese el codigo de pais en mayusculas: ";
    cin.getline(codigo,4);
    clrscr();
    if(existeRegistro(codigo)){
        Pais pais = obtenerRegistroPais(codigo);
        cout<<" "<<endl;
        cout<<"\tCiudades de "<<pais._nombre<<endl;
        cout<<" "<<endl;
        mostrarCiudadesxPaisYCapital(codigo);
        cout<<" "<<endl;
    } else {
        cout<<" "<<endl;
        cout<<"\tCodigo de Pais INCORRECTO"<<endl;
        cout<<" "<<endl;
    }
};

// Funcion: PAIS (By Codigo)
// Recibe el codigo del Pais y busca su registro.
struct Pais obtenerRegistroPais(char *codigo){
    FILE *archivo;
    Pais pais;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    if(existeRegistro(codigo)){
        while(fread(&pais,sizeof(Pais),1,archivo)==1){
            if((strcmp(codigo,pais._codigo))==0){
                return pais;
            }
        }
        fclose(archivo);
    }
    fclose(archivo);
};

// Funcion: MUESTRA LAS CIUDADES Y LA CAPITAL DADO UN CODIGO DE PAIS
void mostrarCiudadesxPaisYCapital(char *codigo){
    FILE *archivo;
    Ciudad ciudad;
    Pais pais=obtenerRegistroPais(codigo);
    int idCapital=pais._capital;
    Ciudad ciudadCapital=ciudadById(idCapital);
    archivo = fopen(ARCHIVO_CIUDADES,"rb");
    while(fread(&ciudad,sizeof(Ciudad),1,archivo)==1){
        if((strcmp(codigo,ciudad._idpais))==0){
            cout<<"\t"<<ciudad._nombre<<" - Poblacion: "<<ciudad._poblacion<<endl;
        }
    }
    cout<<""<<endl;
    cout<<"\tLa capital es :"<<ciudadCapital._nombre<<endl;
    fclose(archivo);
}

// 5) --------------------------------------------------------------
// Leer y guardar los Registros en un Vector.
// Calcular el Total de Superficie Mundial.
// Mostrar dentro de la función misma, NOMBRE - SUPERFICIE - PORCENTAJE %

// Funcion: LISTAR PAISES, su superficie y la relacion con la superficie total
void listarPaises_Superficies(){
    FILE *archivo;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    // Obteniendo cantidad de registros del archivo
    fseek (archivo, 0, SEEK_END);
    int tam = (ftell(archivo))/sizeof(Pais);
    fseek (archivo, 0,0);
    // Asignando poblaciones al vector
    Pais vPaises[tam];
    float vSuperficie[tam];
    float superficieTotal=0;
    fread(&vPaises,sizeof(Pais),tam,archivo);
    for(int x=0;x<tam;x++){
        vSuperficie[x]=vPaises[x]._superficie;
        superficieTotal=superficieTotal+vSuperficie[x];
    }
    cout<<" "<<endl;
    cout<<"\tPAISES / SUPERFICIES"<<endl;
    cout<<" "<<endl;
    cout<<"\tSuperficie Mundial Total: "<<superficieTotal<<endl;
    cout<<" "<<endl;
    for(int x=0;x<tam;x++){
        long double porcentaje = (long double) (vPaises[x]._superficie)/superficieTotal;
        cout<<"\t"<<vPaises[x]._nombre<<" | Sup: "<<vPaises[x]._superficie<<" | "<<porcentaje<<"%"<<endl;
    }
    cout<<" "<<endl;
    fclose(archivo);
};

// 6) --------------------------------------------------------------
// Leo el archivo Paises. Dentro de la función se debe pedir al Usuario que ingrese el nombre del Pais.
// Guardo en un vector los registros.
// Calculo los totales y promedios. Muestro.

// Funcion: ESTADISTICAS por CONTINENTE
void totalesxContinente(){
    char continente[20];
    cout<<" "<<endl;
    cout<<"\tESTADISTICAS por CONTINENTE"<<endl;
    cout<<" "<<endl;
    int numContinente = menuContinentes();
    switch(numContinente){
    case 1:
        strcpy(continente,"America del Sur");
        break;
    case 2:
        strcpy(continente,"America del Norte");
        break;
    case 3:
        strcpy(continente,"Africa");
        break;
    case 4:
        strcpy(continente,"Asia");
        break;
    case 5:
        strcpy(continente,"Europa");
        break;
    case 6:
        strcpy(continente,"Oceania");
        break;
    case 7:
        strcpy(continente,"Antarctica");
        break;
    case 8:
        strcpy(continente,"Continente misterioso");
        break;
    default:
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"\tPareciera que no ha elegido ninguna opcion valida"<<endl;
        break;
    }
    FILE *archivo;
    Pais pais;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    int poblacionTotal=0;
    float superficieTotal=0;
    float densidad=0;
    int cantPaises=0;
    cout<<" "<<endl;
    while(fread(&pais,sizeof(Pais),1,archivo)==1){
        if(strcmp(continente,pais._continente)==0){
            poblacionTotal=poblacionTotal + pais._poblacion;
            superficieTotal=superficieTotal + pais._superficie;
            cantPaises++;
        }
    }
    if(superficieTotal!=0){
        densidad=poblacionTotal/superficieTotal;
    }
    if(cantPaises!=0){
        cout<<" "<<endl;
        cout<<" Usted ha elegido: "<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"\t"<<continente<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"\tCantidad de Paises: "<<cantPaises<<endl;
        cout<<" "<<endl;
        cout<<"\tPoblacion: "<<poblacionTotal<<endl;
        cout<<" "<<endl;
        cout<<"\tSuperficie Total: "<<superficieTotal<<endl;
        cout<<" "<<endl;
        cout<<"\tDensidad Poblacional: "<<densidad<<endl;
        cout<<" "<<endl;
    } else {
        cout<<" "<<endl;
        cout<<"\tEl continente pareciera no tener ningun pais"<<endl;
        cout<<" "<<endl;
    }
    fclose(archivo);
};

// Funcion: MENU de CONTINENTES
int menuContinentes(){
    int continente;
    cout<<"\tQue continente desea explorar?"<<endl;
    cout<<" "<<endl;
    cout<<"\t1 - America del Sur"<<endl;
    cout<<" "<<endl;
    cout<<"\t2 - America del Norte"<<endl;
    cout<<" "<<endl;
    cout<<"\t3 - Africa"<<endl;
    cout<<" "<<endl;
    cout<<"\t4 - Asia"<<endl;
    cout<<" "<<endl;
    cout<<"\t5 - Europa"<<endl;
    cout<<" "<<endl;
    cout<<"\t6 - Oceania"<<endl;
    cout<<" "<<endl;
    cout<<"\t7 - Antarctica"<<endl;
    cout<<" "<<endl;
    cout<<"\t8 - Continente misterioso"<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\tElija una opcion: ";
    cin>>continente;
    clrscr();
    return continente;
}

// 7) --------------------------------------------------------------
// Pido el codigo de pais a modificar.
// Verificar que exista.
// Buscar registro (usar función respectiva).
// Ingresar los nuevos valores y reemplazar.

// Funcion: MODIFICAR PAIS (Verifica que el codigo exista)
void modificarPais(){
    cin.ignore();
    char codigo[4];
    cout<<" "<<endl;
    cout<<"\tBuscar Pais a Modificar"<<endl;
    cout<<" "<<endl;
    cout<<"\tIngrese el Codigo de Pais: ";
    cin.getline(codigo,4);
    bool existe=false;
    existe=existeRegistro(codigo);
    if(existe){
        int opcion=0;
        cout<<" "<<endl;
        cout<<"\tPais Encontrado:"<<endl;
        Pais reg;
        reg=buscarXCodigo(codigo);
        mostrarPaisDetalle(reg);
        cout<<" "<<endl;
        cout<<"\tDesea modificar los datos del pais? (SI = 1 | NO = 9 ): ";
        cin>>opcion;
        if(opcion==1){
            clrscr();
            cout<<" "<<endl;
            cout<<"MODIFICACION de PAIS"<<endl;
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"Pais a modificar: "<<reg._nombre<<endl;
            cout<<" "<<endl;
            grabarModificado(reg);
        } else {
            cout<<" "<<endl;
            cout<<"\Volver al menu."<<endl;
            cout<<" "<<endl;
        }
    } else {
        cout<<" "<<endl;
        cout<<"\tCodigo incorrecto:"<<endl;
        cout<<" "<<endl;
    }
    system("pause");
};

// Funcion: GUARDAR PAIS MODIFICADO en el Registro.
void grabarModificado(Pais reg){
    FILE *archivo;
    int res=-1;
    Pais pais;
    archivo = fopen(ARCHIVO_PAISES,"rb+");
    while(fread(&pais,sizeof(Pais),1,archivo)==1){
        if(strcmp(reg._codigo,pais._codigo)==0){
            cin.ignore();
            fseek(archivo,ftell(archivo)-sizeof(Pais),0);
            cout<<"\tIngrese los datos del pais a modificar"<<endl;
            cout<<" "<<endl;
            cout<<" Ingrese NOMBRE: ";
            cin.getline(pais._nombre,45);
            cout<<" Ingrese CONTINENTE: ";
            cin.getline(pais._continente,20);
            cout<<" Ingrese POBLACION: ";
            cin>>pais._poblacion;
            cout<<" Ingrese CODIGO de CAPITAL: ";
            cin>>pais._capital;
            cout<<" Ingrese SUPERFICIE: ";
            cin>>pais._superficie;
            cout<<" Ingrese INDEPENDENCIA: ";
            cin>>pais._independencia;
            cout<<" Ingrese Expectativa de Vida: ";
            cin>>pais._expectativaDeVida;
            res = fwrite(&pais,sizeof(Pais),1,archivo);
            fclose(archivo);
        }
    }
    fclose(archivo);
    if(res==1){
        cout<<" "<<endl;
        cout<<"\tOK: El pais se modifico satisfactoriamente"<<endl;
        cout<<" "<<endl;
    } else {
        cout<<" "<<endl;
        cout<<"\tPor algun motivo no pudo modificarse los datos."<<endl;
        cout<<" "<<endl;
    }
};

// Funcion: DEVUELVE PAIS By Codigo
struct Pais buscarXCodigo(char *codigo){
    FILE *archivo;
    Pais pais;
    Pais paisX;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    cout<<" "<<endl;
    while(fread(&pais,sizeof(Pais),1,archivo)==1){
        if(strcmp(codigo,pais._codigo)==0){
            paisX=pais;
        }
    }
    fclose(archivo);
    return paisX;
}

// 8) --------------------------------------------------------------

// Funcion: MODIFICAR CIUDAD (Se pide el Id de Ciudad)
void modificarCiudad(){
    int id;
    cout<<" "<<endl;
    cout<<"\Modificar CIUDAD?"<<endl;
    cout<<" "<<endl;
    cout<<"\Ingrese el CODIGO de la CIUDAD a modificar: ";
    cin>>id;
    bool existe = existeRegistro(id);
    if(existe){
        int opcion;
        cout<<" "<<endl;
        cout<<"\tCIUDAD ENCONTRADA"<<endl;
        mostrarCiudad(id);
        cout<<" "<<endl;
        cout<<"\tDesea modificar el codigo de pais de la CIUDAD:? (SI = 1 | NO = 9 ): ";
        cin>>opcion;
        if(opcion==1){
            cin.ignore();
            clrscr();
            char codigo[4];
            cout<<" "<<endl;
            cout<<"\tIngrese el NUEVO CODIGO de PAIS:  ";
            cin.getline(codigo,4);
            bool existePais = existeRegistro(codigo);
            if(existePais){
                cout<<" "<<endl;
                cout<<"\tCodigo correcto"<<endl;
                cout<<" "<<endl;
                Ciudad reg;
                reg=ciudadById(id);
                strcpy(reg._idpais,codigo);
                grabarModificado(reg);
                system("pause");
            } else {
                cout<<" "<<endl;
                cout<<"\tEl codigo de pais ingresado es incorrecto:  "<<endl;
                cout<<" "<<endl;
            }
        } else {
            cout<<" "<<endl;
            cout<<"\Volver al menu."<<endl;
            cout<<" "<<endl;
        }
    } else {
        cout<<" "<<endl;
        cout<<"|tEl Id de Ciudad es Incorrecto"<<endl;
        cout<<" "<<endl;
    }
};

// Funcion: EXISTE CIUDAD ? (By Id Ciudad)
// Ingreso codigo ciudad y verifico si existe
// Verifico si existe Registro. (SOBRECARGA DE FUNCIONES)
bool existeRegistro(int id){
    bool existe = false;
    FILE *archivo;
    Ciudad ciudad;
    archivo = fopen(ARCHIVO_CIUDADES,"rb");
    while(fread(&ciudad,sizeof(Ciudad),1,archivo)==1){
        if(id==ciudad._ID){
            existe=true;
        }
    }
    fclose(archivo);
    return existe;
};

// Funcion: GUARDA CIUDAD MODIFICADA
// Guardar Ciudad Modificada. (SOBRECARGA DE FUNCIONES)
void grabarModificado(Ciudad reg){
    FILE *archivo;
    Ciudad ciudad;
    archivo = fopen(ARCHIVO_CIUDADES,"rb+");
    int grabo=0;
    while(fread(&ciudad,sizeof(Ciudad),1,archivo)==1){
        if(ciudad._ID==reg._ID){
            fseek(archivo,ftell(archivo)-sizeof(Ciudad),0);
            ciudad._ID=reg._ID;
            strcpy(ciudad._idpais,reg._idpais);
            strcpy(ciudad._nombre,reg._nombre);
            ciudad._poblacion=reg._poblacion;
            grabo=fwrite(&ciudad,sizeof(Ciudad),1,archivo);
            fclose(archivo);
        }
    }
    fclose(archivo);
    if(grabo==1){
        cout<<" "<<endl;
        cout<<"\tEl nuevo codigo se guardo satisfactoriamente"<<endl;
        cout<<" "<<endl;
        cout<<"\tCIUDAD:"<<endl;
        cout<<" "<<endl;
        mostrarCiudad(reg._ID);
    } else {
        cout<<" "<<endl;
        cout<<"\tPor algun motivo NO pudo guardarse el nuevo codigo"<<endl;
        cout<<" "<<endl;
    }
};

// Funcion: MOSTRAR CIUDAD (By Id)
void mostrarCiudad(int id){
    FILE *archivo;
    Ciudad ciudad;
    archivo = fopen(ARCHIVO_CIUDADES,"rb");
    while(fread(&ciudad,sizeof(Ciudad),1,archivo)==1){
        if(id==ciudad._ID){
            cout<<" "<<endl;
            cout<<"\tNombre: "<<ciudad._nombre<<endl;
            cout<<" "<<endl;
            cout<<"\tPoblacion: "<<ciudad._poblacion<<endl;
            cout<<" "<<endl;
            cout<<"\tId Ciudad: "<<ciudad._ID<<endl;
            cout<<" "<<endl;
            cout<<"\tId Pais: "<<ciudad._idpais<<endl;
            cout<<" "<<endl;
        }
    }
    fclose(archivo);
};

// Funcion: BUSCAR CIUDAD (By Id)
struct Ciudad ciudadById(int id){
    FILE *archivo;
    Ciudad ciudad;
    Ciudad city;
    archivo = fopen(ARCHIVO_CIUDADES,"rb");
    while(fread(&ciudad,sizeof(Ciudad),1,archivo)==1){
        if(id==ciudad._ID){
            city=ciudad;
        }
    }
    fclose(archivo);
    return city;
};

// 9) --------------------------------------------------------------

//Funcion: POBLACION MUNDIAL y PAISES
void totalesPais_Poblacion(){
    FILE *archivo;
    Pais pais;
    long poblacionMundial=0;
    int cant=0;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    while(fread(&pais,sizeof(Pais),1,archivo)==1){
        poblacionMundial=poblacionMundial+pais._poblacion;
        cant++;
    }
    fclose(archivo);
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\tESTADISTICA MUNDIAL"<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\tPOBLACION MUNDIAL: "<<poblacionMundial<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\tCantidad de Paises: "<<cant<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    system("pause");
};

// 10) --------------------------------------------------------------

// Funcion: CIUDAD de MAYOR POBLACION
void buscarMayorPoblacion(){
    FILE *archivo;
    Ciudad ciudad;
    Ciudad superCiudad;
    long mayorPoblacion=0;
    int idCiudad;
    archivo = fopen(ARCHIVO_CIUDADES,"rb");
    while(fread(&ciudad,sizeof(Ciudad),1,archivo)==1){
        if(ciudad._poblacion>mayorPoblacion){
            mayorPoblacion=ciudad._poblacion;
            superCiudad=ciudad;
        }
    }
    Pais pais;
    pais = buscarXCodigo(superCiudad._idpais);
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\tCIUDAD de MAYOR POBLACION"<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\tCiudad: "<<superCiudad._nombre<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\tPoblacion: "<<superCiudad._poblacion<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\tPais: "<<pais._nombre<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"\tContinente: "<<pais._continente<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    fclose(archivo);
    system("pause");
};


/// ADICIONALES IMPORTANTES
// Contar Registros Archivo Paises
int contarPaises(){
    int cant=0;
    FILE *archivo;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    fseek (archivo, 0, SEEK_END);
    cant = (ftell(archivo))/sizeof(Pais);
    fseek (archivo, 0,0);
    fclose(archivo);
    return cant;
};

// Contar Registros Archivo Ciudades
int contarCiudades(){
    int cant=0;
    FILE *archivo;
    archivo = fopen(ARCHIVO_CIUDADES,"rb");
    fseek (archivo, 0, SEEK_END);
    cant = (ftell(archivo))/sizeof(Ciudad);
    fseek (archivo, 0,0);
    fclose(archivo);
    return cant;
};

// 11) --------------------------------------------------------------

// Funcion: BACKUP de PAISES
void backupPaises(){
    FILE *archivo;
    archivo=fopen(ARCHIVO_PAISES,"rb");
    FILE *backup;
    backup=fopen(BACKUP_PAISES,"ab+");
    Pais pais;
    while(fread(&pais,sizeof(Pais),1,archivo)==1){
        fwrite(&pais,sizeof(Pais),1,backup);
    }
    fclose(archivo);
    fclose(backup);
    cout<<" "<<endl;
    cout<<"\tBackup realizado: Backup-Paises.bak"<<endl;
    cout<<" "<<endl;
};

// Funcion: BACKUP de CIUDADES
void backupCiudades(){
    FILE *archivo;
    archivo=fopen(ARCHIVO_CIUDADES,"rb");
    FILE *backup;
    backup=fopen(BACKUP_CIUDADES,"ab+");
    Ciudad ciudad;
    while(fread(&ciudad,sizeof(Ciudad),1,archivo)==1){
        fwrite(&ciudad,sizeof(Ciudad),1,backup);
    }
    fclose(archivo);
    fclose(backup);
    cout<<" "<<endl;
    cout<<"\tBackup realizado: Backup-Ciudades.bak"<<endl;
    cout<<" "<<endl;
};

// Funcion: RESTAURAR PAISES
void restaurarPaises(){
    FILE *backup;
    backup=fopen(BACKUP_PAISES,"rb");
    if(backup){
        FILE *archivo;
        archivo=fopen(ARCHIVO_PAISES,"wb");
        Pais pais;
        while(fread(&pais,sizeof(Pais),1,backup)==1){
            fwrite(&pais,sizeof(Pais),1,archivo);
        }
        fclose(archivo);
        cout<<" "<<endl;
        cout<<"\tArchivos de Paises Restaurados."<<endl;
        cout<<" "<<endl;
    } else {
        cout<<" "<<endl;
        cout<<"\tERROR: Aun no hay ningun backup realizado!"<<endl;
        cout<<" "<<endl;
    }
    fclose(backup);
};

// Funcion: RESTAURAR CIUDADES
void restaurarCiudades(){
    FILE *backup;
    backup=fopen(BACKUP_CIUDADES,"rb");
    if(backup){
        FILE *archivo;
        archivo=fopen(ARCHIVO_CIUDADES,"wb");
        Ciudad ciudad;
        while(fread(&ciudad,sizeof(Ciudad),1,backup)==1){
            fwrite(&ciudad,sizeof(Ciudad),1,archivo);
        }
        fclose(archivo);
        cout<<" "<<endl;
        cout<<"\tArchivos de Ciudades Restauradas."<<endl;
        cout<<" "<<endl;
    } else {
        cout<<" "<<endl;
        cout<<"\tERROR: Aun no hay ningun backup realizado!"<<endl;
        cout<<" "<<endl;
    }
    fclose(backup);
};


// 12) --------------------------------------------------------------

// Funcion: GENERA EXCEL de PAISES
void crearExcelPaises(){
    Book* book = xlCreateBook();
    if (book){
        Sheet* hoja = book->addSheet("PAISES");
        if (hoja){

            Format* campos = book->addFormat();
            Font* font = book->addFont();
            font->setSize(12);
            font->setBold(true);
            campos->setFont(font);
            campos->setFillPattern(FILLPATTERN_SOLID);
            campos->setPatternForegroundColor(COLOR_GRAY25);
            campos->setBorder(BORDERSTYLE_THIN);
            campos->setAlignH(ALIGNH_CENTER);
            campos->setAlignV(ALIGNV_CENTER);
            Format* datos = book->addFormat();
            datos->setBorder(BORDERSTYLE_THIN);
            datos->setAlignH(ALIGNH_CENTER);
            datos->setAlignV(ALIGNV_CENTER);
            hoja->setCol(0, 0, 2);
            hoja->setCol(1, 1, 12);
            hoja->setCol(2, 2, 12);
            hoja->setCol(3, 3, 30); // Puse un tamaño acorde
            hoja->setCol(4, 4, 25); // Puse un tamaño acorde
            hoja->setCol(5, 5, 15);
            hoja->setCol(6, 6, 15);
            hoja->setCol(7, 7, 20);
            hoja->setCol(8, 8, 28);
            hoja->setCol(9, 9, 25);
            hoja->writeStr(1, 1, "CODIGO",campos);
            hoja->writeStr(1, 2, "CODIGO2",campos);
            hoja->writeStr(1, 3, "NOMBRE",campos);
            hoja->writeStr(1, 4, "CONTINENTE",campos);
            hoja->writeStr(1, 5, "SUPERFICIE",campos);
            hoja->writeStr(1, 6, "POBLACION",campos);
            hoja->writeStr(1, 7, "INDEPENDENCIA",campos);
            hoja->writeStr(1, 8, "EXPECTATIVA DE VIDA",campos);
            hoja->writeStr(1, 9, "CAPITAL",campos);
            FILE *archivo;
            Pais pais;
            archivo = fopen(ARCHIVO_PAISES,"rb");
            int f=2;
            while(fread(&pais,sizeof(Pais),1,archivo)==1){
                hoja->writeStr(f, 1, pais._codigo,datos);
                hoja->writeStr(f, 2, pais._codigo2,datos);
                hoja->writeStr(f, 3, pais._nombre,datos);
                hoja->writeStr(f, 4, pais._continente,datos);
                hoja->writeNum(f, 5, pais._superficie,datos);
                hoja->writeNum(f, 6, pais._poblacion,datos);
                hoja->writeNum(f, 7, pais._independencia,datos);
                hoja->writeNum(f, 8, pais._expectativaDeVida,datos);
                Ciudad capital = ciudadById(pais._capital);
                hoja->writeStr(f, 9, capital._nombre,datos);
                f++;
            }
            fclose(archivo);
        }
        book->save("Registro_PAISES.xls");
        cout<<" "<<endl;
        cout<<"\tArchivo descargado: Registro_PAISES.xls"<<endl;
        cout<<" "<<endl;
        book->release();
    }

};

// Funcion: GENERA EXCEL de ciudades
void crearExcelCiudades(){
    Book* book = xlCreateBook();
    if (book){
        Sheet* hoja = book->addSheet("CIUDADES");
        if (hoja){
            Format* campos = book->addFormat();
            Font* font = book->addFont();
            font->setSize(12);
            font->setBold(true);
            campos->setFont(font);
            campos->setFillPattern(FILLPATTERN_SOLID);
            campos->setPatternForegroundColor(COLOR_GRAY25);
            campos->setBorder(BORDERSTYLE_THIN);
            campos->setAlignH(ALIGNH_CENTER);
            campos->setAlignV(ALIGNV_CENTER);
            Format* datos = book->addFormat();
            datos->setBorder(BORDERSTYLE_THIN);
            datos->setAlignH(ALIGNH_CENTER);
            datos->setAlignV(ALIGNV_CENTER);
            hoja->setCol(0, 0, 2);
            hoja->setCol(1, 1, 12);
            hoja->setCol(2, 2, 30);
            hoja->setCol(3, 3, 20);
            hoja->setCol(4, 4, 35);
            hoja->setCol(5, 5, 15);
            hoja->writeStr(1, 1, "ID",campos);
            hoja->writeStr(1, 2, "NOMBRE",campos);
            hoja->writeStr(1, 3, "POBLACION",campos);
            hoja->writeStr(1, 4, "PAIS",campos);
            hoja->writeStr(1, 5, "ID PAIS",campos);
            FILE *archivo;
            Ciudad ciudad;
            archivo = fopen(ARCHIVO_CIUDADES,"rb");
            int f=2;
            while(fread(&ciudad,sizeof(Ciudad),1,archivo)==1){
                hoja->writeNum(f, 1, ciudad._ID,datos);
                hoja->writeStr(f, 2,ciudad._nombre,datos);
                hoja->writeNum(f, 3, ciudad._poblacion,datos);
                Pais pais = buscarXCodigo(ciudad._idpais);
                hoja->writeStr(f, 4, pais._nombre,datos);
                hoja->writeStr(f, 5, ciudad._idpais,datos);
                f++;
            }
            fclose(archivo);
        }
        book->save("Registro_CIUDADES.xls");
        cout<<" "<<endl;
        cout<<"\tArchivo descargado: Registro_CIUDADES.xls"<<endl;
        cout<<" "<<endl;
        book->release();
    }
};


#endif // FUNCIONES_H_INCLUDED
