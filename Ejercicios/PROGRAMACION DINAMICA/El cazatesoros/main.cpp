#include <fstream>
#include <iostream>
#include "Matriz.h"

typedef struct
{
	int oro;
	int profundidad;
} cofre;

void resolver(Matriz<size_t>& matrizDeAdyacencia, std::vector<cofre>& vectorDeCofres) {

	Matriz<std::pair<size_t,size_t>> vieneDePosicion(matrizDeAdyacencia.numfils(),matrizDeAdyacencia.numcols(),{0,0});

	for(int t = 1 ; t < matrizDeAdyacencia.numfils() ; t++)

		for(int c = 1 ; c < matrizDeAdyacencia.numcols() ; c++)

			if(t >= (vectorDeCofres[c].profundidad + 2 * vectorDeCofres[c].profundidad)) {

				if(matrizDeAdyacencia[t][c-1] > vectorDeCofres[c].oro + matrizDeAdyacencia[t-(vectorDeCofres[c].profundidad + 2 * vectorDeCofres[c].profundidad)][c-1]) {

					vieneDePosicion[t][c] = {t,c-1};

					matrizDeAdyacencia[t][c] = matrizDeAdyacencia[t][c-1];

				} else {

					vieneDePosicion[t][c] = {t-(vectorDeCofres[c].profundidad + 2 * vectorDeCofres[c].profundidad),c-1};

					matrizDeAdyacencia[t][c] = vectorDeCofres[c].oro + matrizDeAdyacencia[t-(vectorDeCofres[c].profundidad + 2 * vectorDeCofres[c].profundidad)][c-1];

				}

			} else {

				vieneDePosicion[t][c] = {t,c-1};

				matrizDeAdyacencia[t][c] = matrizDeAdyacencia[t][c-1];

			}

	size_t cofreAnterior;
	size_t resultadoAnterior;
	size_t contadorCofres = 0;
	std::vector<size_t> cofresSeleccionados;
	size_t i = matrizDeAdyacencia.numfils() - 1;
	size_t j = matrizDeAdyacencia.numcols() - 1;

	std::cout << matrizDeAdyacencia[i][j] << std::endl;

	while(matrizDeAdyacencia[i][j] != 0) {

		cofreAnterior = j;

		resultadoAnterior = matrizDeAdyacencia[i][j];

		i = vieneDePosicion[i][j].first;
		j = vieneDePosicion[i][j].second;

		if(matrizDeAdyacencia[i][j] != resultadoAnterior){

			contadorCofres++;

			cofresSeleccionados.push_back(cofreAnterior);

		}

	}

	std::cout << contadorCofres << std::endl;

	for(int i = cofresSeleccionados.size() - 1 ; i > -1 ; i--)

		std::cout << vectorDeCofres[cofresSeleccionados[i]].profundidad << " " << vectorDeCofres[cofresSeleccionados[i]].oro << std::endl;

}

bool resuelveCaso() {

	int tiempoOxigeno;

	int totalDeCofres;

	std::cin >> tiempoOxigeno >> totalDeCofres;

	if(!std::cin)

		return false;

	int oro;

	int profundidad;

	std::vector<cofre> vectorDeCofres = { {} };

	Matriz<size_t> matrizDeAdyacencia(tiempoOxigeno+1,totalDeCofres+1,0);

	for( int cofre = 1 ; cofre <= totalDeCofres ; cofre++ ) {

		std::cin >> profundidad >> oro;

		vectorDeCofres.push_back({oro,profundidad});

	}

	resolver(matrizDeAdyacencia,vectorDeCofres);

	std::cout << "----" << std::endl;

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
