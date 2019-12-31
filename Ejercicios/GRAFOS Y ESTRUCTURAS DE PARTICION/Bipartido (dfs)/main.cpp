/*

   TAIS, Curso 3º, Grupo E, Manuel Guerrero Moñús y Guillermo Delgado Yepes.

	Calculo del coste:

	* Coste de la carga del grafo: O( E + V )

		+ E: Numero de aristas del grafo.
		+ V: Numero de vertices del grafo.

	* Coste de la busqueda en profundidad: O( V )

	 	+ V: Numero de vertices del grafo.

	* Coste total: O( (E + V) + (V) ) = O( E + 2V )

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Grafo.h"

class Problema {

private:

	bool bipartido;

	std::vector<char> color;

	std::vector<bool> marcado;

	void dfs(Grafo const& g, size_t v, char c) {

		if(this->bipartido) {

			if( this->color[v] == 'N' ) {

				this->color[v] = c;

				c = ((c == 'R')? 'A' : 'R');

			}

			this->marcado[v] = true;

			for(size_t w : g.adj(v))

				if(!this->marcado[w]) {

					this->dfs(g,w,c);

				} else if( this->color[v] == this->color[w] ) {

					this->bipartido = false;

				}

		}

	}

public:

	Problema(Grafo const& g) : bipartido(true) , marcado(g.V(),false) , color(g.V(),'N') {

		for(size_t v = 0 ; v < g.V() ; ++v)

			if(!this->marcado[v])

				this->dfs(g,v,'R');

	}

	std::string getBipartido() {
		return (this->bipartido)? "SI" : "NO";
	}

};

bool resuelveCaso()
{

	int v, e;

	std::cin >> v >> e;

	if(!std::cin)

		return false;

	Grafo grafo(v);

	int w;

	for (int i = 0 ; i < e ; ++i) {

		std::cin >> v >> w;

		grafo.ponArista(v,w);

	}

	Problema problema(grafo);

	std::cout << problema.getBipartido() << std::endl;

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
