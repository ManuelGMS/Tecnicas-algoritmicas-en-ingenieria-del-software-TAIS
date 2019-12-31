#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

void resolver(std::vector<int>& pajaros) {

	size_t i = 1;

	PriorityQueue<> mayores;

	int cabecilla = pajaros[0];

	PriorityQueue<int,std::greater<int>> menores;

	while(i < pajaros.size()) {

		for(int j = 0 ; j < 2 ; j++) {

			if(pajaros[i] > cabecilla)

				mayores.push(pajaros[i]);

			else

				menores.push(pajaros[i]);

			i++;

		}

		if(menores.size() != mayores.size()) {

			if(menores.size() > mayores.size()) {

				mayores.push(cabecilla);

				menores.pop(cabecilla);

			} else {

				menores.push(cabecilla);

				mayores.pop(cabecilla);

			}

		}

		std::cout << cabecilla << " ";

	}

	std::cout << std::endl;

}

bool resuelveCaso() {

	int parejas, cabecilla;

	std::cin >> cabecilla >> parejas;

	if(parejas == 0 && cabecilla == 0)

		return false;

	int p1, p2;

	std::vector<int> pajaros;

	pajaros.push_back(cabecilla);

	for( ; parejas > 0 ; parejas-- ) {

		std::cin >> p1 >> p2;

		pajaros.push_back(p1);

		pajaros.push_back(p2);

	}

	resolver(pajaros);

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
