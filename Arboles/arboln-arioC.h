#include <iostream>
#include <cstring>
#include <string>
#include<stdlib.h>
using namespace std;

//-----------------------------------------------------------------------------------------------------------------
//Clase Nodo

template<class T>
class NodoNC{
	public:
		int num_hijos = 0;
		T etiqueta;
		NodoNC<T>* primerHijo;
		NodoNC<T>* hermano_derecho;  	
		public:
			NodoNC(T dato){ 
			num_hijos = 0;
			etiqueta = dato;
			hermano_derecho=NULL;
			primerHijo=0;		
			}	
};
//-----------------------------------------------------------------------------------------------------------------
//Clase Arbol

template<class T>
class Arbol{
	public:
		int nodos_totales = 0;
		NodoNC<T>* raiz;
	public:
	
		void Iniciar();
		bool Vacio();
		void PonerRaiz(T dato);
		NodoNC<T>* Raiz();
		NodoNC<T>* HijoMasIzq(NodoNC<T>* nodo);
		NodoNC<T>* HermanoDer(NodoNC<T>* nodo);
		T Etiqueta(NodoNC<T>* nodo);
		void ModificarEtiqueta(NodoNC<T>* nodo,T dato);
		NodoNC<T>* AgregarUltimoHijo(NodoNC<T>* nodo, T dato);
		NodoNC<T>* AgregarHijo(NodoNC<T>* nodo, T dato);
		int NumNodos();
		NodoNC<T>* Padre(NodoNC<T>* nodo);
		NodoNC<T>* PadreR(NodoNC<T>* nodo, NodoNC<T>* nodo_Padre);
		int NumHijos(NodoNC<T>* nodo);
		void BorrarNodoHoja(NodoNC<T>* nodo);
		void BorrarNodoHojaR(NodoNC<T>* nodo, NodoNC<T>* actual);
		bool EsHoja(NodoNC<T>* nodo); 
		void Destruir();
		void DestruirR(NodoNC<T>* nodo, NodoNC<T>* anterior);
		void Vaciar();
		//void run();
		void RecorrerArbol(NodoNC<T>* nodo);
		
};


//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Inicializa A como árbol vacío

  Requiere: A no inicializado o destruido
  Parametros: Arbol
  Retorna: N/A
  Modifica: Arbol
*/
template<class T>
	void Arbol<T>::Iniciar(){
		raiz = 	NULL;
	}
	
//--------------------------------------------------------------

/*
  Funcion: Devuelve verdadero si A está vacío y falso si A no está vacío
  Requiere: Arbol inicializado.
  Parametros: Arbol
  Retorna: verdadero si esta vacio, falso si arbol contiene elementos.
  Modifica: N/A
*/	
	template<class T>
	bool Arbol<T>::Vacio(){
		bool es_vacio = false;
		if(raiz == NULL){
			es_vacio = true;
		}
		return es_vacio; 
	}

//--------------------------------------------------------------

/*
  Funcion: Agrega una raiz al arbol
  Requiere: Arbol inicializado
  Parametros: elemento, Arbol
  Retorna: N/A
  Modifica: Arbol
*/
	template<class T>
	void Arbol<T>::PonerRaiz(T dato){
		NodoNC<T>* nuevo = new NodoNC<T>(dato);
		raiz = nuevo;		
		nodos_totales++;
	}

//--------------------------------------------------------------

/*
  Funcion: Siempre devuelve el nodo raiz
  Requiere: Arbol inicializado
  Parametros: Arbol
  Retorna: retorna nodo
  Modifica: N/A
*/
	template<class T>
	NodoNC<T>* Arbol<T>::Raiz(){
		return raiz;
	}

//--------------------------------------------------------------

/*
  Funcion: Devuelve el hijo mas izquierdo del nodo digitado
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo y Arbol
  Retorna: hijo mas izquierdo de nodo digitado
  Modifica: N/A
*/
	template<class T>
	NodoNC<T>* Arbol<T>::HijoMasIzq(NodoNC<T>* nodo){
		return nodo->primerHijo;
	}

//--------------------------------------------------------------

/*
  Funcion: Devuelve el hermano derecho del nodo digitado
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo y Arbol
  Retorna: hermano derecho de nodo digitado
  Modifica: N/A
*/
	template<class T>
	NodoNC<T>* Arbol<T>::HermanoDer(NodoNC<T>* nodo){
		return nodo->hermano_derecho;
	}

//--------------------------------------------------------------

/*
  Funcion: Devuelve la etiqueta del nodo digitado
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo y Arbol
  Retorna: etiqueta
  Modifica: N/A
*/
	template<class T>
	T Arbol<T>::Etiqueta(NodoNC<T>* nodo){
		return nodo->etiqueta;
	}

//--------------------------------------------------------------

/*
  Funcion: Modificar etiqueta de un nodo determinado
  Requiere: nodo valido, arbol inicializado
  Parametros: nodo, elemento, Arbol
  Retorna: N/A
  Modifica: Arbol
*/
	template<class T>
	void Arbol<T>::ModificarEtiqueta(NodoNC<T>* nodo,T dato){
		nodo->etiqueta = dato;
	}

//--------------------------------------------------------------

/*
  Funcion: Agrega un hijo con etiqueta e al nodo n en la última 
  posición(la más a la derecha).
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo, elemento, Arbol
  Retorna: N/A
  Modifica: Arbol
*/
	template<class T>
	NodoNC<T>* Arbol<T>::AgregarUltimoHijo(NodoNC<T>* nodo, T dato){
		
		NodoNC<T>* nod;
		nodo->num_hijos++;
		
		if(nodo->primerHijo != NULL){
			nodo = nodo->primerHijo;
			while(nodo->hermano_derecho != NULL){
				nodo = nodo->hermano_derecho;
			}
			nodo->hermano_derecho = new NodoNC<T>(dato);
			nod = nodo->hermano_derecho;
		}else{
			nodo->primerHijo = new NodoNC<T>(dato);
			nod = nodo->primerHijo;
		}
		
		nodos_totales++;
		return nod;
	}	

//--------------------------------------------------------------

/*
  Funcion: Agrega un hijo con etiqueta e al nodo n. Además, devuelve 
  el nodo creado
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo, elemento, Arbol
  Retorna: N/A
  Modifica: Arbol
*/
	template<class T>
	NodoNC<T>* Arbol<T>::AgregarHijo(NodoNC<T>* nodo, T dato){
		
		NodoNC<T>* nod;
		nodo->num_hijos++;
		
		if(nodo->primerHijo != NULL){
			NodoNC<T>* nod_aux;
			
			nod_aux = nodo->primerHijo;
			nodo->primerHijo = new NodoNC<T>(dato);
			nodo->primerHijo->hermano_derecho = nod_aux;
			nod = nodo->primerHijo;
		}else{
			nodo->primerHijo = new NodoNC<T>(dato);
			nod = nodo->primerHijo;
		}
		
		nodos_totales++;
		return nod;
	}	

//--------------------------------------------------------------

/*
  Funcion: retorna el numero de nodos
  Requiere: Arbol inicializado y con elementos
  Parametros: Arbol
  Retorna: numero de nodos del Arbol
  Modifica: N/A
*/
	template<class T>
	int Arbol<T>::NumNodos(){
		return nodos_totales;
	}

//--------------------------------------------------------------

/*
  Funcion: Devuelve el padre de nodo(devuelve nodo)
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo y Arbol
  Retorna: N/A
  Modifica: N/A
*/
	template<class T>
	NodoNC<T>* Arbol<T>::Padre(NodoNC<T>* nodo){
		NodoNC<T>* nod = NULL;
		
		if (Vacio() != true){
			nod = PadreR(nodo, raiz);
		}
		
		return nod;
	}


	template<class T>
	NodoNC<T>* Arbol<T>::PadreR(NodoNC<T>* nodo,NodoNC<T>* nodo_Padre){
		NodoNC<T>* n1;
		NodoNC<T>* n2;
		NodoNC<T>* padre = NULL;
		
		n1 = HijoMasIzq(nodo_Padre);
		n2 = n1;
		
		while(n2 != NULL && padre == NULL ){

			if(nodo == n2){
				padre = nodo_Padre;
			}
			n2 = HermanoDer(n2);
		}
		
		while (n1 != NULL && padre == NULL){
			padre = PadreR(nodo, n1);
			n1 = HermanoDer(n1);
		}
		
		return padre;
	}

//--------------------------------------------------------------

/*
  Funcion: Devuelve el numero de hijos que tiene un nodo
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo y arbol
  Retorna: numero de hijos del nodo
  Modifica: N/A
*/
	template<class T>
	int Arbol<T>::NumHijos(NodoNC<T>* nodo){
		return nodo->num_hijos;
	}
	

//--------------------------------------------------------------

/*
  Funcion: Borra un nodo hoja del arbol
  Requiere: nodo valido, es decir un nodo hoja, ademas requiere arbol inicializado
  Parametros: nodo, Arbol
  Retorna: N/A
  Modifica: Arbol
*/
	bool borrar = true;
	template<class T>
	void Arbol<T>::BorrarNodoHoja(NodoNC<T>* nodo){
		borrar = true;
		NodoNC<T>* nod = NULL;
		
		if (Vacio() != true){
			BorrarNodoHojaR(nodo, raiz);
			nodos_totales--;
		}
	}

	template<class T>
	void Arbol<T>::BorrarNodoHojaR(NodoNC<T>* nodo, NodoNC<T>* actual){
		NodoNC<T>* n1;
		NodoNC<T>* n2;
		
		n1 = actual->primerHijo;
		n2 = n1;
		
		if(n1 == nodo){
			Padre(nodo)->num_hijos--;
			NodoNC<T>* aux1 = n1->hermano_derecho;
			delete actual->primerHijo;
			actual->primerHijo = aux1;
			borrar = false;
		}
		while (n1 != NULL && borrar != false){
			BorrarNodoHojaR(nodo, n1);
			n2 = n1;
			n1 = HermanoDer(n1);
			if(n1 == nodo){
				Padre(nodo)->num_hijos--;
				NodoNC<T>* aux1 = n1->hermano_derecho;
				free(n1);
				n2->hermano_derecho = aux1;
				borrar = false;
			}
		}
	}
	
//--------------------------------------------------------------

/*
  Funcion: Devuelve verdadero si un nodo es hoja y falso si no lo es
  Requiere: Arbol incializado y nodo valido
  Parametros: el nodo a analizar y el Arbol
  Retorna: verdadero si nodo es hoja, falso si no es hoja
  Modifica: N/A
*/
	template<class T>
	bool Arbol<T>::EsHoja(NodoNC<T>* nodo){
		bool hoja = false;
		if(nodo->primerHijo == NULL){
			hoja = true;
		}
		return hoja;
	}
	

//--------------------------------------------------------------

/*
Funcion: Destruye el árbol A y lo deja inutilizable
Requiere: Requiere: A inicializado.
Parametros: A (tipo árbol)
Retorna: N/A
Modifica: A
*/
	template<class T>
	void Arbol<T>::Destruir(){
		if(Vacio() != true){
			DestruirR(raiz, raiz);
			nodos_totales = 0;
		}
	}
	
	template<class T>
	void Arbol<T>::DestruirR(NodoNC<T>* nodo,NodoNC<T>* anterior){
		
		while(nodo->primerHijo != NULL){
			DestruirR(nodo->primerHijo, nodo);
		}
		
		if(nodo->hermano_derecho == NULL){
			anterior->hermano_derecho = NULL;
			anterior->primerHijo = NULL;
			cout<<"Borre: "+nodo->etiqueta<<endl;
			delete nodo;
		}else{
			
			DestruirR(nodo->hermano_derecho, nodo);
			
			if(nodo->primerHijo == NULL && nodo->hermano_derecho == NULL){
				anterior->primerHijo = NULL;
				cout<<"Borre2: "+nodo->etiqueta<<endl;
				delete nodo;
			}
			
		}
		
	}
	

//--------------------------------------------------------------
/*
  Funcion: Hace que A quede vacío
  Requiere: A inicializado.
  Parametros: Arbol
  Retorna: N/A
  Modifica: Arbol
*/
	template<class T>
	void Arbol<T>::Vaciar(){
		
	}
	
//--------------------------------------------------------------

/*
  Funcion: Recorrer el arreglo arbol para poder mostrar cada uno de sus nodos
  Requiere: Arbol inicializado y con elementos
  Parametros: Arbol
  Retorna: N/A
  Modifica: N/A
*/
	template<class T>
	void Arbol<T>::RecorrerArbol(NodoNC<T>* nodo){
		cout<<nodo->etiqueta<<endl;
	
		if(nodo->num_hijos>0){
			NodoNC<T>* i = nodo->primerHijo;
			while(i != NULL){
				RecorrerArbol(i);
				i = i->hermano_derecho;
			}
		}
	}

//--------------------------------------------------------------

/*
template<class T, class K>
void Arbol<T,K>::run(){
	Arbol<T,K> arbol;	
	arbol.Iniciar();
	arbol.PonerRaiz("D");
	arbol.AgregarHijo(arbol.raiz, "A");
	arbol.AgregarUltimoHijo(arbol.raiz, "V");
	arbol.AgregarHijo(arbol.raiz->primerHijo, "B");
	arbol.AgregarHijo(arbol.raiz->primerHijo, "I");
	arbol.AgregarHijo(arbol.raiz->primerHijo->hermano_derecho, "J");
	arbol.AgregarUltimoHijo(arbol.raiz->primerHijo->hermano_derecho, "U");
	cout<<"hermano de "+arbol.raiz->primerHijo->etiqueta;
	cout<<arbol.raiz->primerHijo->hermano_derecho->etiqueta<<endl;
	cout<<"primer impresion"<<endl;
	arbol.recorrer(arbol.raiz);
}
*/
