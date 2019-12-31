#include <limits>
#include <fstream>
#include <iostream>
#include "Matriz.h"

const size_t INFINITO = std::numeric_limits<size_t>::max();

size_t recursiva(const std::vector<size_t>& posCortes, const size_t& i, const size_t& j) {

	if( (i+1) == j )

		return 0;

	else {

		size_t minimo = INFINITO;

		for(size_t k = i + 1 ; k < j ; k++)

			minimo = std::min( minimo , recursiva(posCortes,i,k) + recursiva(posCortes,k,j) + (2 * (posCortes[j] - posCortes[i])) );

		return minimo;

	}

}

void resolver(const std::vector<size_t>& vectorDeCortes) {

	size_t j;
	size_t minimo;

	Matriz<size_t> matrizDeAdyacencia(vectorDeCortes.size(),vectorDeCortes.size(),0);

	for(size_t d = 2 ; d < vectorDeCortes.size() ; d++)

		for (size_t i = 0 ; i < vectorDeCortes.size() - d ; ++i) {

			j = i + d;

			minimo = INFINITO;

			for (size_t k = i + 1 ; k < j ; ++k)

				minimo = std::min(matrizDeAdyacencia[i][k]+matrizDeAdyacencia[k][j]+((vectorDeCortes[j]-vectorDeCortes[i])*2),minimo);

			matrizDeAdyacencia[i][j] = minimo;

		}

	std::cout << matrizDeAdyacencia[0][matrizDeAdyacencia.numcols()-1] << std::endl;

}

bool resuelveCaso() {

	size_t numeroCortes;

	size_t longitudTablon;

	std::cin >> longitudTablon >> numeroCortes;

	if(longitudTablon == 0 && numeroCortes == 0)

		return false;

	size_t corte;

	std::vector<size_t> vectorDeCortes;

	vectorDeCortes.push_back(0);

	for( ; numeroCortes > 0 ; numeroCortes-- ) {

		std::cin >> corte;

		vectorDeCortes.push_back(corte);

	}

	vectorDeCortes.push_back(longitudTablon);

	resolver(vectorDeCortes);

	// std::cout << recursiva(vectorDeCortes,0,vectorDeCortes.size()-1) << std::endl;

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
