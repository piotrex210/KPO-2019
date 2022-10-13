#pragma once
#include <iostream>
using namespace std;
/*!
 *  Plik zawiera definicje struktury Complex oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct Complex
{
    double re; /*! Pole repezentuje czesc rzeczywista. */
    double im; /*! Pole repezentuje czesc urojona. */

    //podstawienie liczby rzeczywistej do liczby zespolonej
    Complex &operator = (double number) { this->re = number;
        this->im = 0; 
        return *this; }

    /*
    metoda przypisania liczby zespolonej, dziala jak '=' dla zmiennych. 
    Po wykonaniu, pierwszy argument jest rowny drugiemu
    */
    Complex &operator=(const Complex arg2){
        this->re = arg2.re;
        this->im = arg2.im;
        return *this; }



};

Complex operator+(Complex arg1, Complex arg2); //dodawanie
Complex operator-(Complex arg1, Complex arg2); //odejmowanie
Complex operator*(Complex arg1, Complex arg2); //mnożenie
Complex operator/(Complex arg1, Complex arg2); //dzielenie
                                                /*dzielenie=>Liczba*sprzężenie/(modul^2)*/

//przypisanie iloczynu
void operator*=(Complex& arg1, Complex arg2);
//przypisanie roznicy
void operator-=(Complex& arg1, Complex arg2);

//obliczanie argumentu liczby zespolonej
double Argument(Complex arg1);

//wczytanie liczby zespolonej ze strumienia wejscia
istream& operator>>(istream& StrmWe, Complex& Lz );                                                               
/*Funkcja wyświetla liczbę zespoloną w nawiasach*/
ostream& operator<<(ostream& StrmWy,const Complex& Lz );
// wczytanie odpowiedzi uzytkownika
void enterAnswer(Complex& result);
//porownanie 2 liczb zespolonych
bool operator==(Complex arg1, Complex arg2);
// sprawdza czy liczby zespolone sa takie same z dokladnozcia do RESOLUTION
bool operator==(const Complex arg1, double arg2);
// sprawdza czy liczby zespolone sa takie same z dokladnozcia do RESOLUTION
bool operator==(double arg2, const Complex arg1);

// sprawdza czy liczby zespolone sa różne z dokladnozcia do RESOLUTION
bool operator!=(const Complex arg1, double arg2);



// mnożenie Complex * double, przydatne, przy funkcji Determinant, przy mnożeniu razy (-1)
Complex operator*(const Complex& arg1, const double factor);
// mnożenie Complex * double
Complex operator*(const double factor, const Complex& arg1);

// zwracA sprzężenie liczby zespplonej
Complex conjugation(const Complex& arg);
