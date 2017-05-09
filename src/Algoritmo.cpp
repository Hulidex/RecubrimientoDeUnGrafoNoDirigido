#include "../include/Algoritmo.hpp"

Algoritmo::Algoritmo(const Problema &recubrimiento)
{
	this->p = recubrimiento;
	NumeroAristas();
}

void Algoritmo::NumeroAristas()
{
	for (int i = 0; i < p.getTamanio(); ++i)
		for (int k = 0; k <=i; ++k)
			num_aristas += p.getElemento(i,k);
}

bool operator<(const candidato &c1, const  candidato &c2)
{
	return c1.aristas.size() < c2.aristas.size();//aristas.size() es el grado del nodo
}

Algoritmo::Algoritmo(const Algoritmo &alg)
{
	*this = alg;
}


Algoritmo &Algoritmo::operator=(const Algoritmo &alg)
{
	if (this == &alg)
		return *this;
	else{
		this->num_aristas = alg.num_aristas;
		this->p = alg.p;

		return *this;
	}
}


bool EstaArista(const vector<pair<int,int> > &aristas,const pair<int,int> &arista)
{
	bool esta = false;
	vector<pair<int,int> >::const_iterator it;


	for (it = aristas.begin(); it != aristas.end() && !esta; ++it)
		if ((it->first == arista.first && it->second == arista.second) || (it->first == arista.second && it->second == arista.first))
			esta = true;


	return esta;
}


Solucion Algoritmo::Recubrimiento()
{
	list<candidato> candidatos;
	candidato n;
	Solucion sol;
	vector<pair<int,int> >aristas_usadas;
	int n_aristas = 0;

	//INICIALIZAMOS CANDIDATOS
	for (int i = 0; i < p.getTamanio(); ++i){
		n.nodo = i;
		for (int k = 0; k < p.getTamanio(); ++k){
			if ( p.getElemento(i,k) == 1)
				n.aristas.push_back(pair<int,int>(i,k));
		}
		candidatos.push_back(n);
		n.aristas.clear();
	}

	candidatos.sort();//esta operación ordena los candidatos de menor a mayor grado
	candidatos.reverse(); //como nos interesa tenerlos oredenados de mayor a menor grado invertimos la lista.


	//OPERACIÓN
	while(aristas_usadas.size() < num_aristas){
		n =  candidatos.front();//selecionamos el primer candidato, puesto que la lista está ordenada el primero siempre será el mas prometedor
		
		for (int i = 0; i < n.aristas.size(); ++i){
			if (!EstaArista(aristas_usadas, n.aristas[i]))
				aristas_usadas.push_back(n.aristas[i]);
			else n_aristas++;//aristas que ya están usadas en la estructuta "aristas_usadas", del nodo que estoy analizando en el bucle.
		}

		if (!(n_aristas == n.aristas.size()))//!(si todas las aristas del nodo que estoy analizando (n) están usadas, no meto ese nodo).
			sol.aniadirNodo(n.nodo);

		candidatos.pop_front();//borramos el candidato analizado.

		n_aristas = 0;
	}



	return sol;
}

