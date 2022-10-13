#include <fstream>
#include <iostream>
#include <math.h>
#include "Bottom.hh"

using namespace std;


Bottom::Bottom()
{
    ifstream inputFile;
    inputFile.open(kModelBottom);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Water file!" 
             << endl;
        return;
    }

    Vector3D point;
    while(inputFile >> point)
    {
        points.push_back(point);        // zapisuje na koniec listy punktow
    }
    inputFile.close();
}


void Bottom::draw(std::string filename) const
{
    ofstream outputFile;
    outputFile.open(filename);
    if(!outputFile.is_open())
    {
        cerr << "Unable to open water file!" << endl;
        return;
    }
    Vector3D pos; // position
    pos[0] = -300;
    pos[1] = -300;
    pos[2] = bottomlevel;
    for(int i = 0; i < 10; ++i){
        for( int j = 0; j < 10; ++j){
        pos[0] = -300 + i*60;
        pos[1] = -300 + j*60;
        outputFile <<  pos << endl;
        ++counter; // zlicza obiekty Vector3D
        }
        outputFile << "#\n\n";  // aby gnuplot rozumiał, po każdej linii
    }
    outputFile.close();
}