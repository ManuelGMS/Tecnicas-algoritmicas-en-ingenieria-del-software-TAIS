#include <fstream>
#include <iostream>
#include "bintree_eda.h"

template<class T>
int resolver(const bintree<T>& arbol) {

	if(!arbol.empty())

		return std::max(resolver(arbol.left()),resolver(arbol.right())) + 1;

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

	std::cout << resolver(arbol) << std::endl;

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
