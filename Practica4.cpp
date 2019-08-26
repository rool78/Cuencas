  /*****************************************
  * NOMBRE: #Raul#
  * PRIMER APELLIDO: #Maza#
  * SEGUNDO APELLIDO: ##
  * DNI: ##
  * EMAIL: #raul.mazaa@gmail.com#
  *****************************************/
/*Practica 4*/
/*Por: Raul Maza*/
/*Programa gestion reservas de agua de una region*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TipoAlta.h"
#include "TipoCalendario.h"

int main(){

TipoAltaCuenca Gestion_reservas;
char letra;

Gestion_reservas.Inicializar();

//prueba.InicializaTest();

/*Menu hecho con switch para elegir la letra*/
do{

    fflush( stdin );                  //Limpiamos buffer para leer correctamente el caracter
    Gestion_reservas.MenuPrincipal();
    scanf("%c",&letra);

    switch (letra){

      case 'A':
        Gestion_reservas.MenuAlta();
        break;
      case 'N':
        Gestion_reservas.NuevaMedida();
        break;
      case 'R':
        Gestion_reservas.Registros();
        break;
        case 't':
        Gestion_reservas.Test();
        break;
      case 'V':
        Gestion_reservas.VariacionesMensuales();
        break;
      default:
      system("cls");
    }

}while (letra != 'S');

    return 0;

}
