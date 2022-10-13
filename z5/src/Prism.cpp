#include <fstream>
#include <iostream>
#include <math.h>
#include "Cuboid.hh"
#include "RotationMatrix.hh"
#include "Bottom.hh"
#include "Water.hh"
#include "Prism.hh"

using namespace std;


Prism::Prism(): angle{0}
{
    ifstream inputFile;
    inputFile.open(kModelPrism);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Prism file!" 
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

void Prism::draw(std::string filename) const
{
    RotationMatrix zrotation('z', angle); // macierz rotacji osi OX
    RotationMatrix xrotation('x', rotangle); // macierz rotacji osi OX
    RotationMatrix yrotation('y', rotangle); // macierz rotacji osi OY

    ofstream outputFile;
    outputFile.open(filename);
    
    if(!outputFile.is_open())
    {
        cerr << "Unable to open drone file!" << endl;
        return;
    }
    for(unsigned i = 0; i < points.size(); ++i)
    {
     	outputFile <<  zrotation*(localTranslation + yrotation*points[i]*15.0) + translation  << endl;  //macierz rotacji i translacja uwzględnione
        if(i % 4 == 3) // triggers after every 4 points                         
        {
            outputFile << "#\n\n";  
        }
    }

    outputFile.close();
}

void Prism::translate(const Vector3D& change)
{
    translation = translation + change;
    if (translation[2] <= bottomlevel + 20) translation[2] = bottomlevel + 20;  // nie przejdz przez dno
    else if (translation[2] >= waterlevel)  translation[2] = waterlevel;        // nie wynurz się zbyt mocno
}

void Prism::checkDepth(){
        if (translation[2] <= bottomlevel + 20)
            std::cout << std::endl << "Dotknieto dna, zmniejsz glebokosc!" << std::endl;
        else if (translation[2] >= waterlevel)
            std::cout << std::endl << "Wynuzenie, zwieksz glebokosc!" << std::endl;
}

Vector3D Prism::getMax() const {
    RotationMatrix zrotation('z', angle); // macierz rotacji wzgl osi OZ
    RotationMatrix xrotation('x', rotangle); // macierz rotacji osi OX

    Vector3D Max;
    Vector3D temp;
    Max[0] = Max[1] = Max[2] = -1000;
    for(unsigned int i = 0; i < points.size(); ++i){
        temp = zrotation*(localTranslation + xrotation*points[i]*15.0);
        if(temp[0] > Max[0]) Max[0] = temp[0] + translation[0];  
        if(temp[1] > Max[1]) Max[1] = temp[1] + translation[1];
        if(temp[2] > Max[2]) Max[2] = temp[2] + translation[2];  
    }
  return Max;
}

Vector3D Prism::getMin() const {
    RotationMatrix zrotation('z', angle); // macierz rotacji wzgl osi OZ
    RotationMatrix xrotation('x', rotangle); // macierz rotacji osi OX


    Vector3D Min;
    Vector3D temp;
    Min[0] = Min[1] = Min[2] = 1000;
    for(unsigned int i = 0; i < points.size(); ++i){
        temp = zrotation*(localTranslation + xrotation*points[i]*15.0);
        if(temp[0] < Min[0]) Min[0] = temp[0] + translation[0]; 
        if(temp[1] < Min[1]) Min[1] = temp[1] + translation[1];
        if(temp[2] < Min[2]) Min[2] = temp[2] + translation[2];  
    }
  return Min;
}