#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Matriz.h"

const int MENOS_INFINIO = std::numeric_limits<int>::min();

void resolver(Matriz<int>& tablero) {

	// Caso base

	for (size_t j = 0 ; j < tablero.numcols() ; j++)
	
		tablero[0][j] = 0;

	// Caso recursivo

	int maximo;

	for (int i = 1 ; i < tablero.numfils() - 1; i++)

		for (int j = tablero.numcols() - 2; j > 0; j--)

			tablero[i][j] += std::max(tablero[i - 1][j], std::max(tablero[i - 1][j - 1], tablero[i - 1][j + 1]));

	// Solucion

	int columna;

	maximo = tablero[tablero.numfils() - 2][0];

	for (size_t j = 1; j < tablero.numcols() ; j++)
	
		if (maximo < tablero[tablero.numfils() - 2][j]) {

			columna = j;

			maximo = tablero[tablero.numfils() - 2][j];

		}
	
	std::cout << maximo << " " << columna << std::endl;

}

bool resuelveCaso() {

	int dimensionTablero;

	std::cin >> dimensionTablero;

	if (!std::cin)

		return false;

	dimensionTablero += 2;

	Matriz<int> tablero(dimensionTablero,dimensionTablero,MENOS_INFINIO);

	for (size_t i = 1 ; i < tablero.numfils() - 1  ; i++)
		
		for (size_t j = 1; j < tablero.numcols() - 1 ; j++)
		
			std::cin >> tablero[i][j];

	resolver(tablero);

	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	getchar();
#endif

	return 0;

}