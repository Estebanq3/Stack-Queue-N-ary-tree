#include <iostream>
#include <string>
#include <stdlib.h>
#define max 30
using namespace std;

//-----------------------------------------------------------------------------------------------------------------
template<typename K>
class Arbol{
	public:
		
		Arbol();
		void Iniciar();
		~Arbol() = default;
		void Vaciar();
		bool Vacio();
		void PonerRaiz(K elemento);
		void AgregarHijo(int nodo,K elemento);
		void AgregarUltimoHijo(int nodo,K elemento);
		void BorrarNodoHoja(int nodo);
		void ModificarEtiqueta(int nodo,K elemento);
		int HijoMasIzq(int nodo);
		int HermanoDer(int nodo);
		int Raiz();
		int Padre(int nodo);
		K Etiqueta(int nodo);
		int NumHijos(int nodo);
		bool EsHoja(int nodo);
		int NumNodos();
		void RecorrerArbol(int nodo);

		

	private:
	struct nodo{
		int padre = 0;
		K elemento;
		int numHijos = 0;
	};

	int numElem;
	nodo nodos[max];
		

};


template<typename K>
Arbol<K>::Arbol(){
	numElem = 0;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Inicializa A como árbol vacío

  Requiere: A no inicializado o destruido
  Parametros: Arbol
  Retorna: N/A
  Modifica: Arbol
*/
template<typename K>
void Arbol<K>::Iniciar(){
	//cout << "Inicializando arbol"<< endl;
	numElem = 0;
	
}
//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Hace que A quede vacío
  Requiere: A inicializado.
  Parametros: Arbol
  Retorna: N/A
  Modifica: Arbol
*/
template<typename K>
void Arbol<K>::Vaciar(){
	numElem = 0;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Devuelve verdadero si A está vacío y falso si A no está vacío
  Requiere: Arbol inicializado.
  Parametros: Arbol
  Retorna: verdadero si esta vacio, falso si arbol contiene elementos.
  Modifica: N/A
*/
template<typename K>
bool Arbol<K>::Vacio(){
	if(numElem == 0){
		//cout << "\nArbol esta vacio" << endl;
		return true;
	}else{
		//cout << "Arbol contiene elementos" << endl;
		return false;
	}
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Agrega una raiz al arbol
  Requiere: Arbol inicializado
  Parametros: elemento, Arbol
  Retorna: N/A
  Modifica: Arbol
*/
template<typename K>
void Arbol<K>::PonerRaiz(K elemento){
	nodos[0].elemento = elemento;
	nodos[0].padre = NULL;
	numElem++;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Agregar un hijo a un nodo
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo (posicion nodo), elemento, Arbol
  Retorna: N/A
  Modifica: Arbol
*/
template<typename K>
void Arbol<K>::AgregarHijo(int nodo, K elemento){
	nodos[numElem].elemento = elemento;
	nodos[numElem].padre = nodo;
	nodos[nodo].numHijos++;
	//cout << "Agregando hijo " << elemento <<  " a: " << Arbol.nodos[nodo].elemento <<endl;
	//cout << "Agregando hijo " << elemento <<  " a: " << nodo <<endl;
	numElem++;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Borra un nodo hoja del arbol
  Requiere: nodo valido, es decir un nodo hoja, ademas requiere arbol inicializado
  Parametros: nodo (posicion de nodo), Arbol
  Retorna: N/A
  Modifica: Arbol
*/
template<typename K>
void Arbol<K>::BorrarNodoHoja(int nodo){
	nodos[nodos[nodo].padre].numHijos--;
	int contador = nodo+1;
	int existePadre = 0;
	while(contador < numElem && existePadre != 1){
		if(nodos[contador].numHijos > 0){
			existePadre = 1;
		}
		contador++;
	}

	if(existePadre == 0){
		for(int i = nodo+1; i< numElem; i++){
			nodos[i-1].elemento = nodos[i].elemento;
			nodos[i-1].padre = nodos[i].padre;
			nodos[i-1].numHijos = nodos[i].numHijos;
		}
		numElem--;
	}
	else{

		bool unPadre = 0;
		int contadorModificaciones = nodo+1;

		while(contadorModificaciones< numElem && unPadre != 1){
			if(nodos[contadorModificaciones].numHijos == 0){
				nodos[contadorModificaciones-1].elemento = nodos[contadorModificaciones].elemento;
				nodos[contadorModificaciones-1].padre = nodos[contadorModificaciones].padre;
				nodos[contadorModificaciones-1].numHijos = nodos[contadorModificaciones].numHijos;
				contadorModificaciones++;
			}
			else{
				unPadre = 1;
			}
		}

		while(contadorModificaciones < numElem){
			if(nodos[contadorModificaciones].padre > nodo){
				nodos[contadorModificaciones].padre--;
				nodos[contadorModificaciones-1].elemento = nodos[contadorModificaciones].elemento;
				nodos[contadorModificaciones-1].padre = nodos[contadorModificaciones].padre;
				nodos[contadorModificaciones-1].numHijos = nodos[contadorModificaciones].numHijos;
				contadorModificaciones++;
			}
			else{
				nodos[contadorModificaciones-1].elemento = nodos[contadorModificaciones].elemento;
				nodos[contadorModificaciones-1].padre = nodos[contadorModificaciones].padre;
				nodos[contadorModificaciones-1].numHijos = nodos[contadorModificaciones].numHijos;
				contadorModificaciones++;
			}
		}
		numElem--;

	}
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Modificar etiqueta de un nodo determinado
  Requiere: nodo valido, arbol inicializado
  Parametros: nodo(posicion nodo), elemento, Arbol
  Retorna: N/A
  Modifica: Arbol
*/
template<typename K>
void Arbol<K>::ModificarEtiqueta(int nodo, K elemento){
	nodos[nodo].elemento = elemento;
}

//-----------------------------------------------------------------------------------------------------------------


/*
  Funcion: Devuelve el hijo mas izquierdo del nodo digitado
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo(posicion de nodo) y Arbol
  Retorna: hijo mas izquierdo de nodo digitado
  Modifica: N/A
*/
template<typename K>
int Arbol<K>::HijoMasIzq(int nodo){
	for(int i = nodo+1; i< numElem; i++){
		if(nodos[i].padre == nodo){
			return i;
		}
	}
	return NULL;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Devuelve el hermano derecho del nodo digitado
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo(posicion de nodo) y Arbol
  Retorna: hermano derecho de nodo digitado
  Modifica: N/A
*/
template<typename K>
int Arbol<K>::HermanoDer(int nodo){
	for(int i = nodo+1; i< numElem; i++){
		if(nodos[i].padre == nodos[nodo].padre){
			return i;
		}
	}
	return NULL;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Siempre devuelve el nodo raiz
  Requiere: Arbol inicializado
  Parametros: Arbol
  Retorna: retorna nodo (posicion de nodo)
  Modifica: N/A
*/
template<typename K>
int Arbol<K>::Raiz(){
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Devuelve el padre de nodo(devuelve nodo, es decir la posicion en la que se encuentra el padre)
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo(posicion de nodo) y Arbol
  Retorna: N/A
  Modifica: N/A
*/
template<typename K>
int Arbol<K>::Padre(int nodo){
	return nodos[nodo].padre;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Devuelve la etiqueta del nodo digitado
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo(posicion de nodo) y Arbol
  Retorna: etiqueta
  Modifica: N/A
*/
template<typename K>
K Arbol<K>::Etiqueta(int nodo){
	return nodos[nodo].elemento;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Devuelve el numero de hijos que tiene un nodo
  Requiere: Arbol inicializado y nodo valido
  Parametros: nodo(posicion de nodo) y arbol
  Retorna: numero de hijos del nodo
  Modifica: N/A
*/
template<typename K>
int Arbol<K>::NumHijos(int nodo){
	int numHijos = 0;
	for(int i = nodo+1; i< numElem; i++){
		if(nodos[i].padre == nodo){
			numHijos++;
		}
	}
	return numHijos;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Devuelve verdadero si un nodo es hoja y falso si no lo es
  Requiere: Arbol incializado y nodo valido
  Parametros: el nodo(posicion de nodo) a analizar y el Arbol
  Retorna: verdadero si nodo es hoja, falso si no es hoja
  Modifica: N/A
*/
template<typename K>
bool Arbol<K>::EsHoja(int nodo){
	for(int i = nodo+1; i< numElem; i++){
		if(nodos[i].padre == nodo){
			return false;
		}
	}
	return true;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: retorna el numero de nodos
  Requiere: Arbol inicializado y con elementos
  Parametros: Arbol
  Retorna: numero de nodos del Arbol
  Modifica: N/A
*/
template<typename K>
int Arbol<K>::NumNodos(){
	return numElem;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Recorrer el arreglo arbol para poder mostrar cada uno de sus nodos
  Requiere: Arbol inicializado y con elementos
  Parametros: Arbol
  Retorna: N/A
  Modifica: N/A
*/
template<typename K>
void Arbol<K>::RecorrerArbol(int nodo){
	if(numElem == 0){
		cout << "Arbol vacio" << endl;
	}
	for(int i = 0; i < numElem;i++){
		cout<< " "<< "[" << i << "]" << nodos[i].elemento <<"[" << nodos[i].padre << "]" <<"TH:" << nodos[i].numHijos << endl;
	}
	cout << endl;
}

//-----------------------------------------------------------------------------------------------------------------

template<typename K>
void Arbol<K>::AgregarUltimoHijo(int nodo,K elemento){
	nodos[numElem].elemento = elemento;
	nodos[numElem].padre = nodo;
	nodos[nodo].numHijos++;
	numElem++;
}

//-----------------------------------------------------------------------------------------------------------------
/*
int main(){
	/*
	Arbol arbol;
	 	Cola cola;
	arbol.Iniciar();
	//arbol.Vacio();
	arbol.PonerRaiz("D");
	arbol.AgregarHijo(0,"B");
	arbol.AgregarHijo(0,"D");
	arbol.AgregarHijo(1,"E");
	arbol.AgregarHijo(1,"F");
	arbol.AgregarHijo(2,"H");
	arbol.AgregarHijo(5,"J");
	arbol.AgregarHijo(6,"K");
	arbol.AgregarHijo(2,"G");
	arbol.AgregarHijo(0,"C");
	arbol.AgregarHijo(5,"I");
	
	
	arbol.RecorrerArbol();
	//Destruir(Arbol);

	Arbol<int,char,int> arbol;
	
	arbol.Iniciar();
	arbol.PonerRaiz('D');
	arbol.AgregarHijo(0,'A');
	arbol.AgregarHijo(0,'V');
	arbol.AgregarHijo(1,'I');
	arbol.AgregarHijo(1,'B');

	arbol.AgregarHijo(2,'J');
	arbol.AgregarHijo(2,'U');
	arbol.AgregarHijo(6,'P');
	arbol.AgregarHijo(7,'O');
	arbol.AgregarHijo(7,'L');	
	

	
	
	arbol.RecorrerArbol();
	
	return 0;
*/