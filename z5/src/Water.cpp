#include <fstream>
#include <iostream>
#include <math.h>
#include "SMatrix.hh"
#include "Water.hh"

using namespace std;


Water::Water()
{
    ifstream inputFile;
    inputFile.open(kModelWater);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Water file!" 
             << endl;
        return;
    }

    Vector3D point;
    while(inputFile >> point)
    {
        points.push_back(point);
    //    counter++;
    }
    inputFile.close();
    //cout << "Aktualna liczba obiektor Vektor3D: " << counter;
}

void Water::draw(std::string filename) const
{
    ofstream outputFile;
    outputFile.open(filename);
    if(!outputFile.is_open())
    {
        cerr << "Unable to open water file!" << endl;
        return;
    }
    Vector3D pos; // position
    for(int i = 0; i < 10; ++i){
        for( int j = 0; j < 10; ++j){
        pos[0] = -300 + i*60; // zakres od -300 do 300
        pos[1] = -300 + j*60;
        if(j%2 == 0) pos[2] = waterlevel + 10; // co drugi rządek rób fale
        else pos[2] = waterlevel - 10;
        outputFile <<  pos << endl;
        ++counter;
        }
        outputFile << "#\n\n";

    }
    outputFile.close();
}