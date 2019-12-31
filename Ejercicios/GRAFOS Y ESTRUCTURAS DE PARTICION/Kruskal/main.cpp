#include <vector>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

bool operator < (const Arista<int>& a1, const Arista<int>& a2) {

	return a1.valor() < a2.valor();

}

void kruskal(GrafoValorado<int>& g, PriorityQueue<Arista<int>,std::less<Arista<int>>>& pq) {

	int total = 0;

	std::vector<Arista<int>> aristas;

	// std::vector<int> conjuntosDisjuntos;

	ConjuntosDisjuntos sacos(g.V());

	/*
	for(int i = 0 ; i < g.V() ; ++i)

		conjuntosDisjuntos.push_back(i);
	*/

	while( !pq.empty() && aristas.size() < g.V() - 1 ) {

		Arista<int> a = pq.top();

		pq.pop();

		int origen = a.uno();

		int destino = a.otro(origen);

		/*
		if( conjuntosDisjuntos[origen] != conjuntosDisjuntos[destino] ) {

			int mayor = std::max(conjuntosDisjuntos[origen],conjuntosDisjuntos[destino]);

			int menor = std::min(conjuntosDisjuntos[origen],conjuntosDisjuntos[destino]);

			for(int i = 0 ; i < g.V() ; ++i)

				if(conjuntosDisjuntos[i] == mayor)

					conjuntosDisjuntos[i] = menor;

			total += a.valor();

			aristas.push_back(a);

		}
		*/

		if(!sacos.unidos(origen,destino)) {

			sacos.unir(origen,destino);

			total += a.valor();

			aristas.push_back(a);

		}

	}

	std::cout << "Solucion:" << std::endl;

	for(const Arista<int>& i : aristas)

		std::cout << "Origen: " << i.uno() + 1 << ", Destino: " << i.otro(i.uno()) + 1 << " , Valor: " <<  i.valor() << std::endl;

	std::cout << "Total: " << total << std::endl;

	std::cout << "-------------------------------------" << std::endl;

}

bool resuelveCaso() {

	int V;

	std::cin >> V;

	if(!std::cin)

		return false;

	GrafoValorado<int> g(V);

	PriorityQueue<Arista<int>,std::less<Arista<int>>> pq;

	std::vector<std::vector<std::string>> matrizDeAdyacencia(V,std::vector<std::string>(V));

	for(std::vector<std::string>& v : matrizDeAdyacencia)

		for(std::string& i : v)

			std::cin >> i;

	std::vector<std::vector<int>> matrizDeAdyacentes;

	for(int i = 0 ; i < matrizDeAdyacencia.size() ; ++i)

		for(int j = 0 ; j < matrizDeAdyacencia[0].size() ; ++j)

			if(matrizDeAdyacencia[i][j].compare("I") != 0 && i != j) {

				g.ponArista(Arista<int>(i,j,std::stoi(matrizDeAdyacencia[i][j])));

				pq.push(Arista<int>(i,j,std::stoi(matrizDeAdyacencia[i][j])));

			}

	kruskal(g,pq);

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
