#include <fstream>
#include <iostream>
#include "PriorityQueue.h"

typedef struct {
	bool esUnica;
	int comienzo;
	int finalizacion;
	int periodo;
} tarea;

class cmp {
public:
	bool operator () (const tarea& t1, const tarea& t2) {
		return t1.comienzo < t2.comienzo;
	}
};

void resolver(PriorityQueue<tarea,cmp>& agenda, std::pair<int,int> iniFin) {

	tarea tareaActual;

	bool hayConflicto = false;

	agenda.pop(tareaActual);

	while( !agenda.empty() && tareaActual.comienzo < iniFin.second && !hayConflicto ) {

		if(agenda.top().comienzo < tareaActual.finalizacion && agenda.top().comienzo < iniFin.second) {

			hayConflicto = true;

		} else {

			if(!tareaActual.esUnica) {

				tareaActual.comienzo += tareaActual.periodo;

				tareaActual.finalizacion += tareaActual.periodo;

				agenda.push(tareaActual);

			}

			agenda.pop(tareaActual);

		}

	}

	std::cout << ((hayConflicto)? "SI" : "NO") << std::endl;

}

bool resuelveCaso() {

	int unicas;
	int minutos;
	int periodicas;

	std::cin >> unicas >> periodicas >> minutos;

	if(!std::cin)

		return false;

	tarea t;

	int periodo;
	int comienzo;
	int finalizacion;

	PriorityQueue<tarea,cmp> agenda;

	for( int tareas = 0 ; tareas < unicas + periodicas ; tareas++ ) {

		if(tareas < unicas){

			t.periodo = 0;

			t.esUnica = true;

			std::cin >> t.comienzo >> t.finalizacion;

			agenda.push(t);

		} else {

			t.esUnica = false;

			std::cin >> t.comienzo >> t.finalizacion >> t.periodo;

			agenda.push(t);

		}

	}

	resolver( agenda, {0,minutos} );

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
