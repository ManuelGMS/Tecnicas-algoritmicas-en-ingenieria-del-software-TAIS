#include <vector>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"

const int INFINITO = std::numeric_limits<int>::max();

void dijkstra(const GrafoDirigidoValorado<int>& g, const int& origen) {

	IndexPQ<int,std::less<int>> colaDePrioridad(g.V());

	colaDePrioridad.push(origen,0);

	std::vector<int> distanciaAlVertice(g.V(),INFINITO);

	distanciaAlVertice[origen] = 0;

	std::vector<AristaDirigida<int>> aristaAlvertice(g.V());

	aristaAlvertice[0] = AristaDirigida<int>(0,0,0);

	while(!colaDePrioridad.empty()) {

		auto v = colaDePrioridad.top();

		colaDePrioridad.pop();

		for( const AristaDirigida<int>& aristaVerticeAdyacente : g.adj(v.elem) ) {

			int destino = aristaVerticeAdyacente.to();

			int origen =  aristaVerticeAdyacente.from();

			int costeDeIrDeOrigenDestino =  aristaVerticeAdyacente.valor();

			if( distanciaAlVertice[destino] >  distanciaAlVertice[origen] + costeDeIrDeOrigenDestino ) {

				aristaAlvertice[destino] =  aristaVerticeAdyacente;

				distanciaAlVertice[destino] =  distanciaAlVertice[origen] + costeDeIrDeOrigenDestino;

				colaDePrioridad.update(destino, distanciaAlVertice[destino]);

			}

		}

	}

	for( int i = 0 ; i < g.V() ; ++i )

		std::cout << "Distancia al vertice " << i << ": " << distanciaAlVertice[i] << std::endl;

	for( int i = 0 ; i < g.V() ; ++i )

		std::cout << "Arista al vertice " << i << ": " << aristaAlvertice[i] << std::endl;

}

bool resuelveCaso() {

	int V , O;

	std::cin >> V >> O;

	if(!std::cin)

		return false;

	std::string valor;

	GrafoDirigidoValorado<int> g(V);

	for( int i = 0 ; i < V ; ++i )

		for( int j = 0 ; j < V ; ++j ) {

			std::cin >> valor;

			if( valor.compare("I") != 0 && i != j )

				g.ponArista(AristaDirigida<int>(i,j,std::stoi(valor)));

		}

	dijkstra(g,O);

	return true;

}

int main()
{
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
