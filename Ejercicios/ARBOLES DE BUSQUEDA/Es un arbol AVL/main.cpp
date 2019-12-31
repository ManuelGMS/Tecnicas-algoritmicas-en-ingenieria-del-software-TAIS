#include <limits>
#include <fstream>
#include <iostream>
#include "bintree_eda.h"

typedef struct {
	int altura;
	bool esAVL;
	int menorPorLaDerecha;
	int mayorPorLaIzquierda;
} datos;

template<class T>
datos resolver(const bintree<T>& arbol) {

	if(!arbol.empty()) {

		datos izq, der;

		izq = resolver(arbol.left());

		if(izq.esAVL)

			der = resolver(arbol.right());

		if(izq.esAVL && der.esAVL && izq.mayorPorLaIzquierda < arbol.root() && der.menorPorLaDerecha > arbol.root() && std::abs(izq.altura-der.altura) < 2 )

			return { std::max(izq.altura,der.altura) + 1 , true , std::min(arbol.root(),std::min(izq.menorPorLaDerecha,der.menorPorLaDerecha)) , std::max(arbol.root(),std::max(izq.mayorPorLaIzquierda,der.mayorPorLaIzquierda)) };

		return { -1 , false , -1 , -1 };

	}

	return { 0 , true , std::numeric_limits<T>::max() , std::numeric_limits<T>::min() };

}

template<class T>
bintree<T> cargarArbol(T vacio) {

	T raiz;

	std::cin >> raiz;

	if(raiz != vacio)

		return { cargarArbol(vacio) , raiz , cargarArbol(vacio) };

	return {};

}

void resuelveCaso() {

	bintree<int> arbol = cargarArbol(-1);

	std::cout << ( (resolver(arbol).esAVL)? "SI" : "NO") << std::endl;

}

int main() {

	#ifndef DOMJUDGE
	std::ifstream in("EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int arboles;

	std::cin >> arboles;

	for( ; arboles > 0 ; arboles-- )

		resuelveCaso();

	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	#endif

	return 0;

}
