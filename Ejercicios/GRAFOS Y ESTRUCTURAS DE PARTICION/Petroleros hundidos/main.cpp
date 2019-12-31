#include <vector>
#include <limits>
#include <fstream>
#include <iostream>
#include "Matriz.h"
#include "ConjuntosDisjuntos.h"

void resolver(Matriz<bool>& fondoMarino, ConjuntosDisjuntos& cjtos, const std::vector<std::pair<int,int>>& direcciones, size_t& maximo) {

	size_t y , x;

	std::cin >> y >> x;

	y--; x--;

	size_t verticeDestino;

	fondoMarino[y][x] = true;

	size_t verticeOrigen = y * fondoMarino.numcols() + x;

	for(const std::pair<int,int>& dir : direcciones ) {

		verticeDestino = verticeOrigen + dir.first * fondoMarino.numcols() + dir.second ;

		if(fondoMarino.posCorrecta(y+dir.first,x+dir.second))

			if(fondoMarino[y+dir.first][x+dir.second])

				if(!cjtos.unidos(verticeOrigen,verticeDestino)) {

					cjtos.unir(verticeOrigen,verticeDestino);

					maximo = std::max(cjtos.size(verticeDestino),maximo);

				}

	}

	std::cout << maximo << " ";

}

bool resuelveCaso() {

	int filas;

	int columnas;

	std::cin >> filas >> columnas;

	if(!std::cin)

		return false;

	char casilla;

	std::string linea;

	size_t maximo = 0;

	size_t vertice = 0;

	size_t contadorDeManchas = 0;

	ConjuntosDisjuntos cjtos(filas * columnas);

	Matriz<bool> fondoMarino(filas,columnas,false);

	std::vector<std::pair<int,int>> direcciones = {
		{-1,-1} , {-1,0} , {-1,1} ,
		{0,-1} , {0,1} ,
		{1,-1} , {1,0} , {1,1}
	};

	std::getline(std::cin,linea,'\n');

	for( int i = 0 ; i < filas ; i++ ) {

		std::getline(std::cin,linea,'\n');

		while(linea.size() > 0 && linea[0] == '\n' )

			std::getline(std::cin,linea,'\n');

		for( int j = 0 ; j < columnas ; j++ , vertice++ ) {

			casilla = linea[j];

			fondoMarino[i][j] = (casilla == '#');

			if(fondoMarino[i][j]) {

				contadorDeManchas++;

				for(const std::pair<int,int>& dir : direcciones ) {

					size_t verticeDestino = ( ( i + dir.first ) * columnas ) + ( j + dir.second );

					if(fondoMarino.posCorrecta(i+dir.first,j+dir.second))

						if(fondoMarino[i+dir.first][j+dir.second])

							if(!cjtos.unidos(vertice,verticeDestino)) {

								cjtos.unir(vertice,verticeDestino);

								maximo = std::max(cjtos.size(vertice),maximo);

							}

				}

			}

		}

	}

	if(contadorDeManchas > 0 && maximo == 0)

		maximo = 1;

	std::cout << maximo << " ";

	size_t casos;

	std::cin >> casos;

	if(maximo == 0 && casos > 0)

		maximo = 1;

	for( ; casos > 0 ; casos-- )

		resolver(fondoMarino,cjtos,direcciones,maximo);

	std::cout << std::endl;

	return true;

}

int main() {

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
