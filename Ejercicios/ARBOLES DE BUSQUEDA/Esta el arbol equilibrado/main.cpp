#include <fstream>
#include <iostream>
#include "bintree_eda.h"

template<class T>
int resolver(const bintree<T>& arbol) {

	if(!arbol.empty()) {

		int izq, der;

		izq = resolver(arbol.left());

		if(izq != -1)

			der = resolver(arbol.right());

		if(izq != -1 && der != -1)

			return ( std::abs(izq-der) < 2 )? std::max(izq+1,der+1) : -1;

		return -1;

	}

	return 0;

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

	bintree<char> arbol = cargarArbol('.');

	std::cout << ( (resolver(arbol) != -1)? "SI" : "NO") << std::endl;

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
