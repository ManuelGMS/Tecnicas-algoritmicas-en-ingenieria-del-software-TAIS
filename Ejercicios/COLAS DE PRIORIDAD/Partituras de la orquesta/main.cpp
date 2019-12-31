#include <fstream>
#include <iostream>
#include <exception>
#include "PriorityQueue.h"

class cmp {
public:
	bool operator () (const std::pair<int,int>& a, const std::pair<int,int>& b) {
		return (
			(a.first / a.second) + (a.first % a.second)
			>
			(b.first / b.second) + (b.first % b.second)
		);
	}
};

int resolver(PriorityQueue<std::pair<int,int>,cmp>& pq, int& partituras) {

	// (Musicos, Partituras)
	std::pair<int,int> grupo;

	while(partituras != 0) {

		pq.pop(grupo);

		grupo.second++;

		partituras--;

		pq.push(grupo);

	}

	return (pq.top().first / pq.top().second) + ( (pq.top().first % pq.top().second) != 0 );

}

bool resuelveCaso() {

	int partituras, musicos;

	std::cin >> partituras >> musicos;

	if(!std::cin)

		return false;

	int personas;

	PriorityQueue<std::pair<int,int>,cmp> pq;

	for(int i = 0 ; i < musicos ; i++) {

		std::cin >> personas;

		pq.push({personas,1});

		partituras--;

	}

	std::cout << resolver(pq,partituras) << std::endl;

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
