#include <vector>
#include <limits>
#include <fstream>
#include <iostream>
#include "IndexPQ.h"
#include "GrafoValorado.h"

const size_t INFINITO = std::numeric_limits<size_t>::max();

void dijkstra(const GrafoValorado<size_t>& g, const size_t& verticeOrigen) {

	std::vector<Arista<size_t>> aristaAlVertice (g.V());

	aristaAlVertice[verticeOrigen] = { verticeOrigen , verticeOrigen , 0 };

	IndexPQ<size_t,std::less<size_t>> pq(g.V());

	pq.push(verticeOrigen,0);

	std::vector<size_t> distanciaAlVertice(g.V(),INFINITO);

	distanciaAlVertice[verticeOrigen] = 0;

	std::vector<size_t> caminosMinimosAlVertice(g.V(),0);

	caminosMinimosAlVertice[verticeOrigen] = 1;

	while(!pq.empty()) {

		auto v = pq.top(); pq.pop();

		size_t origen = v.elem;

		for( const Arista<size_t>& aristaVerticeAdyacente : g.adj(origen) ) {

			size_t coste = aristaVerticeAdyacente.valor();

			size_t dest = aristaVerticeAdyacente.otro(origen);

			if( distanciaAlVertice[dest] >= distanciaAlVertice[origen] + coste) {

				if(distanciaAlVertice[dest] > distanciaAlVertice[origen] + coste)

					caminosMinimosAlVertice[dest] = caminosMinimosAlVertice[origen];

				else

					caminosMinimosAlVertice[dest] += caminosMinimosAlVertice[origen];

				aristaAlVertice[dest] = aristaVerticeAdyacente;

				distanciaAlVertice[dest] = distanciaAlVertice[origen] + coste;

				pq.update(dest, distanciaAlVertice[dest]);

			}

		}

	}

	std::cout << caminosMinimosAlVertice[g.V()-1] << std::endl;

}

bool resuelveCaso() {

	size_t aristas;

	size_t vertices;

	std::cin >> vertices >> aristas;

	if(!std::cin)

		return false;

	size_t p1, p2 , vl;

	GrafoValorado<size_t> g(vertices);

	for( ; aristas > 0 ; aristas-- ) {

		std::cin >> p1 >> p2 >> vl;

		g.ponArista({p1-1,p2-1,vl});

	}

	dijkstra(g,0);

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
