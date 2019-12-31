/*
   TAIS 10, Manuel Guerrero Moñús y Guillermo Delgado Yepes.

   Calculo del coste de la funcion resolver:

	   * Coste total: O( n + n * log( n ) )

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

size_t resolver(std::vector<size_t>& v, const size_t& max)
{

	size_t i = 0;

	size_t sillas = 0;

	size_t j = v.size() - 1;

	sort(v.begin(),v.end(),std::greater<int>());

	while(i < j) {

		if( v[i] + v[j] <= max) --j;

		++sillas;

		++i;

	}

	if(i == j) ++sillas;

    return sillas;

}

bool resuelveCaso()
{

	size_t kg, pers;

	std::cin >> kg >> pers;

	if(!std::cin) return false;

	size_t d;

	std::vector<size_t> v;

	for( ; pers > 0 ; --pers ) {

		std::cin >> d;

		v.push_back(d);

	}

	std::cout << resolver(v,kg) << std::endl;

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
