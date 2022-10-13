#include "Vector.hh"
#include <iostream>

// przypisanie wartości do wektora
std::istream &operator>>(std::istream &stream, Vector &vec)
{
    double element = 0;
    for(int i=0; i < SIZE; i++) // dla wszystkich komórek
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
std::ostream &operator<<(std::ostream &stream, const Vector &vec)
{
    for(int i=0; i < SIZE; i++)
    {
        stream << vec(i);
        if(i+1 < SIZE) stream << "\t"; 
    }
    return stream;
}

// dodawanie dwóch wektorów
Vector Vector::operator+(const Vector& V2) const
    {
      Vector result;
      double element = 0;
      for(int i=0; i < SIZE; i++){ // dla każdej komórki
        element = Tab[i] + V2[i]; 
        result[i] = element; // przypisz sumę komórek dwóch wektorów
      }
      return result;
    }

// odejmowanie dwóch wektorów
Vector Vector::operator-(const Vector& V2) const
    {
      Vector result;
      double element = 0;
      for(int i=0; i < SIZE; i++){ // dla każdej komórki
        element = this->Tab[i] - V2[i];
        result[i] = element; // przypisz różnicę komórek dwóch wektorów
      }
      return result;
    }

// obliczanie iloczynu skalarnego - metoda
double Vector::operator&(const Vector& V2) const {
    double result = 0;
    for(int i=0; i < SIZE; i++) // z każdej pary komórek
       result += this->Tab[i]*V2[i]; //policz iloczyn sumuj
    return result;
}



// dzielenie wektora przez liczbę typu double
Vector Vector::operator/(double factor) const
{
  Vector result;
  if(factor == 0) 
    std::cerr << "Vector.cpp: Blad w dzieleniu przez 0!"; // komunikuj błąd, gdy dzieli przez 0
  else{
    for(int i=0; i < SIZE; i++) // każdą komórkę
      result[i] = this->Tab[i] / factor; // podziel przez factor
  }   
  return result;

}

// mnożenie wektora przez liczbę typu double
// kolejność argumentów ma znaczenie
Vector operator*(const Vector& V1, double factor){
  Vector result;
  for(int i=0; i < SIZE; i++) // każdą komórkę
    result[i] = V1[i] * factor; // pomnóż przez factor
  return result;
} 

// mnożenie wektora przez liczbę typu double
// kolejność argumentów ma znaczenie
Vector operator*(double factor, const Vector& V1){
  Vector result;
  for(int i=0; i < SIZE; i++)
    result[i] = V1[i] * factor;
  return result;
}

// przypisanie wektora
void Vector::operator=(const Vector& V2) {
  for(int i=0; i < SIZE; ++i){
    this->Tab[i] = V2[i];
  }
}

