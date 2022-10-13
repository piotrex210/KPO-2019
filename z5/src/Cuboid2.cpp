#include <fstream>
#include <iostream>
#include <math.h>
#include "Cuboid2.hh"

using namespace std;

Cuboid2::Cuboid2(){
    ifstream inputFile;
    inputFile.open(kModelCuboid2);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Cuboid2 file!" 
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

Vector3D Cuboid2::getMax() const {
    Vector3D Max;
    Max[0] = Max[1] = Max[2] = -1000;     // najnmniejsze wartości, spoza wykresu
    for(unsigned int i = 0; i < points.size(); ++i){
        if(points[i][0] >= Max[0]) Max[0] = points[i][0] + translation[0];
        if(points[i][1] >= Max[1]) Max[1] = points[i][1] + translation[1];
        if(points[i][2] >= Max[2]) Max[2] = points[i][2] + translation[2];   
    }
  return Max;
} 

Vector3D Cuboid2::getMin() const {
    Vector3D Min;
    Min[0] = Min[1] = Min[2] = 1000;    // największe wartości, spoza wykresu
    for(unsigned int i = 0; i < points.size(); ++i){
        if(points[i][0] < Min[0]) Min[0] = points[i][0] + translation[0];
        if(points[i][1] < Min[1]) Min[1] = points[i][1] + translation[1];
        if(points[i][2] < Min[2]) Min[2] = points[i][2] + translation[2];  
    }
  return Min; 
}
