#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

typedef struct {
	int id;
	int frecuencia;
	int frecuenciaAcumulada;
} datagrama;

class cmp {
public:
	bool operator () (const datagrama& p1, const datagrama& p2) {
		return (
			(p1.frecuenciaAcumulada < p2.frecuenciaAcumulada)
			||
			(p1.frecuenciaAcumulada == p2.frecuenciaAcumulada && p1.id < p2.id)
		)
		? true : false;
	}
};

void resolver(PriorityQueue<datagrama,cmp>& red, int& envios) {

	datagrama paquetePrioritario;

	while(envios > 0) {

		red.pop(paquetePrioritario);

		std::cout << paquetePrioritario.id << std::endl;

		paquetePrioritario.frecuenciaAcumulada += paquetePrioritario.frecuencia;

		red.push(paquetePrioritario);

		envios--;

	}

	std::cout << "----" << std::endl;

}

bool resuelveCaso() {

	int usuarios;

	std::cin >> usuarios;

	if(usuarios == 0)

		return false;

	datagrama paquete;

	PriorityQueue<datagrama,cmp> red;

	for( ; usuarios > 0 ; usuarios--) {

		std::cin >> paquete.id >> paquete.frecuencia;

		red.push({paquete.id,paquete.frecuencia,paquete.frecuencia});

	}

	int envios;

	std::cin >> envios;

	resolver(red,envios);

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
