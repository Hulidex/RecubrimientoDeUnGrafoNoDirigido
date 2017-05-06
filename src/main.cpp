#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "../include/Problema.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
  Problema pr, pr3, pr4;
  ifstream is;


  if (argc != 2){
    cerr << "Uso:" << argv[0] << " <Fichero_Datos>" << endl;
    return 1;
  }

  is.open(argv[1], ifstream::in);

  is >> pr;

  cout << pr;


  is.close();
  return 0;
}
