#pragma once

#include "Size.hh"
#include <iostream>
#include <math.h>
#include "Complex.hh"

/**
 * Plik zawiera definicje szablonu Vector oraz zapowiedzi i definicje 
 * przeciążeń operatorów i metod działających na tej klasie.
 * 
 * Modeluje pojęcie wektora
*/
template <typename SType, unsigned int SSize>
class SVector
{
  SType Tab[SSize]; // reprezentacja wektora jako tablicy jednowymiarowej
public:
      /**
       * Konstruktor wektora
       * ustawia watrość wszystkich komórek wektora na 0
      */
    SVector<SType, SSize>() { for(unsigned int i=0; i < SSize; i++) Tab[i] = 0; } // konstruktor

  
/**
 * Przeciążenie operatora (), używanie do wyswietlania/wypisywania 
 * *   komunikuje błąd, gdy przekroczymy zakres tablicy, indeks > SSize
 * zawartosci komórki wektora
 * Argumenty:
 *    i - numer komórki/kolumny
 * Zwraca:
 *    Tab[i] - zawatrosc komórki typu SType
 * */    
    const SType  operator()(unsigned int i) const { 
      if(i >= SSize) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
      return Tab[i]; } // wyswietlenie elementu

/**
 * Przeciążenie operatora (), używanie do zmiany
 * zawartosci komórki wektora
 * *   komunikuje błąd, gdy przekroczymy zakres tablicy, indeks > SSize
 * Argumenty:
 *    i - numer komórki/kolumny
 * Zwraca:
 *    Tab[i] - referencja do komórki o indeksie i
 * */ 
          SType& operator()(unsigned int i)       { 
            if(i >= SSize) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
            return Tab[i]; } // przypisanie wartosci do elementu
  
  /**
 * Przeciążenie operatora [] używanie do wyswietlania/wypisywania 
 * zawartosci komórki wektora
 * *   komunikuje błąd, gdy przekroczymy zakres tablicy, indeks > SSize
 * Argumenty:
 *    i - numer komórki/kolumny
 * Zwraca:
 *    Tab[i] - zawatrosc komórki typu SType
 * */  
    const SType  operator[](unsigned int i) const { 
      if(i >= SSize) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
      return Tab[i]; } // wyswietlenie elementu
 
 /**
 * Przeciążenie operatora [] używanie do zmiany
 * zawartosci komórki wektora
 * *   komunikuje błąd, gdy przekroczymy zakres tablicy, indeks > SSize
 * Argumenty:
 *    i - numer komórki/kolumny
 * Zwraca:
 *    Tab[i] - referencja do komórki o indeksie i
 * */ 
          SType& operator[](unsigned int i)       { 
            if(i >= SSize) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
            return Tab[i]; } // przypisanie wartosci do elementu
 
 /*!
 * Przeciążenie operatora +, realizuje dodawanie
 * dwóch wektorów
 * Argumenty:
 *    V1 - staly wektor
 * Zwraca:
 *    result - nowy wektor, sumę dwóch wektorów Tab + V1
 */
    SVector<SType, SSize> operator+(const SVector<SType, SSize>& V1) const; // dodanie 2 wektorów
 
  /*!
 * Przeciążenie operatora -, realizuje odejmowanie
 * dwóch wektorów
 * Argumenty:
 *    V1 - staly wektor
 * Zwraca:
 *    result - nowy wektor, różnicę 2 wektorów Tab - V1
 */
    SVector<SType, SSize> operator-(const SVector<SType, SSize>& V1) const; // odejmowanie wektorów
 
   /*!
 * Przeciążenie operatora &, realizuje iloczyn skalarny
 * dwóch wektorów
 * Argumenty:
 *    V1 - staly wektor
 * Zwraca:
 *    result - liczba typu SType, iloczyn skalarny
 */
   SType  operator&(const SVector<SType, SSize>& V2) const; // iloczyn skalarny

 
   /*!
 * Przeciążenie operatora /, realizuje dzielenie
 * wektora przez liczbę typu SType
 * Argumenty:
 *    factor - dzielnik, typ SType
 * Zwraca:
 *    result - nowy wektor, iloraz Tab/factor
 */
    SVector<SType, SSize> operator/(SType factor) const; // dzielenie przez liczbe

  /**
   * Przeciążenie operatora =, realizuje operacje przypisania wektorow
   * Argumenty:
   *  V2 - stały wektor
  */
    void operator=(const SVector<SType, SSize>& V2);

//Obliczanie dlugosci wektora
//    double VectorLenght();
};




/*!
 * Realizuje mnozenie wektora przez liczbe typu SType.
 * kolejność argumentów ma znaczenie
 * Argumenty:
 *    V1 - staly wektor
 *    factor- liczba, przez ktorą mnożymy wektor
 * Zwraca:
 *    result - nowy wektor, pomnożony
 */
template <typename SType, unsigned int SSize>
SVector<SType, SSize> operator*(SType factor, const SVector<SType, SSize>& V1);


/**
 * Przeciążenie operatora*, wykonuje mnożenie wektora razy liczbę
 * kolejność argumentów ma znaczenie
 * Argumenty:
 *  factor - czynnik
 *  V1 - wektor
 * Zwraca:
 *  result - wymnożony wektor
*/
template <typename SType, unsigned int SSize>
SVector<SType, SSize> operator*(const SVector<SType, SSize>& V1, SType factor);


/*
    Przeciazenie operatora >> 
    Argumenty
    stream - referencja do strumienia, do ktorego przesylamy dane
    vec - referencja do wektora, ktorego wczytujemy
    Zwraca:
    stream - referencja do strumienia, do ktorego przesylamy dane
*/
template <typename SType, unsigned int SSize>
std::istream &operator>>(std::istream &stream, SVector<SType, SSize> &vec);

/*
    Przeciazenie operatora << 
    Argumenty
    stream - referencja do strumienia, do ktorego przesylamy dane
    vec - referencja do stalego wektora, ktorego wyswietlamy/przesylamy
    Zwraca:
    stream - referencja do strumienia, do ktorego przesylamy dane
*/
template <typename SType, unsigned int SSize>
std::ostream &operator<<(std::ostream &stream, const SVector<SType, SSize> &vec);

/*
// obliczanie iloczynu skalarnego - funkcja
template <typename SType, unsigned int SSize>
SType operator&(const SType V1[SSize]<SType, SSize>, const SType V2[SSize]<SType, SSize>);

*/






// przypisanie wartości do wektora
template <typename SType, unsigned int SSize>
std::istream &operator>>(std::istream &stream, SVector<SType, SSize> &vec)
{
    SType element;
    element = 0;
    for(unsigned int i=0; i < SSize; i++) // dla wszystkich komórek
    {
        stream >> element; //pobierz element
        if(stream.fail()) { // jesli zły format danych, zwróć błąd i zakończ procedurę
          std::cerr << "Blad zapisu macierzy, bledny format danych";
          return stream; }

        vec(i) = element; //jeśli poprawnie wczytano, przypisz element do danej komórki
    }
    return stream;
}

// wyswietlenie/wysłanie wektora
template <typename SType, unsigned int SSize>
std::ostream &operator<<(std::ostream &stream, const SVector<SType, SSize> &vec)
{
    for(unsigned int i=0; i < SSize; i++)
    {
        stream << vec(i);
        if(i+1 < SSize) stream << "\t"; 
    }
    return stream;
}

// dodawanie dwóch wektorów
template <typename SType, unsigned int SSize>
SVector<SType, SSize> SVector<SType, SSize>::operator+(const SVector<SType, SSize>& V2) const
    {
      SVector<SType, SSize> result;
      SType element = 0;
      for(unsigned int i=0; i < SSize; i++){ // dla każdej komórki
        element = Tab[i] + V2[i]; 
        result[i] = element; // przypisz sumę komórek dwóch wektorów
      }
      return result;
    }

// odejmowanie dwóch wektorów
template <typename SType, unsigned int SSize>
SVector<SType, SSize> SVector<SType, SSize>::operator-(const SVector<SType, SSize>& V2) const
    {
      SVector<SType, SSize> result;
      SType element;
      element = 0;
      for(unsigned int i=0; i < SSize; i++){ // dla każdej komórki
        element = this->Tab[i] - V2[i];
        result[i] = element; // przypisz różnicę komórek dwóch wektorów
      }
      return result;
    }

// obliczanie iloczynu skalarnego - metoda
template <typename SType, unsigned int SSize>
SType SVector<SType, SSize>::operator&(const SVector<SType, SSize>& V2) const {
    SType result;
    result = 0;
    for(unsigned int i=0; i < SSize; i++) // z każdej pary komórek
       result = result + this->Tab[i]*V2[i]; //policz iloczyn sumuj
    return result;
}
/*
// obliczanie iloczynu skalarnego - funkcja
template <typename SType, unsigned int SSize>
SType operator&(const SType V1[SSize], const SType V2[SSize]){
    SType result;
    result = 0;
    for(unsigned int i=0; i < SSize; i++) // z każdej pary komórek
       result = result + V1[i]*V2[i]; //policz iloczyn sumuj
    return result;
}
*/


// dzielenie wektora przez liczbę typu SType
template <typename SType, unsigned int SSize>
SVector<SType, SSize> SVector<SType, SSize>::operator/(SType factor) const
{
  SVector<SType, SSize> result;
  if(factor == 0) 
    std::cerr << "SVector.cpp: Blad w dzieleniu przez 0!"; // komunikuj błąd, gdy dzieli przez 0
  else{
    for(unsigned int i=0; i < SSize; i++) // każdą komórkę
      result[i] = this->Tab[i] / factor; // podziel przez factor
  }   
  return result;

}

// mnożenie wektora przez liczbę typu SType
// kolejność argumentów ma znaczenie
template <typename SType, unsigned int SSize>
SVector<SType, SSize> operator*(const SVector<SType, SSize>& V1, SType factor){
  SVector<SType, SSize> result;
  for(unsigned int i=0; i < SSize; i++) // każdą komórkę
    result[i] = V1[i] * factor; // pomnóż przez factor
  return result;
} 

// mnożenie wektora przez liczbę typu SType
// kolejność argumentów ma znaczenie
template <typename SType, unsigned int SSize>
SVector<SType, SSize> operator*(SType factor, const SVector<SType, SSize>& V1){
  SVector<SType, SSize> result;
  for(unsigned int i=0; i < SSize; i++)
    result[i] = V1[i] * factor;
  return result;
}

// przypisanie wektora
template <typename SType, unsigned int SSize>
void SVector<SType, SSize>::operator=(const SVector<SType, SSize>& V2) {
  for(unsigned int i=0; i < SSize; ++i){
    this->Tab[i] = V2[i];
  }
}

/*
//specjalizacja liczenia dlugosci wektora bledu dla nie Complex
template <typename SType, unsigned int SSize>
double SVector<SType, SSize>::VectorLenght(){ 
  double result = 0;
  for(unsigned int i=0; i < SSize; i++) // liczenie iloczynu skalarnego
    result = result + this->Tab[i]*Tab[i]; 
  return sqrt(result); } // pierwiastek z iloczynu skalarnego


//specjalizacja liczenia dlugosci wektora bledu dla Complex
template <unsigned int SSize>
Complex SVector<Complex, SSize>::VectorLenght<Complex, SSize>()  {
  double result;
  Complex conjugation = 0; // sprzężenie liczby zespolonej
  for(unsigned int i = 0, i < SSize; ++i){
    conjugation = this->Tab[i];
    conjugation.im *= -1;
    result += this->Tab[i] * conjunction; // dodaj iloczyny wszystkich wyrazów razy ich sprzężenia
  }
  return sqrt(result); // spierwiastkuj wynik
}
*/
