/*

   TAIS, Curso 3º, Grupo E, Manuel Guerrero Moñús y Guillermo Delgado Yepes.

	Calculo del coste:

	* Coste de la carga de la matriz: O( S )

		+ N: Numero de filas de la matriz.
		+ M: Numero de columnas de la matriz.
		+ S: Total de  elementos de la matriz. ( S = N * M )

	* Coste de generar los conjuntos disjuntos: O( S * log(S) )

	* Coste total: O( S + S * log(S) ) = O( S * (1 + log(S)) )

*/

#include <vector>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>

#include "Matriz.h"
#include "ConjuntosDisjuntos.h"

size_t resolver(const int& rows, const int& cols) {

	char data;

	int sheepPixels = 0;

	Matriz<int> matrix(rows,cols,-1);

	for (int i = 0 ; i < rows ; ++i)
		for (int j = 0 ; j < cols ; ++j) {

			std::cin >> data;

			if(data == '.')

				matrix[i][j] = sheepPixels++;

		}

	ConjuntosDisjuntos disjointSets(sheepPixels);

	for (int i = 0 ; i < rows ; ++i) {
		for (int j = 0 ; j < cols ; ++j) {

			if(matrix[i][j] != -1) {

				if( (j-1 > -1) && (matrix[i][j-1] != -1) )

					disjointSets.unir(matrix[i][j],matrix[i][j-1]);

				if( (j+1 < cols) && (matrix[i][j+1] != -1) )

					disjointSets.unir(matrix[i][j],matrix[i][j+1]);

				if( (i-1 > -1) && (matrix[i-1][j] != -1) )

					disjointSets.unir(matrix[i][j],matrix[i-1][j]);

				if( (i+1 < rows) && (matrix[i+1][j] != -1) )

					disjointSets.unir(matrix[i][j],matrix[i+1][j]);

			}

		}
	}

	return disjointSets.count() - 1;

}

bool resuelveCaso()
{

	int rows, cols;

	std::cin >> cols >> rows;

	if(!std::cin)

		return false;

	std::cout << resolver(rows,cols) << std::endl;

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
