#include <fstream>
#include <iostream>
#include <math.h>
#include "Obstacle.hh"

using namespace std;





void Obstacle::draw(std::string filename) const
{
    ofstream outputFile;
    outputFile.open(filename);
    if(!outputFile.is_open())
    {
        cerr << "Unable to open obstacle file!" << endl;
        return;
    }
    for(unsigned i = 0; i < points.size(); ++i)
    {
     	outputFile <<  points[i] + translation  << endl;  //translacja uwzględniona
        if(i % 4 == 3) // triggers after every 4 points                         
        {
            outputFile << "#\n\n";  
        }
    }

    outputFile.close();
}

