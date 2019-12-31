/*
 * DEFINICION:
 *
 * F(i) = Numero maximo de minutos que puedo ver de una serie de 1 .. i peliculas, teniendo un total de N peliculas.
 *
 * CASO BASE:
 *
 * F(i) = Duracion pelicula 1 <--> Si i = 1
 *
 * CASO RECURSIVO:
 *
 * F(i) = { max { Duracion pelicula i , F(j) + Duracion pelicula i } } <--> Si 1 < i <= N
 *
 * ForAll j : ( 1 <= j < i )
 *
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

class Movie {

private:

	size_t hourBegin, minuteBegin, hourEnd, minuteEnd, duration;

public:

	Movie(size_t m) : hourBegin(0), minuteBegin(0), hourEnd(0), minuteEnd(0), duration(0) { }

	Movie() : hourBegin(0), minuteBegin(0), hourEnd(0), minuteEnd(0), duration(0) {

		char separator;

		std::cin >> this->hourBegin >> separator >> this->minuteBegin >> this->duration;

		this->hourEnd = this->hourBegin + ((this->minuteBegin + this->duration + 10) / 60);

		this->minuteEnd = (this->minuteBegin + this->duration + 10) % 60;

	}

	static bool evaluateMovies(const std::vector<Movie>& movies, const size_t& i, const size_t& j) {

		bool hourIsLess = (movies[j].getHourEnd() < movies[i].getHourBegin());

		bool sameHourLessMinutes = (movies[j].getHourEnd() == movies[i].getHourBegin() && movies[j].getMinuteEnd() <= movies[i].getMinuteBegin());

		return (hourIsLess || sameHourLessMinutes)? true : false;

	}

	size_t getHourEnd() const { return hourEnd; }

	size_t getDuration() const { return duration; }

	size_t getHourBegin() const { return hourBegin; }

	size_t getMinuteEnd() const { return minuteEnd; }

	size_t getMinuteBegin() const { return minuteBegin; }

};

class MovieComparator {

public:

	bool operator () (const Movie& m1, const Movie& m2){

		if(m1.getHourBegin() < m2.getHourBegin()) {

			return true;

		} else if(m1.getHourBegin() == m2.getHourBegin()) {

			if(m1.getMinuteBegin() < m2.getMinuteBegin())

				return true;

		}

		return false;

	}

};

size_t resolver(const std::vector<Movie>& movies) {

	size_t maximo;

	std::vector<size_t> vectorDecCombinaciones(movies.size(),0);

	vectorDecCombinaciones[1] =  movies[1].getDuration();

	for(size_t i = 2 ; i < movies.size() ; ++i) {

		maximo = 0;

		for(size_t j = 1 ; j < i ; ++j)

			maximo = std::max(maximo, (Movie::evaluateMovies(movies,i,j))? vectorDecCombinaciones[j] : 0 );

		vectorDecCombinaciones[i] = movies[i].getDuration() + maximo;

	}

	return *std::max_element(vectorDecCombinaciones.begin(),vectorDecCombinaciones.end());

}

bool resuelveCaso()
{

	size_t P;

	std::cin >> P;

	if(P == 0)

		return false;

	std::vector<Movie> movies;

	movies.push_back(Movie(0));

	for( ; P > 0 ; --P)

		movies.push_back(Movie());

	std::sort(movies.begin()+1,movies.end(),MovieComparator());

	std::cout << resolver(movies) << std::endl;

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
