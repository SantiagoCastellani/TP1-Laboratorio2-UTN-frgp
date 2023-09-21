#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// Colocar las Librerías que se utilizarán

#include <cstdio>
#include <string.h>

#include "Structs.h" // Librería con los Structs y constantes de los Archivos

Pais reg;

/// --------------------------- PROTOTIPOS DE LAS FUNCIONES ---------------------------
// 1) --------------------------------------------------------------
bool existeRegistro(char *codigo);

// 2) --------------------------------------------------------------
void cargarPais();          // Cargo un registro de Struct.
void grabarPais(Pais reg);  // Grabo en Archivo.
void mostrarPaisDetalle(Pais reg);
// 3) --------------------------------------------------------------
void leerPaises();          // Leo el Archivo.
void mostrarPais(Pais reg); // Recibo el Registro leido del archivo y lo muestro. Registro x Registro, sin uso de Vectores.

// 4) --------------------------------------------------------------
void mostrarCiudadesxPais();                  // Leo el archivo Ciudades. Dentro de la función se debe pedir al Usuario que ingrese el nombre del Pais.
struct Pais obtenerRegistroPais(char *pais);  // Recibe el nombre del Pais y busca su registro.
                                              // Revisar la opción de pedir primero el ingreso para obtener el Registro y luego leer el archivo Ciudades.
void mostrarCiudadesxPaisYCapital(char *codigo,int idCapital);

// 5) --------------------------------------------------------------
void listarPaises_Superficies();    // Leer y guardar los Registros en un Vector.
                                    // Calcular el Total de Superficie Mundial.
                                    // Mostrar dentro de la función misma, NOMBRE - SUPERFICIE - PORCENTAJE %

// 6) --------------------------------------------------------------
void totalesxContinente();          // Leo el archivo Paises. Dentro de la función se debe pedir al Usuario que ingrese el nombre del Pais.
                                    // Guardo en un vector los registros.
                                    // Calculo los totales y promedios. Muestro.
int menuContinentes();
// 7) --------------------------------------------------------------
void modificarPais();               // Pido el codigo de pais a modificar.
                                    // Verificar que exista.
                                    // Buscar registro (usar función respectiva).
                                    // Ingresar los nuevos valores y reemplazar.
void grabarModificado(Pais reg);    // Guardar Pais Modificado.

// 8) --------------------------------------------------------------
void modificarCiudad();             // Pido el codigo de la ciudad a modificar.
bool existeRegistro(int id);        // Verifico si existe Registro. (SOBRECARGA DE FUNCIONES)
                                    // Ingreso codigo pais y verifico si existe
void grabarModificado(Ciudad reg);  // Guardar Ciudad Modificada. (SOBRECARGA DE FUNCIONES)

// 9) --------------------------------------------------------------
void totalesPais_Poblacion();

// 10) --------------------------------------------------------------
void buscarMayorPoblacion();

    /// ADICIONALES IMPORTANTES
int contarPaises();     // Contar Registros Archivo Paises
int contarCiudades();   // Contar Registros Archivo Ciudades

    /// PUNTOS 11 y 12 (OPCIONALES)
        /// COLOCAR AQUÍ LOS PROTOTIPOS DE LAS FUNCIONES


/// --------------------------- DESARROLLO DE LAS FUNCIONES ---------------------------

// 1) --------------------------------------------------------------

// Verifico si existe Registro.
bool existeRegistro(char codigo[]){
    int tam=0; // Cantidad de Registros del archivo
    bool existe = false;
    //Abrir Archivo
    FILE *archivo;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    // Obteniendo cantidad de registros del archivo
    fseek (archivo, 0, SEEK_END);
    tam = (ftell(archivo))/sizeof(Pais);
    fseek (archivo, 0,0);
    // Leer Archivo
    Pais vPaises[tam];
    fread(&vPaises,sizeof(Pais),tam,archivo);
    for(int x=0;x<tam;x++){
        if((strcmp(codigo,vPaises[x]._codigo))==0){
            existe=true;
        }
    }
    // Cerrar Archivo
    fclose(archivo);
    return existe;
};

// 2) --------------------------------------------------------------

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

// Grabo en Archivo.
void grabarPais(Pais reg){
    // Abrir archivo
    FILE *archivo;
    archivo = fopen(ARCHIVO_PAISES,"ab");
    // Grabar archivo
    fwrite(&reg,sizeof(Pais),1,archivo);
    // Cerrar archivo
    fclose(archivo);
};

void mostrarPaisDetalle(Pais reg){
    cout<<" Nombre: "<<reg._nombre<<endl;
    cout<<" Capital: "<<reg._capital<<endl;
    cout<<" Continente: "<<reg._continente<<endl;
    cout<<" Codigo: "<<reg._codigo<<endl;
    cout<<" Codigo 2: "<<reg._codigo2<<endl;
    cout<<" Superficie: "<<reg._superficie<<endl;
    cout<<" Poblacion: "<<reg._poblacion<<endl;
    cout<<" Independencia: "<<reg._independencia<<endl;
    cout<<" Expectativa de Vida: "<<reg._expectativaDeVida<<endl;
};



// 3) --------------------------------------------------------------

// Leo el Archivo.
void leerPaises(){
    // Abrir el archivo
    FILE *archivo;
    Pais pais;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    // Leer archivo
    cout<<" "<<endl;
    cout<<"\tLISTA de PAISES y su Codigo"<<endl;
    cout<<" "<<endl;
    while(fread(&pais,sizeof(Pais),1,archivo)==1){
        mostrarPais(pais);
    }
    cout<<" "<<endl;
    fclose(archivo);
};

// Recibo el Registro leido del archivo y lo muestro. Registro x Registro, sin uso de Vectores.
void mostrarPais(Pais reg){/*
    cout<<"PAIS"<<endl;
    cout<<"Nombre: "<<reg._nombre<<"\tCodigo: "<<reg._codigo<<" - Codigo2: "<<reg._codigo2<<endl;
    cout<<"Capital: "<<reg._capital<<endl;
    cout<<"Continente: "<<reg._continente<<endl;
    cout<<"Superficie: "<<reg._superficie<<endl;
    cout<<"Poblacion: "<<reg._poblacion<<endl;
    cout<<"Independencia: "<<reg._independencia<<endl;
    cout<<"Expectativa de Vida: "<<reg._expectativaDeVida<<endl;*/
    cout<<"\t"<<reg._nombre<<" - ("<<reg._codigo<<")"<<reg._continente<<endl;
};


// 4) --------------------------------------------------------------

// Leo el archivo Ciudades. Dentro de la función se debe pedir al Usuario que ingrese el nombre del Pais.
void mostrarCiudadesxPais(){
    char codigo[4];
    cout<<" "<<endl;
    cout<<" Ingrese el codigo de pais en mayusculas: ";
    cin.getline(codigo,4);
    clrscr();
    Pais pais = obtenerRegistroPais(codigo);
    if(strcmp(codigo,pais._codigo)==0){
        int idCapital = pais._capital;
        cout<<" "<<endl;
        cout<<"\tCiudades de "<<pais._nombre<<endl;
        cout<<" "<<endl;
        mostrarCiudadesxPaisYCapital(codigo,idCapital);
        cout<<" "<<endl;
    } else {
        cout<<" "<<endl;
        cout<<"\tCodigo de Pais INCORRECTO"<<endl;
        cout<<" "<<endl;
    }
};

// Recibe el codigo del Pais y busca su registro.
struct Pais obtenerRegistroPais(char *codigo){
   // Abrir el archivo
    int x=0;
    FILE *archivo;
    Pais pais;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    // Leer archivo
    if(existeRegistro(codigo)){
        while(fread(&pais,sizeof(Pais),1,archivo)==1){
            if((strcmp(codigo,pais._codigo))==0){
                return pais;
            }
        }
    }
    fclose(archivo);
};

// mUESTRA LAS CIUDADES Y LA CAPITAL DADO UN CODIGO DE PAIS
void mostrarCiudadesxPaisYCapital(char *codigo,int idCapital){
    // Abrir archivo
    FILE *archivo;
    Ciudad ciudad;
    Ciudad ciudadCapital;
    archivo = fopen(ARCHIVO_CIUDADES,"rb");
    // Leer archivo
    while(fread(&ciudad,sizeof(Ciudad),1,archivo)==1){
        if((strcmp(codigo,ciudad._idpais))==0){
            cout<<"\t"<<ciudad._nombre<<" - Poblacion: "<<ciudad._poblacion<<endl;
        }
        if(idCapital==ciudad._ID){
            ciudadCapital=ciudad;
        }
    }
    cout<<""<<endl;
    cout<<"\tLa capital es :"<<ciudadCapital._nombre<<endl;
    // Cerrar archivo
    fclose(archivo);
}

// 5) --------------------------------------------------------------
// Leer y guardar los Registros en un Vector.
// Calcular el Total de Superficie Mundial.
// Mostrar dentro de la función misma, NOMBRE - SUPERFICIE - PORCENTAJE %

void listarPaises_Superficies(){
    // Abrir archivo
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
    /*
        cout<<"Pais: "<<vPaises[x]._nombre<<endl;
        cout<<"Superficie: "<<vPaises[x]._superficie<<" | Porcentaje: "<<porcentaje<<"%"<<endl;
        cout<<" "<<endl;*/
        cout<<"\t"<<vPaises[x]._nombre<<" | Sup: "<<vPaises[x]._superficie<<" | "<<porcentaje<<"%"<<endl;
    }
    cout<<" "<<endl;
    fclose(archivo);
};

// 6) --------------------------------------------------------------
// Leo el archivo Paises. Dentro de la función se debe pedir al Usuario que ingrese el nombre del Pais.
// Guardo en un vector los registros.
// Calculo los totales y promedios. Muestro.
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



#endif // FUNCIONES_H_INCLUDED
