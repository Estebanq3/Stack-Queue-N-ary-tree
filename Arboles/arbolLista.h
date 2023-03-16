#include<iostream>
using namespace std;
template<class T>

class NodoA{
	public:
	class Lista{
		public:
		class NodoL{	
		public:
		NodoL * siguiente;
		NodoA<T> * nodo;
		NodoL(NodoA<T>* nodo){
			this->nodo=nodo;
			this->siguiente=nullptr;
		}	
		NodoA RecuperarNodo(){
			return this->nodo;
		}
		NodoL getSiguiente(){
		return this->siguiente;	
		}
		T Etiqueta(){
			return this->nodo->Etiqueta();
		}
		
		
	};
		NodoL * primero;
		
		Lista(){
			primero=nullptr;
		
		}
		void setPrimero(NodoL* nodo){
			primero=nodo;
		}
		bool Vacia(){
			bool vacio=false;
			if(primero==nullptr){
				vacio=true;
			}else{
				vacio=false;
			}
			return vacio;
		}
		bool Esta(NodoA<T>* puntero){
			NodoL* actual = nullptr;
			actual=primero;
			bool siEsta=false;
			while(actual!=nullptr&&!siEsta){
				if(actual->nodo==puntero){
					siEsta=true;
				}
				else{
				actual=actual->siguiente;	
				}
				
			}
			
			return siEsta;
			
		}
		int Cantidad(){
			NodoL* actual=primero;
			int contador=0;
			while(actual!=nullptr){
				contador++;
				actual=actual->siguiente();
			}
			return contador;
		}
		void Insertar(NodoA<T>* hijo){
			NodoL* nuevo=new NodoL(hijo);
			nuevo->nodo=hijo;
			if(primero==nullptr){
				primero = nuevo;
				
			}else{
				
			}
		}
		void Destruir(){
			while(primero!=nullptr){
				Borrar(primero);
			}
			delete *this;
		}
		void Vaciar(){
			while(primero->siguiente!=nullptr){
			 Borrar(primero->siguiente);
			
			}
			primero=nullptr;
			
		}
		void Borrar(NodoL* puntero){
			NodoL* actual = new NodoL();
			NodoL* borrado = new NodoL();
			if (puntero == this->primero) {
				borrado = this->primero;
				this->primero=borrado->siguiente;
				delete borrado;			
			}
			else {
				actual = this->primero;
				bool encontrado = false;
				while (actual->siguiente != nullptr && !encontrado) {
					if (puntero == actual->siguiente) {
						borrado = actual->siguiente;
						if (borrado == this->ultimo) {
							actual->siguiente = nullptr;
						}
						else {
						actual->siguiente = borrado->siguiente;
					}
					delete borrado;
					encontrado = true;
				}
				actual = actual->siguiente;
				}
			}	
			
		}
	
};
	public:
		
		T valor;
		NodoA<T>* siguiente;
		Lista* hijos;
		NodoA(){
			this->valor=nullptr;
			siguiente=nullptr;
			hijos=new Lista();
		}
		NodoA(T dato){
			this->valor=dato;
			siguiente=nullptr;
			hijos=new Lista();	
		}
		T getEtiqueta(){
		return this->valor;
	    }
	    void setSiguiente(NodoA<T>*s){
	    	siguiente=s;
	    }
		
	
	
};
template<class T>
class Arbol {
//-----------------------------------------------------------------------------------------------------------------
	
	public:
	NodoA<T>* LaRaiz;
	int NumeroNodos=0;
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Inicializa A como √°rbol vac√≠o

  Requiere: A no inicializado o destruido
  Parametros: Arbol
  Retorna: N/A
  Modifica: Arbol
*/
	void Iniciar(){
	LaRaiz=nullptr;	
	}
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Hace que A quede vacio
  Requiere: A inicializado.
  Parametros: Arbol
  Retorna: N/A
  Modifica: Arbol
*/
//-----------------------------------------------------------------------------------------------------------------
    void Vaciar(){
    NodoA<T>* actual;
    typename NodoA<T>::Lista::NodoL* actual2; 
	while(LaRaiz!=nullptr){
		actual=LaRaiz;
		while(actual->hijos->primero!=nullptr){
			actual2=actual->hijos->primero;
			LaRaiz=LaRaiz->siguiente;
			delete actual2;
		}
		LaRaiz=actual->siguiente;
		delete actual;
	}		
    }
//-----------------------------------------------------------------------------------------------------------------
 /*
  Funcion: Devuelve verdadero si A esta° vacio≠o y falso si A no esta° vacio
  Requiere: Arbol inicializado.
  Parametros: Arbol
  Retorna: verdadero si esta vacio, falso si arbol contiene elementos.
  Modifica: N/A
*/
	bool Vacio(){
		bool es_vacio=false;
		if(this->LaRaiz==nullptr){
			es_vacio=true;
		} 
		return es_vacio;
	}
//-----------------------------------------------------------------------------------------------------------------
	
	void Destruir(){
	NodoA<T>* actual;
	while(LaRaiz!=nullptr){
		actual=LaRaiz;
		LaRaiz=actual->siguiente;
		delete actual;
	}	
//-----------------------------------------------------------------------------------------------------------------
	/*
  Funcion: Agrega una raiz al arbol
  Requiere: Arbol inicializado
  Parametros: elemento, Arbol
  Retorna: N/A
  Modifica: Arbol
*/
	}
	void PonerRaiz(T etiqueta){
		NodoA<T>* nuevo= new NodoA<T>(etiqueta);
		LaRaiz=nuevo;
		NumeroNodos++;
	}
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Siempre devuelve el nodo raiz
  Requiere: Arbol inicializado
  Parametros: Arbol
  Retorna: retorna nodo (posicion de nodo)
  Modifica: N/A
*/	
	NodoA<T>* Raiz(){
		return LaRaiz;
	}
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Devuelve la etiqueta del nodo digitado
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo(posicion de nodo) y Arbol
  Retorna: etiqueta
  Modifica: N/A
*/	
	T Etiqueta(NodoA<T>* nodo){
		return nodo->getEtiqueta();
	}
//-----------------------------------------------------------------------------------------------------------------
	/*
  Funcion: Devuelve verdadero si un nodo es hoja y falso si no lo es
  Requiere: Arbol incializado y nodo valido
  Parametros: el nodo(posicion de nodo) a analizar y el Arbol
  Retorna: verdadero si nodo es hoja, falso si no es hoja
  Modifica: N/A
*/
	bool EsHoja(NodoA<T>* hoja){
		bool es_Hoja=false;
		if(hoja->hijos->primero!=nullptr){
			es_Hoja=false;
		}else{
			es_Hoja=true;
		}
			
		return es_Hoja;
	}
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Devuelve el numero de hijos que tiene un nodo
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo(posicion de nodo) y arbol
  Retorna: numero de hijos del nodo
  Modifica: N/A
*/
    int NumHijos(NodoA<T>* nodo){
    	int num=0;
    	typename NodoA<T>::Lista::NodoL * recorrido=nodo->hijos->primero;
    	if(recorrido!=nullptr){
    	while(recorrido!=nullptr){
    	num++;
		recorrido=recorrido->siguiente;	
    	}	
    	}else{
    	num=0;	
    	}
		
    	return num;
    }
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Modificar etiqueta de un nodo determinado
  Requiere: nodo valido, arbol inicializado
  Parametros: nodo(posicion nodo), elemento, Arbol
  Retorna: N/A
  Modifica: Arbol
*/	
	void ModificarEtiqueta(NodoA<T>* nodo,T dato){
		nodo->valor=dato;
	}
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Borra un nodo hoja del arbol
  Requiere: nodo valido, es decir un nodo hoja, ademas requiere arbol inicializado
  Parametros: nodo (posicion de nodo), Arbol
  Retorna: N/A
  Modifica: Arbol
*/
	void BorrarNodoHoja(NodoA<T>* nodo){
		typename NodoA<T>::Lista::NodoL * borrado=nodo->hijos->primero;
		NodoA<T> * recorrido=Raiz();
		typename NodoA<T>::Lista::NodoL * recorridohijo=nodo->hijos->primero;
		bool encontrado=false;
		while(recorrido!=nullptr&&!encontrado){
			if(recorrido->hijos->primero!=nullptr){
				if(recorrido->hijos->primero->nodo==nodo){
					encontrado=true;
					NumeroNodos--;
					recorrido->hijos->primero=recorrido->hijos->primero->siguiente;
					delete nodo;
				}else{
					recorridohijo=recorrido->hijos->primero;
					while(!encontrado&&recorridohijo->siguiente!=nullptr){
						if(recorridohijo->siguiente->nodo==nodo){
							encontrado=true;
							NumeroNodos--;
							borrado=recorridohijo->siguiente;
							recorridohijo->siguiente=recorridohijo->siguiente->siguiente;
							delete borrado;
						}else{
							recorridohijo=recorridohijo->siguiente;
						}
					}
				}
			}
			if(recorrido->siguiente!=nodo){
				recorrido=recorrido->siguiente;
			}else{
				recorrido->siguiente=recorrido->siguiente->siguiente;
				recorrido=recorrido->siguiente;
			}
		}
		delete nodo;
	}
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Agregar de ultimo un hijo a un nodo
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo (posicion nodo), elemento, Arbol
  Retorna: N/A
  Modifica: Arbol
*/
	NodoA<T>* AgregarUltimoHijo(NodoA<T>* nodo, T dato){
	
		NodoA<T>*nuevo =new NodoA<T>(dato);
		nuevo->siguiente=Raiz()->siguiente;
		LaRaiz->siguiente=nuevo;
		typename NodoA<T>::Lista::NodoL * nuevoL=new typename NodoA<T>::Lista::NodoL(nuevo);
		if(nodo->hijos->primero==nullptr){
			nodo->hijos->primero=nuevoL;
		}else{
			typename NodoA<T>::Lista::NodoL * recorrido= nodo->hijos->primero;
			bool encontrado=false;
			while(recorrido!=nullptr&&!encontrado){
				if(recorrido->siguiente==nullptr){
					recorrido->siguiente=nuevoL;
					encontrado=true;
				}else{
					recorrido=recorrido->siguiente;
				}
				
			}
		}
	
		NumeroNodos++;
	
		return nuevo;
	}
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Agregar un hijo a un nodo
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo (posicion nodo), elemento, Arbol
  Retorna: N/A
  Modifica: Arbol
*/
	NodoA<T>* AgregarHijo(const NodoA<T>* nodo,T dato){
	
		NodoA<T>* nuevo =new NodoA<T>(dato);
		nuevo->siguiente=Raiz()->siguiente;
		LaRaiz->siguiente=nuevo;
		typename NodoA<T>::Lista::NodoL * nuevoL=new typename NodoA<T>::Lista::NodoL(nuevo);
		nuevoL->siguiente=nodo->hijos->primero;
		nodo->hijos->primero=nuevoL;
	
		NumeroNodos++;
		return nuevo;
	}
//-----------------------------------------------------------------------------------------------------------------

	void AgregarHijoL(const NodoA<T>* padre,NodoA<T>* nodo){

		typename NodoA<T>::Lista::NodoL * nuevo=new typename NodoA<T>::Lista::NodoL(nodo);
		nuevo->siguiente=nodo->hijos->primero;
		nodo->hijos->primero=nuevo;

	}
//-----------------------------------------------------------------------------------------------------------------

	void AgregarUltimoHijoL(){
		
	}
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Devuelve el hijo mas izquierdo del nodo digitado
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo(posicion de nodo) y Arbol
  Retorna: hijo mas izquierdo de nodo digitado
  Modifica: N/A
*/
	NodoA<T>* HijoMasIzq(NodoA<T>* nodoPadre){
		return nodoPadre->hijos->primero->nodo;
	}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: retorna el numero de nodos
  Requiere: Arbol inicializado y con elementos
  Parametros: Arbol
  Retorna: numero de nodos del Arbol
  Modifica: N/A
*/
	int NumNodos(){
		return NumeroNodos;
	}
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Devuelve el hermano derecho del nodo digitado
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo(posicion de nodo) y Arbol
  Retorna: hermano derecho de nodo digitado
  Modifica: N/A
*/
	NodoA<T>* HermanoDer(NodoA<T>* nodo){
	typename NodoA<T>::Lista::NodoL * recorrido= Padre(nodo)->hijos->primero;
	NodoA<T>* hermano=nullptr;
	if(nodo!=Raiz()){
		while(recorrido->nodo!=nodo&&recorrido!=nullptr){
			recorrido=recorrido->siguiente;
		}
		
		if(recorrido!=nullptr&&recorrido->siguiente!=nullptr){
		
			hermano=recorrido->siguiente->nodo;
		
		}else{
	
			hermano=NULL;
		}
	}
	return hermano;
	}
//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Devuelve el padre de nodo(devuelve nodo, es decir la posicion en la que se encuentra el padre)
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo(posicion de nodo) y Arbol
  Retorna: N/A
  Modifica: N/A
*/
	
	NodoA<T>* Padre(NodoA<T>* nodo){
		NodoA<T>* actual=Raiz();
		typename NodoA<T>::Lista::NodoL* actualHijo=nullptr;
		bool encontrado=false;
		if(nodo!=Raiz()){
			while(actual!=nullptr&&!encontrado){
				if(actual->hijos->primero!=nullptr){
					actualHijo=actual->hijos->primero;
					while(actualHijo!=nullptr&&!encontrado){
						if(actualHijo->nodo==nodo){
							encontrado=true;
						}else{
							actualHijo=actualHijo->siguiente;
						}
					}
				}
				if(!encontrado){
					actual=actual->siguiente;
				}
			}
		}
		else{
			actual=nullptr;
		}
		
	return actual;
	}
	
};
//-----------------------------------------------------------------------------------------------------------------


