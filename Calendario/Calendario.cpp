  /*****************************************
  * NOMBRE: #Raul#
  * PRIMER APELLIDO: #Maza#
  * SEGUNDO APELLIDO: #Samperiz#
  * DNI: #73213082-B#
  * EMAIL: #raul.mazaa@gmail.com#
  *****************************************/

#include <stdio.h>
#include "TipoCalendario.h"

int main(){

TipoCalendario calendario1;
int mes, anio;

printf("Mes (1..12)?");
scanf("%d",&mes);
printf("Anio (1601..3000)?");
scanf("%d",&anio);

calendario1.ImprimeCalendario(mes,anio);

 return 0;
}
