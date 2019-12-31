#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

int resolver(PriorityQueue<>& pq) {

	int e2 = 0;

	int sol = 0;

	int e1 = pq.top(); pq.pop();

	while(!pq.empty()) {

		e2 = pq.top(); pq.pop();

		sol = sol + e1 + e2;

		pq.push(e1 + e2);

		e1 = pq.top(); pq.pop();

	}

	return sol;

}

bool resuelveCaso() {

	int equipos;

	std::cin >> equipos;

	if(equipos == 0)

		return false;

	PriorityQueue<> pq;

	int equipo;

	for( ; equipos > 0 ; equipos-- ) {

		std::cin >> equipo;

		pq.push(equipo);

	}

	std::cout << resolver(pq) << std::endl;

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
