#include <fstream>
#include <iostream>
#include <math.h>
#include "Cuboid.hh"
#include "RotationMatrix.hh"
#include "Bottom.hh"
#include "Water.hh"

using namespace std;


Cuboid::Cuboid(): angle{0}
{
    ifstream inputFile;
    inputFile.open(kModelCuboid);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Cuboid file!" 
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

void Cuboid::draw(std::string filename) const
{
    RotationMatrix rotation('z', angle); // macierz rotacji wzgl osi OZ
    ofstream outputFile;
    outputFile.open(filename);
    if(!outputFile.is_open())
    {
        cerr << "Unable to open drone file!" << endl;
        return;
    }
    for(unsigned i = 0; i < points.size(); ++i)
    {
     	outputFile <<  rotation*points[i] + translation  << endl;  //macierz rotacji i translacja uwzględnione
        if(i % 4 == 3) // triggers after every 4 points                         
        {
            outputFile << "#\n\n";  
        }
    }

    outputFile.close();
}

void Cuboid::translate(const Vector3D& change)
{
    translation = translation + change;
    if (translation[2] <= bottomlevel + 20) translation[2] = bottomlevel + 20;  // nie przejdz przez dno
    else if (translation[2] >= waterlevel)  translation[2] = waterlevel;        // nie wynurz się zbyt mocno
}

void Cuboid::checkDepth(){
        if (translation[2] <= bottomlevel + 20)
            std::cout << std::endl << "Dotknieto dna, zmniejsz glebokosc!" << std::endl;
        else if (translation[2] >= waterlevel)
            std::cout << std::endl << "Wynuzenie, zwieksz glebokosc!" << std::endl;

}

Vector3D Cuboid::getMax() const {
    RotationMatrix rotation('z', angle); // macierz rotacji wzgl osi OZ
    Vector3D Max;
    Vector3D temp;
    Max[0] = Max[1] = Max[2] = -1000;
    for(unsigned int i = 0; i < points.size(); ++i){
        temp = rotation * points[i];
        if(temp[0] > Max[0]) Max[0] = temp[0] + translation[0];  
    }
        for(unsigned int i = 0; i < points.size(); ++i){
        temp = rotation * points[i];
        if(temp[1] > Max[1]) Max[1] = temp[1] + translation[1];
    }
        for(unsigned int i = 0; i < points.size(); ++i){
        temp = rotation * points[i];
        if(temp[2] > Max[2]) Max[2] = temp[2] + translation[2];  
    }
  return Max;
}

Vector3D Cuboid::getMin() const {
    RotationMatrix rotation('z', angle); // macierz rotacji wzgl osi OZ
    Vector3D Min;
    Vector3D temp;
    Min[0] = Min[1] = Min[2] = 1000;
    for(unsigned int i = 0; i < points.size(); ++i){
        temp = rotation * points[i];
        if(temp[0] < Min[0]) Min[0] = temp[0] + translation[0];  
    }
        for(unsigned int i = 0; i < points.size(); ++i){
        temp = rotation * points[i];
        if(temp[1] < Min[1]) Min[1] = temp[1] + translation[1];
    }
        for(unsigned int i = 0; i < points.size(); ++i){
        temp = rotation * points[i];
        if(temp[2] < Min[2]) Min[2] = temp[2] + translation[2];  
    }
  return Min;
}
