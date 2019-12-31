#include <fstream>
#include <iostream>
#include "Grafo.h"
#include "PriorityQueue.h"

bool bfs(const Grafo& g, std::vector<bool>& marca, const int& origen) {

	size_t i;

	size_t actual;

	marca[origen] = true;

	bool bipartido = true;

	std::vector<size_t> distancia(g.V(),0);

	PriorityQueue<size_t,std::less<size_t>> q;

	q.push(origen);

	while(!q.empty()) {

		q.pop(actual);

		std::vector<size_t> adyacentes = g.adj(actual);

		i = 0;

		while(i < adyacentes.size() && bipartido) {

			if(!marca[adyacentes[i]]) {

				q.push(adyacentes[i]);

				marca[adyacentes[i]] = true;

				distancia[adyacentes[i]] = distancia[actual] + 1;

			} else if( distancia[actual] % 2 == distancia[adyacentes[i]] % 2 ) {

				bipartido = false;

			}

			i++;

		}

	}

	return bipartido;

}

bool resolver(const Grafo& g) {

	size_t i = 0;

	bool bipartido = true;

	std::vector<bool> marca(g.V(),false);

	while(i < g.V() && bipartido) {

		if(!marca[i])

			bipartido = bfs(g,marca,i);

		i++;

	}

	return bipartido;

}

bool resuelveCaso() {

	size_t aristas;

	size_t vertices;

	std::cin >> vertices >> aristas;

	if(!std::cin)

		return false;

	size_t p1, p2;

	Grafo g(vertices);

	for( ; aristas > 0 ; aristas-- ) {

		std::cin >> p1 >> p2;

		g.ponArista(p1,p2);

	}

	std::cout << ( resolver(g)? "SI" : "NO" ) << std::endl;

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
