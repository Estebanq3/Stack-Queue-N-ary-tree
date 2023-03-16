#include <iostream>
#include <stdio.h>
#include "Cola.h"

using namespace std;

template<typename T>
Cola<T>::Cola(){
	frente = -1;
	parteTrasera  = -1;
	size  =  0;
}

template<typename T>
bool Cola<T>::vacia(){
	return (frente == -1 && parteTrasera == -1);
}

template<typename T>
bool Cola<T>::llena(){
	return (parteTrasera+1)%MAX_SIZE == frente ? true: false;
}

template<typename T>
void Cola<T>::encolar(T x){
	if(llena()){
		return;
	}

	if(vacia()){
		frente = parteTrasera = 0;
	}else{
		parteTrasera = (parteTrasera + 1)%MAX_SIZE;
	}

	a[parteTrasera] = x;
}

template<typename T>
T Cola<T>::desencolar(){
	if(vacia()){
		return 0;
	}else if(frente == parteTrasera){
		T temp =  a[parteTrasera];
		parteTrasera = frente = -1;
		return temp;
		
	}else{
		T nodoDesencolado = a[frente];
		frente = (frente+1)%MAX_SIZE;
		return nodoDesencolado;
	}

}

template<typename T>
T Cola<T>::mostrarfrente(){
	if(frente == -1){
		return -1;
	}

	return a[frente];
}

template<typename T>
void Cola<T>::print(){
	int count = (parteTrasera + MAX_SIZE -frente)%MAX_SIZE + 1;
	cout<<"Cola : ";
	for (size_type i = 0; i < count; ++i){
		int index = (frente + i) % MAX_SIZE;
		cout<<a[index]<<" ";
	}
	cout<<"\n";
}

