#include "Pila.h"

Pila::Celda::Celda(int valor){ 
   this->valor = valor;
   resto = 0;
}

Pila::Pila(){ 
   tope = 0;
}


void Pila::Vaciar(){ 
   while(!Vacia()){ 
     this->Quitar();
   }
}

bool Pila::Vacia(){
   bool vacio=false;
   if (tope!=0){
   vacio=true;
   }
   return vacio;
}

int Pila::Tope(){ 
	int valor = 0;
   if(tope){
      valor = tope->valor;
   }
   return valor;
}

Pila& Pila::Quitar(){ 
   if(tope){
      Celda * victima = tope; 
      tope = tope->resto; 
      delete victima;
   }

   return *this;
}

Pila& Pila::Poner(int valor){ 
   Celda * nueva = new Celda(valor); 
   nueva->resto = tope;
   tope = nueva;
   return *this;
}

ostream& Pila::imprimir(ostream& salida){ 
   if(tope ) {
      salida << tope->valor;
      Celda * actual = tope->resto;
      while(actual){
        salida << "->" << actual->valor;
        actual= actual->resto;
      }
      salida << endl;
   }
   else {
      salida << "--Stack isEmpty--"<<endl;
   }
   return salida;
}
void Pila::Destruir(){
delete this;
cout<<"pila borrada";
}

