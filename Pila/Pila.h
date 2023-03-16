#ifndef _PILA
#define _PILA
#include<iostream>
using namespace std;

class Pila {
   
   
   friend ostream& operator<<(ostream& salida, Pila &p){
	   return p.imprimir(salida);
   }

   private:
      class Celda {
         friend class Pila;
         private:
            int valor;
            Celda * resto; 
         public:
            Celda(int);
      };

      Celda * tope;

   public:
 /*  	Crear 
Parámetros:pila P
Efecto:inicializa P cómo pila vacía
Requiere:pila P no inicializada o P destruida
Modifica:pila P
*/
      Pila(); 
       
/*Vaciar
Parámetros:pila P
Efecto:Hace que la pila P quede vacía 
Requiere:pila P inicializada 
Modifica:pila P
*/
      void Vaciar();
 /*¿Vacía?
Parámetros:pila P
Efecto:Devuelve verdadero/ falso si la pila está vacía 
Requiere: pila P inicializada
Modifica:nada
 */    
      bool Vacia(); 
 /*Tope?
Parámetros:pila P
Efecto:devuelve el elemento en el tope de la pila
Requiere:P inicializada y P no vacía 
Modifica:nada
 */    
      int Tope(); 
/*Quitar 
Parámetros:pila P
Efecto:Borra el elemento en el tope de la pila
Requiere:pila P inicializada y no vacía 
Modifica:P 
*/      
      Pila& Quitar(); 
/* Poner
Parámetros: pila P,elemento e
Efecto:Agrega un elemento en el tope de la pila
Requiere:pila P inicializada y elemento válido
Modifica:pila P
 */     
      Pila& Poner(int); 
/*Destruir 
Parámetros:pila P
Efecto:Destruye la pila P y la deja inutilizable
Requiere:pila P inicializada 
Modifica:pila P
*/
      void Destruir();
      
      ostream& imprimir (ostream&);
};

#endif
