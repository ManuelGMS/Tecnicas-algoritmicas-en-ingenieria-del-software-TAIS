/*
   TAIS 10, Manuel Guerrero Moñús y Guillermo Delgado Yepes.

   Calculo del coste de la funcion resolver:

	   * Coste total: O( n + n * log( n ) ) = O( n * (1 + log(n)) )

		   * Coste de la ordenacion: O( n * log( n ) )

			   * n: Número de elementos del vector.

		   * Coste del algoritmo voraz: O( n )

			   * n: Número de elementos del vector.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

size_t resolver(std::vector<size_t>& v)
{

	size_t descuento = 0;

	sort(v.begin(),v.end(),std::greater<size_t>());

	for( size_t i = 0 ; i < v.size() ; ++i )

		if( (i+1) % 3 == 0 )

			descuento += v[i];

    return descuento;

}

bool resuelveCaso()
{

	size_t libros;

	std::cin >> libros;

	if(!std::cin) return false;

	size_t precio;

	std::vector<size_t> v;

	for( ; libros > 0 ; --libros ) {

		std::cin >> precio;

		v.push_back(precio);

	}

	std::cout << resolver(v) << std::endl;

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
