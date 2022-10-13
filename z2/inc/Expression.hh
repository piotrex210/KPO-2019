#pragma once

#include "Complex.hh"

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator
{
    kAddition,
    kSubtraction,
    kMultiplication,
    kDivision
};

/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct Expression
{
    Complex arg1; // Pierwszy argument wyrazenia arytmetycznego
    Operator op;  // Opertor wyrazenia arytmetycznego
    Complex arg2; // Drugi argument wyrazenia arytmetycznego
};

/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */
/*
Wyswietla dwuargumentowe wyrazenie zespolone
*/
void DisplayExpr(Expression expr);
/*

*/
Complex Solve(Expression expr);
/*
Czyta wyrazenie zespolone i je zwraca.
PRE:Liczby zezpolone muszą być zawarte w nawiasach np. (1+3i), i pomiędzy nimi musi być jeden z operatorów:+,-,/,*.
POST:Zwracanie wczytanego wyrazenia
*/

//Funkcja wczytująca wyrazenie zespolone
istream& operator>>(istream& Strm, Expression& expr);

// Funkcja wczytujaca operator wyrazenia
istream& operator>>(istream& StrmWe, Operator& ExprOper);

//Funkcja wyswietlajaca wyrazenie zespolone
ostream& operator<<(ostream& StrmWy, Expression& expr);
