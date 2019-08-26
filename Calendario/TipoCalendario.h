#pragma once

typedef enum TipoMes {Enero,Febrero,Marzo,Abril,Mayo,Junio,Julio,Agosto,Septiembre,Octubre,Noviembre,Diciembre};
typedef int TipoVector[12];

typedef struct TipoCalendario{

  void ImprimeCalendario(int mes, int anio);
  private:
  bool AnioBisiesto(int anio);
  void EscribirMes(int mes);
  int InicioDia(int anio,int mes);
};
