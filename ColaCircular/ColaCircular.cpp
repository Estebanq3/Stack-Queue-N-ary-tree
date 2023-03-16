#include <iostream>
#include <string>
#include <stdlib.h>
#define max 10000
using namespace std;

//-----------------------------------------------------------------------------------------------------------------
//Struct para definir cola

typedef struct {
  int final;
  int inicio;
  int numElem;
  string vector[max];
} queue;

//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Retorna el numero de elementos de la cola.
  Requiere: Cola inicializada.
  Parametros: Cola.
  Retorna: El numero de elementos de la cola.
  Modifica: N/A
*/

int NumElem(queue Cola){
    if(Cola.final == Cola.inicio){
      Cola.numElem = 1;
      if(Cola.inicio == -1 && Cola.final == -1){
          Cola.numElem = 0;
      }
    }
    else{
        if(Cola.final > Cola.inicio){
          Cola.numElem = Cola.final+1; //detalle
        }else{
          Cola.numElem = (max-Cola.inicio)+(Cola.final+1);
        }
    }

    cout  << "***** Inicio: " << Cola.inicio <<  " Final: " << Cola.final << endl;
    return Cola.numElem;
}

//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Inicializa la cola con 0 elementos, el inicio y el frente los establece en -1.
  Requiere: N/A
  Parametros: Cola.
  Retorna: N/A
  Modifica: Cola
*/

void inicializar(queue &Cola) {
  Cola.final = -1;
  Cola.inicio = -1;
  Cola.numElem = 0;
}

//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Devuelve verdadero si la cola esta vacia, falso si no lo esta
  Requiere: Cola inicializada
  Parametros: Cola.
  Retorna: Estado de la cola.
  Modifica: N/A
*/

bool estaVacia(queue Cola) {
  if(Cola.numElem == 0) {
    return true;
  }
  return false;
}

//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Se encarga de eliminar todos los elementos de la cola, logicamente, no fisicamente.
  Requiere: cola inicializada.
  Parametros: Cola.
  Retorna: N/A
  Modifica: Cola
*/

void vaciar(queue &Cola) {
  cout << "Se ha vaciado la cola" <<endl;
  Cola.numElem = 0;
  Cola.final = -1;
  Cola.inicio = -1;
}

//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Destruye la cola dejandola inutilizable.
  Requiere: Cola inicializada.
  Parametros: Cola.
  Retorna: N/A
  Modifica: Cola
*/

void Destruir(queue &Cola) {
  printf("Se esta destruyendo la cola circular\n");
  delete(&Cola);
}

//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Indica si la cola esta llena
  Requiere: Cola incializada
  Parametros: Cola.
  Retorna: Estado de la cola
  Modifica: N/A
*/

bool estaLlena(queue Cola) {
  if(Cola.numElem = max) {
    return true;
  }
  return false;
}

//-----------------------------------------------------------------------------------------------------------------

 // Agrega un elemento a la cola, se modifica la cola
/*
  Funcion: Agregar un nuevo elemento al final de la cola.
  Requiere: Cola inicializada.
  Parametros: Cola y elemento a insertar, puede ser una letra o numero.
  Retorna: N/A
  Modifica: Cola
*/
template <class T>
void encolar(queue &Cola, T elemento) {

    if(estaVacia(Cola)) { //Si es la primera vez que se mete algo, incrementamos inicio y no se vuelve a realizar mas
      cout << "Agregando primer elemento" << endl;
      Cola.inicio++; //inicio = 0
      Cola.final++; //final = 0
      Cola.vector[Cola.final] = elemento;
      cout << "Encolando: <" << elemento << ">" << endl;
      Cola.numElem++;
      Cola.numElem = NumElem(Cola);

    }else{

        if(Cola.final+1 == max-1){
              Cola.final++;
              cout<< "Agregando elemento en ultima posicion" <<endl;
              Cola.vector[Cola.final] = elemento;
              cout << "Encolando elemento: <" << elemento << ">" << endl;
              if(Cola.inicio == Cola.final){
                  Cola.inicio = 0;
              }
              Cola.numElem = NumElem(Cola);
              

        }else{
        
              if(Cola.numElem == max){
                    if(Cola.final+1 == max){
                      cout << "Encolando elemento: <" << elemento << ">" << endl;
                        Cola.final = 0;
                        Cola.inicio = 1;
                        cout << Cola.final << Cola.inicio;
                        Cola.vector[Cola.final] = elemento;
                        Cola.numElem = NumElem(Cola);
                    }
                    else{
                        Cola.final++;
                        Cola.inicio++;
                        Cola.vector[Cola.final] = elemento;
                        cout << "Encolando elemento: <" << elemento << ">" << endl;
                        Cola.numElem = NumElem(Cola);
                    }
                  
              }
              else{
                Cola.final++;
                Cola.vector[Cola.final] = elemento;
                cout << "Encolando: <" << elemento << ">" << endl;
                Cola.numElem = NumElem(Cola);
              }
        } 
  }

  cout<< "----------------------------------------------------------------------------------"<<endl;
}

//-----------------------------------------------------------------------------------------------------------------

/*
  Funcion: Borra el elemento que se encuentre al inicio de la cola.
  Requiere: Cola incializada y con al menos un elemento.
  Parametros: Cola.
  Retorna: N/A
  Modifica: Cola
*/
string desencolar(queue &Cola) {
    string desencolado;
    if(!estaVacia(Cola)){

        Cola.numElem = NumElem(Cola);
        cout << "Se ha borrado al: " << Cola.vector[Cola.inicio] << endl;
        desencolado = Cola.vector[Cola.inicio];
        if(Cola.numElem == 1) {
          cout << "Se han eliminado todos los elementos" <<endl;
          vaciar(Cola);
        } else {
            Cola.numElem = NumElem(Cola);
            if(Cola.inicio == max-1){
                Cola.inicio = 0;
            }else{
                Cola.inicio++;
                Cola.numElem = NumElem(Cola);
            }
           //Cuando no haya un solo elemento, se corre el inicio hacia delante
          //Asi se deja vacia la posicion donde estaba para que mas adelante en algun punto se haga circular en encolar...
        }
    }else {
        cout << "Cola vacia no se puede borrar nada" << endl;
    }

  return desencolado;
}

//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Muestra el primer elemento de la cola.
  Requiere: Cola inicializada y con al menos un elemento.
  Parametros: Cola.
  Retorna: N/A
  Modifica: N/A
*/

void mostrarFrente(queue Cola) {
  if(!estaVacia(Cola)) {
    cout << "Frente:" << Cola.vector[Cola.inicio] << endl;
  }
}

//-----------------------------------------------------------------------------------------------------------------
/*
  Funcion: Recorre la cola imprimiendo todos sus elementos, mas puede imprimir elementos que logicamente no
  se encuentran en la cola, puesto que es un operador extra realizado durante las pruebas del programa.
  Puede imprimir datos que son basura.
  Requiere: Cola inicializada y con elementos.
  Parametros: Cola.
  Retorna: N/A
  Modifica: N/A
*/

void recorrerArreglo(queue Cola){
  for(int i = 0; i< max; i++){
    cout << " " << Cola.vector[i];
  }
  cout<< endl;
}

//-----------------------------------------------------------------------------------------------------------------
int main() {

  queue ColaCircular;
  inicializar(ColaCircular);
  NumElem(ColaCircular);

  encolar(ColaCircular, '1');
  encolar(ColaCircular, "b");
  encolar(ColaCircular, "c");

  desencolar(ColaCircular);
  mostrarFrente(ColaCircular);

  
  vaciar(ColaCircular);
  encolar(ColaCircular, "1");
  encolar(ColaCircular, "2");
  //recorrerArreglo(ColaCircular);
  encolar(ColaCircular, "3");
  //recorrerArreglo(ColaCircular);
  
  mostrarFrente(ColaCircular);
  encolar(ColaCircular, "A");
  //recorrerArreglo(ColaCircular);
  mostrarFrente(ColaCircular);

  Destruir(ColaCircular);
  
  

  return 0;
}