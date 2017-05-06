#include "../include/Problema.hpp"

using namespace std;

ifstream &operator>>(ifstream &in, Problema &pr)
{
  if (!in.is_open()){
    cerr << "Flujo de entrada no abierto" << endl;
    assert(in.is_open());
  }

  //BORRAMOS CONTENIDO ANTERIOR EN Matriz triangular
  pr.m.clear();
  pr.n = 0;

  in >> pr.n;//leemos filas


  pr.m = vector<vector<unsigned int> >(pr.n);

  for (int i = pr.n-1; i >= 0; --i)//reservamos de abajo hacia arriba la matriz
    pr.m[i] = vector<unsigned int>( pr.n - (pr.n-(i+1)) , 0);

  for (unsigned int i = 0; i < pr.n && !in.eof(); ++i)
    for (unsigned int k = 0; k <= i && !in.eof(); ++k)
      in >> pr.m[i][k];



  return in;
}

ostream &operator<<(ostream &out, const Problema &pr)
{
  out << "\t";
  for (unsigned int i = 0; i <  pr.n; ++i)
    out << i << "\t";
  out << endl;

  for (unsigned int i = 0; i < pr.n; ++i){
    out << i << "\t";
    for (unsigned int k = 0; k <=i; ++k)
      out << pr.m[i][k] << "\t";

    out << endl;
    }

    return out;
}

Problema::Problema()
{
    n = 0;
}

Problema::Problema(const Problema &pr)
{
  *this = pr;
}

Problema &Problema::operator=(const Problema &pr)
{
  if (this == &pr)
    return *this;

  this->m.clear();//limpiamos el contenido anterior
  this->n = pr.n;
  this->m = pr.m;

  return *this;
}

unsigned int Problema::get(unsigned int fil, unsigned int col) const
{
  if (fil < col)
    return this->m[col][fil];
  else return this->m[fil][col];
}
