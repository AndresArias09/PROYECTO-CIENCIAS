/**
	@file escructuras.h
	@brief gestiona las estructuras necesarias para todo el proyecto
	
	este archivo posee todos las estructuras necesarias para el proyecto  
	
	@author Andres Arias & Isabel Perez
	
	@date 8/05/2018,28/05/2018
*/

#ifndef estruct
#define estruct
#include "Librerias/ListaOrdenada.h"

//estructura para candidatos
struct candidate{
	int clave;
	string nombre;
	string apellido;
	long long cc;
	string sexo;
	string estadoCivil;
	string fechaNacimiento;
	int ciudadNatal;
	int ciudadResidencia;
	int partido;
	int territorio;
	int formulaVi;
	int estado;
};
//estructura para partidos
struct partid{
	int clave;
	string nombre;
	string representante;
	Lista<candidate*> candidatos;
	int estado;
};
//estructura para ciudades
struct city{
	int clave;
	string nombre;
	int departamento;		
	long long censo;
	Lista<candidate*> candidatos;
	int estado;
};
//estructura para la simuacion de las elecciones, guarda datos acerca de cada candidato
struct candidatoSimulacion{
	candidate can;
	long long votos;
	float porcentaje;
};
//estructura para la simulacion de las elecciones, guarda datos acerca de cada ciudad
struct territorioSimulacion{
	int clave;
	city ciu;
	ListaO <candidatoSimulacion> candidatos;
	long long votosBlanco;
	long long votosNulos;
	long long abstencion;
	long long censoVotante;
	candidatoSimulacion ganador;
};
//estructura para departamentos
struct departament{
	int clave;
	string nombre;
	Lista<city*> cities;
	Lista<territorioSimulacion> ciudades;
};
//estructura que contiene las estadisticas para un departamento
struct departamentoSimulacion{
	int clave;
	departament dep;
	long long totalVotos;
	long long votosBlanco;
	long long votosNulos;
	long long abstencion;
	int *totalByPartido;
	int totalHombres;
	int totalMujeres;
	int cantidadCiudades;
	long long censo;
	Lista<territorioSimulacion> ciudadesVotoBlanco;
};
//estructura que contiene las estadisticas del pais
struct simulacionNacionales{
	int *totalesByPartido;
	int totalHombres;
	int totalMujeres;
	int censoTotal;
	int totalCiudades;
	Lista<territorioSimulacion> ciudadesVotoBlanco;
};
#endif

