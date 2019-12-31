/*

   TAIS, Curso 3º, Grupo E, Manuel Guerrero Moñús y Guillermo Delgado Yepes.

*/

#include <vector>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>

#include "Grafo.h"
#include "Matriz.h"
#include "MatrixGenerator.h"
#include "MatrixToGraphConverter.h"

void resuelveCaso()
{

	int rows, cols;

	std::cin >> cols >> rows;

	MatrixGenerator mG(rows,cols);

	if(mG.getCanBeResolved()) {

		MatrixToGraphConverter mTgC(mG.getMatrix());

		BreadthFirstPaths bFp(mTgC.getGraph(),mG.getGardenEntrance());

		if(bFp.hasPathTo(mG.getHouseDoor()))

			std::cout << bFp.distance(mG.getHouseDoor()) << std::endl;

		else

			std::cout << "NO" << std::endl;

	} else

		std::cout << "NO";

}

int main()
{
    #ifndef DOMJUDGE
    std::ifstream in("EntradaEjemplo.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif

    int jardines;

    std::cin >> jardines;

    while(jardines--)

    	resuelveCaso();

    #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    #endif

    return 0;
}
