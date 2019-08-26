#pragma once

const int tam_cadena = 100;      //Constante para el tamaño de las cadenas
const int max_cuencas = 3;       //Constante para el maximo de cuencas
const int max_presas = 5;        //Constante para el maximo de presas
const int maximo_medidas = 100;  //Constante para el maximo de presas

typedef char TipoCadenaVar[3];
typedef int TipoVector[12];            //Vector para los meses
typedef int TipoVectorVarInt[32];  //Vector donde voy guardando las variaciones diarias
typedef char TipoCadena[tam_cadena];

typedef TipoCadenaVar TipoCadenasVar[31];  //Vector de strings donde almacenare los datos a imprimir en el calendario

/*Estructura para el registro de medidas*/
typedef struct TipoMedida{
  int volumen,dia,mes,anio;
  bool hay_medida;
};

typedef TipoMedida TipoMedidas[maximo_medidas]; //Vector con un maximo de 100 medidad

/*Estructura para la presa*/
typedef struct TipoPresa{

  TipoCadena presa;
  TipoMedidas medidas;
  int contador_medidas;  //Variable para ir acumulando las medidas
  int capacidad;
  int volumen_actual_presa;
  bool primera_medida;  //Variable para saber si es la primera medida leida
  bool ultima_medida;   //Variable para saber si es la ultima medida

};

typedef TipoPresa TipoPresas[max_presas]; //Hacemos vector con 5 presas

/*Estructura para la cuenca*/
typedef struct TipoCuenca{

  TipoCadena cuenca;
  TipoPresas presas;
  int volumen_actual_cuenca;
  int capacidad_cuenca;
  int numero_presa;           //Contador presas

};

typedef TipoCuenca TipoCuencas[max_cuencas]; //Hacemos vector con 3 cuencas

/*TAD altas*/
typedef struct TipoAltaCuenca{

  TipoCuencas cuencas;
  int contador_cuencas;
  int capacidad_region;
  int volumen_actual_region;
  void Test();                 //TESTEO
  void MenuPrincipal();        //Procedimiento con el menu principal
  void MenuAlta();             //Procedimiento alta cuencas presas y capacidad
  void Inicializar();          //Inicializacion
  void InicializaTest();       //Registro ciertas variables para el testeo del programa
  void NuevaMedida();          //Procedimiento nueva medida
  void ImprimeMedida(int i,int j,int k);   //Imprime medidas
  int VolumenEmbalsadoPresa(int contador_cuenca, int contador_presa, int contador_medidas); //Devuelve el valor de volumen de una presa hasta una medida dada
  bool ComprobarFecha(int dia, int mes, int anio);  //Compruebo si una fecha es correcta
  bool FechaPosterior(int dia, int mes, int anio,int dia_usuario, int mes_usuario, int anio_usuario); //Compruebo si una fecha es posterior a otra
  void Registros();  //Menu para mostar los registros
  void VariacionesMensuales();  //Menu variaciones mensuales
  int CalculoVariacion(int dia, int mes, int anio, int cuenca, int presa);

};
