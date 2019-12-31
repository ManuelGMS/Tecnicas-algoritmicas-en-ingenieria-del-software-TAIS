/*
   TAIS 10, Manuel Guerrero Moñús y Guillermo Delgado Yepes.

   Calculo del coste de la funcion resolver:

	   * Coste total: O( n + n * log( n ) ) = O( n * (1 + log(n)) )

		   * Coste de la ordenacion: O( n * log( n ) )

			   * n: Número de elementos del vector.

		   * Coste del algoritmo voraz: O( n )

			   * n: Número de elementos del vector.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

class Tiempo {

private:

	char separator;

	size_t horas, minutos, duracion, horasFin, minutosFin;

public:

	Tiempo() : separator(' ') , horas(0) , minutos(0) , duracion(0) {

		std::cin >> this->horas >> separator >> this->minutos >> this->duracion;

		this->minutosFin = (this->minutos + this->duracion + 10) % 60;

		this->horasFin = this->horas + (this->minutos + this->duracion + 10) / 60;

	}

	size_t getHoras() const { return this->horas; }

	size_t getDuracion() const { return duracion; }

	size_t getHorasFin() const { return horasFin; }

	size_t getMinutos() const { return this->minutos; }

	size_t getMinutosFin() const { return minutosFin; }

};

bool operator < (const Tiempo& t1, const Tiempo& t2) {

	if(t1.getHorasFin() < t2.getHorasFin())

		return true;

	else if(t1.getHorasFin() == t2.getHorasFin() && t1.getMinutosFin() < t2.getMinutosFin())

		return true;

	return false;

}

bool operator <= (const Tiempo& t1, const Tiempo& t2) {

	return(

			(t1.getHorasFin() < t2.getHoras())

			||

			(t1.getHorasFin() == t2.getHoras() && t1.getMinutosFin() <= t2.getMinutos())

	);

}

size_t resolver(std::vector<Tiempo>& v)
{

	size_t actual = 0, peliculas = 1;

	sort(v.begin(),v.end(),std::less<Tiempo>());

	for( size_t i = 1; i < v.size() ; ++i ) {

		if( v[actual] <= v[i] ) {

			actual = i;

			++peliculas;

		}

	}

    return peliculas;

}

bool resuelveCaso()
{

	size_t pelis;

	std::cin >> pelis;

	if(pelis == 0) return false;

	std::vector<Tiempo> v;

	for( size_t i = 0 ; i < pelis ; ++i )

		v.push_back(Tiempo());

	std::cout << resolver(v) << std::endl;

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
