#include <map>
#include <limits>
#include <fstream>
#include <iostream>
#include "Matriz.h"

const size_t INFINITO = std::numeric_limits<size_t>::max();

/*
size_t floyd(Matriz<size_t>& matrizDeAdyacencia, const size_t& i, const size_t& j, const size_t& k) {

	if(k == 0)

		return (i == j)? 0 : matrizDeAdyacencia[i][j];

	size_t origen = floyd(matrizDeAdyacencia,i,k,k-1);

	size_t destino = floyd(matrizDeAdyacencia,k,j,k-1);

	size_t coste = (origen != INFINITO && destino != INFINITO)? (origen + destino) : INFINITO;

	return std::min( floyd(matrizDeAdyacencia,i,j,k-1) , coste );

}
*/

void resolver(Matriz<size_t>& matrizDeAdyacencia) {

	for(size_t k = 1 ; k < matrizDeAdyacencia.numfils() ; k++)

		for(size_t i = 1 ; i < matrizDeAdyacencia.numfils() ; i++)

			for(size_t j = 1 ; j < matrizDeAdyacencia.numfils() ; j++)

				if(matrizDeAdyacencia[i][k] != INFINITO && matrizDeAdyacencia[k][j] != INFINITO)

					matrizDeAdyacencia[i][j] = std::min( matrizDeAdyacencia[i][j] , matrizDeAdyacencia[i][k] + matrizDeAdyacencia[k][j] );

	size_t gradoDeSeparacion = 0;

	for(size_t i = 1 ; i < matrizDeAdyacencia.numfils() && gradoDeSeparacion != INFINITO ; i++)

		for(size_t j = 1 ; j < matrizDeAdyacencia.numfils() && gradoDeSeparacion != INFINITO ; j++)

			gradoDeSeparacion = std::max( matrizDeAdyacencia[i][j] , gradoDeSeparacion );

	std::cout << ( (gradoDeSeparacion != INFINITO)? std::to_string(gradoDeSeparacion) : "DESCONECTADA" ) << std::endl;

}

Matriz<size_t> cargarDatos(size_t& personas, size_t& relaciones) {

	std::string p1, p2;

	std::map<std::string,size_t> personaVertice;

	std::map<std::string,std::vector<std::string>> amistades;

	Matriz<size_t> matrizDeAdyacencia(personas+1,personas+1,INFINITO);

	for(size_t i = 0 ; i < matrizDeAdyacencia.numfils() ; i++)

		matrizDeAdyacencia[i][i] = 0;

	for(size_t j = 0 ; j < matrizDeAdyacencia.numcols() ; j++)

		matrizDeAdyacencia[0][j] = 0;

	for(size_t i = 0 ; i < matrizDeAdyacencia.numfils() ; i++)

		matrizDeAdyacencia[i][i] = 0;

	for( ; relaciones > 0 ; relaciones-- ) {

		std::cin >> p1 >> p2;

		if(amistades.count(p1))

			amistades[p1].push_back(p2);

		else

			amistades[p1] = { p2 };

		if(amistades.count(p2))

			amistades[p2].push_back(p1);

		else

			amistades[p2] = { p1 };

	}

	size_t vertice = 1;

	for(const auto& p : amistades)

		personaVertice[p.first] = vertice++;

	for(const auto& p : personaVertice)

		for(const auto& r : amistades[p.first])

			matrizDeAdyacencia[personaVertice[p.first]][personaVertice[r]] = 1;

	return matrizDeAdyacencia;

}

bool resuelveCaso() {

	size_t personas;

	size_t relaciones;

	std::cin >> personas >> relaciones;

	if(!std::cin)

		return false;


	Matriz<size_t> matrizDeAdyacencia = cargarDatos(personas,relaciones);

	resolver(matrizDeAdyacencia);

	// std::cout << floyd(matrizDeAdyacencia,1,personas,personas) << std::endl;

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
