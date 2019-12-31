/*
   TAIS 10, Manuel Guerrero Moñús y Guillermo Delgado Yepes.

   Calculo del coste de la funcion resolver:

	   * Coste total: O( n + 2 * n * log(n) ) = O( n * (1 + 2 * log(n)) )

		   * Coste de la ordenacion de los dos vectores: O( 2 * n * log( n ) )

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

size_t resolver(std::vector<size_t>& enemigos, std::vector<size_t>& defensores)
{

	size_t ciudadesSalvadas = 0;

	sort(enemigos.begin(),enemigos.end(),std::less<size_t>());

	sort(defensores.begin(),defensores.end(),std::less<size_t>());

	for(size_t i = 0 , j = 0 ; i < enemigos.size() && j < defensores.size() ; ++j)

		if( defensores[j] >= enemigos[i] ) {

			++ciudadesSalvadas;

			++i;

		}

    return ciudadesSalvadas;

}

bool resuelveCaso()
{

	size_t ciudades;

	std::cin >> ciudades;

	if(!std::cin) return false;

	size_t guerrero;

	std::vector<size_t> enemigos, defensores;

	for( size_t i = 0 ; i < ciudades ; ++i ) {

		std::cin >> guerrero;

		enemigos.push_back(guerrero);

	}

	for( size_t i = 0 ; i < ciudades ; ++i ) {

		std::cin >> guerrero;

		defensores.push_back(guerrero);

	}

	std::cout << resolver(enemigos,defensores) << std::endl;

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
