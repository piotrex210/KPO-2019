#include <fstream>
#include <iostream>
#include <math.h>
#include "Surface.hh"

using namespace std;

Surface::Surface(){
    ifstream inputFile;
    inputFile.open(kModelSurface);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Surface file!" 
             << endl;
        return;
    }

    Vector3D point;
    while(inputFile >> point)
    {
        points.push_back(point);
        ++counter;
    }
    inputFile.close();
  }