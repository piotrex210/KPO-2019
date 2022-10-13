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
};

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

Complex operator+(Complex arg1, Complex arg2); //dodawanie
Complex operator-(Complex arg1, Complex arg2); //odejmowanie
Complex operator*(Complex arg1, Complex arg2); //mnożenie
Complex operator/(Complex arg1, Complex arg2); //dzielenie
                                                /*dzielenie=>Liczba*sprzężenie/(modul^2)*/
//Wczytanie liczby zespolonej
// przypisanie liczby zespolonej, w domysle '=', ale wyskakiwal blad
void operator%(Complex& arg1, Complex arg2);
//przypisanie iloczynu
void operator*=(Complex& arg1, Complex arg2);
//przypisanie roznicy
void operator-=(Complex& arg1, Complex arg2);
//obliczanie argumentu liczby zespolonej
double Argument(Complex arg1);

//wczytanie liczby zespolonej ze strumienia wejscia
istream& operator>>(istream& StrmWe, Complex& Lz );                                                               
/*Funkcja wyświetla liczbę zespoloną w nawiasach*/
ostream& operator<<(ostream& StrmWy, Complex& Lz );
// wczytanie odpowiedzi uzytkownika
void enterAnswer(Complex& result);
//porownanie 2 liczb zespolonych
bool operator==(Complex arg1, Complex arg2);