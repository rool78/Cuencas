#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TipoAlta.h"
#include "TipoCalendario.h"

/*Procedimiento para dibujar el menu principal*/
void TipoAltaCuenca::MenuPrincipal(){

    printf("\nGestion reserva de agua\n");
    printf("     Alta cuenca/presa        (Pulsar A) \n");
    printf("     Nueva medicion           (Pulsar N) \n");
    printf("     Registros                (Pulsar R) \n");
    printf("     Variaciones mensuales    (Pulsar V) \n");
    printf("     Salir                    (Pulsar S) \n");
    printf("Teclear una opcion valida (A|N|R|V|S)?");
}
/*Funcion que comprueba que las fechas de mediciones sean correctas*/
bool TipoAltaCuenca::ComprobarFecha(int dia, int mes, int anio){

const TipoVector vector_meses={31,28,31,30,31,30,31,31,30,31,30,31};
const TipoVector vector_meses_bisiesto={31,29,31,30,31,30,31,31,30,31,30,31};

TipoCalendario calendario;    //Creo calendario para poder usar la funcion AnioBisiesto que esta en el TAD TipoCalendario

if ((anio < 1601) || (anio > 3000)) {   //Compruebo año dentro del rango admitido
  //printf("Fecha incorrecta");
  return false;
}
if ((mes < 1) || (mes > 12)) {   //Compruebo mes dentro del rango admitido
  //printf("Fecha incorrecta");
  return false;
}
/*Compruebo si el dia es correcto en año no bisiesto*/
if (!calendario.AnioBisiesto(anio)){

if ((dia < 1) || (dia > vector_meses[mes-1] )){
 //printf("Fecha incorrecta");
  return false;
}else{
  //printf("Fecha CORRECTA");
  return true;
}
}
/*Compruebo si el dia es correcto en año bisiesto*/
if (calendario.AnioBisiesto(anio)){

if ((dia < 1) || (dia> vector_meses_bisiesto[mes-1] )){
  //printf("Fecha incorrecta");
  return false;
}else{
  //printf("Fecha CORRECTA");
  return true;
  }
 }
}
/*Funcion para comprobar si la fecha es posterior o no*/
bool TipoAltaCuenca::FechaPosterior(int dia, int mes, int anio,int dia_usuario, int mes_usuario, int anio_usuario){

   if (anio_usuario < anio ){
     return false;
   }

   if (anio_usuario > anio){
    return true;
   }

   if ((anio_usuario == anio) && (mes_usuario < mes)) {
    return false;
   }

   if ((anio_usuario == anio) && (mes_usuario > mes)) {
    return true;
   }

   if ((anio_usuario == anio) && (mes_usuario == mes) && (dia_usuario <= dia)){
    return false;
   }

   if ((anio_usuario == anio) && (mes_usuario == mes) && (dia_usuario > dia)){
    return true;
   }

}
/*Procedimiento inicializacion*/
void TipoAltaCuenca::Inicializar(){

 contador_cuencas = 0;                            //Inicializa el numero de cuencas a 0
 capacidad_region = 0;
 volumen_actual_region = 0;
/*Inicializo todas la cuencas , numero de presas a 0*/
 for(int i = 0; i < 3; i++){

   cuencas[i].numero_presa = 0;                   //Inicializa la cantidad de presas por cuenca a 0
   cuencas[i].volumen_actual_cuenca = 0;
   cuencas[i].capacidad_cuenca = 0;
 }
 /*Inicializo los contadores de las medidas y la capacidad a 0*/
 for(int i = 0; i < 3; i++){

    for (int j = 0; j < 5; j++){
    cuencas[i].presas[j].volumen_actual_presa = 0;
    cuencas[i].presas[j].contador_medidas = 0;    //Inicializa el contador de medidas de cada presa a 0
    cuencas[i].presas[j].capacidad = 0;           //Inicializa la capacidad de las presas a 0
    cuencas[i].presas[j].primera_medida = true;   //Inicializa la primera medida a true
    cuencas[i].presas[j].ultima_medida = false;   //Ultima medida a false

    for (int k = 0; k < 100; k++){
       cuencas[i].presas[j].medidas[k].volumen = 0; //Inicializa las medidas a 0
       cuencas[i].presas[j].medidas[k].hay_medida = false;
     }
    }
   }
  }
/*Procedimiento inicializacion variable para TEST*/
void TipoAltaCuenca::InicializaTest(){

 contador_cuencas = 2;
 cuencas[0].numero_presa = 2;

 strcpy(cuencas[0].cuenca,"C1");

 strcpy(cuencas[0].presas[0].presa,"P1");

 strcpy(cuencas[0].presas[1].presa,"P1a");

 cuencas[0].presas[0].capacidad = 5000;
 cuencas[0].presas[1].capacidad = 10000;

 cuencas[1].numero_presa = 1;

 strcpy(cuencas[1].cuenca,"C2");
 strcpy(cuencas[1].presas[0].presa,"P2");

 cuencas[1].presas[0].capacidad = 10000;

cuencas[1].presas[0].contador_medidas = 6;

cuencas[1].presas[0].medidas[0].volumen = 350;
cuencas[1].presas[0].medidas[0].dia = 5;
cuencas[1].presas[0].medidas[0].mes = 5;
cuencas[1].presas[0].medidas[0].anio = 1900;
cuencas[1].presas[0].medidas[0].hay_medida = true;

cuencas[1].presas[0].medidas[1].volumen = 400;
cuencas[1].presas[0].medidas[1].dia = 1;
cuencas[1].presas[0].medidas[1].mes = 7;
cuencas[1].presas[0].medidas[1].anio = 1900;
cuencas[1].presas[0].medidas[1].hay_medida = true;

cuencas[1].presas[0].medidas[2].volumen = 250;
cuencas[1].presas[0].medidas[2].dia = 1;
cuencas[1].presas[0].medidas[2].mes = 1;
cuencas[1].presas[0].medidas[2].anio = 1901;
cuencas[1].presas[0].medidas[2].hay_medida = true;

cuencas[1].presas[0].medidas[3].volumen = 0;
cuencas[1].presas[0].medidas[3].dia = 16;
cuencas[1].presas[0].medidas[3].mes = 1;
cuencas[1].presas[0].medidas[3].anio = 1901;
cuencas[1].presas[0].medidas[3].hay_medida = true;

cuencas[1].presas[0].medidas[4].volumen = 200;
cuencas[1].presas[0].medidas[4].dia = 30;
cuencas[1].presas[0].medidas[4].mes = 1;
cuencas[1].presas[0].medidas[4].anio = 1901;
cuencas[1].presas[0].medidas[4].hay_medida = true;

cuencas[1].presas[0].medidas[5].volumen = -333;
cuencas[1].presas[0].medidas[5].dia = 31;
cuencas[1].presas[0].medidas[5].mes = 1;
cuencas[1].presas[0].medidas[5].anio = 1901;
cuencas[1].presas[0].medidas[5].hay_medida = true;






}
/*Procedimiento registro cuencas presas y capacidad funcionando la estructura*/
void TipoAltaCuenca::MenuAlta(){

    TipoCadena cuenca_usuario, presa_usuario;   //Cadenas de las variables introducidas por el usuario
    bool coincidencia_cuenca = false;
    bool coincidencia_presa = false;

    //system("cls");
    printf("\nAlta cuenca/presa:\n");
/*/////////////////////////ALTA DE LA CUENCA///////////////////////*/
    printf("Dime el nombre de la cuenca: ");
    scanf("%s",&cuenca_usuario);               //Pido la cuenca al usuario y lo guardo en una variable usuario

/*Recorro el buble en busca de una coincidencia en el nombre de la cuenca*/
    for (int i = 0; i < 3; i++){

        if (strcmp(cuenca_usuario,cuencas[i].cuenca) == 0){  //Si hay coincidencia pongo el valor coincidencia a true
          coincidencia_cuenca = true;
     }
    }
/*Si no hay coincidencia guardo el nombre de usuario en la variable cuencas segun contador*/
    if ((!coincidencia_cuenca) && (contador_cuencas < 3)){

      strcpy( cuencas[contador_cuencas].cuenca, cuenca_usuario );
      coincidencia_cuenca = false;
      contador_cuencas++;
    }

/*/////////////////////////ALTA DE LA PRESA///////////////////////*/
    printf("Dime el nombre de la presa: ");
    scanf("%s",&presa_usuario);

  /*Buscamos que la cuenca exista y cuando la encontramos, comprobamos si ya habia presa, si no habia la guardamos*/
   for (int i = 0; i < 3; i++){ //Busqueda cuenca

        if (strcmp(cuenca_usuario,cuencas[i].cuenca) == 0){  //Si encuentro una cuenca, entonces busco las presas
        coincidencia_cuenca = true;
              /*++++Buscamos presa+++++*/
              for(int j = 0; j < 5; j++){

                if (strcmp(presa_usuario,cuencas[i].presas[j].presa) == 0){
                  coincidencia_presa = true;
                }
               }
             /*Si no hay coincidencia en la presa y hay menos de 5 persas, copiamos la variable del usuario*/
           if ((!coincidencia_presa) && (cuencas[i].numero_presa < 5)){

            strcpy( cuencas[i].presas[cuencas[i].numero_presa].presa, presa_usuario );  //Copiamos el nombre del usuario en mi vector
            /*Aqui preguntamos la capacidad de la presa*/
            printf("Capacidad de la presa: ");
            scanf("%d",&cuencas[i].presas[cuencas[i].numero_presa].capacidad);
            /*Sumo la capacidad introducida a la capacidad de la cuenca*/
            cuencas[i].capacidad_cuenca = cuencas[i].capacidad_cuenca + cuencas[i].presas[cuencas[i].numero_presa].capacidad;

            capacidad_region = capacidad_region + cuencas[i].presas[cuencas[i].numero_presa].capacidad;

            coincidencia_presa = false;
            cuencas[i].numero_presa++;
           }
          }
          coincidencia_cuenca = false;
         }

/*AYUDA PARA MOSTRAR LOS DATOS QUE VOY INTRODUCIENDO*/
/*
for (int i = 0; i < 3; i++){

    printf("\n++++TU CUENCA++++ [%d] es: %s",i,cuencas[i].cuenca);

    for (int j = 0; j < 5; j++){

    printf("\nTu presa [%d] es: %s y tiene una capacidad de: %d",j,cuencas[i].presas[j].presa,cuencas[i].presas[j].capacidad);

  }
 }*/
}
/*Procedimiento para insertar nuevas medidas*/
void TipoAltaCuenca::NuevaMedida(){

TipoCadena presa_usuario;
int volumen,dia,mes,anio;                //Valores introducidos por el usuario
int contador = 0;
bool coincidencia_presa = false;
bool fecha_anterior = false;              //Booleana de fecha erronea

printf("\nNueva medicion:\n");
/*Perdimos el nombre de la presa al usuario*/
printf("\tDime el nombre de la presa: ");
scanf("%s",&presa_usuario);
/*Buscamos si la presa que introduce el usuario existe en nuestra base de datos*/
for (int i = 0; i < 3; i++){

      for (int j = 0; j < 5; j++){

            if (strcmp(presa_usuario,cuencas[i].presas[j].presa) == 0){
            coincidencia_presa = true;
   }
/*Si encuentra una presa pedimos los demas datos*/
   if (coincidencia_presa){
    printf("\tVolumen embalsado: ");
    scanf("%d",&volumen);
    printf("\tDia de lectura: ");
    scanf("%d",&dia);
    printf("\tMes de lectura: ");
    scanf("%d",&mes);
    printf("\tAnio de lectura: ");
    scanf("%d",&anio);
    coincidencia_presa = false;

    if(cuencas[i].presas[j].contador_medidas > 0){
     cuencas[i].presas[j].primera_medida = false;   //Ponemos a falso la variable que determina la primera medida
    }
/*(****PRIMER CASO****), si es la primera medida, la fecha es correcta y el volumen no excede a la capacidad*/
   //if ((cuencas[i].presas[j].primera_medida) && (ComprobarFecha(dia,mes,anio))  && (volumen < cuencas[i].presas[j].capacidad)){

   /*Modifique el condicional usando la funcion VolumenEmbalsadoPresa para que no pueda añadir una medida que haga sobrepasar la capacidad de la presa
queda un poco largo pero esta bien, arriba esta comentado el antiguo ,****CREO QUE EN ESTE CASO NO HARIA FALTA USAR LA FUNCIION VOLUMEN EMBALSADO*****/
      if ((cuencas[i].presas[j].primera_medida)&&(ComprobarFecha(dia,mes,anio))&&(((VolumenEmbalsadoPresa(i,j,cuencas[i].presas[j].contador_medidas)) + volumen ) <= cuencas[i].presas[j].capacidad)){
      /*Guardamos los datos introducidos por el usuario*/
      cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas].volumen = volumen;
      cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas].dia = dia;
      cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas].mes = mes;
      cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas].anio = anio;
      cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas].hay_medida = true;
      /*Sumamos el volumen a la presa, cuenca y region*/

      cuencas[i].presas[j].volumen_actual_presa = cuencas[i].presas[j].volumen_actual_presa + volumen;
      cuencas[i].volumen_actual_cuenca = cuencas[i].volumen_actual_cuenca + volumen;
      volumen_actual_region = volumen_actual_region + volumen;


      cuencas[i].presas[j].contador_medidas++;       //Avanzamos en el contador de medidas de esa cuenca -> presa
    }

/*(****SEGUNDO CASO****), comprobamos que la fecha introducida sea posterior a las fechas ya introducidas */
//if((!cuencas[i].presas[j].primera_medida)&&(ComprobarFecha(dia,mes,anio))&& (volumen < cuencas[i].presas[j].capacidad)){

/*Modifique el condicional usando la funcion VolumenEmbalsadoPresa para que no pueda añadir una medida que haga sobrepasar la capacidad de la presa
queda un poco largo pero esta bien, arriba esta comentado el antiguo*/
   if((!cuencas[i].presas[j].primera_medida)&&(ComprobarFecha(dia,mes,anio))&&(((VolumenEmbalsadoPresa(i,j,cuencas[i].presas[j].contador_medidas)) + volumen ) <= cuencas[i].presas[j].capacidad)){
  /*Comprobamos si la fecha introducida es posterior
  los argumentos de la funcion bool FechaPosterior son muy dificiles de ver pero tienen esta forma
  bool FechaPosterior(int dia_anterior, int mes_anterior, int anio_anterior,int dia_usuario, int mes_usuario, int anio_usuario); */

  if(FechaPosterior(cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas-1].dia,
  cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas-1].mes,
  cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas-1].anio,
  dia,
  mes,
  anio)){

      cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas].volumen = volumen;
      cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas].dia = dia;
      cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas].mes = mes;
      cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas].anio = anio;
      cuencas[i].presas[j].medidas[cuencas[i].presas[j].contador_medidas].hay_medida = true;


       /*Sumamos el volumen a la presa, cuenca y region*/

      cuencas[i].presas[j].volumen_actual_presa = cuencas[i].presas[j].volumen_actual_presa + volumen;
      cuencas[i].volumen_actual_cuenca = cuencas[i].volumen_actual_cuenca + volumen;
      volumen_actual_region = volumen_actual_region + volumen;

      cuencas[i].presas[j].contador_medidas++; //Sumamos un medida mas al contador

      }
     }
    }
   }
  }


 /*AYUDA PARA MOSTRAR LOS DATOS QUE VOY INTRODUCIENDO*/
/*for (int i = 0; i < 3; i++){

    printf("\n++++TU CUENCA++++ [%d] es: %s",i,cuencas[i].cuenca);

    for (int j = 0; j < 5; j++){

    printf("\nTu presa [%d] es: %s y tiene una capacidad de: %d",j,cuencas[i].presas[j].presa,cuencas[i].presas[j].capacidad);
    printf("\nTU PRESA [%d] TIENE UN VOLUMEN EMBALSADO ACUMULADO DE %d",j,VolumenEmbalsadoPresa(i,j,cuencas[i].presas[j].contador_medidas));
    for (int k = 0; k < cuencas[i].presas[j].contador_medidas; k++){
    printf("\nSu medida %d es de %d hm3  ",k,cuencas[i].presas[j].medidas[k].volumen);
    printf("\nIntroducida en fecha %d / %d / %d  ",cuencas[i].presas[j].medidas[k].dia,cuencas[i].presas[j].medidas[k].mes,cuencas[i].presas[j].medidas[k].anio);
   }
  }
 }*/
}
/*Me devuelve el volumen embalsado total de una presa*/
int TipoAltaCuenca::VolumenEmbalsadoPresa(int contador_cuenca, int contador_presa, int contador_medidas){

  int volumen_acumulado = 0;

      for (int k = 0; k <= contador_medidas; k ++){

      volumen_acumulado = volumen_acumulado + cuencas[contador_cuenca].presas[contador_presa].medidas[k].volumen;

      }

  return volumen_acumulado;
}
/*Le doy la posicion de la medida y me imprime el registro*/
void TipoAltaCuenca::ImprimeMedida(int i,int j,int k){

int espacios,cifras,volumen;
float porcentaje;

espacios = 0;
cifras = 0;
porcentaje = 0;
volumen = 0;

printf("%s",cuencas[i].cuenca);    //Imprimo nombre de la cuenca
espacios = 19 - strlen(cuencas[i].cuenca);  //Calculo los espacios que tengo que imprimir

  for (int n = 0; n < espacios; n++){
   printf(" ");                         //Imprimo los espacios
  }

printf("%s",cuencas[i].presas[j].presa);      //Imprimo nombre de la presa

espacios = 18 - strlen(cuencas[i].presas[j].presa);

  for (int n = 0; n < espacios; n++){
   printf(" ");
  }

/*Calculo porcentaje de la medida actual respecto a la capacidad*/

porcentaje = float((VolumenEmbalsadoPresa(i,j,k)) * 100) / float(cuencas[i].presas[j].capacidad);

//  porcentaje = float((cuencas[i].presas[j].volumen_actual_presa) * 100) / float(cuencas[i].presas[j].capacidad);

printf("%d(%5.1f%c)",cuencas[i].presas[j].medidas[k].volumen,porcentaje,'%');

/*Calculando el log en base 10 del volumen + 1, sabemos los espacios que ocupa*/

volumen = cuencas[i].presas[j].medidas[k].volumen;

/*Con el logaritmo solo saco las cifras de numeros positivos, lo convierto a positivo en el caso de que sea menor que 0
y le añado una cifra (por el -)*/
if (volumen < 0){
  volumen = volumen - volumen - volumen;

  cifras = log10(volumen) + 1;

  espacios = 12 - cifras;
}else{

  cifras = log10(volumen) + 1;

  espacios = 13 - cifras;
}
  for (int n = 0; n < espacios; n++){
   printf(" ");
  }

printf("%02d/%02d/%d",cuencas[i].presas[j].medidas[k].dia,cuencas[i].presas[j].medidas[k].mes,cuencas[i].presas[j].medidas[k].anio);

printf("\n");

espacios = 0;
cifras = 0;
porcentaje = 0;
volumen = 0;

}
/*Menu registros R*/
void TipoAltaCuenca::Registros(){

TipoCadena presa_usuario, cuenca_usuario;
int dia, mes, anio, espacios, cifras,i_cuenca,j_presa; //Importantes las variables i_cuenca y j_presa donde almaceno el numero del vector donde coincide con el usuario
bool coincidencia_cuenca = false;
bool coincidencia_presa = false;
float porcentaje;

espacios = 0;
cifras = 0;
porcentaje = 0;
i_cuenca = -1;
j_presa = -1;

/*Pedimos los datos al usuario*/
printf("\nRegistros:\n");
printf("\tNombre de la cuenca: ");
scanf("%s",&cuenca_usuario);
printf("\tNombre de la presa: ");
scanf("%s",&presa_usuario);
printf("\tPosterior al dia: ");
scanf("%d",&dia);
printf("\tMes: ");
scanf("%d",&mes);
printf("\tAnio: ");
scanf("%d",&anio);
printf("\n");

/*Seguimos solo si la fecha es valida*/
if (ComprobarFecha(dia,mes,anio)){

/*Dibujo cabezera siempre*/

printf("Cuenca             Presa             Volumen              Fecha\n");

 /*Primer caso, no encuentra la cuenca dada, entonces mostramos todos los datos de la region, anteriores a la fecha*/
  for (int i = 0; i < 3; i++){

    if (strcmp(cuenca_usuario,cuencas[i].cuenca) == 0){  //Buscamos si existe la cuenca
    coincidencia_cuenca = true;
    i_cuenca = i; //Me quedo con la cuenca que ha coincidido
    /*Si la cuenca coincide, buscamos la presa*/
    for (int j = 0; j < 5; j++){
      if (strcmp(presa_usuario,cuencas[i].presas[j].presa) == 0){  //Buscamos si existe la presa
        coincidencia_presa = true;
        j_presa = j; //Me quedo con la presa que ha coincidido
     }
    }
   }
  }
  /*Si no existe, buscaremos la fecha anterior a la dada*/
  if (!coincidencia_cuenca){

   for (int i = 0; i < 3; i++){

    for (int j = 0; j < 5; j++){

     for (int k = 0; k < cuencas[i].presas[j].contador_medidas; k++){

        /*Miramos si las fecha no son posteriors( son anteriores ) y si no lo son, las imprimimos*/
       if (FechaPosterior(cuencas[i].presas[j].medidas[k].dia,
           cuencas[i].presas[j].medidas[k].mes,
           cuencas[i].presas[j].medidas[k].anio,
           dia,mes,anio)){

         ImprimeMedida(i,j,k);

      }
     }
    }
   }

   /*Imprimo los todales de las cuencas*/
   for(int i = 0; i < contador_cuencas; i++){

     printf("%s",cuencas[i].cuenca);
     espacios = 19 - strlen(cuencas[i].cuenca);  //Calculo los espacios que tengo que imprimir

     for (int n = 0; n < espacios; n++){   //Imprimo los espacios
     printf(" ");
      }
    /*Calculo porcentaje cuenca*/
    porcentaje = float((cuencas[i].volumen_actual_cuenca) * 100) / float(cuencas[i].capacidad_cuenca);

    printf("TOTAL             %d(%5.1f%c)\n",cuencas[i].volumen_actual_cuenca,porcentaje,'%');
   }
   /*Calculo porcentaje region*/
   porcentaje = 0;

   porcentaje = float((volumen_actual_region) * 100) / float(capacidad_region);

   printf("TODAS              TOTAL             %d(%5.1f%c)",volumen_actual_region,porcentaje,'%');
   printf("\n");

espacios = 0;
porcentaje = 0;
  }
  /*En el segundo caso, la cuenca coincide, pero la presa no (imprimimos todos las medidas de la cuenca*/

  if (coincidencia_cuenca && (!coincidencia_presa)){

      for (int j = 0; j < 5; j++){
          for (int k = 0; k < cuencas[i_cuenca].presas[j].contador_medidas; k++){
            /*Miramos si las fecha no son posteriors( son anteriores ) y si no lo son, las imprimimos*/
               if (FechaPosterior(cuencas[i_cuenca].presas[j].medidas[k].dia,
                   cuencas[i_cuenca].presas[j].medidas[k].mes,
                   cuencas[i_cuenca].presas[j].medidas[k].anio,
                   dia,mes,anio)){

                 ImprimeMedida(i_cuenca,j,k);

      }
     }
    }
    /*Imprimimos total cuenca*/
     printf("%s",cuencas[i_cuenca].cuenca);
     espacios = 19 - strlen(cuencas[i_cuenca].cuenca);  //Calculo los espacios que tengo que imprimir

     for (int n = 0; n < espacios; n++){   //Imprimo los espacios
     printf(" ");
      }
      /*Calculo porcentaje cuenca*/
    porcentaje = float((cuencas[i_cuenca].volumen_actual_cuenca) * 100) / float(cuencas[i_cuenca].capacidad_cuenca);

    printf("TOTAL             %d(%5.1f%c)\n",cuencas[i_cuenca].volumen_actual_cuenca,porcentaje,'%');

   /*Calculo porcentaje region*/
   porcentaje = 0;

   porcentaje = float((volumen_actual_region) * 100) / float(capacidad_region);

   printf("TODAS              TOTAL             %d(%5.1f%c)",volumen_actual_region,porcentaje,'%');
   printf("\n");


   espacios = 0;
   porcentaje = 0;
   i_cuenca = -1;
   coincidencia_cuenca = false;


  }

/*Ultimo caso* donde la cuenca y la presa coincide con el usuario (imprimimos datos de esa presa)*/

  if ((coincidencia_cuenca) && (coincidencia_presa)){


    for (int k = 0; k < cuencas[i_cuenca].presas[j_presa].contador_medidas; k++){

        /*Miramos si las fecha no son posteriores( son anteriores ) y si no lo son, las imprimimos*/
               if (FechaPosterior(cuencas[i_cuenca].presas[j_presa].medidas[k].dia,
                   cuencas[i_cuenca].presas[j_presa].medidas[k].mes,
                   cuencas[i_cuenca].presas[j_presa].medidas[k].anio,
                   dia,mes,anio)){

                 ImprimeMedida(i_cuenca,j_presa,k);

      }
    }

    /*Imprimimos total cuenca*/
     printf("%s",cuencas[i_cuenca].cuenca);
     espacios = 19 - strlen(cuencas[i_cuenca].cuenca);  //Calculo los espacios que tengo que imprimir

     for (int n = 0; n < espacios; n++){   //Imprimo los espacios
     printf(" ");
      }
      /*Calculo porcentaje cuenca*/
    porcentaje = float((cuencas[i_cuenca].volumen_actual_cuenca) * 100) / float(cuencas[i_cuenca].capacidad_cuenca);

    printf("TOTAL             %d(%5.1f%c)\n",cuencas[i_cuenca].volumen_actual_cuenca,porcentaje,'%');

   /*Calculo porcentaje region*/
   porcentaje = 0;

   porcentaje = float((volumen_actual_region) * 100) / float(capacidad_region);

   printf("TODAS              TOTAL             %d(%5.1f%c)",volumen_actual_region,porcentaje,'%');
   printf("\n");


  espacios = 0;
  porcentaje = 0;
  i_cuenca = -1;
  j_presa = -1;
  coincidencia_cuenca = false;
  coincidencia_presa = false;
  }
 }
}
/*Calculo variaicones de un mismo dia volumen embalsado dado una fecha, devolvemos un -1234 en el caso de no encontrar mediciones*/
int TipoAltaCuenca::CalculoVariacion(int dia, int mes, int anio, int cuenca, int presa){

int variacion;
int contador_medidas;  //La utilizo para guardar la cantidad de medidas que voy grabando

contador_medidas = 0;
variacion = 0;

/*Cuando la cuenca y la presa no coinciden, recibimos -1 en ambas*/

if ((cuenca < 0) && (presa < 0)){

for (int i = 0; i < 3; i++){
  for (int j = 0; j < 5; j++){
    for (int k = 0; k < 100; k++){
    /*Si la fecha coincide, guardamos el volumen*/
    if ((cuencas[i].presas[j].medidas[k].dia == dia)
         && (cuencas[i].presas[j].medidas[k].mes == mes)
         && (cuencas[i].presas[j].medidas[k].anio == anio)){

          /*Sumo los volumenes la variable variacion*/
          variacion = variacion + cuencas[i].presas[j].medidas[k].volumen;
          /*Calculo el porcentaje respecto a la capacidad*/
          variacion = (variacion * 100) / cuencas[i].presas[j].capacidad;
          contador_medidas++;

    }
   }
  }
 }
  if (contador_medidas == 0){
    return (-1234);  //Si no ha habido medidas, devuelvo -1234
  }else{   //De lo contrario, devuelvo la variacion
  return variacion;
  }
 }

/*Cuenca coincide pero presa no*/

if ((cuenca >= 0) && (presa < 0)){

  for (int j = 0; j < 5; j++){
    for (int k = 0; k < 100; k++){
    /*Si la fecha coincide, guardamos el volumen*/
    if ((cuencas[cuenca].presas[j].medidas[k].dia == dia)
         && (cuencas[cuenca].presas[j].medidas[k].mes == mes)
         && (cuencas[cuenca].presas[j].medidas[k].anio == anio)){

          /*Sumo los volumenes la variable variacion*/
          variacion = variacion + cuencas[cuenca].presas[j].medidas[k].volumen;
          /*Calculo el porcentaje respecto a la capacidad*/
          variacion = (variacion * 100) / cuencas[cuenca].presas[j].capacidad;
          contador_medidas++;

    }
   }
  }

  if (contador_medidas == 0){
    return (-1234);  //Si no ha habido medidas, devuelvo -1234
  }else{   //De lo contrario, devuelvo la variacion
  return variacion;
  }
 }

/*Empezaremos calculando lo sabiendo la cuenca y la presa
(cuando la cuenca no se sepa entrara con valor -1 y
lo mismo ocurre con la presa */

if ((cuenca >= 0) && (presa >= 0)){

for (int k = 0; k < 100; k++){
/*Si la fecha coincide, guardamos el volumen*/
if ((cuencas[cuenca].presas[presa].medidas[k].dia == dia)
     && (cuencas[cuenca].presas[presa].medidas[k].mes == mes)
     && (cuencas[cuenca].presas[presa].medidas[k].anio == anio)){

      /*Sumo los volumenes la variable variacion*/
      variacion = variacion + cuencas[cuenca].presas[presa].medidas[k].volumen;
      /*Calculo el porcentaje respecto a la capacidad*/
      variacion = (variacion * 100) / cuencas[cuenca].presas[presa].capacidad;
      contador_medidas++;

     }
  }
  if (contador_medidas == 0){
    return -1234;  //Si no ha habido medidas, devuelvo -1234
  }else{   //De lo contrario, devuelvo la variacion
  return variacion;
  }
 }
}
/*Menu variaciones mensuales*/
void TipoAltaCuenca::VariacionesMensuales(){

const TipoVector vector_meses={31,28,31,30,31,30,31,31,30,31,30,31};
const TipoVector vector_meses_bisiesto={31,29,31,30,31,30,31,31,30,31,30,31};

TipoCalendario calendario;   //Declaracion tipo calendario

TipoVectorVarInt vector_int;  //Vector donde guardare las variaciones de los dias
TipoCadenasVar cadena_var;    //Vector que le pasare al calendario para que me lo imprima
TipoCadena presa_usuario, cuenca_usuario;


int mes, anio,i_cuenca,j_presa, variacion, dias_mes; //Importantes las variables i_cuenca y j_presa donde almaceno el numero del vector donde coincide con el usuario

//bool coincidencia_cuenca = false;
//bool coincidencia_presa = false;

variacion = 0;
i_cuenca = -1;
j_presa = -1;

/*Inicializo vector variaciones a 0*/

for (int i = 0; i <= 32; i++){

 vector_int[i]=0;

}

/*Preguntamos los datos al usuario*/

printf("\nVariaciones mensuales:\n");
printf("\tNombre de la cuenca: ");
scanf("%s",&cuenca_usuario);
printf("\tNombre de la presa: ");
scanf("%s",&presa_usuario);
printf("\tMes: ");
scanf("%d",&mes);
printf("\tAnio: ");
scanf("%d",&anio);
printf("\n");

/*Calculo dias de fecha dada*/

if (calendario.AnioBisiesto(anio)){

  dias_mes = vector_meses_bisiesto[mes-1];

}else{

  dias_mes = vector_meses[mes-1];

}

/*Solo continuo si la fecha esta dentro de rango (no seria necesario)*/
if ((mes > 0 || mes < 13) && (anio > 1599 || anio < 3001)){

 /*Busco coincidencia entre la cuenca y presa dadas por el usuario y las mias*/
  for (int i = 0; i < 3; i++){

    if (strcmp(cuenca_usuario,cuencas[i].cuenca) == 0){  //Buscamos si existe la cuenca
//    coincidencia_cuenca = true;
    i_cuenca = i; //Me quedo con la cuenca que ha coincidido
    /*Si la cuenca coincide, buscamos la presa*/
    for (int j = 0; j < 5; j++){
      if (strcmp(presa_usuario,cuencas[i].presas[j].presa) == 0){  //Buscamos si existe la presa
  //      coincidencia_presa = true;
        j_presa = j; //Me quedo con la presa que ha coincidido
     }
    }
   }
  }
/*Calculo de las variaciones, las guardo en mi vector*/
 for (int n = 1; n <= dias_mes; n++){

  vector_int[n] =  CalculoVariacion(n,mes,anio,i_cuenca,j_presa);

 }

/*Analizo la cadena de enteros y le asigno los valores que quiero que me imprima en el calendario*/

for (int n = 1; n <= dias_mes ; n++){

    if (vector_int[n] ==  -1234){
      strcpy(cadena_var[n],"--");
    }else{

    /*Si la posicion del vector tiene guardado un 0, la cadena sera 00*/
    if (vector_int[n] == 0){
     strcpy(cadena_var[n],"00");
    }
    /*Si el vector enetero es mayor que 9 o menor que -9, la cadena sera EE, overflow*/
    if (vector_int[n] > 9 || vector_int[n] < -9){
     strcpy(cadena_var[n],"EE");
     }
     /*Si el vector esta entre 1 y 9, ellos incluidos, la cadena sera +(el valor del vector)*/
     if (vector_int[n] <= 9 && vector_int[n] >= 1){
       sprintf(cadena_var[n],"+%d",vector_int[n]);
     }
     /*Si el vector esta entre -1 y -9, ellos incluidos, la cadena sera -(el valor del vector)*/
     if (vector_int[n] >= -9 && vector_int[n] <= -1){
       sprintf(cadena_var[n],"%d",vector_int[n]);
     }
    }
   }

calendario.ImprimeCalendario(mes,anio,cadena_var,cuenca_usuario,presa_usuario);

 }


//  coincidencia_cuenca = false;
//  coincidencia_presa = false;
  i_cuenca = -1;
  j_presa = -1;

/*Vuelvo a poner a las variables usadas a su estado inicial*/
  for (int i = 0; i <= 32; i++){

 vector_int[i]=0;


 }
}

void TipoAltaCuenca::Test(){

  for (int i = 0 ; i < 3; i++){

  printf("\nLa capacidad de la cuenca[%d] es %d",i,cuencas[i].capacidad_cuenca);

  }
printf("\n\nLa capacidad de la region es %d",capacidad_region);

  for (int i = 0 ; i < 3; i++){

  printf("\nEl volumen de la cuenca[%d] es %d",i,cuencas[i].volumen_actual_cuenca);

  }
printf("\n\nEl volumen de la region es %d",volumen_actual_region);
}
