#include <iostream>
#include <string>
#include <stdlib.h>
#include<conio.h>
//-----------------------------
//Arboles
#include "arregloArbol.h"
//#include "arboln-arioD.h"
//#include "Arbol.h"
//#include "arboln-arioC.h"
//-----------------------------

#include "Cola.h"
#include "Cola.cpp"

using namespace std;

//----------------------------------------------------------------
//Busqueda de hermano izquierdo

bool encontrado;
    template<class T, class K>
    T BusquedaHermanoIzq(T nodo, K Arbol){
        T  nod = NULL;
        encontrado = false;
        if (Arbol.Vacio() != true){
            nod = BusquedaHermanoIzqR(nodo, Arbol.Raiz(),Arbol);
        }
        return nod;
    }

    template<class T, class K>
    T BusquedaHermanoIzqR(T  nodo, T  actual, K Arbol){
        T n1 = NULL;
        T n2 = NULL;
        T hermano = NULL;

        n1 = Arbol.HijoMasIzq(actual);

        if(n1 == nodo){
            encontrado = true;
        }else{
            while (n1!= NULL && encontrado != true){
                hermano = BusquedaHermanoIzqR(nodo,n1,Arbol);
                n2 = n1;
                n1 = Arbol.HermanoDer(n1);
                if(n1 == nodo){
                    hermano = n2;
                    encontrado = true;
                }
            }
        }
        return hermano;
    }

//----------------------------------------------------------------
//Altura Nodo

template<class T, class K>
int AlturaNodoR(T nodo,K Arbol){
	int maximo = 0;
	int minimo = 0;
	if(Arbol.EsHoja(nodo) == true){
		cout << "\nEs hoja" << endl;
		return 0;
	}else{
		
		T n1 = Arbol.HijoMasIzq(nodo);
        T nodoAux2 = NULL;
		while(n1!= NULL){
			cout << "No estoy entrando" << endl;
            minimo = AlturaNodoR(n1,Arbol)+1;
			if(minimo > maximo){
				maximo = minimo;
			}
            nodoAux2 = n1;
			n1 = Arbol.HermanoDer(n1);
		}
	}
	return maximo;
}

template<class T,class K>
void AlturaNodo(T nodo, K Arbol){
	if(Arbol.Vacio() != 1){
		int altura;
		altura = AlturaNodoR(nodo,Arbol);
		cout << "\n Altura: " << altura << endl;
	}
}

//----------------------------------------------------------------
//Etiquetas Repetidas

int contador;
template<class T,class K>
bool EtiquetasRepetidasR(T nodo, string Etiquetas[],int numNodos, K Arbol){
	Etiquetas[contador] = Arbol.Etiqueta(nodo);
	contador++;
	T n1 = Arbol.HijoMasIzq(nodo);
	while(n1 != NULL){
		EtiquetasRepetidasR(n1, Etiquetas,numNodos,Arbol);
		n1 = Arbol.HermanoDer(n1);
	}

	return 0;
}

template<class T>
void EtiquetasRepetidas(T Arbol){
	contador = 0;
	bool repetidos = false;
	string Etiquetas[Arbol.NumNodos()];
	if(Arbol.Vacio() != 1){
		EtiquetasRepetidasR(Arbol.Raiz(),Etiquetas, Arbol.NumNodos(),Arbol);
		
	}
	for(int i = 0; i< Arbol.NumNodos(); i++){
		for(int j = i+1; j<Arbol.NumNodos();j++){
			if(Etiquetas[i] == Etiquetas[j]){
				repetidos = true;
			}
		}
	}

	if(repetidos == 1){
		cout<< "\nExisten etiquetas repetidas"<<endl;
	}
	else{
		cout << "\nNo existen etiquetas repetidas" << endl;
	}
}

//----------------------------------------------------------------
//Profundidad de nodo

template<class T, class K>
int ProfundidadNodo(T nodoBuscado, K Arbol){
	T raiz = Arbol.Raiz();
	T auxiliar = nodoBuscado;
	int profundidad = 0;

	//cout << "Etiqueta: " << Etiqueta(nodoBuscado,Arbol) << endl;
	while(auxiliar!=raiz){
		auxiliar = Arbol.Padre(auxiliar);
		profundidad++;

	}

    cout << "Profundidad del nodo es:" << profundidad;

return profundidad;
}

//----------------------------------------------------------------
//Listar las etiquetas del i-ésimo nivel del árbol haciendo un recorrido en pre-orden

template<class T, class K>
int ListarEtiquetasPreordenR(int nivel_act, T nodo, int i, K Arbol) {
	if(nivel_act == i){
		cout << " Nivel actual:"<< nivel_act << " nodo:" << Arbol.Etiqueta(nodo);	
	}
	
 	T nh = Arbol.HijoMasIzq(nodo);
 		while (nh != NULL ) {
 			ListarEtiquetasPreordenR(nivel_act+1,nh,i,Arbol);
 			nh = Arbol.HermanoDer(nh);
 		}
 	

 	return 0;
} 

template<class T>
int ListarEtiquetasPreorden(int i, T Arbol) {
	if (!Arbol.Vacio()) {
		if( i == 1 ){
			cout << "Nivel actual: " << "1" << " nodo:" << Arbol.Etiqueta(Arbol.Raiz()) << endl;
		}else
 		ListarEtiquetasPreordenR(1,Arbol.Raiz(),i,Arbol);
 	}
    cout<< "Arbol Sebas llego";
return 0;
}

 //----------------------------------------------------------------
//Listar las etiquetas del i-ésimo nivel del árbol haciendo un recorrido por niveles

    template<class T, class K>
    void ListarEtiquetasPorNiveles(int i, T nodo, K Arbol){
        if (Arbol.Vacio() != true){

            if (i == 1){ 
                cout << " \nNivel actual: " << 1 << " nodo:" << Arbol.Etiqueta(Arbol.Raiz()) << endl;
            }
            else{ 
                T nodaux = 0;
                T nod_actual = 0;
                int nivel_actual = 1;
                Cola<T> cola;
                Cola<int> cola2;
                cola.encolar(Arbol.Raiz());
                cola2.encolar(nivel_actual);
                while (cola.vacia() != true && cola2.vacia() != true){
                    nivel_actual = cola2.desencolar();
                    nodaux = cola.desencolar();
                    nod_actual = Arbol.HijoMasIzq(nodaux);
                    nivel_actual++;
                    while (nod_actual != NULL){
                        if (nivel_actual == i){
                            cout << "\nNivel actual: " << nivel_actual << " nodo:" << Arbol.Etiqueta(nod_actual);
                            if (Arbol.HermanoDer(nod_actual) == NULL){
                                nivel_actual--;
                            }
                        }
                        else{
                            if(Arbol.EsHoja(nod_actual) == true ){
                                if(Arbol.HermanoDer(nod_actual) == NULL){
                                    nivel_actual--;
                                }
                            }else{

                                cola.encolar(nod_actual);
                                cola2.encolar(nivel_actual);
                            }
                        } 
                        nod_actual = Arbol.HermanoDer(nod_actual);

                    }
                }
                cola.~Cola(); 
                cola2.~Cola(); 
            }
        }
    }

//----------------------------------------------------------------
//Buscar etiqueta en el arbol
int counter;
template<class T, class K, class P>
bool BuscarEtiquetaR(T nodo,K etiquetaBuscada, P Arbol){
	bool encontrada = false;
	//cout << " Etiqueta actual:" << Arbol.Etiqueta(nodo) <<endl;
	if(Arbol.Etiqueta(nodo) == etiquetaBuscada){
		encontrada = true;
	}
	counter++;
	T n1 = Arbol.HijoMasIzq(nodo);
	while(n1 != NULL && encontrada!= true){
		encontrada = BuscarEtiquetaR(n1,etiquetaBuscada,Arbol);
		n1 = Arbol.HermanoDer(n1);
	}

	return encontrada;
}

template<class K, class P>
bool BuscarEtiqueta(K etiquetaBuscada, P Arbol){
	counter = 0;
	return BuscarEtiquetaR(Arbol.Raiz(),etiquetaBuscada,Arbol);
}

//----------------------------------------------------------------
//Listar el árbol en pre-orden usando la recursividad que provee el compilador.
template<class T, class K>
void ListarPreOrdenR(T nodo, K Arbol){
	
	cout << Arbol.Etiqueta(nodo);
	T n1 = Arbol.HijoMasIzq(nodo);
	while(n1 != NULL){
		ListarPreOrdenR(n1,Arbol);
		n1 = Arbol.HermanoDer(n1);

	}
	
}

template<class T>
void ListarPreorden(T Arbol){
	if(Arbol.Vacio() != 1){
		cout << "\nListado del arbol en preorden: ";
		ListarPreOrdenR(Arbol.Raiz(),Arbol);

	}
}

//----------------------------------------------------------------

 //Copiar arbol con recorrido por niveles
	template<class T, class K>
    void CopiarArbolNiveles(K Arbol,T node,K &Arbol2){
       	Cola<T> cola;
        T nodo;
        T nodoaux;
        
        if (Arbol.Vacio() != true){
            cola.encolar(Arbol.Raiz());
            while (cola.vacia()!= true){
                //cout<<"Etiqueta: "<<Arbol.Etiqueta(nodo)<<endl;
                
                nodo = cola.desencolar();
                //cout<< " Nodo actual:" << nodo;
                if(Arbol2.Vacio() == 1){
					//cout << "Agregando raiz a arbol copia" <<endl;
					Arbol2.PonerRaiz(Arbol.Etiqueta(Arbol.Raiz()));
                    //cout << "Arbol1: "<<endl;
                    //Arbol.RecorrerArbol(Arbol.Raiz());
                    //cout << "Arbol2: "<<endl;
                    //Arbol2.RecorrerArbol(Arbol2.Raiz());

				}else{
                    //cout << "Agregando nodo a arbol copia" <<endl;
                	Arbol2.AgregarUltimoHijo(TagToNode(Arbol.Etiqueta(Arbol.Padre(nodo)),Arbol2.Raiz(),Arbol2),Arbol.Etiqueta(nodo));
                    //TagToNode(Arbol.Etiqueta(Arbol.Padre(nodo)),Arbol2.Raiz(),Arbol2),Arbol.Etiqueta(nodo)
                    //cout << "Arbol1: "<<endl;
                    //Arbol.RecorrerArbol(Arbol.Raiz());
                    //cout << "Arbol2: "<<endl;
                    //Arbol2.RecorrerArbol(Arbol2.Raiz());
                }
                nodoaux = Arbol.HijoMasIzq(nodo);
                while (nodoaux != NULL){
                    cola.encolar(nodoaux);
                    nodoaux = Arbol.HermanoDer(nodoaux);
                }
            }
        }
        cola.~Cola();
    }
//----------------------------------------------------------------
 //Listar por niveles
	template<class T, class K>
    void ListarPorNiveles(T nodo, K Arbol){
       	cout << "Lista: " << endl;
        Cola<T> cola;
        T node;
        T nodoaux;
        
        if (Arbol.Vacio() != true){
            cola.encolar(Arbol.Raiz());
            while (cola.vacia()!= true){
                nodo = cola.desencolar();
                cout<<"Etiqueta: "<<Arbol.Etiqueta(nodo)<<endl;
                nodoaux = Arbol.HijoMasIzq(nodo);
                while (nodoaux!= NULL){
                    cola.encolar(nodoaux);
                    nodoaux = Arbol.HermanoDer(nodoaux);
                }
            }
        }
        cola.~Cola();
        
    }
    

//----------------------------------------------------------------


template<class T, class K>
    bool IgualdadArbolesR(K Arbol, T nodoArbol,K Arbol2, T nodoArbol2){
        bool iguales = true;
        T nodauxA1;
        T nodauxA2;
        if(Arbol.Etiqueta(nodoArbol) != Arbol2.Etiqueta(nodoArbol2)){
            iguales = false;
        }else{
            nodauxA1 = Arbol.HijoMasIzq(nodoArbol);
            nodauxA2 = Arbol2.HijoMasIzq(nodoArbol2);

            if(nodauxA1 != NULL && nodauxA2 != NULL){
                if(Arbol.Etiqueta(nodauxA1) != Arbol2.Etiqueta(nodauxA2)){
                    iguales = false;
                }else{
                    while (nodauxA1 != NULL &&  nodauxA2 != NULL && iguales != false){
                        iguales = IgualdadArbolesR(Arbol, nodauxA1, Arbol2, nodauxA2);
                        nodauxA1 = Arbol.HermanoDer(nodauxA1);
                        nodauxA2 = Arbol2.HermanoDer(nodauxA2);
                    }
                    if((nodauxA1 != NULL && nodauxA2 == NULL) || (nodauxA1 == NULL && nodauxA2 != NULL)){
                        iguales = false;
                    }
                }
            }
            else{
                if((nodauxA1 != NULL && nodauxA2 == NULL)  || (nodauxA1 == NULL && nodauxA2 != NULL)){
                    iguales = false;
                }
            }

        }
        return iguales;
    }

template<class K>
bool IgualdadArboles(K Arbol, K Arbol2){
    bool iguales = false;
    if (Arbol.Vacio() == true && Arbol2.Vacio() == true){
        iguales = true;
    }
    else{
        if ((Arbol.Vacio() != true && Arbol2.Vacio() != true) && (Arbol.NumNodos() == Arbol2.NumNodos() )){
            iguales = IgualdadArbolesR(Arbol, Arbol.Raiz(), Arbol2, Arbol2.Raiz());
        }
    }
    return iguales;
}

//----------------------------------------------------------------
//Buscar nodo de etiquetas
int countTag;
bool nodoEncontrado = false;
template<class T, class K, class P>
T TagToNodeR(T nodo,K etiquetaBuscada, P Arbol){
    
    T nodoEtiqueta;
    //cout << " Etiqueta actual:" << Arbol.Etiqueta(nodo) <<endl;
    if(Arbol.Etiqueta(nodo) == etiquetaBuscada){
        //cout << "Guardando etiqueta encontrada y retornando" << endl;
        nodoEtiqueta = nodo;
        nodoEncontrado = true;
    }else{
        counter++;
        T n1 = Arbol.HijoMasIzq(nodo);
        while(n1 != NULL && nodoEncontrado != true){
            nodoEtiqueta = TagToNodeR(n1,etiquetaBuscada,Arbol);
            n1 = Arbol.HermanoDer(n1);
        }
    }

    return nodoEtiqueta;
}

template<class K, class P,class T>
T TagToNode(K etiquetaBuscada,T node, P Arbol){
    nodoEncontrado = false;
    if(Arbol.Vacio() != 1){
        countTag = 0;
        return TagToNodeR(Arbol.Raiz(),etiquetaBuscada,Arbol);
    }
    return NULL;
}

//----------------------------------------------------------------
template<class K, class P>
void menu(K elemento, P arbol, P arbol2){
    K hijo;
    int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
        
        cout << "\nMenu de Opciones" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 1. IniciarArbol" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 2. DestruirArbol" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 3. VaciarArbol" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 4. PreguntarVacio" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 5. PonerRaiz" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 6. AgregarHijo" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 7. AgregarUltimoHijo" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 8. BorrarNodoHoja" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 9. ModificarEtiqueta" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "10. HijoMasIzq" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "11. HermanoDerecho" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "12. Raiz" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "13. Padre" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "14. NumHijos" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "15. EsHoja" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "16. NumNodos" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "17. ImprimirArbolPorNiveles" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "18. Menu de Algoritmos" << endl;
        cout << "-------------------------------------"<<endl;
        
        cout << "0. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            
            //------------------------------------------------------------
            case 1:
                arbol.Iniciar();

                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------
            case 2:             
                arbol.~Arbol();

                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------  
            case 3:           
                arbol.Vaciar();

                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa            
                break;
            //------------------------------------------------------------   
            case 4:
                if(arbol.Vacio() == 1){
                    cout << "Arbol se encuentra vacio" << endl;
                }else{
                    cout << "Arbol no vacio" << endl;
                }

                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa                
                break;
            //------------------------------------------------------------
            case 5: 
                cout<< "Digite la raiz del arbol: " << endl;
                cin >> elemento;
                arbol.PonerRaiz(elemento);            
                

                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa                
                break;
            //------------------------------------------------------------
            case 6:
                cout<< "Digite a que elemento desea agregar un hijo:";
                cin >> elemento;
                cout<< "Digite que elemento desea agregar:";
                cin >> hijo;

                arbol.AgregarHijo(TagToNode(elemento,arbol.Raiz(),arbol),hijo);                               

                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa                
                break;
            //------------------------------------------------------------
            case 7:
                cout<< "Digite a que elemento desea agregar un hijo:";
                cin >> elemento;
                cout<< "Digite que elemento desea agregar:";
                cin >> hijo;

                arbol.AgregarUltimoHijo(TagToNode(elemento,arbol.Raiz(),arbol),hijo);  
                
                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa                          
                break;
            //------------------------------------------------------------
            case 8:
                cout<< "Digite a que elemento desea borrar:";
                cin >> elemento;              
                arbol.BorrarNodoHoja(TagToNode(elemento,arbol.Raiz(),arbol));

                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa                 
                break;
            //------------------------------------------------------------
            case 9:
                cout<< "Digite que etiqueta desea modificar:";
                cin >> elemento;
                cout<< "Digite la nueva etiqueta:";
                cin >> hijo;
                
                arbol.ModificarEtiqueta(TagToNode(elemento,arbol.Raiz(),arbol),hijo);
                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa                
                break;
            //------------------------------------------------------------
            case 10:
                cout<< "Digite la etiqueta a la cual desea conocer su hijo izquierdo:";
                cin >> elemento;
                cout<< "Hijo mas izquierdo: ";
                cout<<arbol.Etiqueta(arbol.HijoMasIzq(TagToNode(elemento,arbol.Raiz(),arbol)))<<endl;
                
                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa               
                break;
            //------------------------------------------------------------
            case 11:
                cout<< "Digite la etiqueta a la cual desea conocer su hermano derecho:";
                cin >> elemento;
                cout<< "Hermano derecho: ";
                cout<<arbol.Etiqueta(arbol.HermanoDer(TagToNode(elemento,arbol.Raiz(),arbol)))<<endl;
                
                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa               
                break;
            //------------------------------------------------------------                
            case 12:
                cout<< "Raiz: ";
                cout << arbol.Etiqueta(arbol.Raiz()) << endl;
                
                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa                 
                break;
            //------------------------------------------------------------
            case 13:
                cout<< "Digite la etiqueta a la cual desea conocer su padre:";
                cin >> elemento;
                cout<< "Padre: ";
                cout<<arbol.Etiqueta(arbol.Padre(TagToNode(elemento,arbol.Raiz(),arbol)))<<endl;
                
                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa                                 
                break;
            //------------------------------------------------------------
            case 14:
                cout<< "Digite la etiqueta a la cual desea conocer su numero de hijos:";
                cin >> elemento;
                cout<< "Numero de hijos es de: ";
                cout<<arbol.NumHijos(TagToNode(elemento,arbol.Raiz(),arbol))<<endl;

                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa                
                break;
            //------------------------------------------------------------
            case 15:
                cout<< "Digite la etiqueta a la cual desea conocer si es hoja o no:";
                cin >> elemento;
                
                if(arbol.EsHoja(TagToNode(elemento,arbol.Raiz(),arbol)) == 1){
                    cout<< "Es Hoja" << endl;
                }else{
                    cout<< "No es hoja" << endl;
                }

                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa                
                break;
            //------------------------------------------------------------
            case 16:
               cout<< "Numero de nodos del arbol:";
                cout<<arbol.NumNodos()<<endl;               

                cout<< "Presione enter para continuar..." << endl;
                system("pause>nul"); // Pausa                             
                break;
            //------------------------------------------------------------
            case 17:
                ListarPorNiveles(arbol.Raiz(),arbol);
                
                system("pause>nul"); // Pausa                
                break;
            //------------------------------------------------------------
            case 18:
                subMenu(elemento,arbol,arbol2);                              
                break;    
        }        
    } while (opcion != 0);            // En vez de 5 pones el número de la opción de SALIDA        

}




template<class K, class P>
void subMenu(K elemento, P arbol, P arbol2){
    K hijo;
    int opcion;
    
    do {
        system("cls");        // Para limpiar la pantalla
        
        // Texto del menú que se verá cada vez
        
        cout << "\nMenu de Opciones" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 1. HermanoIzquierdoDeNodo" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 2. EtiquetasRepetidas" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 3. AlturaNodo" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 4. ProfundidadNodo" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 5. ListarEtiquetasEnPreorden" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 6. ListarEtiquetasPorNiveles" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 7. CopiarArbol" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 8. ArbolesIguales" << endl;
        cout << "-------------------------------------"<<endl;
        cout << " 9. ListarEnPreorden" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "10. PilaPreorden" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "11. ListarPorNiveles" << endl;
        cout << "-------------------------------------"<<endl;
        cout << "12. BuscarExistenciaEtiqueta" << endl;
        cout << "-------------------------------------"<<endl;
    
        
        cout << "0. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            
            //------------------------------------------------------------
            case 1:
                cout<< "Digite el elemento al que quiere encontrar su hermano izquierdo:";
                cin >> elemento;
                cout<< "Hermano izquierdo: ";
                cout<< arbol.Etiqueta(BusquedaHermanoIzq(TagToNode(elemento,arbol.Raiz(),arbol),arbol)) << endl;
                //arbol.Etiqueta(SearchBrother(TagToNode(elemento,arbol.Raiz(),arbol), arbol.Raiz(),arbol));

                cout<< "\nPresione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------
            case 2:
                EtiquetasRepetidas(arbol);

                cout<< "\nPresione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------
            case 3:
                cout<< "Digite el elemento al que quiere calcular su altura:";
                cin >> elemento;
                AlturaNodo(TagToNode(elemento,arbol.Raiz(),arbol),arbol);

                cout<< "\nPresione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------
            case 4:
                cout<< "Digite el elemento al que quiere calcular su profundidad:";
                cin >> elemento;
                ProfundidadNodo(TagToNode(elemento,arbol.Raiz(),arbol),arbol);

                cout<< "\nPresione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------
            case 5:
                cout << "Digite el nivel el cual desea listar:";
                int nivel;
                cin >> nivel;
                ListarEtiquetasPreorden(nivel,arbol);

                cout<< "\nPresione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------
            case 6:
                cout << "Digite el nivel el cual desea listar:";
                int niv;
                cin >> niv;
                ListarEtiquetasPorNiveles(niv,arbol.Raiz(),arbol);

                cout<< "\nPresione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------
            case 7:
                cout << "Copiando arbol 1 en arbol 2";
                CopiarArbolNiveles(arbol,arbol.Raiz(),arbol2);

                cout<< "\nPresione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------
            case 8:
                if(IgualdadArboles(arbol,arbol2) == 1){
                    cout << "Los arboles son iguales" << endl;
                }else{
                    cout << "Arboles distintos" << endl;
                }

                cout<< "\nPresione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------
            case 9:
                ListarPreorden(arbol);

                cout<< "\nPresione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------
            case 11:
                ListarPorNiveles(arbol.Raiz(),arbol);

                cout<< "\nPresione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------
            case 12:
                cout<< "Digite la etiqueta que desea buscar:";
                cin >> elemento;
                if(BuscarEtiqueta(elemento,arbol) == 1){
                    cout << "Existe etiqueta en el arbol" << endl;
                }else{
                    cout << "No existe etiqueta en el arbol" << endl;
                }
                
                cout<< "\nPresione enter para continuar..." << endl;
                system("pause>nul"); // Pausa
                break;
            //------------------------------------------------------------


    }  
    } while (opcion != 0);     

    
}





int main(){

    
	
    Arbol<char> arbol;
    Arbol<char> arbol2;
    //Arbol<string>&arbol2 = arbolx; 

    menu('A',arbol,arbol2);

	
return 0;	
}
