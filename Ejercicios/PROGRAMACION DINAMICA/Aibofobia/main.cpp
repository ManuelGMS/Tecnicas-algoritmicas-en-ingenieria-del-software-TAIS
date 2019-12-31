#include <fstream>
#include <iostream>
#include "Matriz.h"

size_t resolver(const std::string& palabra) {

	size_t i;

	Matriz<size_t> espacioDeSoluciones(palabra.size(),palabra.size(),0);

	for(size_t d = 1 ; d < palabra.size() ; d++)

		for(size_t j = d ; j < palabra.size() ; j++) {

			i = j - d;

			if( palabra[i] == palabra[j] )

				espacioDeSoluciones[i][j] = espacioDeSoluciones[i+1][j-1];

			else

				espacioDeSoluciones[i][j] = 1 + std::min(espacioDeSoluciones[i][j-1],espacioDeSoluciones[i+1][j]);

		}

	return espacioDeSoluciones[0][palabra.size()-1];

}

bool resuelveCaso() {

	std::string palabra;

	std::cin >> palabra;

	if(!std::cin)

		return false;

	std::cout << resolver(palabra) << std::endl;

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
