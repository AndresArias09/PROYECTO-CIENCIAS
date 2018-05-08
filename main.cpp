#include <iostream>
#include <windows.h>
using namespace std;

void menu(int opcion);
void modificarCiudad();
void consultarCiudades();
void insertarCandidato();
void eliminarCandidato();
void modificarCandidato();
void mostrarPartidosPoliticos();
void consultarCandidatosDepartamentoPartido();
void consultarCandidatosPorPartido();
void consultarCandidatosPorCiudad();
void consultarCandidatosPporPartido();
void consultarCandidatosP();
void censoTotal();
void censoCiudad();
void tarjetonPresidencial();
void targetonPorCiudad();
void simulacion(int opcion);
void menuConsultas(int opcion);
void consultasTargetones(int opcion);
void consultasCenso(int opcion);
void consultasCandidatos(int opcion);
void menuRegistros(int opcion);
void menuPartidos(int opcion);
void menuCandidatos(int opcion);
void menuCiudades(int opcion);
void iniciarSimulacion();
void estadisticasAlcaldias(int opcion);
void estadisticasPresidenciales();
void alcaldesPorPartido();
void estadisticasDepartamento();
void estadisticasCiudad();


int main(){
	int opcion;
	menu(opcion);
}

void menu(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"MENU PRINCIPAL"<<endl<<endl;
	cout<<"1. Registros"<<endl<<"2. Consultas"<<endl<<"3. Iniciar simulacion"<<endl<<"4. Salir"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //gestion de registros
			menuRegistros(opcion);
		break;
		case 2: //consultas
			menuConsultas(opcion);
		break;
		case 3: //simulacion electoral
			simulacion(opcion);
		break;
		case 4:
			return;
		break;
		default: 
			cout<<"Dato erroneo"<<endl;
			system("pause");
			system("CLS");
			menu(opcion);
	}
}

void menuConsultas(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"CONSULTAS"<<endl<<endl;
	cout<<"1. Candidatos"<<endl<<"2. Censo electoral"<<endl<<"3. Targetones"<<endl<<"4. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //consultas candidatos
			consultasCandidatos(opcion);
		break;
		case 2: //censo electoral
			consultasCenso(opcion);
		break;
		case 3: //targetones
			consultasTargetones(opcion);
		break;
		case 4: //volver
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			menuConsultas(opcion);
	}
	system("pause");
	menu(opcion);
}
void consultasTargetones(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"TARJETONES ELECTORALES"<<endl<<endl;
	cout<<"1. Tarjeton electoral de una ciudad"<<endl<<"2. Tarjeton presidencial"<<endl<<"3. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //tarjeton por ciudad
			targetonPorCiudad();
		break;
		case 2: //tarjeton presidencial
			tarjetonPresidencial();
		break;
		case 3: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			consultasTargetones(opcion);
	}
	system("pause");
	menu(opcion);
}

void consultasCenso(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"CENSO ELECTORAL"<<endl<<endl;
	cout<<"1. Censo electoral de una ciudad"<<endl<<"2. Censo electoral total"<<endl<<"3. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //censo electoral de una ciudad
			censoCiudad();
		break;
		case 2: //censo total
			censoTotal();
		break;
		case 3: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			consultasCenso(opcion);
	}
	system("pause");
	menu(opcion);
}

void consultasCandidatos(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"CONSULTA DE CANDIDATOS"<<endl<<endl;
	cout<<"1. Candidatos a la presidencia"<<endl<<"2. Candidatos a alcaldias por ciudad"<<endl<<"3. Candidatos a alcaldias por partido"
	<<endl<<"4. Candidatos a alcald�as por departamento y partido"<<endl<<"5. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //consultar candidatos a la presidencia
			system("cls");
			cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
			cout<<"CANDIDATOS PRESIDENCIALES"<<endl<<endl;
			cout<<"1. Consultar todos"<<endl<<"2. Consultar por partido"<<endl<<"Opcion: ";
			cin>>opcion;
			switch(opcion){
				case 1: //consultar todos los candidatos presidenciales
					consultarCandidatosP();
				break;
				case 2: //consultar candidatos presidenciales por partido
					consultarCandidatosPporPartido();
				break;
				default:
					cout<<"Dato err�neo"<<endl;
					system("pause");
					system("CLS");
					consultasCandidatos(opcion);
			}
		break;
		case 2: //consultar candidatos a alcandias por ciudad
			consultarCandidatosPorCiudad();
		break;
		case 3: //consultar candidatos a alcandias por partido
			consultarCandidatosPorPartido();
		break;
		case 4: //consultar cantidatos a alcadias por departamento y partido
			consultarCandidatosDepartamentoPartido();
		break;
		case 5: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			consultasCandidatos(opcion);
	}
	system("pause");
	menu(opcion);
}

void menuRegistros(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"REGISTROS"<<endl<<endl;
	cout<<"1. Ciudades"<<endl<<"2. Candidatos"<<endl<<"3. Partidos politicos"<<endl<<"4. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //registros de ciudades
			menuCiudades(opcion);
		break;
		case 2: //candidatos
			menuCandidatos(opcion);
		break;
		case 3: //partidos politicos
			menuPartidos(opcion);
		break;
		case 4: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			menuRegistros(opcion);
	}
	system("pause");
	menu(opcion);
}

void menuPartidos(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"REGISTROS DE PARTIDOS POLITICOS"<<endl<<endl;
	mostrarPartidosPoliticos();
	system("pause");
	system("CLS");
	menu(opcion);
}

void menuCandidatos(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"REGISTROS DE CANDIDATOS"<<endl<<endl;
	cout<<"1. Insertar"<<endl<<"2. Eliminar"<<endl<<"3. Modificar"<<endl<<"4. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //insertar un candidato
			insertarCandidato();
		break;
		case 2: //eliminar un candidato
			eliminarCandidato();
		break;
		case 3: //modificar un candidato
			modificarCandidato();
		break;
		case 4: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			menuCandidatos(opcion);
	}
	system("pause");
	menu(opcion);
}

void menuCiudades(int opcion){
	system("CLS");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"REGISTROS DE CIUDADES"<<endl<<endl;
	cout<<"1. Modificar"<<endl<<"2. Consultar todas las ciudades"<<endl<<"3. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //modificar ciudad
			modificarCiudad();
		break;
		case 2: //consultar ciudades
			consultarCiudades();
		break;
		case 3: //volver al inicio
			system("CLS");
			menu(opcion);
		break;
		default:
			cout<<"Dato err�neo"<<endl;
			system("pause");
			system("CLS");
			menuCiudades(opcion);
	}
	system("pause");
	menu(opcion);
}

void simulacion(int opcion){
	iniciarSimulacion();
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"SIMULACION"<<endl<<endl;	
	cout<<"1. Estadisticas presidenciales"<<endl<<"2. Estadisticas de alcaldias"<<endl<<"3. Volver al inicio"<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //estadisticas presidenciales
			estadisticasPresidenciales();
		break;
		case 2: //estadisticas de alcaldias
			estadisticasAlcaldias(opcion);
		break;
		case 3: //volver al inicio
			system("cls");
			menu(opcion);
		break;
		default:
			cout<<"Dato erroneo";
			system("pause");
			system("cls");
			menu(opcion);
	}
	system("pause");
	menu(opcion);
}

void estadisticasAlcaldias(int opcion){
	system("cls");
	cout<<"ELECCIONES PRESIDENCIALES Y LOCALES COLOMBIA 2018"<<endl<<endl;
	cout<<"ESTADISTICAS DE ALCALDIAS"<<endl<<endl;
	cout<<"1. Estadisticas por ciudad"<<endl<<"2. Estadisticas por departamento"<<endl<<"3. Total alcaldes por partido"<<endl<<"4. Volver a inicio"
	<<endl<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1: //estadisticas por ciudad
			estadisticasCiudad();
		break;
		case 2: //estadisticas por departamento
			estadisticasDepartamento();
		break;
		case 3: //total alcaldes por partidos
			alcaldesPorPartido();
		break;
		case 4: //volver al inicio
			system("cls");
			menu(opcion);
		break;
		default:
			cout<<"Dato erroneo";
			system("pause");
			system("cls");
			estadisticasAlcaldias(opcion);
	}	
	system("pause");
	menu(opcion);
}

void alcaldesPorPartido(){
	
}

void estadisticasDepartamento(){
	
}

void estadisticasCiudad(){
	
}

void modificarCiudad(){
	
}

void consultarCiudades(){
	
}

void insertarCandidato(){
	
}

void eliminarCandidato(){
	
}

void modificarCandidato(){
	
}

void mostrarPartidosPoliticos(){
	
}

void consultarCandidatosDepartamentoPartido(){
	
}

void consultarCandidatosPorPartido(){
	
}

void consultarCandidatosPorCiudad(){
	
}

void consultarCandidatosPporPartido(){
	
}

void consultarCandidatosP(){
	
}

void censoTotal(){
	
}

void censoCiudad(){
	
}

void tarjetonPresidencial(){
	
}

void targetonPorCiudad(){
	
}

void estadisticasPresidenciales(){
	
}

void iniciarSimulacion(){
}

