#include "Complex.hh"
#include "math.h"
#include <iostream>
#include <iomanip> 
 
#define CORRECT 5
using namespace std;
/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik dodawania,
 *    arg2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
Complex operator+(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = arg1.re + arg2.re;
    result.im = arg1.im + arg2.im;
    return result;
}
/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - odjemna
 *    arg2 - odjemnik
 * Zwraca:
 *    roznice dwoch skladnikow przekazanych jako parametry.
 */
Complex operator-(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = arg1.re - arg2.re;
    result.im = arg1.im - arg2.im;
    return result;
}
/*
    Funkcja przypisania, dziala jak '=' dla zmiennych. 
    Po wykonaniu, pierwszy argument jest rowny drugiemu
*/
void operator%(Complex& arg1, Complex arg2)
{
    arg1.re = arg2.re;
    arg1.im = arg2.im;
}
/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - odjemna
 *    arg2 - odjemnik
 * roznica jest zapisywana jako pierwszy argument
 */
void operator-=(Complex& arg1, Complex arg2)
{
    arg1 % (arg1 - arg2);
}
/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy czynnik
 *    arg2 - drugi czynnik
 * iloczyn jest zapisywany jako pierwszy argument
 */
void operator*=(Complex& arg1, Complex arg2)
{
    arg1 % (arg1 * arg2);
}
/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy czynnik mnozenia,
 *    arg2 - drugi czynnik mnozenia.
 * Zwraca:
 *    iloczyn dwoch liczb zesp przekazanych jako parametry.
 */
Complex operator*(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = arg1.re*arg2.re-arg1.im*arg2.im;
    result.im = arg1.im*arg2.re+arg1.re*arg2.im;
    return result;
}
/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * dzielenie liczb zesp:
 * Lzesp*sprzezenie/(modul)^2
 * Argumenty:
 *    arg1 - dzielna
 *    arg2 - dzielnik
 * Zwraca:
 *    Sume iloraz liczb zesp przekazanych jako parametry.
 */
Complex operator/(Complex arg1, Complex arg2)
{
    if(arg2.im==0 && arg2.re==0){
    cerr<<"Blad w dzieleniu przez 0"<<endl;
    }
    else
    {
    Complex result;

    result.re = (arg1.re*arg2.re-arg1.im*arg2.im*(-1))/(pow(arg2.re,2)+pow(arg2.im,2));
    result.im = (arg1.im*arg2.re+arg1.re*arg2.im*(-1))/(pow(arg2.re,2)+pow(arg2.im,2));
    return result;
    }
}
/*
// sprawdza czy liczby zespolone sa takie same z dokladnozcia do 0.1?
    Argumenty: 
    arg1 - liczba zesp
    arg2 - liczba zesp
    Zwraca:
        true - gdy liczby takie same
        false - gdy liczby inne
*/

bool operator==(Complex arg1, Complex arg2)
{
    if(abs(arg1.re - arg2.re)<0.1 && (arg1.im - arg2.im)<0.1) // czy liczby zespolone/
                                                    // sa takie same z zaoktagleniem do 0.1
        return true; //tak
    else
        return false; // nie
}
/*
    Przeciazenie operatora << 
    Argumenty
    StrmWy - referencja do strumienia, do ktorego przesylamy dane
    Lz - referencja do liczby zespolonej, ktora wyswietlamy/przesylamy
    Zwraca:
    StrmWy - referencja do strumienia, do ktorego przesylamy dane

*/
ostream& operator<<(ostream& StrmWy, Complex& Lz )
{
  StrmWy<<setprecision(3)<<"("<<Lz.re<<showpos<<Lz.im<<noshowpos<<"i)"<<setprecision(6); 
  //ustaw dokladnosc do 3 cyfr, pokaz znak liczby, nie pokazuj znaku, precyzja 6 cyfr
  return StrmWy;
}

/*
    Przeciazenie operatora >>
    Argumenty
    StrmWe - referencja do strumienia, z ktorego pobieramy dane
    Lz - referencja do liczby zespolonej, ktora wczytujemy
    Zwraca:
    StrmWy - referencja do strumienia, z ktorego pobieramy dane

*/
istream& operator>>(istream& StrmWe, Complex& Lz )
{
    float Arg;
    char  c; // for brackets and operators
    StrmWe>>c;
    if(c != '(') StrmWe.setstate(ios::badbit); // Je??li ??le wprowadzono nawias, postaw flag?? b????du
    if(StrmWe.fail()) return StrmWe; // Jesli flaga b????du zako??cz funkcjie. 
                                    //Podniesiona flaga wydostaje si?? poza funkcj?? 
    StrmWe>>Arg;
    if(StrmWe.fail()) return StrmWe;// Jesli ??le wprowadzono liczb??, postaw flag??
    Lz.re=Arg;
    StrmWe>>Arg;
    if(StrmWe.fail()) return StrmWe; // correct entering float
    Lz.im=Arg;
    StrmWe>>c;
    if(c != 'i') StrmWe.setstate(ios::badbit);
    if(StrmWe.fail()) return StrmWe;//correct form
    StrmWe>>c;
    if(c != ')') StrmWe.setstate(ios::badbit);

    return StrmWe; // jesli Lz wprowadzono poprawnie, to strumien bez flagi
}
/*
    Wczytanie odpowiedzi uzytkownika. Uzytkownik ma 3 szanse na poprawne
    wpisanie liczby zespolonej: '(' double '-' lub '+' double 'i' ')'
    Argumenty
    Arg - referencja do liczby zespolonej, ktora wczytujemy
    Funkcja stawia flage bledu, gdy odpowiedz zostala niezaliczona

*/
void enterAnswer(Complex& Arg)
{
    int counter=0;
    Complex answ;
    while(counter<3 && counter !=CORRECT){ //toleruj do 3 b????dnych wprowadzen zespolonej
        cin>>answ;
        if(!cin.fail()) counter = CORRECT; //strumien nie pokazal flag, zakomunikuj 
                                            // poprawne wpisanie liczby
        else
        {
            counter++; //zlicza bledne odpowiedzi
            cout<<"Blad wczytania liczby zespolonej, zostalo prob: "<<3-counter<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    if(counter==CORRECT){ //poprawne wpisanie, odpowiedz wczytana
        Arg=answ;
    }
    else{
        cout<<"Odpowiedz niezaliczona"<<endl;
        cin.setstate(ios::failbit); // komunikuje bledna odpowiedz, flaga
    }
}
/*
    Oblicza argument liczby zespolonej
    Argument:
        arg1 - liczba zespolona
    Zwraca:
        double, obliczony argument
    Funkcja komunikuje argument nieokreslony stawiajac flage bledu
*/
double Argument(Complex arg1){
    if(abs(arg1.re) > 0.01){ // prawie jak przyrownanie do zera, 
                            //  abs() - wartosc bezwzgledna
        if(arg1.re < 0) 
            return atan2(arg1.im, arg1.re); // atan2(x,y) - zwraca cotangens(x/y)
        else
            return atan2(arg1.im, arg1.re)+M_PI; // M_PI - stala pi, ok 3,14
    }
    else if(abs(arg1.im) > 0.01) // jesli liczba urujona nie jest rowna 0
        if(arg1.im > 0)
            return M_PI*0.5; 
        else
            return -M_PI*0.5;
    else
        cin.setstate(ios::failbit); // komunikuje argument nieokreslony, flaga   

}

