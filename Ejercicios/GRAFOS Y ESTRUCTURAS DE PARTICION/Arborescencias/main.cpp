#include <fstream>
#include <iostream>
#include "GrafoDirigido.h"

void dfs(const GrafoDirigido& g, std::vector<bool>& marca, size_t& origen) {

	std::vector<size_t> adyacentes = g.adj(origen);

	for(const size_t& adj : adyacentes) {

		if(!marca[adj]) {

			origen = adj;

			marca[adj] = true;

			dfs(g,marca,origen);

		}

	}

}

bool resuelveCaso() {

	size_t aristas;

	size_t vertices;

	std::cin >> vertices >> aristas;

	if(!std::cin)

		return false;

	size_t v1, v2;

	GrafoDirigido g(vertices);

	std::vector<bool> marca(g.V(),false);

	std::vector<size_t> referenciado(g.V(),0);

	for( ; aristas > 0 ; aristas-- ) {

		std::cin >> v1 >> v2;

		g.ponArista(v1,v2);

		referenciado[v2]++;

	}

	size_t i;

	size_t raiz = 0;

	size_t raices = 0;

	for(i = 0 ; i < referenciado.size() && referenciado[i] < 2 ; i++)

		if(referenciado[i] == 0) {

			raices++;

			raiz = i;

		}

	if(i == referenciado.size() && raices == 1) {

		size_t r = raiz;

		marca[raiz] = true;

		dfs(g,marca,raiz);

		size_t i = 0;

		while(i < marca.size() && marca[i]) i++;

		std::cout << ((i == marca.size())? "SI " + std::to_string(r) : "NO") << std::endl;

	} else {

		std::cout << "NO" << std::endl;

	}

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
