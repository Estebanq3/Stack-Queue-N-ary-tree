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
Par�metros:pila P
Efecto:inicializa P c�mo pila vac�a
Requiere:pila P no inicializada o P destruida
Modifica:pila P
*/
      Pila(); 
       
/*Vaciar
Par�metros:pila P
Efecto:Hace que la pila P quede vac�a 
Requiere:pila P inicializada 
Modifica:pila P
*/
      void Vaciar();
 /*�Vac�a?
Par�metros:pila P
Efecto:Devuelve verdadero/ falso si la pila est� vac�a 
Requiere: pila P inicializada
Modifica:nada
 */    
      bool Vacia(); 
 /*Tope?
Par�metros:pila P
Efecto:devuelve el elemento en el tope de la pila
Requiere:P inicializada y P no vac�a 
Modifica:nada
 */    
      int Tope(); 
/*Quitar 
Par�metros:pila P
Efecto:Borra el elemento en el tope de la pila
Requiere:pila P inicializada y no vac�a 
Modifica:P 
*/      
      Pila& Quitar(); 
/* Poner
Par�metros: pila P,elemento e
Efecto:Agrega un elemento en el tope de la pila
Requiere:pila P inicializada y elemento v�lido
Modifica:pila P
 */     
      Pila& Poner(int); 
/*Destruir 
Par�metros:pila P
Efecto:Destruye la pila P y la deja inutilizable
Requiere:pila P inicializada 
Modifica:pila P
*/
      void Destruir();
      
      ostream& imprimir (ostream&);
};

#endif
