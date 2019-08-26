#pragma once

typedef char TipoCadenaVar[3];
typedef enum TipoMes {Enero,Febrero,Marzo,Abril,Mayo,Junio,Julio,Agosto,Septiembre,Octubre,Noviembre,Diciembre};
typedef int TipoVector[12];
typedef char TipoCadena[100];
//typedef int TipoVectorInt[32];
typedef TipoCadenaVar TipoCadenasVar[31];  //Vector de strings donde almacenare los datos a imprimir en el calendario

typedef struct TipoCalendario{

  void ImprimeCalendario(int mes, int anio, TipoCadenasVar var, TipoCadena cuenca, TipoCadena presa);
  bool AnioBisiesto(int anio);
  void EscribirMes(int mes);
  int InicioDia(int anio,int mes);
};

