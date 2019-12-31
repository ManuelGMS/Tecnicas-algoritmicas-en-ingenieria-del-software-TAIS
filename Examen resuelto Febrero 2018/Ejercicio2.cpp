#include <vector>
#include <fstream>
#include <iostream>
#include "GrafoValorado.h"

void dfs(const GrafoValorado<size_t>& g, std::vector<bool>& marca, const size_t& origen, const size_t& ancho) {

	for( const auto& e : g.adj(origen) ) {

		if(!marca[e.otro(origen)] && ancho <= e.valor()) {

			marca[e.otro(origen)] = true;

			bfs(g,marca,e.otro(origen),ancho);

		}

	}

}

void resolver(const GrafoValorado<size_t>& g) {

	size_t ancho;

	size_t origen;

	size_t destino;

	size_t  consultas;

	std::cin >> consultas;

	for( ; consultas > 0 ; consultas-- ) {

		std::cin >> origen >> destino >> ancho;

		origen--;

		destino--;

		std::vector<bool> marca(g.V(),false);

		marca[origen] = true;

		bfs(g,marca,origen,ancho);

		std::cout << ( (marca[destino])? "SI" : "NO" ) << std::endl;

	}

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

	resolver(g);

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
