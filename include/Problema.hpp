#include <ostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Problema
{
private:
  vector<vector<unsigned int> > m;
  unsigned int n;//filas columnas matriz

public:
  Problema();
  Problema(const Problema &pr);
  Problema &operator=(const Problema &pr);
  unsigned int get(unsigned int fil, unsigned int col) const;


  friend ifstream &operator>>(ifstream &in, Problema &pr);
  friend ostream &operator<<(ostream &out, const Problema &pr);
};

ifstream &operator>>(ifstream &in, Problema &pr);
ostream &operator<<(ostream &out, const Problema &pr);
