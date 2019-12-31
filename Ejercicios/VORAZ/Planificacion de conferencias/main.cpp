#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "PriorityQueue.h"

typedef struct {
	int inicio;
	int final;
	int salaAsignada;
} conferencia;

class comparadorDeSalas {
public:
	bool operator () (const conferencia& c1, const conferencia& c2) {
		return c1.final < c2.final;
	}
};

class comparadorDeConferencias {
public:
	bool operator () (const conferencia& c1, const conferencia& c2) {
		return (
			(c1.inicio < c2.inicio)
			||
			(c1.inicio == c2.inicio && c1.final > c2.final)
		);
	}
};

/*
int resolver(std::vector<conferencia>& conferencias) {

	conferencia conferenciaActual;

	std::vector<conferencia> estadoActualSalas;

	estadoActualSalas.push_back({-1,-1,0});

	PriorityQueue<conferencia,comparadorDeSalas> proximaSalaLibre;

	proximaSalaLibre.push({-1,-1,0});

	sort(conferencias.begin(),conferencias.end(),comparadorDeConferencias());

	for(size_t i = 0 ; i < conferencias.size() ; i++) {

		conferenciaActual = conferencias[i];

		if(conferenciaActual.inicio >= proximaSalaLibre.top().final) {

			conferenciaActual.salaAsignada = proximaSalaLibre.top().salaAsignada;

			estadoActualSalas[proximaSalaLibre.top().salaAsignada] = conferenciaActual;

			proximaSalaLibre.pop();

		} else {

			conferenciaActual.salaAsignada = estadoActualSalas.size();

			estadoActualSalas.push_back(conferenciaActual);

		}

		proximaSalaLibre.push(conferenciaActual);

	}

	return estadoActualSalas.size();

}
*/

int resolver(std::vector<conferencia>& conferencias) {

	size_t salasNecesarias = 0;

	PriorityQueue<conferencia,comparadorDeSalas> proximaSalaLibre;

	proximaSalaLibre.push({-1,-1,0});

	sort(conferencias.begin(),conferencias.end(),comparadorDeConferencias());

	for(size_t i = 0 ; i < conferencias.size() ; i++) {

		if(conferencias[i].inicio >= proximaSalaLibre.top().final)

			proximaSalaLibre.pop();

		proximaSalaLibre.push(conferencias[i]);

		if(proximaSalaLibre.size() > salasNecesarias)

			salasNecesarias = proximaSalaLibre.size();

	}

	return salasNecesarias;

}

bool resuelveCaso() {

	int numConferencias;

	std::cin >> numConferencias;

	if(numConferencias == 0)

		return false;

	conferencia c;

	std::vector<conferencia> conferencias;

	for( ; numConferencias > 0 ; numConferencias-- ) {

		std::cin >> c.inicio >> c.final;

		conferencias.push_back({ c.inicio , c.final , -1 });

	}

	std::cout << resolver(conferencias) << std::endl;

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
