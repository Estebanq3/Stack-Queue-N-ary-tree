#include <iostream>
#include <cstring>
#include <string>
#include<stdlib.h>
using namespace std;

template<typename T>
class NodoND{
		public:
			int num_hijos = 0;
			T etiqueta;
			NodoND<T>* primerHijo;
			NodoND<T>* hermano_derecho;
			bool senalar_padre = false;				
			
		public:
			NodoND(T dato){ 
			num_hijos = 0;
			etiqueta = dato;
			hermano_derecho = NULL;
			primerHijo = 0;
			senalar_padre = false;					  
		}	
};

template<typename T>
class Arbol{
	public:

		int nodos_totales = 0;
		NodoND<T>* raiz;
	public:
	
		void Iniciar();
		bool Vacio();
		void PonerRaiz(T dato);
		NodoND<T>* Raiz();
		NodoND<T>* HijoMasIzq(NodoND<T>* nodo);
		NodoND<T>* HermanoDer(NodoND<T>* nodo);
		T Etiqueta(NodoND<T>* nodo);
		void ModificarEtiqueta( NodoND<T>* nodo, T dato);
		NodoND<T>* AgregarUltimoHijo(NodoND<T>* nodo, T dato);
		NodoND<T>* AgregarHijo(NodoND<T>* nodo, T dato);
		int NumNodos();
		NodoND<T>* Padre(NodoND<T>* nodo);
		int NumHijos(NodoND<T>* nodo);
		void BorrarNodoHoja(NodoND<T>* nodo);
		void BorrarNodoHojaR(NodoND<T>* nodo, NodoND<T>* actual);
		bool EsHoja(NodoND<T>* nodo); 
		void Destruir();
		void DestruirR(NodoND<T>* nodo, NodoND<T>* anterior);
		void Vaciar();
		void Recorrer(NodoND<T>* nodo);
		
};


	template<typename T>
	void Arbol<T>::Iniciar(){
		raiz = 	NULL;
	} 
	
	template<typename T>
	bool Arbol<T>::Vacio(){
		bool es_vacio = false;
		if(raiz == NULL){
			es_vacio = true;
		}
		return es_vacio; 
	}

	template<typename T>
	void Arbol<T>::PonerRaiz(T dato){
		NodoND<T>* nuevo= new NodoND<T>(dato);
		raiz = nuevo;		
		nodos_totales++;
	}
	
	template<typename T>
	NodoND<T>* Arbol<T>::Raiz(){
		return raiz;
	}
	
	template<typename T>
	NodoND<T>* Arbol<T>::HijoMasIzq(NodoND<T>* nodo){
		return nodo->primerHijo;
	}
	
	template<typename T>
	NodoND<T>* Arbol<T>::HermanoDer(NodoND<T>* nodo){
		NodoND<T>* nod = NULL;
		if(nodo != NULL){
			if(nodo->senalar_padre == false && nodo != raiz){
				nod = nodo->hermano_derecho;
			}
		}
		return nod;
	}

	template<typename T>
	T Arbol<T>::Etiqueta(NodoND<T>* nodo){
		return nodo->etiqueta;
	}
	
	template<typename T>
	void Arbol<T>::ModificarEtiqueta(NodoND<T>* nodo, T dato){
		nodo->etiqueta = dato;
	}
	
	template<typename T>
	NodoND<T>* Arbol<T>::AgregarUltimoHijo(NodoND<T>* nodo, T dato){
		
		NodoND<T>* nod;
		nodo->num_hijos++;
		
		if(nodo->primerHijo != NULL){
			NodoND<T>* nodaux1;
			nodo = nodo->primerHijo;
			while(nodo->senalar_padre != true){
				nodo = nodo->hermano_derecho;
			}
			nodaux1 = nodo->hermano_derecho;
			nodo->senalar_padre = false;
			nodo->hermano_derecho = new NodoND<T>(dato);
			nodo = nodo->hermano_derecho;
			nodo->senalar_padre = true;
			nodo->hermano_derecho = nodaux1;
			nod = nodo->hermano_derecho;
		}else{
			nodo->primerHijo = new NodoND<T>(dato);
			nodo->primerHijo->senalar_padre = true;
			nodo->primerHijo->hermano_derecho = nodo;
			nod = nodo->primerHijo;
		}
		
		nodos_totales++;
		return nod;
	}	
	
	template<typename T>
	NodoND<T>* Arbol<T>::AgregarHijo(NodoND<T>* nodo, T dato){
		
		NodoND<T>* nod;
		nodo->num_hijos++;
		
		if(nodo->primerHijo != NULL){
			NodoND<T>* nod_aux;
			
			nod_aux = nodo->primerHijo;
			nodo->primerHijo = new NodoND<T>(dato);
			nodo->primerHijo->hermano_derecho = nod_aux;
			nod = nodo->primerHijo;
		}else{
			nodo->primerHijo = new NodoND<T>(dato);
			nodo->primerHijo->senalar_padre = true;
			nodo->primerHijo->hermano_derecho = nodo;
			nod = nodo->primerHijo;
		}
		
		nodos_totales++;
		return nod;
	}	
	
	template<typename T>
	int Arbol<T>::NumNodos(){
		return nodos_totales;
	}

	template<typename T>
	NodoND<T>* Arbol<T>::Padre(NodoND<T>* nodo){
		
		NodoND<T>* padre = NULL;
		
		if (Vacio() != true && nodo != raiz){
			if(nodo->senalar_padre == true){
				padre = nodo->hermano_derecho;
			}else{
				while(nodo->senalar_padre != true){
					nodo = nodo->hermano_derecho;
				}
				padre = nodo->hermano_derecho;
			}
			
		}
		
		return padre;
	}
	
	template<typename T>
	int Arbol<T>::NumHijos(NodoND<T>* nodo){
		return nodo->num_hijos;
	}
	
	bool borrar = true;
	template<typename T>
	void Arbol<T>::BorrarNodoHoja(NodoND<T>* nodo){
		borrar = true;
		NodoND<T>* nod = NULL;
		
		if (Vacio() != true){
			BorrarNodoHojaR(nodo, raiz);
			nodos_totales--;
		}
	}
	
	template<typename T>
	void Arbol<T>::BorrarNodoHojaR(NodoND<T>* nodo, NodoND<T>* actual){
		NodoND<T>* n1;
		NodoND<T>* n2;
		
		n1 = actual->primerHijo;
		n2 = n1;
		
		if(n1 == nodo){
			Padre(nodo)->num_hijos--;
			NodoND<T>* aux1 = n1->hermano_derecho;
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
				NodoND<T>* aux1 = n1->hermano_derecho;
				n2->senalar_padre = n1->senalar_padre;
				delete n1;
				n2->hermano_derecho = aux1;
				borrar = false;
			}
		}
	}
	
	template<typename T>
	bool Arbol<T>::EsHoja(NodoND<T>* nodo){
		bool hoja = false;
		if(nodo->primerHijo == NULL){
			hoja = true;
		}
		return hoja;
	}
	
	template<typename T>
	void Arbol<T>::Destruir(){
		if(Vacio() != true){
			DestruirR(raiz, raiz);
			nodos_totales = 0;
			raiz = NULL;
			delete raiz;
		}
	}
	
	template<typename T>
	void Arbol<T>::DestruirR(NodoND<T>* nodo, NodoND<T>* anterior){
		
		while(nodo->primerHijo != NULL){
			cout<<"PADRE: "+nodo->etiqueta<<endl;
			cout<<"HIJO: "+nodo->primerHijo->etiqueta<<endl;
			DestruirR(nodo->primerHijo, nodo);
		}
		cout<<"-------------------------------------------------------"<<endl;
		if(nodo->senalar_padre == true){
			anterior->hermano_derecho = NULL;
			anterior->primerHijo = NULL;
			anterior->senalar_padre = true;
			cout<<"Borre: "+nodo->etiqueta<<endl;
			delete nodo;
		}else{
			
			if(nodo != raiz){
				DestruirR(nodo->hermano_derecho, nodo);
				
				if(nodo->primerHijo == NULL && nodo->senalar_padre == true){
					anterior->primerHijo = NULL;
					cout<<"Borre2: "+nodo->etiqueta<<endl;
					delete nodo;
				}
			}
			
		}
		
	}
	
	template<typename T>
	void Arbol<T>::Vaciar(){
		
	}
	
	template<typename T>
	void Arbol<T>::Recorrer(NodoND<T>* nodo){
		cout<<nodo->etiqueta<<endl;
	
		if(nodo->num_hijos>0){
			NodoND<T>* i = nodo->primerHijo;
			while(i != NULL){
				Recorrer(i);
				i = i->hermano_derecho;
			}
		}
	}