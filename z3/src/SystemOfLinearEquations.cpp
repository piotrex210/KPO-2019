#include "SystemOfLinearEquations.hh"
#include <math.h>
using namespace std;

// wyświetlanie układu równań
std::ostream &operator<<(std::ostream &stream,
                       const SystemOfLinearEquations &system){
    Matrix temp = system.getMatrixM1();
    temp.transpose(); // transponowanie macierzy na potrzebę wyświetlenia
    stream << endl;
    for(int i=0; i < SIZE; ++i){
        stream << "|";
        stream << temp[i] << "\t| |x_" << i+1 <<"|    " ;
        if(i == SIZE/2) stream << "=";
        stream << "\t|";
        stream.width(5); // aby kolumna wyrazów wolnych ładnie wyglądała
        stream << system.getVectorb()[i] << "\t|\n";
    }
    stream << "\nRozwiazanie x = (x1, x2, x3):\n\n" << system.getSolutionVector();      
    stream << "\n\nWektor bledu: Ax-b = \n\n(" << system.getErrorVector() << ")";
    stream << "\n\nDlugosc wektora bledu ||Ax-b|| = " << system.getE() << "\n\n";                
    return stream;
 }

// wczytywanie układu równań
std::istream &operator>>(std::istream &stream, SystemOfLinearEquations &system){
  stream >> system.setMatrixM1(); // wczytaj macierz
  stream >> system.setVectorb(); // wczytaj wektor wyrazów wolnych
  return stream; }



//rozwiązanie układu równań
void SystemOfLinearEquations::Cramer() {
    int numerator = 0; // do liczenia zerowych wyznaczników
    double det = 0; // wyznacznik macierzy po zamianie kolumn
    double detM = 0; // wyznacznik głównej macierzy
    Vector solutionVec; // pomocniczy wektor wyników
    Matrix temp = this->getMatrixM1(); // pomocnicza macierz
    detM = Determinant(temp);
    for(int i = 0; i < SIZE; ++i){
        temp = this->getMatrixM1(); // przywróć pomocniczą macierz
        temp[i] = this->getVectorb(); // podmień kolumnę nr i
        det = Determinant(temp); // oblicz wyznacznik Xi
        if(detM != 0)
            solutionVec(i) = det / detM; // zapisz rozwiazanie do wektora rozwiązań
        else if(det != 0){ // jeśli wyz. główny == 0 i inny wyz. != 0 układ sprzeczny
            cout << endl << "Układ sprzeczny!" << endl << endl;
            return;
        }
        else ++numerator; // policz ile jest zerowych wyznaczników
    }
    if(numerator >= SIZE && detM == 0) // gdy wszystkie wyznaczniki == 0
        cout << endl << "Układ nieoznaczony, nieskończenie wiele rozwiązań!" << endl << endl;
    this->setSolutionVector() = solutionVec; // przypisz wektor wyników w klasie System...

    ErrorVec(); // oblicz wektor błędu

    this->E = sqrt(this->ErrorV & this->ErrorV); // oblicz długość wektora błędu = pierwiastek z sprzężenia
    

}

//obliczanie wektora błędu
  void SystemOfLinearEquations::ErrorVec(){ // Ax - b 
    Matrix M1 = this->M1; // pomocnicza macierz
    M1.transpose(); //transponujemy macierz
    Vector temp; // wektor pomocniczy
    temp = M1 * this->SolutionV; // Ax
    temp = temp - this->Vb; // Ax - b
    this->setErrorVector() = temp; // zappisanie wyniku w obiekcie klasy
  }







