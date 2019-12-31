/*
   TAIS 10, Manuel Guerrero Moñús y Guillermo Delgado Yepes.

   Calculo del coste de la funcion resolver:

   	   * Coste: O( n )

   	   	   * n: Número de elementos del vector.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

size_t resolver(const std::vector<size_t>& v, const size_t& t)
{

	int tam = t;

	size_t parches = 1;

	for (size_t i = 0 ; i < v.size() - 1 ; ++i) {

		if( v[i+1] != v[i] )

			if( v[i+1] - v[i] <= tam ) {

				tam -= (v[i+1] - v[i]);

			} else {

				tam = t;

				parches++;

			}

	}

    return parches;

}

bool resuelveCaso()
{

	size_t n, l;
	std::cin >> n >> l;

	if(!std::cin) return false;

	size_t d;

	std::vector<size_t> v;

	for( ; n > 0 ; --n ) {

		std::cin >> d;

		v.push_back(d);

	}

	std::cout << resolver(v,l) << std::endl;

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
