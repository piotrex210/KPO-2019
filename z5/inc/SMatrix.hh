#pragma once


#include "SVector.hh"


#include <iostream>

/**
 * Plik zawiera definicje szablony SMatrix oraz zapowiedzi i definicje przeciążeń 
 * oparatorów i metod działających na tym szablonie
 * 
 * Modeluje pojęcie macierzy
*/
template <typename SType, unsigned int SSize>
class SMatrix
{
protected:
    SVector<SType, SSize> Column[SSize]; // reprezentacja macierzy jako tablicy wektorów
public:
  /**
   * Konstruktor macierzy
   * ustawia wartość wszystkich komórek macierzy na 0
  */
  SMatrix<SType, SSize>(){    for(unsigned int i=0; i < SSize; i++){ //konstruktor, wszystkie elementy maja wartosc 0
    for(unsigned int j=0; j < SSize; j++) Column[i][j] = 0; } }

  /*!
  *   przeciążenie operatora [], używane do pobierania stałego wektora
  *   komunikuje błąd, gdy przekroczymy zakres tablicy, indeks > SSize
  * Argumenty:
  *   Col - numer kolumny
  * Zwraca:
  *   Column[Col] - wybrany wektor
  */
  const SVector<SType, SSize>& operator[](unsigned int Col) const  { 
  if(Col >= SSize) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
  return Column[Col]; }

    /*!
  *   przeciążenie operatora [], używane do zmiany wektora
  *   komunikuje błąd, gdy przekroczymy zakres tablicy, indeks > SSize
  * Argumenty:
  *   Col - numer kolumny
  * Zwraca:
  *   Column[Col] - referencja do wybranego wektora
  */
        SVector<SType, SSize>& operator[](unsigned int Col)        { 
          if(Col >= SSize) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
          return Column[Col]; }

  /*!
  //  przeciążenie operatora (), używane do pobierania wartości komórki
  *   komunikuje błąd, gdy przekroczymy zakres tablicy, indeks > SSize
  * Argumenty:
  *   i - numer kolumny
  *   j - numer wiersza
  * Zwraca:
  *   Column[i][j] - zawartosc wybranej komorki
  */
  const SType  operator()(unsigned int i, unsigned int j) const { 
    if(i >= SSize || j >= SSize) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
    return Column[i][j]; }

    /*!
  //  przeciążenie operatora (), używane do zmiany wartości komórki
  *   komunikuje błąd, gdy przekroczymy zakres tablicy, indeks > SSize
  * Argumenty:
  *   i - numer kolumny
  *   j - numer wiersza
  * Zwraca:
  *   Column[i][j] - referencja do wybranej komorki
  */
        SType& operator()(unsigned int i, unsigned int j)       { 
          if(i >= SSize || j >= SSize) std::cerr << "Blad: Operator indeksujacy, wyjscie poza zakres!\n"; 
          return Column[i][j]; }
  
  /**
   * przeciążenie operatora =, używanie do kopiowania i przypisywania wartości macierzy
   * Argumenty:
   *  M2 - stała macierz, która zostaje skopiowana
  */
  void operator=(const SMatrix<SType, SSize>& M2);

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
  SVector<SType, SSize> operator*(const SVector<SType, SSize>& V1) const;

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
    SMatrix<SType, SSize> operator*(const SMatrix<SType, SSize>& M2) const;




};



      /**
   * Funkcja oblicza wyznacznik macierzy
   * Argumenty: 
   *  M1 - stała macierz
   * Zwraca:
   *  wyznacznik typu SType
  */
template <typename SType, unsigned int SSize>
  const SType Determinant(const SMatrix<SType, SSize>& M1);
/*
    Przeciazenie operatora >>
    Argumenty
    stream - referencja do strumienia, z ktorego pobieramy dane
    SMatrix<SType, SSize> - referencja do macierzy, ktora wczytujemy
    Zwraca:
    stream - referencja do strumienia, z ktorego pobieramy dane
    Komunikuje błąd i zwraca stream gdy błędny format danych
*/
template <typename SType, unsigned int SSize>
std::istream &operator>>(std::istream &stream, SMatrix<SType, SSize> &smatrix);

/*
    Przeciazenie operatora << 
    Argumenty
    stream - referencja do strumienia, do ktorego przesylamy dane
    SMatrix<SType, SSize> - referencja do stałej macierzy, ktora wyswietlamy/przesylamy
    Zwraca:
    stream - referencja do strumienia, do ktorego przesylamy dane

*/
template <typename SType, unsigned int SSize>
std::ostream &operator<<(std::ostream &stream, const SMatrix<SType, SSize> &smatrix);

void TestComplex();

void TestDouble();


using Matrix3D = SMatrix<double, 3>;







// byłe Matrix.cpp





/*
    Przeciazenie operatora >>
    Argumenty
    stream - referencja do strumienia, z ktorego pobieramy dane
    SMatrix<SType, SSize> - referencja do macierzy, ktora wczytujemy
    Zwraca:
    stream - referencja do strumienia, z ktorego pobieramy dane
    Komunikuje błąd i zwraca stream gdy błędny format danych
*/
template <typename SType, unsigned int SSize>
std::istream &operator>>(std::istream &stream, SMatrix<SType, SSize> &matrix){
    SType element;
    element = 0;
    
    for(unsigned int i=0; i < SSize; i++)
    {
        for(unsigned int j=0; j < SSize; j++){
            stream >> element;
            if(stream.fail()) { // jesli zły format danych, zwróć błąd i zakończ procedurę
                std::cerr << "Blad zapisu macierzy, bledny format danych";
                return stream; }
            matrix(i, j) = element; //wczytanie danej wartości do komórki
        }
    }
    return stream; 
}

/*
    Przeciazenie operatora << 
    Argumenty
    stream - referencja do strumienia, do ktorego przesylamy dane
    SMatrix<SType, SSize> - referencja do stałej macierzy, ktora wyswietlamy/przesylamy
    Zwraca:
    stream - referencja do strumienia, do ktorego przesylamy dane

*/
template <typename SType, unsigned int SSize>
std::ostream &operator<<(std::ostream &stream, const SMatrix<SType, SSize> &matrix)
{
    for(unsigned int i=0; i < SSize; i++){
        for(unsigned int j=0; j < SSize; j++)
        {
            stream << matrix(i, j) << "\t"; // przesylanie zawartości komórki
        }
        stream << "\n"; // dla interfejsu graficznego
    }
    return stream;
}

// przeciążenie operatora przypisania
template <typename SType, unsigned int SSize>
void SMatrix<SType, SSize>::operator=(const SMatrix<SType, SSize>& M2){
    for(unsigned int i=0; i < SSize; ++i){ // każdej kolumnie
        this->Column[i] = M2[i]; // przypisz wartość kolumny w drugiej macierzy
    }
}

// metoda zamieniająca kolumny miejscami
template <typename SType, unsigned int SSize>
void SMatrix<SType, SSize>::ChangeColumns(unsigned int i, unsigned int j){
SVector<SType, SSize> temp = this->Column[j]; // wektor pomocniczy
this->Column[j] = this->Column[i];
this->Column[i] = temp; 
}

// metoda transponująca macierz
template <typename SType, unsigned int SSize>
  void SMatrix<SType, SSize>::transpose() {
    SType temp;
    temp = 0; // zmienna pomocnicza
    for(unsigned int i = 0; i < SSize; ++i)
      for(unsigned int j = i; j < SSize; ++j){ // od przekątnej w prawo, aby nie zamieniać dwa razy
        temp = Column[i][j];
        Column[i][j] = Column[j][i];
        Column[j][i] = temp;
      }
   }

// przeciążenie operatora mnożenia macierzy przez wektor
template <typename SType, unsigned int SSize>
SVector<SType, SSize> SMatrix<SType, SSize>::operator*(const SVector<SType, SSize>& V1) const {
    SVector<SType, SSize> result;
    for(unsigned int i = 0; i< SSize; ++i){  
        result[i] = (this->Column[i] & V1);
    }
    return result;
}

// przeciążenie operatora*, mnożenie macierzy przez siebie
template <typename SType, unsigned int SSize>
SMatrix<SType, SSize> SMatrix<SType, SSize>::operator*(const SMatrix<SType, SSize>& M2) const{
    SMatrix<SType, SSize> result, temp = M2;
    temp.transpose(); // aby kolumna [j] macierzy M2 stała się wierszem [j]
    for(unsigned int i=0; i < SSize; ++i){
        for(unsigned int j=0; j < SSize; ++j){
           result[i][j] = this->Column[i] & temp[j]; // w rzeczywistości kolumna[i] * wiersz[j]
        }
    }
    return result;
}

//obliczanie wyznacznika
template <typename SType, unsigned int SSize>
const SType Determinant(const SMatrix<SType, SSize>& M1){
    SType determinant;
    determinant = 1; // wyznacznik
    SType scale;
    scale = 1; // pomocna przy odejmowaniu wierszy
    SMatrix<SType, SSize> temp = M1; // macierz pomocnicza
    int parity = 1; // parzystość
    for(unsigned int i = 0; i < SSize; ++i){
        for(unsigned int k = i; k < SSize && temp[i][i] == 0; ++k){ // wyszukanie el. niezerowego i zamiana
            if(temp[i][k] != 0){ // gdy znajdzie komórkę niezerową
                temp.ChangeColumns(i, k); // zamienia wiersze
                parity = -parity; 
            }
        }
        if(temp[i][i] == 0) { // gdy operacja zamiany wierzy się nie powiodła, bo w kolumnie są same 0
            determinant = 0;
            return determinant;
        }
        for(unsigned int j = i + 1; j < SSize; j++){
            scale = temp[j][i] / temp[i][i]; // mnożnik
            temp[j] = temp[j] - temp[i] * scale; // diegonalizuj
        }
    }
     for(unsigned int i = 0; i < SSize; ++i){  
        if(temp[i][i] == 0) determinant = 0;      
        else determinant *= temp[i][i]; // wyznacznik = iloczyn liczb na przekątnej

    } 

    determinant = determinant * parity; // czy były zmieniane kolumny
    return determinant;

}
/*
// funkcja wykonująca test szablonu Macierzy dla klasy Complex, testuje metodę Determinant, liczącą wyznacznik
// dane do testu są pobierane z pliku rownanieLiniowe.dat
template <typename SType, unsigned int SSize>
void TestSzablonWyznacznikComplex(){
    std::cout << std::endl << "Test klasy SMatrix<Complex, SIZE>" << std::endl << std::endl; // SIZE = 2
    SMatrix<Complex, SSize>  M1, M2;
    Complex det; // wyznacznik
    std::cin >> M1;
    std::cout << std::endl << "Macierz M1: " << std::endl << M1 << std::endl;
    det = Determinant(M1);
    std::cout << "Wyznacznik macierzy M1 = " << det << std::endl << std::endl;
    M2 = M1 * M1;
    std::cout << "Macierz M2 = M1 * M1: " << std::endl << M2 << std::endl;
    M2.transpose();
    std::cout << "Macierz M2 transponowana: " << std::endl << M2 << std::endl;
}
*/

template <typename SType, unsigned int SSize>
void TestSzablonWyznacznikDouble(){
    std::cout << std::endl << "Test klasy SMatrix<Complex, SIZE>" << std::endl << std::endl; // SIZE = 2
    SMatrix<double, SSize>  M3, M4;
    double det; // wyznacznik
    std::cin >> M3;
    std::cout << std::endl << "Macierz M3: " << std::endl << M3 << std::endl;
    det = Determinant(M3);
    std::cout << "Wyznacznik macierzy M3 = " << det << std::endl << std::endl;
    M4 = M3 * M3;
    std::cout << "Macierz M4 = M3 * M3: " << std::endl << M4 << std::endl;
    M4.transpose();
    std::cout << "Macierz M4 transponowana: " << std::endl << M4 << std::endl;
}