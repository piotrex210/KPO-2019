#include "Matrix.hh"

/*
    Przeciazenie operatora >>
    Argumenty
    stream - referencja do strumienia, z ktorego pobieramy dane
    matrix - referencja do macierzy, ktora wczytujemy
    Zwraca:
    stream - referencja do strumienia, z ktorego pobieramy dane
    Komunikuje błąd i zwraca stream gdy błędny format danych
*/
std::istream &operator>>(std::istream &stream, Matrix &matrix){
    double element = 0;
    
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < SIZE; j++){
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
    matrix - referencja do stałej macierzy, ktora wyswietlamy/przesylamy
    Zwraca:
    stream - referencja do strumienia, do ktorego przesylamy dane

*/
std::ostream &operator<<(std::ostream &stream, const Matrix &matrix)
{
    for(int i=0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++)
        {
            stream << matrix(i, j) << "\t"; // przesylanie zawartości komórki
        }
        stream << "\n"; // dla interfejsu graficznego
    }
    return stream;
}

// przeciążenie operatora przypisania
void Matrix::operator=(const Matrix& M2){
    for(int i=0; i < SIZE; ++i){ // każdej kolumnie
        this->Column[i] = M2[i]; // przypisz wartość kolumny w drugiej macierzy
    }
}

// metoda zamieniająca kolumny miejscami
void Matrix::ChangeColumns(unsigned int i, unsigned int j){
Vector temp = this->Column[j]; // wektor pomocniczy
this->Column[j] = this->Column[i];
this->Column[i] = temp; 
}

// metoda transponująca macierz
  void Matrix::transpose() {
    double temp = 0; // zmienna pomocnicza
    for(int i = 0; i < SIZE; ++i)
      for(int j = i; j < SIZE; ++j){ // od przekątnej w prawo, aby nie zamieniać dwa razy
        temp = Column[i][j];
        Column[i][j] = Column[j][i];
        Column[j][i] = temp;
      }
   }

// przeciążenie operatora mnożenia macierzy przez wektor
Vector Matrix::operator*(const Vector& V1) const {
    Vector result;
    for(int i = 0; i< SIZE; ++i){  
        result[i] = (this->Column[i] & V1);
    }
    return result;
}

// przeciążenie operatora*, mnożenie macierzy przez siebie
Matrix Matrix::operator*(const Matrix& M2) const{
    Matrix result, temp = M2;
    temp.transpose(); // aby kolumna [j] macierzy M2 stała się wierszem [j]
    for(int i=0; i < SIZE; ++i){
        for(int j=0; j < SIZE; ++j){
           result[i][j] = this->Column[i] & temp[j]; // w rzeczywistości kolumna[i] * wiersz[j]
        }
    }
    return result;
}

//obliczanie wyznacznika
const double Determinant(const Matrix& M1){
    double determinant = 1; // wyznacznik
    double scale = 1; // pomocna przy odejmowaniu wierszy
    Matrix temp = M1; // macierz pomocnicza
    int parity = 1; // parzystość
    for(int i = 0; i < SIZE; ++i){
        for(int k = i; k < SIZE && temp[i][i] == 0; ++k){ // wyszukanie el. niezerowego i zamiana
            if(temp[i][k] != 0){ // gdy znajdzie komórkę niezerową
                temp.ChangeColumns(i, k); // zamienia wiersze
                parity = -parity; 
            }
        }
        if(temp[i][i] == 0) { // gdy operacja zamiany wierzy się nie powiodła, bo w kolumnie są same 0
            determinant = 0;
            return determinant;
        }
        for(int j = i + 1; j < SIZE; j++){
            scale = temp[j][i] / temp[i][i]; // mnożnik
            temp[j] = temp[j] - temp[i] * scale; // diegonalizuj
        }
    }
     for(int i = 0; i < SIZE; ++i){  
        if(temp[i][i] == 0) determinant = 0;      
        else determinant *= temp[i][i]; // wyznacznik = iloczyn liczb na przekątnej

    } 

    determinant = determinant * parity; // czy były zmieniane kolumny
    return determinant;

}