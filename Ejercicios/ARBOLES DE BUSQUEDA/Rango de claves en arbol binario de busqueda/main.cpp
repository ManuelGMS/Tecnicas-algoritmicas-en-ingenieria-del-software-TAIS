#include <fstream>
#include <iostream>
#include "TreeMap_AVL.h"

void resolver(map<int,int>& arbol, const std::pair<int,int>& iniFin) {

	arbol.range(iniFin);

}

bool resuelveCaso() {

	int nodos;

	std::cin >> nodos;

	if(nodos == 0)

		return false;

	int nodo;

	map<int,int> arbol;

	for( ; nodos > 0 ; nodos-- ) {

		std::cin >> nodo;

		arbol[nodo] = nodo;

	}

	std::pair<int,int> iniFin;

	std::cin >> iniFin.first >> iniFin.second;

	resolver(arbol,iniFin);

	return true;

}

int main() {

	#ifndef DOMJUDGE
	std::ifstream in("EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	while(resuelveCaso());

	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	#endif

	return 0;

}
