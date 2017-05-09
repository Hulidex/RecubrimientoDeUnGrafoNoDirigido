#include <ostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Problema
{
private:
  vector<vector<unsigned int> > m;//matriz Triangular
  unsigned int n;//tamaño filas/columnas matriz Triangular

public:
  Problema();
  Problema(const Problema &pr);
  Problema &operator=(const Problema &pr);
  
  unsigned int getElemento(unsigned int fil, unsigned int col) const;
  unsigned int getTamanio() const;
  void CargarDesdeFichero(const char* file_name);


  friend ifstream &operator>>(ifstream &in, Problema &pr);
  friend ostream &operator<<(ostream &out, const Problema &pr);
};

ifstream &operator>>(ifstream &in, Problema &pr);
ostream &operator<<(ostream &out, const Problema &pr);
