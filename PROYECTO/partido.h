/**
	@file partido.h
	@brief clase que gestiona el archivo partido
	
	este archivo posee todos los metodos necesarios para el manejo de la informacion de los partidos  
	
	@author Andres Arias & Isabel Perez
	
	@date 8/05/2018,28/05/2018
*/
#ifndef PARTIDO_H
#define PARTIDO_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Librerias/arbolAVL.h"
#include "facade.h"
#include "estructuras.h"

//esta clase gestiona la lectura, escritura y la busqueda en el archivo partidos.txt
class partido: public facade{
	private:
		//arbol AVL
		arbolAVL<partid> *arbolPartidos;
		//instancia unica
		static partido *instance;
		/** 
			@brief metodo constructor 
			@returns lectura de registros 
		*/
		partido(){
			this->cantidad = 0;
			this->leido = false;
			arbolPartidos = new arbolAVL<partid>();
			leerRegistros();
		}
		/**
		@brief funcion para leer los registros del archivo 
		*/
		void leerRegistros(){
			if(leido==false){
				int clave,estado;
				string nombre;
				string representante;
				partid par;
				//archivo de entrada
				ifstream archEntrada("Archivos/partidos.txt", ios::in);
				if (!archEntrada.good()){
				 	cerr<< "No se pudo abrir el archivo partidos" << endl;
			    	exit(1);
				}
				while(!archEntrada.eof()) {
					archEntrada >> clave;
					archEntrada >> nombre;
					archEntrada >> representante;
					archEntrada >>estado;
					par.clave = clave;
					par.estado = estado;
					par.nombre = nombre;
					par.representante = representante;
					agregarPartido(par);
				}
				archEntrada.close();
				this->leido = true;
			}
		}
	public:
		//se obtiene la instancia unica
		/** 
			@brief metodo de instanciacion de la clase (Patron singleton)
			@returns devuelve la instancia de la clase
		*/
		static partido *getInstance(){
			if(instance==0){
				instance = new partido();
			}
			return instance;
		}
		/** 
			@brief Funcion para agregar un partido al arbol AVL
			@param partido partid, estructura que sera insertada en el arbol AVL
		*/
		void agregarPartido(partid partido){
			partido.clave = ++this->cantidad;
			arbolPartidos->agregar(partido);
		}
		/** 
		@brief funcion para obtener todos los partidos
		@returns apuntador a lista tipo partid con todos los partidos  
		*/
		Lista<partid> *consultarPartidos(){
			Lista<partid> *lista = arbolPartidos->recorridoInOrden();
			return lista;
		}
		/** 
		@brief funcion para obtener un partido dada su clave
		@returns apuntador a la estructura tipo partid que tiene esa clave 
		@param clave int 
		*/
		partid *getPartido(int clave){
			partid *partido = arbolPartidos->retornarEstructura(clave);
			return partido;
		}
		/** 
		@brief funcion para agregar un candidato a su correspondiente partido
		@param candidato candidate*, apuntador al candidato que se desea insertar
		@param partido int, clave del partido al que se va a agregar el candidato 
		*/
		void agregarCandidato(candidate *candidato,int partido){
			partid *par = arbolPartidos->retornarEstructura(partido);
			par->candidatos.anadir_final(candidato);
		}
		/** 
		@brief funcion para obtener el nombre de un partido dada su clave
		@returns string con el nombre del partido
		@param clave int 
		*/
		string getNombrePartido(int clave){
			partid *par = arbolPartidos->retornarEstructura(clave);
			return par->nombre;
		}
		/** 
			@brief funcion para obtener los candidatos que corresponden a un determinado partido
			@returns lista de apuntadores a los candidatos que pertenecen a un determinado partido
			@param clave int
			@param partido int  
		*/
		Lista<candidate*> consultarCandidatosByPartido(int clave){
			partid *partid = arbolPartidos->retornarEstructura(clave);
			return partid->candidatos;
		}
		/** 
			@brief Funcion para obtener la cantidad de regisitros que se tienen en los partidos
			@returns retonara un 'int' con la cantidad de registros
		*/
		int getCantidad(){
			return this->cantidad;
		}
		/** 
			@brief Funcion que libera memoria eliminando los apuntadores que contiene
		*/
		void liberar(){
			delete arbolPartidos;
			delete instance;
		}
		/** 
			@brief Funcion que reescribe el archivo partidos con todas las modificaciones hechas
		*/
		void escribirRegistros(){
			ofstream archsalida("Archivos/partidos.txt",ios::out|ios::trunc);
			if (!archsalida.good()){
				cerr << "No se pudo abrir el archivo partidos" << endl;
				exit(1);
			}
			Lista<partid> partidos = *arbolPartidos->recorridoInOrden();
			for(int i=0;i<partidos.getTam();i++){
				partid par = partidos.devolverDato(i);
				if(i!=partidos.getTam()-1){
					archsalida<<par.clave<<" "<<par.nombre<<" "<<par.representante<<" "<<par.estado<<"\n";
				}
				else{
					archsalida<<par.clave<<" "<<par.nombre<<" "<<par.representante<<" "<<par.estado;
				}
			}
			archsalida.close();
		}
		/** 
			@brief Funcion que verifica si un partido esta eliminado
			@returns retorna un 'bool' indicando si esta eliminado o no
			@param clave int,  Corresponde a la clave del partido
		*/
		bool estaDeshabilitado(int clave){
			partid par = *arbolPartidos->retornarEstructura(clave);
			if(par.estado==0){
				return true;
			}
			return false;
		}
		/** 
			@brief Funcion para modificar un partido
			@param clave int, que corresponde a la clave del partido que se desea modificar
			@param partid nuevo, que corresponde a la nueva informacion que tendra el partido
		*/
		void modificarPartido(int clave, partid nuevo){
			partid *par = arbolPartidos->retornarEstructura(clave);
			par->nombre = nuevo.nombre;
			par->representante = nuevo.representante;
		}
		/** 
			@brief Funcion para eliminar un partido
			@param clave int, que corresponde a la clave del partido que se desea eliminar
		*/
		void eliminarPartido(int clave){
			partid *par = arbolPartidos->retornarEstructura(clave);
			par->estado = 0;
			Lista<candidate*> candidatos = par->candidatos;
			//se eliminan todos los candidatos que estan en ese partido
			for(int i=0;i<candidatos.getTam();i++){
				candidate *can = candidatos.devolverDato(i);
				can->estado = 0;
			}
		} 
};
partido* partido::instance = 0;
#endif

