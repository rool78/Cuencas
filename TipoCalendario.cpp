#include <stdio.h>
#include "TipoCalendario.h"
#include "TipoAlta.h"
/*Funcion para saber si el año es bisiesto o no
un año es bisiesto si es multiplo de 4 a excepcion
de los que son multiplos de 100 y a su vez NO lo son
de 400.
-Ejemplos bisiestros 1604,1992,2000 o 2000
-Ejemplos no bisiestos 1900 2100 o 2900*/
bool TipoCalendario::AnioBisiesto(int anio){

  int mul_4 = 0;
  int mul_100 = 0;
  int mul_400 = 0;

  mul_4 = anio % 4;
  mul_100 = anio % 100;
  mul_400 = anio % 400;

  if(mul_4 == 0){
   if((mul_100 == 0) && (mul_400 != 0)){
    return false;
   }else{
    return true;
   }
  }
  return false;
}
/*Funcion para escribir el mes*/
void TipoCalendario::EscribirMes(int mes){

 switch(mes){
  case 1:printf("ENERO                  ");//23, Pongo los espacios para que cuadre con el año
  break;
  case 2:printf("FEBRERO                ");
  break;
  case 3:printf("MARZO                  ");
  break;
  case 4:printf("ABRIL                  ");
  break;
  case 5:printf("MAYO                   ");
  break;
  case 6:printf("JUNIO                  ");
  break;
  case 7:printf("JULIO                  ");
  break;
  case 8:printf("AGOSTO                 ");
  break;
  case 9:printf("SEPTIEMBRE             ");
  break;
  case 10:printf("OCTUBRE                ");
  break;
  case 11:printf("NOVIEMBRE              ");
  break;
  case 12:printf("DICIEMBRE              ");
  break;
 }

}
/*Funcion para saber el inicio del dia del año
de momento en enero de un cierto año, sin entrar en los meses*/
int TipoCalendario::InicioDia(int anio,int mes){

const TipoVector vector_meses={31,28,31,30,31,30,31,31,30,31,30,31}; //Hay que tener cuidado con el vector[12]
const TipoVector vector_meses_bisiesto={31,29,31,30,31,30,31,31,30,31,30,31};

  const int dias_normal = 365;
  const int dias_bisiesto = 366;
  const int anio_inicial = 1601;
  bool hay_bisiesto = false;   //booleana para que realize la suma de los bisiestos o no, si hay
  int dias_total = 0;         //Dias totales para sacar el calculo
  int dias_total_bisiestos = 0;
  int dias_total_normales = 0;
  int anios_sin_bisiestos = 0;
  int anios_bisiestos = 0;     //Contadora años bisiestos.
  int dias_mismo_anio = 0; //Son los dias a contar del propio año (para saber en que dia empieza cuando nos dan el mes)
  int dia_inicio = 0; //Dia de inicio segun fecha

/*Queremos contar los dias del año insertado si estamos en un mes superior a enero*/

  if(mes > 1) {  //Contamos si el mes es mayor a enero solo
  for(int i = 0; i < mes-1; i++){
    if(AnioBisiesto(anio) == false){
    dias_mismo_anio = dias_mismo_anio + vector_meses[i];
    }else{
      dias_mismo_anio = dias_mismo_anio + vector_meses_bisiesto[i];
    }
   }
  }

  /*Contamos el numero de años bisiestos respecto al año introducido*/

  for(int i = 1601; i < anio; i++){

   if(AnioBisiesto(i) == true){ //si el año es bisiesto, sumamos 1 al contador
    anios_bisiestos++;
    hay_bisiesto = true;
   }
  }
  anios_sin_bisiestos = (anio - anio_inicial) - anios_bisiestos; //Diferencia de los años entre el inicio y el año introducido restando los años bisiestos
  if(hay_bisiesto == true){ //Solo se hace la operacion si hay bisiesto
    dias_total_bisiestos = dias_bisiesto * anios_bisiestos; //Total dias bisiestos
  }
  dias_total_normales = anios_sin_bisiestos * dias_normal;
  dias_total = dias_total_bisiestos + dias_total_normales + dias_mismo_anio;
  dias_total++; //Hay que sumar 1 diaa el total, pues el dia empezara al dia siguiente
  dia_inicio = dias_total%7;
  if(dia_inicio == 0){ //Convierto a dia 7 si el modulo es 0, para que quede mas claro que el dia 7 es domingo
   dia_inicio = 7;
  }
  return dia_inicio;
}
/*Funcion para dibujar el calendario*/
void TipoCalendario::ImprimeCalendario(int mes, int anio, TipoCadenasVar var, TipoCadena cuenca, TipoCadena presa){

TipoAltaCuenca program;
const TipoVector vector_meses={31,28,31,30,31,30,31,31,30,31,30,31}; //Hay que tener cuidado con el vector[12]
const TipoVector vector_meses_bisiesto={31,29,31,30,31,30,31,31,30,31,30,31};
 int dias_mes = 0;
 bool imprime_normal = false;
 int contador_linea = 0;
 int dia_inicio = 0;
 int contador_dias = 0;
 int contador_posicion = 0; //Se trata de un contador que arrastremos por todo el calendario para saber en que dia estamos
 bool error = false; //Variable error en introduccion de dato usuario
 bool fin = false; //Variable fin de while

 dia_inicio = InicioDia(anio,mes); //Econtramos el dia inicio

/*El mes tiene que estar comprendido entre 1 y 12 y el año entre 1601 y 3000*/
 if((mes > 12)||(mes < 1)||(anio > 3000)||(anio < 1601)){
  error = true;
 }

while((!error) && (!fin)){

 printf("\n");
 printf(" %cVariacion Agua Embalsada",'%');
 printf("\nCuenca:%-8s Presa:%s\n",cuenca,presa);

 EscribirMes(mes);
 printf("%d\n",anio);
 printf("===========================\n");
 printf("LU  MA  MI  JU  VI | SA  DO\n");
 printf("===========================\n");

/*Imprimimos primera fila*/

for(int i=1;i < dia_inicio;i++){
 contador_posicion++;

/*Imprimo los puntos iniciales hasta que comienza el primer dia de la semana*/

if ((contador_posicion % 7) == 5){  //Uso el modulo para imprimir la | en el caso de que sea viernes

   printf(" . | ");
  }else{
    printf(" .  ");
  }
}
/*Imprime numeros primera fila*/

for(int i=dia_inicio;i <=7;i++){
  contador_dias++;
  contador_posicion++;

if ((contador_posicion % 7) == 5){

   printf("%s | ",var[contador_dias]);
  }else{
    printf("%s  ",var[contador_dias]);
  }
}
printf("\n");


/*Calculo numero dias mes sefun si es bisiesto o no*/

if(!AnioBisiesto(anio)){                            //Utilizamos la funcion año bisiesto para guardarla en mi variable dias_mes
    dias_mes = dias_mes + vector_meses[mes-1];
    }else{
      dias_mes = dias_mes + vector_meses_bisiesto[mes-1];
    }

/*Imprimo el resto de dias del calendario*/

while(contador_dias < dias_mes){

contador_dias++;
contador_posicion++;

if ((contador_posicion % 7) == 5){

 printf("%s | ",var[contador_dias]);
}else{
  printf("%s  ",var[contador_dias]);
}
    contador_linea++;
    if(contador_linea == 7){  //Salto de linea
     printf("\n");
     contador_linea = 0;
    }
 }

/*Imprimo los puntos finales para rellenar el calendario*/

 if((contador_posicion %7) != 0){

while((contador_posicion %7) != 0){

 contador_posicion++;

if ((contador_posicion % 7) == 5){

     printf(" . | ");
    }else{
      printf(" .  ");
    }
   }
  }

fin = true;

 }
}
