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
    //archivo = fopen(ARCHIVO_PAISES,"rb");
    archivo = fopen("paisesdeprueba.dat","rb");
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
    cout<<"- - - - - - - - "<<endl;
    cout<<""<<endl;
    cout<<"AGREGAR PAIS"<<endl;
    cout<<""<<endl;
    cout<<"Ingrese CODIGO: ";
    cin.getline(reg._codigo,4);
    cout<<"Ingrese CODIGO 2: ";
    cin.getline(reg._codigo2,3);
    cout<<"Ingrese NOMBRE: ";
    cin.getline(reg._nombre,45);
    cout<<"Ingrese CONTINENTE: ";
    cin.getline(reg._continente,20);
    cout<<"Ingrese SUPERFICIE: ";
    cin>>reg._superficie;
    cout<<"Ingrese POBLACION: ";
    cin>>reg._poblacion;
    cout<<"Ingrese INDEPENDENCIA: ";
    cin>>reg._independencia;
    cout<<"Ingrese Expectativa de Vida: ";
    cin>>reg._expectativaDeVida;
    cout<<"Ingrese CAPITAL: ";
    cin>>reg._capital;
    cout<<""<<endl;
    cout<<"Pais Cargado:"<<endl;
    cout<<"Nombre: "<<reg._nombre<<endl;
    cout<<"Capital: "<<reg._capital<<endl;
    cout<<"Continente: "<<reg._continente<<endl;
    cout<<"Codigo: "<<reg._codigo<<endl;
    cout<<"Codigo 2: "<<reg._codigo2<<endl;
    cout<<"Superficie: "<<reg._superficie<<endl;
    cout<<"Poblacion: "<<reg._poblacion<<endl;
    cout<<"Independencia: "<<reg._independencia<<endl;
    cout<<"Expectativa de Vida: "<<reg._expectativaDeVida<<endl;
    cout<<""<<endl;
    cout<<"- - - - - - - - "<<endl;

    grabarPais(reg);
};

// Grabo en Archivo.
void grabarPais(Pais reg){
    // Abrir archivo
    FILE *archivo;
    archivo = fopen(PRUEBA_PAISES,"ab");
    // Grabar archivo
    fwrite(&reg,sizeof(Pais),1,archivo);
    // Cerrar archivo
    fclose(archivo);
}

// 3) --------------------------------------------------------------

// Leo el Archivo.
void leerPaises(){
    // Abrir el archivo
    FILE *archivo;
    Pais pais;
    archivo = fopen(PRUEBA_PAISES,"rb");
    // Leer archivo
    while(fread(&pais,sizeof(Pais),1,archivo)==1){
        mostrarPais(pais);
    }
    fclose(archivo);
};

// Recibo el Registro leido del archivo y lo muestro. Registro x Registro, sin uso de Vectores.
void mostrarPais(Pais reg){
    cout<<" "<<endl;
    cout<<"PAIS"<<endl;
    cout<<"Nombre: "<<reg._nombre<<"\tCodigo: "<<reg._codigo<<" - Codigo2: "<<reg._codigo2<<endl;
    cout<<"Capital: "<<reg._capital<<endl;
    cout<<"Continente: "<<reg._continente<<endl;
    cout<<"Superficie: "<<reg._superficie<<endl;
    cout<<"Poblacion: "<<reg._poblacion<<endl;
    cout<<"Independencia: "<<reg._independencia<<endl;
    cout<<"Expectativa de Vida: "<<reg._expectativaDeVida<<endl;
    cout<<" "<<endl;
};


// 4) --------------------------------------------------------------

// Leo el archivo Ciudades. Dentro de la función se debe pedir al Usuario que ingrese el nombre del Pais.
void mostrarCiudadesxPais(){
    char codigo[4];
    cin.getline(codigo,4);
    Pais pais = obtenerRegistroPais(codigo);
    if(strcmp(codigo,pais._codigo)==0){
        int idCapital = pais._capital;
        cout<<" "<<endl;
        cout<<"Ciudades de "<<pais._nombre<<endl;
        cout<<" "<<endl;
        mostrarCiudadesxPaisYCapital(codigo,idCapital);
        cout<<" "<<endl;
    } else {
        cout<<"El nombre de pais es incorrecto"<<endl;
    }
};

// Recibe el codigo del Pais y busca su registro.
struct Pais obtenerRegistroPais(char *codigo){
   // Abrir el archivo
    int x=0;
    FILE *archivo;
    Pais pais;
    archivo = fopen(PRUEBA_PAISES,"rb");
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

void mostrarCiudadesxPaisYCapital(char *codigo,int idCapital){
    // Abrir archivo
    FILE *archivo;
    Ciudad ciudad;
    Ciudad ciudadCapital;
    archivo = fopen(ARCHIVO_CIUDADES,"rb");
    // Leer archivo
    while(fread(&ciudad,sizeof(Ciudad),1,archivo)==1){
        if((strcmp(codigo,ciudad._idpais))==0){
            cout<<ciudad._nombre<<" - Poblacion: "<<ciudad._poblacion<<endl;
        }
        if(idCapital==ciudad._ID){
            ciudadCapital=ciudad;
        }
    }
    cout<<""<<endl;
    cout<<"La capital es :"<<ciudadCapital._nombre<<endl;
    // Cerrar archivo
    fclose(archivo);
}

struct Ciudad obtenerCapital(int idCiudad){

};




// Revisar la opción de pedir primero el ingreso para obtener el Registro y luego leer el archivo Ciudades.




#endif // FUNCIONES_H_INCLUDED
