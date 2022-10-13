#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "gnuplot_link.hh"
#include "SVector.hh"
#include "menu.hh"
#include "StageObject.hh"

using namespace std;

void menuShow(){
    cout << endl  << "r - zadaj ruch na wprost"      << endl 
                  << "o - zadaj zmiane orientacji"   << endl
                  << "m - wyswietl menu"             << endl << endl; 
}

void menuForward(const double& globalangle, double& riseangle, Vector3D& translation){
    double distance;
    cout << "Podaj wartosc kata (wznoszenia/opadania) w stopniach." << endl
         << "Wartosc kata> ";
    cin  >> riseangle;
    if(cin.fail()) { // gdy źle wpisano dane
         cout << "Blad przy wprowadzaniu kata wznoszenia!" << endl;
         riseangle = 0;
         distance = 0;
         cin.clear();
    }
    else{ // gdy nie popelniono bledu, wczytuj dalej
    cout << "Podaj odleglosc, na jaka ma sie przemiescic dron." << endl
         << "Wartosc odleglosci> ";
    cin  >> distance;
        if(cin.fail()) {
         cout << "Blad przy wprowadzaniu odleglosci!" << endl;
         distance = 0;
         cin.clear();
        }
    }
    translation[0] = distance * cos(riseangle/180*M_PI)*cos(globalangle/180*M_PI); // obliczanie x
    translation[1] = distance * cos(riseangle/180*M_PI)*sin(globalangle/180*M_PI); // obliczanie y
    translation[2] = distance * sin(riseangle/180*M_PI);                           // obliczanie z
}

void menuTurn(double& turnangle){
    cout << "Podaj wartosc kata obrotu w stopniach." << endl
         << "Wartosc kata> ";
    cin  >> turnangle;
     if(cin.fail()) {
         cout << "Blad przy wprowadzaniu kata obrotu!" << endl;
         turnangle = 0;
         cin.clear();
        }
}


