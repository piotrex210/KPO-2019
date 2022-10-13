#pragma once

#include "Size.hh"
#include "Vector.hh"
#include <iostream>

/**
 * Plik zawiera definicje klasy Matrix oraz zapowiedzi i definicje przeciążeń 
 * oparatorów i metod działających na tej klasie
 * 
 * Modeluje pojęcie macierzy
*/
class Matrix
{
  Vector Column[SIZE]; // reprezentacja macierzy jako tablicy wektorów
public:
  /**
   * Konstruktor macierzy
   * ustawia wartość wszystkich komórek macierzy na 0
  */
  Matrix(){    for(int i=0; i < SIZE; i++){ //konstruktor, wszystkie elementy maja wartosc 0
    for(int j=0; j < SIZE; j++) Column[i][j] = 0; } }

  /*!
  *   przeciążenie operatora [], używane do pobierania stałego wektora
  * Argumenty:
  *   Col - numer kolumny
  * Zwraca:
  *   Column[Col] - wybrany wektor
  */
  const Vector& operator[](unsigned int Col) const  { 
  if(Col >= SIZE) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
  return Column[Col]; }

    /*!
  *   przeciążenie operatora [], używane do zmiany wektora
  * Argumenty:
  *   Col - numer kolumny
  * Zwraca:
  *   Column[Col] - referencja do wybranego wektora
  */
        Vector& operator[](unsigned int Col)        { 
          if(Col >= SIZE) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
          return Column[Col]; }

  /*!
  //  przeciążenie operatora (), używane do pobierania wartości komórki
  * Argumenty:
  *   i - numer kolumny
  *   j - numer wiersza
  * Zwraca:
  *   Column[i][j] - zawartosc wybranej komorki
  */
  const double  operator()(unsigned int i, unsigned int j) const { 
    if(i >= SIZE || j >= SIZE) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
    return Column[i][j]; }

    /*!
  //  przeciążenie operatora (), używane do zmiany wartości komórki
  * Argumenty:
  *   i - numer kolumny
  *   j - numer wiersza
  * Zwraca:
  *   Column[i][j] - referencja do wybranej komorki
  */
        double& operator()(unsigned int i, unsigned int j)       { 
          if(i >= SIZE || j >= SIZE) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
          return Column[i][j]; }
  
  /**
   * przeciążenie operatora =, używanie do kopiowania i przypisywania wartości macierzy
   * Argumenty:
   *  M2 - stała macierz, która zostaje skopiowana
  */
  void operator=(const Matrix& M2);

  /**
   * Funkcja transponująca macierz, zamienia wartości komórek Column[i][j] na Column[j][i]
  */
  void transpose();

  /**
   * Przeciążenie operatora *, wykonuje mnożenie macierzy przez wektor
   * Argumenty:
   *  V1 - wektor, przez który mnożymy macierz
   * Zwraca:
   *  result - wektor, wynik mnożenia
   * 
  */
  Vector operator*(const Vector& V1) const;

   /**
   * Funkcja zamieniająca miejscami kolumny macierzy, zamienia Column[i] z Column[j]
   * Argumenty: 
   *  i - indeks pierwszej kolumny
   *  j - indeks drugiej kolumny
  */
    void ChangeColumns(unsigned int i, unsigned int j);

/**
 * Przeciążenie operatora* wykonującego mnożenie macierzy
 * Argumenty:
 *  M2 - Macierz
 * Zwraca:
 *  Macierz, wynik mnożenia
*/
    Matrix operator*(const Matrix& M2) const;




};



      /**
   * Funkcja oblicza wyznacznik macierzy
   * Argumenty: 
   *  M1 - stała macierz
   * Zwraca:
   *  wyznacznik typu double
  */
  const double Determinant(const Matrix& M1);
/*
    Przeciazenie operatora >>
    Argumenty
    stream - referencja do strumienia, z ktorego pobieramy dane
    matrix - referencja do macierzy, ktora wczytujemy
    Zwraca:
    stream - referencja do strumienia, z ktorego pobieramy dane
    Komunikuje błąd i zwraca stream gdy błędny format danych
*/
std::istream &operator>>(std::istream &stream, Matrix &matrix);

/*
    Przeciazenie operatora << 
    Argumenty
    stream - referencja do strumienia, do ktorego przesylamy dane
    matrix - referencja do stałej macierzy, ktora wyswietlamy/przesylamy
    Zwraca:
    stream - referencja do strumienia, do ktorego przesylamy dane

*/
std::ostream &operator<<(std::ostream &stream, const Matrix &matrix);
