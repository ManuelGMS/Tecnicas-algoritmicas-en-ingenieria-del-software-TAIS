#include <fstream>
#include <iostream>
#include "Grafo.h"

void dfs(const Grafo& g, std::vector<bool>& marca, int& amigos, int& origen) {

	std::vector<size_t> adyacentes = g.adj(origen);

	for(const size_t& adj : adyacentes) {

		if(!marca[adj]) {

			amigos++;

			origen = adj;

			marca[adj] = true;

			dfs(g,marca,amigos,origen);

		}

	}

}

size_t resolver(const Grafo& g) {

	int origen;

	int amigos;

	int maximo = 0;

	std::vector<bool> marca(g.V(),false);

	for(size_t i = 0 ; i < g.V() ; i++) {

		if(!marca[i]) {

			amigos = 1;

			origen = i;

			marca[i] = true;

			dfs(g,marca,amigos,origen);

			if(amigos > maximo)

				maximo = amigos;

		}

	}

	return maximo;

}

void resuelveCaso() {

	int p1, p2;

	int personas;

	int relaciones;

	std::cin >> personas >> relaciones;

	Grafo g(personas);

	for( ; relaciones > 0 ; relaciones-- ) {

		std::cin >> p1 >> p2;

		g.ponArista(p1-1,p2-1);

	}

	std::cout << resolver(g) << std::endl;

}

int main() {

	#ifndef DOMJUDGE
	std::ifstream in("EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int casos;

	std::cin >> casos;

	for( ; casos > 0 ; casos-- )

		resuelveCaso();

	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	#endif

	return 0;

}
