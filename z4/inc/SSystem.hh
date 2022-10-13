#pragma once

#include "SMatrix.hh"
#include "Size.hh"
#include <math.h>
#include <iostream>
#include <iomanip>

/*
 *  Plik zawiera definicje klasy SystemOfLinearEquations
 * oraz zapowiedzi i definicje operatorów i metod działających na tej klasie
 * Klasa zawiera: macierz, wektor wyrazów wolnych, wektor rozwiązań, wektor błędu
 * długość wektora błędu
 * 
 * Modeluje pojęcie układu równań liniowych 
 */
template <typename SType, unsigned int SSize>
class SSystemOfLinearEquations
{
  SMatrix<SType, SSize> M1; // macierz
  SVector<SType, SSize> Vb; // wektor wyrazów wolnych
  SVector<SType, SSize> SolutionV; // wektor rozwiązań
  SVector<SType, SSize> ErrorV; // wektor błędu
  SType E; // długość wektora błędu

public:
/**
 * zwraca macierz M1
*/
  SMatrix<SType, SSize>& setMatrixM1(){ return M1; }

  /**
 * zwraca stałą macierz M1
*/
  const SMatrix<SType, SSize> getMatrixM1() const { return M1;}

  /**
 * zwraca wektor Vb
*/
  SVector<SType, SSize>& setVectorb(){ return Vb; }

  /**
   * Zwraca stały wektor Vb
  */
  const SVector<SType, SSize>& getVectorb() const { return Vb; }

/**
 * Zwraca wektor rozwiązań
*/
  SVector<SType, SSize>& setSolutionVector(){ return SolutionV; }

  /**
   * Zwraca stały wektor rozwiązań
  */
  const SVector<SType, SSize>& getSolutionVector() const { return SolutionV; }

/**
 * Zwraca wektor błędu
*/
  SVector<SType, SSize>& setErrorVector(){ return ErrorV; }

  /*
  **Zwraca stały wektor błędu
  */
  const SVector<SType, SSize>& getErrorVector() const { return ErrorV; }

/**
 * Zwraca stałą E, długość wektora błędu
*/
  const SType getE() const { return E; }


  /**
   * Metoda oblicza wszytskie wyznaczniki macierzy, rozwiązuje układ równań
   * Wyświetla komunikat, gdy układ jest sprzeczny lub nieoznaczony
   * oblicza długość wektora błędu, wszystkie właściwości zapisuje w obiektach
   * klasy SystemOfLinearEquations
  */
  void Cramer() ;

  /**
   * Funkcja oblicza wektor błędu macierzy
  */
  void ErrorVec();

};



/*
    Przeciazenie operatora >> 
    Funkcja wczytuje ze strunmienia najpierw Macierz, a później wektor 
    wyrazów wolnych, obiekty klasy SystemOfLinearEquations
    Argumenty
    stream - referencja do strumienia, do ktorego przesylamy dane
    vec - referencja do wektora, ktorego wczytujemy
    Zwraca:
    stream - referencja do strumienia, do ktorego przesylamy dane
*/
template <typename SType, unsigned int SSize>
std::istream &operator>>(std::istream &stream, SSystemOfLinearEquations<SType, SSize> &system);


/*
    Przeciazenie operatora << 
    Funkcja wyświetla układ równań w postaci rozszerzonej z rozdziału 3.5
    wyświetla też wektor rozwiązań, wektor błędu i jego długość
    Argumenty
    stream - referencja do strumienia, do ktorego przesylamy dane
    system - referencja do stalego układu równań, ktorego wyswietlamy/przesylamy
    Zwraca:
    stream - referencja do strumienia, do ktorego przesylamy dane
*/
template <typename SType, unsigned int SSize>
std::ostream &operator<<(std::ostream &stream,
                         const SSystemOfLinearEquations<SType, SSize> &system);




// System.cpp





using namespace std;

// wyświetlanie układu równań
template <typename SType, unsigned int SSize>
std::ostream &operator<<(std::ostream &stream,
                       const SSystemOfLinearEquations<SType, SSize> &system){
    SMatrix<SType, SSize> temp = system.getMatrixM1();
    temp.transpose(); // transponowanie macierzy na potrzebę wyświetlenia
    stream << fixed << setprecision(2);
    stream << "\n";
    for(unsigned int i=0; i < SSize; ++i){
        stream << "|";
        stream << temp[i] << "| |x_" << i+1 <<"|   " ;
        if(i == SSize/2) stream << "=";
        stream << "\t|";
        stream << system.getVectorb()[i] << "|\n";
    }
    stream << "\nRozwiazanie x = (x1, x2, x3):\n\n" << system.getSolutionVector();  
    stream << scientific << setprecision(1);    
    stream << "\n\nWektor bledu: Ax-b = \n\n(" << system.getErrorVector() << ")\n\n";
    //stream << "\n\nDlugosc wektora bledu ||Ax-b|| = " << system.getE() << "\n\n";                
    return stream;
 }

// wczytywanie układu równań
template <typename SType, unsigned int SSize>
std::istream &operator>>(std::istream &stream, SSystemOfLinearEquations<SType, SSize> &system){
  stream >> system.setMatrixM1(); // wczytaj macierz
  stream >> system.setVectorb(); // wczytaj wektor wyrazów wolnych
  return stream; }



//rozwiązanie układu równań
template <typename SType, unsigned int SSize>
void SSystemOfLinearEquations<SType, SSize>::Cramer() {
    unsigned int numerator = 0; // do liczenia zerowych wyznaczników
    SType det;
    det = 0; // wyznacznik macierzy po zamianie kolumn
    SType detM;
    detM = 0; // wyznacznik głównej macierzy
    SVector<SType, SSize> solutionVec; // pomocniczy wektor wyników
    SMatrix<SType, SSize> temp = this->getMatrixM1(); // pomocnicza macierz
    detM = Determinant(temp);
    for(unsigned int i = 0; i < SSize; ++i){
        temp = this->getMatrixM1(); // przywróć pomocniczą macierz
        temp[i] = this->getVectorb(); // podmień kolumnę nr i
        det = Determinant(temp); // oblicz wyznacznik Xi
        if(detM != 0)
            solutionVec(i) = det / detM; // zapisz rozwiazanie do wektora rozwiązań
        else if(det != 0){ // jeśli wyz. główny == 0 i inny wyz. != 0 układ sprzeczny
            std::cout << std::endl << "Układ sprzeczny!" << std::endl << std::endl;
            return;
        }
        else ++numerator; // policz ile jest zerowych wyznaczników
    }
    if(numerator >= SSize && detM == 0) // gdy wszystkie wyznaczniki == 0
        std::cout << std::endl << "Układ nieoznaczony, nieskończenie wiele rozwiązań!" << std::endl << std::endl;
    this->setSolutionVector() = solutionVec; // przypisz wektor wyników w klasie System...

    ErrorVec(); // oblicz wektor błędu

    //this->E = this->ErrorV.VectorLenght(); // oblicz dlugosc wektora bledu

    

}

//obliczanie wektora błędu
template <typename SType, unsigned int SSize>
  void SSystemOfLinearEquations<SType, SSize>::ErrorVec(){ // Ax - b 
    SMatrix<SType, SSize> M1 = this->M1; // pomocnicza macierz
    M1.transpose(); //transponujemy macierz
    SVector<SType, SSize> temp; // wektor pomocniczy
    temp = M1 * this->SolutionV; // Ax
    temp = temp - this->Vb; // Ax - b
    this->setErrorVector() = temp; // zappisanie wyniku w obiekcie klasy
  }

// rozwiązywanie i wyświetlanie układu równań dla liczb rzeczywistych
void TestSzablonSystemDouble(){
    std::cout << std::endl << "Uklad rownan liniowych o wspolczynnikach rzeczywistych:" << std::endl << std::endl; 
    SSystemOfLinearEquations<double, SIZE>  system;
    cin >> system;
    system.Cramer();
    cout << system;
}

// rozwiązywanie i wyświetlanie układu równań dla liczb zespolonych
void TestSzablonSystemComplex(){
      std::cout << std::endl << "Uklad rownan liniowych o wspolczynnikach zespolonych:" << std::endl << std::endl; 
    SSystemOfLinearEquations<Complex, SIZE>  system;
    cin >> system;
    system.Cramer();
    cout << system;
}

// test reprezentacji liczby zespolonej jako macierzy 2X2, w tym przypadku 4 własność
// czy wyznacznik macierzy jest równy modułowi?
void TestComplexAsMatrix(){
  double determinant, modul;
  Complex arg;
  SMatrix<double, 2> m1;
  arg.re = 7;
  arg.im = -3;
  m1(0,0) = arg.re;
  m1(1,1) = arg.re;
  m1(0,1) = -arg.im;
  m1(1,0) = arg.im;

  std::cout << "Test reprezentacji liczby zespolonej jako macierzy" << std::endl;
  std::cout << "LZespolona: " << arg << std::endl << "Macierz: " << std::endl << m1 << std::endl;
  determinant =  Determinant(m1);
  modul = sqrt(pow(arg.re,2)+pow(arg.im,2));
  std::cout << "Modul: " << modul << std::endl << "Wyznaczknik: " << determinant << std::endl;
  std::cout << "Wniosek: Wyznacznik i moduł nie są sobie równe!" << std::endl;
}

