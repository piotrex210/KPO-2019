#include "SVector.hh"
#include "Size.hh"
#include "Complex.hh"
#include "SMatrix.hh"
#include "SSystem.hh"
#include <math.h>

using namespace std;

int main()
{
  TestComplexAsMatrix();

  char type; // typ wprowadzanych danych: zespolone, albo rzeczywiste
  cin >> type;
  if(type == 'z') TestSzablonSystemComplex();
  else if (type == 'r') TestSzablonSystemDouble();
  else cerr << "Bledna opcja dzialania programu!" << endl << "Do wyboru: z - liczby zesoplone, r - liczby rzeczywiste" << endl;
  


}

