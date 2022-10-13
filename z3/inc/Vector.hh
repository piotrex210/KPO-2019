#pragma once

#include "Size.hh"
#include <iostream>

/**
 * Plik zawiera definicje klasy Vector oraz zapowiedzi i definicje 
 * przeciążeń operatorów i metod działających na tej klasie.
 * 
 * Modeluje pojęcie wektora
*/
class Vector
{
  double Tab[SIZE]; // reprezentacja wektora jako tablicy jednowymiarowej
public:
      /**
       * Konstruktor wektora
       * ustawia watrość wszystkich komórek wektora na 0
      */
    Vector() { for(int i=0; i < SIZE; i++) Tab[i] = 0; } // konstruktor

  
/**
 * Przeciążenie operatora (), używanie do wyswietlania/wypisywania 
 * zawartosci komórki wektora
 * Argumenty:
 *    i - numer komórki/kolumny
 * Zwraca:
 *    Tab[i] - zawatrosc komórki typu double
 * */    
    const double  operator()(unsigned int i) const { 
      if(i >= SIZE) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
      return Tab[i]; } // wyswietlenie elementu

/**
 * Przeciążenie operatora (), używanie do zmiany
 * zawartosci komórki wektora
 * Argumenty:
 *    i - numer komórki/kolumny
 * Zwraca:
 *    Tab[i] - referencja do komórki o indeksie i
 * */ 
          double& operator()(unsigned int i)       { 
            if(i >= SIZE) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
            return Tab[i]; } // przypisanie wartosci do elementu
  
  /**
 * Przeciążenie operatora [] używanie do wyswietlania/wypisywania 
 * zawartosci komórki wektora
 * Argumenty:
 *    i - numer komórki/kolumny
 * Zwraca:
 *    Tab[i] - zawatrosc komórki typu double
 * */  
    const double  operator[](unsigned int i) const { 
      if(i >= SIZE) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
      return Tab[i]; } // wyswietlenie elementu
 
 /**
 * Przeciążenie operatora [] używanie do zmiany
 * zawartosci komórki wektora
 * Argumenty:
 *    i - numer komórki/kolumny
 * Zwraca:
 *    Tab[i] - referencja do komórki o indeksie i
 * */ 
          double& operator[](unsigned int i)       { 
            if(i >= SIZE) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
            return Tab[i]; } // przypisanie wartosci do elementu
 
 /*!
 * Przeciążenie operatora +, realizuje dodawanie
 * dwóch wektorów
 * Argumenty:
 *    V1 - staly wektor
 * Zwraca:
 *    result - nowy wektor, sumę dwóch wektorów Tab + V1
 */
    Vector operator+(const Vector& V1) const; // dodanie 2 wektorów
 
  /*!
 * Przeciążenie operatora -, realizuje odejmowanie
 * dwóch wektorów
 * Argumenty:
 *    V1 - staly wektor
 * Zwraca:
 *    result - nowy wektor, różnicę 2 wektorów Tab - V1
 */
    Vector operator-(const Vector& V1) const; // odejmowanie wektorów
 
   /*!
 * Przeciążenie operatora &, realizuje iloczyn skalarny
 * dwóch wektorów
 * Argumenty:
 *    V1 - staly wektor
 * Zwraca:
 *    result - liczba typu double, iloczyn skalarny
 */
   double  operator&(const Vector& V2) const; // iloczyn skalarny

 
   /*!
 * Przeciążenie operatora /, realizuje dzielenie
 * wektora przez liczbę typu double
 * Argumenty:
 *    factor - dzielnik, typ double
 * Zwraca:
 *    result - nowy wektor, iloraz Tab/factor
 */
    Vector operator/(double factor) const; // dzielenie przez liczbe

  /**
   * Przeciążenie operatora =, realizuje operacje przypisania wektorow
   * Argumenty:
   *  V2 - stały wektor
  */
    void operator=(const Vector& V2);
};




/*!
 * Realizuje mnozenie wektora przez liczbe typu double.
 * kolejność argumentów ma znaczenie
 * Argumenty:
 *    V1 - staly wektor
 *    factor- liczba, przez ktorą mnożymy wektor
 * Zwraca:
 *    result - nowy wektor, pomnożony
 */
Vector operator*(double factor, const Vector& V1);


/**
 * Przeciążenie operatora*, wykonuje mnożenie wektora razy liczbę
 * kolejność argumentów ma znaczenie
 * Argumenty:
 *  factor - czynnik
 *  V1 - wektor
 * Zwraca:
 *  result - wymnożony wektor
*/
Vector operator*(const Vector& V1, double factor);


/*
    Przeciazenie operatora >> 
    Argumenty
    stream - referencja do strumienia, do ktorego przesylamy dane
    vec - referencja do wektora, ktorego wczytujemy
    Zwraca:
    stream - referencja do strumienia, do ktorego przesylamy dane
*/
std::istream &operator>>(std::istream &stream, Vector &vec);

/*
    Przeciazenie operatora << 
    Argumenty
    stream - referencja do strumienia, do ktorego przesylamy dane
    vec - referencja do stalego wektora, ktorego wyswietlamy/przesylamy
    Zwraca:
    stream - referencja do strumienia, do ktorego przesylamy dane
*/
std::ostream &operator<<(std::ostream &stream, const Vector &vec);


