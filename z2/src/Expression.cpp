#include "Expression.hh"
#include "Complex.hh"
#include <iostream>
#include <cstring>
using namespace std;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */




/*
    Przeciazenie operatora >>
    Funkcja komunikuje (cerr) gdzie powstal blad przy wczytywaniu wyrazenia zesp
    Argumenty
    StrmWe - referencja do strumienia, z ktorego pobieramy dane
    newex - referencja do wyrazenia zespolonego, ktore wczytujemy
    Zwraca:
    StrmWy - referencja do strumienia, z ktorego pobieramy dane

*/

istream& operator>>(istream& StrmWe, Expression& newex)
{
    StrmWe >> newex.arg1;    //Wczytanie pierwszej liczby zesp
    if(StrmWe.fail()) {
        cerr<<"Blad przy wczytaniu pierwszej liczby zespolonej";
        return StrmWe;     
    }  
    StrmWe >> newex.op; //wczytanie operatora
    if(StrmWe.fail()) {
        cerr<<"Blad przy wczytaniu operatora";
        return StrmWe;   
    }    
    StrmWe >> newex.arg2; // czytanie drugiej liczby zespolonej
    if(StrmWe.fail()) {
        cerr<<"Blad przy wczytaniu drugiej liczby zespolonej";
        return StrmWe; 
    }
    StrmWe.ignore();
    return StrmWe;
}

/*
    Przeciazenie operatora <<
    Argumenty
    StrmWe - referencja do strumienia, do ktorego zapisujemy dane
    expr - referencja do wyrazenia zespolonego, ktore wyswietlamy
    Zwraca:
    StrmWy - referencja do strumienia, z ktorego pobieramy dane

*/
ostream& operator<<(ostream& StrmWy, Expression& expr)
{
    const char operTab[]="+-*/";
    StrmWy<<expr.arg1;
    StrmWy<<" "<<operTab[expr.op]<<" ";
    StrmWy<<expr.arg2;
    return StrmWy;
}
/*
    Przeciazenie operatora >>
    Argumenty
    StrmWe - referencja do strumienia, z ktorego pobieramy dane
    ExprOper - referencja do operatora:+,-,* lub /, ktorego wczytujemy
    Zwraca:
    StrmWy - referencja do strumienia, z ktorego pobieramy dane
    Funkcja stawia flage bledu na StrWe gdy nie rozpozna operatora

*/

istream& operator>>(istream& StrmWe, Operator& ExprOper)
{
    char oper;
    StrmWe >> oper;
    if(oper == '+')
        ExprOper = kAddition;
    else if(oper == '-')
        ExprOper = kSubtraction;
    else if(oper == '*')
        ExprOper = kMultiplication;
    else if(oper == '/')
        ExprOper = kDivision;
    else
    {
        StrmWe.setstate(ios::failbit); // stawiamy flage bledu
    }
    return StrmWe;
}
/*
    funkcaj rozwiazuje wyrazenie zespolone i zwraca wynik, liczbe zespolona
    Argumenty
    expr - referencja do wyrazenia zespolonego, ktore rozwiazujemy
    Zwraca:
    liczba zespolona, wynik dzialania
    Komunikuje na cerr, gdy nie rozpozna operatora
*/

Complex Solve(Expression expr)
{
    switch (expr.op)
    {
    case 0: 
        return expr.arg1+expr.arg2;//0='+', 1='-', 2='*', 3='/'
    case 1:
        return expr.arg1-expr.arg2;
    case 2: 
        return expr.arg1*expr.arg2;
    case 3: 
        return expr.arg1/expr.arg2;
    default:
        cerr<<"Funkcja Solve(): Nieznany operator";
    }
}