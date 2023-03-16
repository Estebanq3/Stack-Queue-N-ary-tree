#ifndef COLA_H
#define COLA_H

#include <array>
#include <iostream>
using namespace std;

#define MAX_SIZE 15

template<typename T>
class Cola{
	public:
		typedef typename array<T, MAX_SIZE>::size_type size_type;
		
		Cola();
		Cola(const Cola&) = default;
		~Cola() = default;

		Cola& operator =(const Cola &) = default;

		void encolar(T x);
		T desencolar();
		bool vacia();
		T mostrarfrente();
		bool llena();
		void print();

	private: 
		array<T, MAX_SIZE> a;
		size_type frente, parteTrasera, size;

};

#endif