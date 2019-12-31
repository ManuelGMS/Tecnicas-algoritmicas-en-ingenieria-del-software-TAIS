#include <fstream>
#include <iostream>
#include "Matriz.h"

size_t resolver(const std::string& p1, const std::string& p2) {

	Matriz<size_t> espacioDeSoluciones(p2.size()+1,p1.size()+1,0);

	for(int i = p2.size() - 1 ; i > -1 ; i--)

		for(int j = p1.size() - 1 ; j > -1 ; j--)

			if(p1[j] != p2[i])

				espacioDeSoluciones[i][j] = std::max(espacioDeSoluciones[i+1][j],espacioDeSoluciones[i][j+1]);

			else

				espacioDeSoluciones[i][j] = espacioDeSoluciones[i+1][j+1] + 1;

	return espacioDeSoluciones[0][0];

}

bool resuelveCaso() {

	std::string p1, p2;

	std::cin >> p1 >> p2;

	if(!std::cin)

		return false;

	std::cout << resolver(p1,p2) << std::endl;

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
