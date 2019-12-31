#include <vector>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include "kAvlMap.h"

void resolver(map<int,int>& avl, std::vector<int>& consultar) {

	for( int& i : consultar ) {

		try {

			std::cout << avl.kElement(i) << std::endl;

		} catch (std::out_of_range& e) {

			std::cout << e.what() << std::endl;

		}

	}

}

bool resuelveCaso()
{

	int numeroDeClaves;

	std::cin >> numeroDeClaves;

	if(numeroDeClaves == 0)

		return false;

	int dato;

	map<int,int> avl;

	for( int i = 0 ; i < numeroDeClaves ; ++i) {

		std::cin >> dato;

		avl.insert(dato);

	}

	int consultas;

	std::cin >> consultas;

	std::vector<int> consultar;

	for( int i = 0 ; i < consultas ; ++i) {

		std::cin >> dato;

		consultar.push_back(dato);

	}

	resolver(avl,consultar);

	std::cout << "----" << std::endl;

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
