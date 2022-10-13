#include <fstream>
#include <iostream>
#include <math.h>
#include "Rod.hh"

using namespace std;

Rod::Rod(){
    ifstream inputFile;
    inputFile.open(kModelRod);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Rod file!" 
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