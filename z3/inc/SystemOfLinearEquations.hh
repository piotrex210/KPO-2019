#pragma once

#include "Matrix.hh"
#include <iostream>

/*
 *  Plik zawiera definicje klasy SystemOfLinearEquations
 * oraz zapowiedzi i definicje operatorów i metod działających na tej klasie
 * Klasa zawiera: macierz, wektor wyrazów wolnych, wektor rozwiązań, wektor błędu
 * długość wektora błędu
 * 
 * Modeluje pojęcie układu równań liniowych 
 */
class SystemOfLinearEquations
{
  Matrix M1; // macierz
  Vector Vb; // wektor wyrazów wolnych
  Vector SolutionV; // wektor rozwiązań
  Vector ErrorV; // wektor błędu
  double E; // długość wektora błędu

public:
/**
 * zwraca macierz M1
*/
  Matrix& setMatrixM1(){ return M1; }

  /**
 * zwraca stałą macierz M1
*/
  const Matrix getMatrixM1() const { return M1;}

  /**
 * zwraca wektor Vb
*/
  Vector& setVectorb(){ return Vb; }

  /**
   * Zwraca stały wektor Vb
  */
  const Vector& getVectorb() const { return Vb; }

/**
 * Zwraca wektor rozwiązań
*/
  Vector& setSolutionVector(){ return SolutionV; }

  /**
   * Zwraca stały wektor rozwiązań
  */
  const Vector& getSolutionVector() const { return SolutionV; }

/**
 * Zwraca wektor błędu
*/
  Vector& setErrorVector(){ return ErrorV; }

  /*
  **Zwraca stały wektor błędu
  */
  const Vector& getErrorVector() const { return ErrorV; }

/**
 * Zwraca stałą E, długość wektora błędu
*/
  const double getE() const { return E; }


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
std::istream &operator>>(std::istream &stream, SystemOfLinearEquations &system);


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
std::ostream &operator<<(std::ostream &stream,
                         const SystemOfLinearEquations &system);
