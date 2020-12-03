#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//---------------------------- PROTOTIPOS -------------------------------
//    

void  Menu_Usuario();
void  Menu_Estudiantes ();
void  Registro_Carreras ();
void  imprimir_Carreras();
void  Registro_Materias ();
void  imprimir_Materias();                                 
void  Registro_Estudiantes ();
void  Imprimir_Estudiantes();
void  Informacion_academica_estudiante();
void  Tabulado_Estudiantes();

//------------------------------------------------------------------------


//definicion de variables Globales ----------------------------------------
char Materias_globales [20][70];
int contador_carrera = 0 ;
char Carreras [5][70];
int contador_materia = 0 ;
int  contador_estudiantes = 0 ; //para controlar la estructura
int  contador_para_semestres = 0 ; //para controlar la estructura
char nada[70]; // se usara para limpiar el gets
//-------------------------------------------------------------------------


// definicion de estructuras -----------
struct Estudiante {
    
    int Id;
    char Nombre    [20]  ;
    char Apellido  [20]  ;
    char Telefono  [20]  ;
    char Correo    [20]  ;
    char Codigo    [5]   ;
    char Carrera   [5]   ;
    
};

struct Semestres
{
    int  id_estudiante;//codigo del estudiante
    int  Semestre ;
    char Materia [6][70]; //maximo 7 materias por semestre
    char  Definitiva [6][2];  // definitiva entre enteros del 1 al 5 para cada materia.

};
//--------------------------------------


// arrays de estructuras ----------------
struct Estudiante datos [50] ;
struct Semestres  sem [100] ;
//---------------------------------------
 
int main(int argc, char const *argv[])
{
    
    printf("\n------------- BIENVENIDO AL SISTEMA DE REGISTRO ---------------\n");
    Menu_Usuario();
    }





void Menu_Usuario() {

    system("cls");//borrar pantalla

    char ingreso_pantalla;
    printf("\n------------- MENU Principal ---------------\n");
    printf("\nAcontinuacion escriba el numero de la accion que desea ejecutar \n");
    printf("\n1- Registrar Carreras\n");
    printf("\n2- Ver Carreras registradas\n");
    printf("\n3- Registrar Materias\n");
    printf("\n4- Ver Materias registradas\n"); 
    printf("\n5- Menu de Estudiantes\n"); 

   

    printf("\nIngrese el numero --> ");   

    ingreso_pantalla = getchar();
    
    switch (ingreso_pantalla){

        case '1' : Registro_Carreras(); 
            break;
        case '2' : imprimir_Carreras();
            break;
        case '3' : Registro_Materias(); 
            break;
        case '4' : imprimir_Materias();
            break;
        case '5' : Menu_Estudiantes(); 
            break;
        default: printf("Nuero Erroneo");
                 Menu_Usuario();      
        }      

}

void Menu_Estudiantes (){


    char ingreso_pantalla;

    system("cls");//borrar pantalla

    printf("\n------------- MENU DE ESTUDIANTES ---------------\n");

    printf("\n1- Registras Estudiantes\n"); 
    printf("\n2- Ver Estudiantes Registrados\n"); 
    printf("\n3- Registro de Semestre, Materias y Notas\n"); 
    printf("\n4- Tabulado del Estudiante \n"); 
    printf("\n5- Menu Principal" ) ;

    printf("\n\nIngrese el numero --> ");   

    ingreso_pantalla = getchar();
    
    switch (ingreso_pantalla){

        case '1':  Registro_Estudiantes ();      
            break;
        case '2':  Imprimir_Estudiantes ();      
            break;
        case '3' : Informacion_academica_estudiante();
            break;
        case '4' : Tabulado_Estudiantes() ;
            break;
        case '5' : Menu_Usuario(); 
            break;        
        default: printf("Nuero Erroneo") ;
                 Menu_Estudiantes ();   
    }
}

void Registro_Carreras (){

    system("cls");//borrar pantalla

 // declaracion de variables locales
    char nombre_carrera [70];
    
    char terminar [70]= "terminar" ;
    bool salir = true ;
    gets(nada);
    
    
    printf("\n-----------------REGISTRO DE CARRERAS--------------------");
    printf("\nPara terminar el proceso, escriba el comando ''terminar'' \n.");


    // do while para capturas las carreras 
    do
    {   
        //mensaje que se muestra por pantalla
       printf("\nIngrese el nombre de la nueva Carrera %d :" ,contador_carrera+1, " :");
        //Capturamos la Cadena que ingresa el usuario
       gets(nombre_carrera);
       
        // condicion para que no se guarde ''terminar'' en la matriz
        //salir del bucle cuando escriban ''terminar'' o registren 5 Carreras
       if (strcmp(nombre_carrera, terminar) != 0 and (contador_carrera != 5) )
       {
            //Almacenamos en orden la cadena en la Matriz de Materias
            strcpy (Carreras[contador_carrera], nombre_carrera ) ; 

            contador_carrera = contador_carrera + 1 ;
       }           
       else {salir = false ; }

    } while (salir);        
    
    //regresar de nuevo al MENU
    Menu_Usuario();
}

void imprimir_Carreras(){
    
    system("cls");//borrar pantalla

    int Longitud_arreglo = sizeof(Carreras) / sizeof(Carreras[0]); 
    char No_Imprimir [70]= "" ;

    printf("\n-------------- CARRERAS -------------- \n");   
    printf("\nMaterias Registradas : \n");

    for(int x = 0; x < Longitud_arreglo; x++){

        //condicion para que no imprima los vacios
        if ( strcmp(Carreras[x], No_Imprimir) != 0)
        {
        printf(" %d - %s\n", (x+1), Carreras[x]);
        }

    }

     //regresar de nuevo al MENU
    gets(nada);

    printf("oprima cualquier tecla para continuar");
    gets(nada);
    Menu_Usuario();
    
}

void Registro_Materias (){

    system("cls");//borrar pantalla

    printf("\n-----------------REGISTRO DE MATERIAS--------------------");
    printf("\nPara terminar el proceso, escriba el comando ''terminar'' \n.");

    // declaracion de variables locales
    char nombre_materia [70];
    
    char terminar [70]= "terminar" ;
    bool salir = true ;
    gets(nada);
    
    // do while para capturas las materias 
    do
    {   
        //mensaje que se muestra por pantalla
       printf("\nIngrese el nombre de la nueva materia %d :" ,contador_materia+1, " :");
        //Capturamos la Cadena que ingresa el usuario
       gets(nombre_materia);
       
        // condicion para que no se guarde ''terminar'' en la matriz
        //salir del bucle cuando escriban ''terminar'' o registren 20 materias
       if (strcmp(nombre_materia, terminar) != 0 and (contador_materia != 20) )
       {
            //Almacenamos en orden la cadena en la Matriz de Materias
            strcpy (Materias_globales[contador_materia], nombre_materia ) ; 

            contador_materia = contador_materia + 1 ;
       }           
       else {salir = false ; }

    } while (salir);        
    
    //regresar de nuevo al MENU
    Menu_Usuario();
}

void imprimir_Materias(){

    system("cls");//borrar pantalla
        
    int Longitud_arreglo = sizeof(Materias_globales) / sizeof(Materias_globales[0]); 
    char No_Imprimir [70]= "" ;

    printf("\n------------------------------------- \n");   
    printf("\nMaterias Registradas : \n");

    for(int x = 0; x < Longitud_arreglo; x++){

        //condicion para que no imprima los vacios
        if ( strcmp(Materias_globales[x], No_Imprimir) != 0)
        {
        printf(" %d - %s\n", (x+1), Materias_globales[x]);
        }

    }

     //regresar de nuevo al MENU
    gets(nada);

    printf("\n Oprima cualquier tecla para continuar");
    gets(nada);
    Menu_Usuario();
    
}

void Registro_Estudiantes (){

    system("cls");//borrar pantalla

    // declaracion de variables locales
    
    char terminar [3];
    char si [3] = "si" ;  
    bool salir = true ;
    bool existe = false ;
    gets(si);
        
    // do while para capturas los Estudiantes 
    do
    {   
        datos[contador_estudiantes].Id=contador_estudiantes;
        printf("\n ------------------------------------------" );
        printf("\nNombre --> " );
        gets(datos[contador_estudiantes].Nombre);
        printf("\nApellido --> " );
        gets(datos[contador_estudiantes].Apellido);
        printf("\nTelefono --> " );
        gets(datos[contador_estudiantes].Telefono);
        printf("\nCorreo Electronico --> " );
        gets(datos[contador_estudiantes].Correo);
        printf("\nCodigo Estudiante --> " );
        gets(datos[contador_estudiantes].Codigo);
        
        // do while para comprobar que la carrera exista 
        do
        {
            
            printf("\nCarrera (que exista)--> " );
            //obtenermos la carrera ingresada por pantalla
            gets(datos[contador_estudiantes].Carrera);
            // recorremos las carreras que estan registradas
            for (size_t i = 0; i < 5; i++)
            {
                //compraramos si la carrera coincide                 
                if ( strcmp(datos[contador_estudiantes].Carrera , Carreras[i] ) == 0)
                {
                    existe = true;
                    break;
                }   
            }            
           
        } while (not(existe));
        
       
        contador_estudiantes = contador_estudiantes + 1 ;

        printf("\n\n Desea Continuar Registrando? (si / no o otra tecla) --> " );
        gets(terminar) ;

        if (strcmp(terminar, si ) != 0 or contador_estudiantes != 50 )
        {
            salir = false;
        }
              

    } while (salir);    

    //regresar de nuevo al MENU
    Menu_Estudiantes();

}

void Imprimir_Estudiantes(){

    system("cls");//borrar pantalla
    printf("\n---------------ESTUDIANTES---------------------\n")  ;
    for(int i=0; i<contador_estudiantes; i++)
     {
        printf ("%d", (i+1) );
        printf("\nNombre --> %s " ,            datos[i].Nombre)  ;
        printf("\nApellido --> %s " ,            datos[i].Apellido);
        printf("\nTelefono --> %s " ,            datos[i].Telefono);
        printf("\nCorreo Electronico --> %s ",   datos[i].Correo)  ;
        printf("\nCodigo Estudiante --> %s " ,   datos[i].Codigo)  ;
        printf("\nCodigo Carrera --> %s " ,      datos[i].Carrera) ;
        printf("\n __________________\n");
        
     }

    //regresar de nuevo al MENU
    gets(nada);

    printf("\n\nOprima cualquier tecla para continuar");
    gets(nada);

    Menu_Estudiantes();

}

void Informacion_academica_estudiante(){

system("cls");//borrar pantalla

char ingreso_id [5] ;
int  Id_estudiante  ;
int  semestre_ingresado ;
bool existe = false; 

gets(nada);

        // do while para comprobar que el estudiante exista
        do
        {
            
            printf("\nIngrese el Codigo del Estudiante -->");
            //obtenermos el codigo del estudiante
            gets(ingreso_id);

            // recorremos los estudiantes que estan registrados
            for (size_t i = 0; i < contador_estudiantes; i++)
            {
                //compraramos si el codigo del estudiante coincide con alguno                 
                if ( strcmp(datos[i].Codigo , ingreso_id ) == 0)
                {
                    existe = true;
                    //mostramo los datos de ese estudiante
                    printf("\n--------------- DATOS ESTUDIANTE---------------------")  ;
                    printf("\nNombre Completo: %s " ,      datos[i].Nombre,", ")  ;
                    printf("%s" ,                          datos[i].Apellido);
                    printf("\nTelefono: %s " ,             datos[i].Telefono);
                    printf("\nCorreo Electronico: %s ",    datos[i].Correo)  ;
                    printf("\nCodigo Estudiante:  %s " ,   datos[i].Codigo)  ;
                    printf("\nCarrera: %s " ,       datos[i].Carrera) ; 

                    Id_estudiante = i ; //almacenamos el id del estudiante para poder operar con el
                    break;
                }   
            }            
           
        } while (not(existe));

        
    char terminar [70]= "terminar" ;
    bool salir = true ;
    char materia [70];
    int contador_materias = 0;
    existe = false ;

        printf("\n\n  Ingrese el numero del semestre 1 a 10:");
        //Capturamos la Cadena que ingresa el usuario
        scanf("%d",semestre_ingresado);
       
    //printf("\n    Semestre numero -> %d",semestre_ingresado);
    gets(nada);

    sem[contador_para_semestres].id_estudiante = Id_estudiante ; //guardamos id estudiante
    sem[contador_para_semestres].Semestre = semestre_ingresado ; //guardamos el semestre

    // do while para comprobar que la materia exista y guardalas con su definitiva
    printf("\n  Escriba ''terminar'' para no registras mas materias");
    do
    {            
            printf("\n\n         Materia (que exista)--> " );
            //obtenermos la materia ingresada por pantalla
            gets(materia);

            // recorremos las materias que estan registradas
            for (size_t i = 0; i < 20; i++)
            {
                //compraramos si las materias coinciden             
                if ( strcmp( materia , Materias_globales[i] ) == 0  )
                {
                        
                        strcpy ( sem[contador_para_semestres].Materia[contador_materias], materia ) ; 
                        
                        printf("\n Definitiva de la materia, entre 1 y 5->") ;
                        gets(sem[contador_para_semestres].Definitiva[contador_materias]);                     
                        
                        contador_materias = contador_materias + 1 ;
                }  
                
            }
            

        } while ( strcmp(materia, terminar) != 0 and contador_materias < 7  ); 
    
    contador_para_semestres = contador_para_semestres + 1 ;

    Menu_Estudiantes();      

}

void Tabulado_Estudiantes(){

system("cls");//borrar pantalla

char ingreso_id [5] ;
int  Id_estudiante  ;
int  semestre_ingresado ;
bool existe = false; 

gets(nada);

        // do while para comprobar que el estudiante exista
do
{
            
            printf("\nIngrese el Codigo del Estudiante -->");
            //obtenermos el codigo del estudiante
            gets(ingreso_id);

            // recorremos los estudiantes que estan registrados
            for (size_t i = 0; i < contador_estudiantes; i++)
            {
                //compraramos si el codigo del estudiante coincide con alguno                 
                if ( strcmp(datos[i].Codigo , ingreso_id ) == 0)
                {
                    existe = true;
                    //mostramo los datos de ese estudiante
                    printf("\n--------------- DATOS ESTUDIANTE---------------------")  ;
                    printf("\nNombre Completo: %s " ,      datos[i].Nombre,", ")  ;
                    printf("%s" ,                          datos[i].Apellido);
                    printf("\nTelefono: %s " ,             datos[i].Telefono);
                    printf("\nCorreo Electronico: %s ",    datos[i].Correo)  ;
                    printf("\nCodigo Estudiante:  %s " ,   datos[i].Codigo)  ;
                    printf("\nCarrera: %s " ,       datos[i].Carrera) ; 

                    Id_estudiante = i ; //almacenamos el id del estudiante para poder operar con el
                    break;
                }   
            }            
           
        } while (not(existe));

        
char terminar [70]= "terminar" ;
bool salir = true ;
char materia [70];
int contador_materias = 0;
int id_semestre;
existe = false ;

printf ("\n\n----- TABULADO ----------\n\n") ;

printf ("\n----- materias -> definitivas ----------\n") ;

    // buscamos la estructura del estudiante 
for (size_t i = 0; i < contador_para_semestres; i++)
    {
        if ((Id_estudiante == sem[i].id_estudiante  ))
        {
            id_semestre = i ;

            printf("\n  comienza semestre ");
            for (size_t j = 0; j < 6; j++)
            {
                printf(sem[i].Materia[j]);
                printf(" -> ");
                printf(sem[i].Definitiva[j]);
                 printf("\n");
            }

            printf("\n  termina semestre ");

        }
        else
        {
            printf("NO EXISTEN  DATOS ");                                  
        }               
    }

    printf("\n\nOprima cualquier tecla para continuar");
    gets(nada);

    Menu_Estudiantes();
    
}
