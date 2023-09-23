#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// Colocar las Librer�as que se utilizar�n

#include <cstdio>
#include <string.h>

#include "Structs.h" // Librer�a con los Structs y constantes de los Archivos

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
void mostrarCiudadesxPais();                  // Leo el archivo Ciudades. Dentro de la funci�n se debe pedir al Usuario que ingrese el nombre del Pais.
struct Pais obtenerRegistroPais(char *pais);  // Recibe el nombre del Pais y busca su registro.
                                              // Revisar la opci�n de pedir primero el ingreso para obtener el Registro y luego leer el archivo Ciudades.
void mostrarCiudadesxPaisYCapital(char *codigo,int idCapital);

// 5) --------------------------------------------------------------
void listarPaises_Superficies();    // Leer y guardar los Registros en un Vector.
                                    // Calcular el Total de Superficie Mundial.
                                    // Mostrar dentro de la funci�n misma, NOMBRE - SUPERFICIE - PORCENTAJE %

// 6) --------------------------------------------------------------
void totalesxContinente();          // Leo el archivo Paises. Dentro de la funci�n se debe pedir al Usuario que ingrese el nombre del Pais.
                                    // Guardo en un vector los registros.
                                    // Calculo los totales y promedios. Muestro.
int menuContinentes();              // Agrego un menu para facilitar la eleccion del continente
// 7) --------------------------------------------------------------
void modificarPais();               // Pido el codigo de pais a modificar.
                                    // Verificar que exista.
                                    // Buscar registro (usar funci�n respectiva).
                                    // Ingresar los nuevos valores y reemplazar.
void grabarModificado(Pais reg);    // Guardar Pais Modificado.
Pais buscarXCodigo(char *codigo);

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
        /// COLOCAR AQU� LOS PROTOTIPOS DE LAS FUNCIONES


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

// Leo el archivo Ciudades. Dentro de la funci�n se debe pedir al Usuario que ingrese el nombre del Pais.
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
// Mostrar dentro de la funci�n misma, NOMBRE - SUPERFICIE - PORCENTAJE %

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
// Leo el archivo Paises. Dentro de la funci�n se debe pedir al Usuario que ingrese el nombre del Pais.
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

// 7) --------------------------------------------------------------
// Pido el codigo de pais a modificar.
// Verificar que exista.
// Buscar registro (usar funci�n respectiva).
// Ingresar los nuevos valores y reemplazar.
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
// Guardar Pais Modificado.
void grabarModificado(Pais reg){
    // Encontrar registro
    int nroRegistro=0;
    int pos=-1;
    FILE *archivo;
    int res=-1;
    Pais pais;
    archivo = fopen(ARCHIVO_PAISES,"rb+");
    // Leer archivo
    while(fread(&pais,sizeof(Pais),1,archivo)==1){
        if(strcmp(reg._codigo,pais._codigo)==0){
            cin.ignore();
            pos=nroRegistro;
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

// Buscar pais x Codigo
struct Pais buscarXCodigo(char *codigo){
    FILE *archivo;
    Pais pais;
    Pais paisX;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    // Leer archivo
    cout<<" "<<endl;
    while(fread(&pais,sizeof(Pais),1,archivo)==1){
        if(strcmp(codigo,pais._codigo)==0){
            paisX=pais;
        }
    }
    fclose(archivo);
    return paisX;
}

// 9) --------------------------------------------------------------
void totalesPais_Poblacion(){
    FILE *archivo;
    Pais pais;
    long poblacionMundial=0;
    int cant=0;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    // Leer archivo
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
void buscarMayorPoblacion(){
    FILE *archivo;
    Ciudad ciudad;
    Ciudad superCiudad;
    long mayorPoblacion=0;
    int idCiudad;
    // Abrir archivo
    archivo = fopen(ARCHIVO_CIUDADES,"rb");
    // Leer archivo
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
    int cant=0; // Cantidad de Registros del archivo
    //Abrir Archivo
    FILE *archivo;
    archivo = fopen(ARCHIVO_PAISES,"rb");
    // Obteniendo cantidad de registros del archivo
    fseek (archivo, 0, SEEK_END);
    cant = (ftell(archivo))/sizeof(Pais);
    fseek (archivo, 0,0);
    // Cerrar Archivo
    fclose(archivo);
    return cant;
};

// Contar Registros Archivo Ciudades
int contarCiudades(){
    int cant=0; // Cantidad de Registros del archivo
    //Abrir Archivo
    FILE *archivo;
    archivo = fopen(ARCHIVO_CIUDADES,"rb");
    // Obteniendo cantidad de registros del archivo
    fseek (archivo, 0, SEEK_END);
    cant = (ftell(archivo))/sizeof(Ciudad);
    fseek (archivo, 0,0);
    // Cerrar Archivo
    fclose(archivo);
    return cant;
};


#endif // FUNCIONES_H_INCLUDED
