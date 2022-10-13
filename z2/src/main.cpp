#include <iostream>
#include "Database.hh"
#include <iomanip>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    Database base = {nullptr, 0, 0};
    if (argc < 2)
    {
        cout << endl;
        cout << " Brak opcji okreslajacej rodzaj testu." << endl;
        cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
        cout << endl;
        return 1;
    }
   
    if (Init(&base, argv[1]) == false)
    {
        cerr << " Inicjalizacja testu nie powiodla sie." << endl;
        return 1;
    }
    //zaczynamy test nowych operatorow: '-=' i '*='
     cout << endl;
    cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
    cout << endl;
    Complex arg1, arg2;
    double argument;
    arg1.re=1; // przypisaie poczatkowych wartosci
    arg1.im=0;
    arg2.im=2;
    arg2.re=3;
    cout << "Pierwsza lz: " << arg1 << endl << "Druga lz: " << arg2 << endl << endl; // wyswietlenie liczb zesp

    argument = Argument(arg2);
    if(cin.fail()){
        cout << "Argument liczby: " << arg2 << " jest nieokreslony!" << endl;
        cin.ignore();
    }
    else 
        cout << "Argumentem liczby: " << arg2 << " jest: " << argument << endl;

    arg1-=arg2;
    cout << endl <<"Funkcja -=. Pierwsza lz: " << arg1 << endl << "Druga lz: " << arg2 << endl; // wyswietlenie liczb zesp
    arg1*=arg2;
    cout << "Funkcja *=. Pierwsza lz: " << arg1 << endl << "Druga lz: " << arg2 << endl; // wyswietlenie liczb zesp
    cout << endl;
    cout << " Koniec testu arytmetyki zespolonej: " << argv[1] << endl;
    cout << endl;
   
    
    int correctanswers=0;
    Expression expression;
    Complex result, answer; 

    while (GetNextQuestion(&base, &expression))
    {
        cout << " Podaj wynik operacji : ";
        cout << expression << endl;
        cout << " Odp:";
        result = Solve(expression);
        cout << " Twoja odpowiedz to : ";
        enterAnswer(answer);
        if(!cin.fail())
        {
            if(answer == result){
                cout<<" Odpowiedz poprawna" << endl;
                correctanswers++;   //zliczanie poprawnych odpowiedzi
            }
            else
                cout << " Odpowiedz bledna" << endl;
        }
        cin.clear();
        cout << endl;
    }

    cout << endl;
    cout << " Koniec testu" << endl;
    cout << endl;
    cout << "Ilosc poprawnych odpowiedzi: " << correctanswers << endl;
    cout << "Ilosc blednych odpowiedzi: " << base.number_of_questions-correctanswers << endl;
    // liczba wszystkich odp- liczba poprawnych odp
    cout << "Wynik procentowy poprawnych odpowiedzi: ";
    cout << correctanswers*100/base.number_of_questions << "%" << endl;
    
    

   
    /*
    Complex a,b; //test nr 2
    a=enterComp();
    b=enterComp();
    cout << endl << "Dzialania:+,-,*,/:" << endl;
    display(a+b);
    display(a-b);
    display(a*b);
    display(a/b);
    */
   /*
    a.re=11.0; // test nr 1
    a.im=0.0;
    b.re=3.5;
    b.im=3.7;
    cout << "Pierwsza liczba: ";
    display(a);
    cout << endl << "Druga liczba: ";
    display(b);
    */

}
