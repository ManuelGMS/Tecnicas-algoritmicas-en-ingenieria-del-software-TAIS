#include <vector>
#include <fstream>
#include <iostream>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

bool operator < (const Arista<size_t>& a, const Arista<size_t>& b) {

	return a.valor() < b.valor();

}

void kruskal(const GrafoValorado<size_t>& g, PriorityQueue<Arista<size_t>,std::less<Arista<size_t>>>& pq) {

	size_t origen;

	size_t destino;

	size_t total = 0;

	Arista<size_t> actual;

	ConjuntosDisjuntos djts(g.V());

	std::vector<Arista<size_t>> aristas;

	while(!pq.empty() && aristas.size() < g.V() - 1) {

		pq.pop(actual);

		origen = actual.uno();

		destino = actual.otro(origen);

		if(!djts.unidos(origen,destino)) {

			total += actual.valor();

			aristas.push_back(actual);

			djts.unir(origen,destino);

		}

	}

	std::cout << ( (aristas.size() == g.V() - 1)? std::to_string(total) : "Imposible" ) << std::endl;

}

bool resuelveCaso() {

	size_t aristas;

	size_t vertices;

	std::cin >> vertices >> aristas;

	if(!std::cin)

		return false;

	size_t p1, p2 , vl;

	GrafoValorado<size_t> g(vertices);

	PriorityQueue<Arista<size_t>,std::less<Arista<size_t>>> pq;

	for( ; aristas > 0 ; aristas-- ) {

		std::cin >> p1 >> p2 >> vl;

		pq.push({p1-1,p2-1,vl});

		g.ponArista({p1-1,p2-1,vl});

	}

	kruskal(g,pq);

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
