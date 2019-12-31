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

size_t resolver(std::vector<size_t>& rivales, std::vector<size_t>& broncos)
{

	size_t maximo = 0;

	sort(rivales.begin(),rivales.end(),std::less<size_t>());

	sort(broncos.begin(),broncos.end(),std::greater<size_t>());

	for( size_t i = 0 ; i < broncos.size() ; ++i )

		if( broncos[i] > rivales[i] )

			maximo += (broncos[i] - rivales[i]);

    return maximo;

}

bool resuelveCaso()
{

	size_t partidos;

	std::cin >> partidos;

	if(partidos == 0) return false;

	size_t resultado;

	std::vector<size_t> rivales, broncos;

	for( size_t i = 0 ; i < partidos ; ++i ) {

		std::cin >> resultado;

		rivales.push_back(resultado);

	}

	for( size_t i = 0 ; i < partidos ; ++i ) {

		std::cin >> resultado;

		broncos.push_back(resultado);

	}

	std::cout << resolver(rivales,broncos) << std::endl;

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
