#include <iostream>
#include <math.h>
#include "RotationMatrix.hh"


// macierz obrotu według dr Kreczmera, działa jak należ
  RotationMatrix::RotationMatrix(const char axis, const double& angle){
    if(axis == 'x'){
    Column[0][0] = 1; 
    Column[0][1] = 0; 
    Column[0][2] = 0;

    Column[1][0] = 0; 
    Column[1][1] = cos(angle*2*M_PI/360);
    Column[1][2] = -sin(angle*2*M_PI/360);;

    Column[2][0] = 0;
    Column[2][1] = sin(angle*2*M_PI/360);
    Column[2][2] = cos(angle*2*M_PI/360);
    }

    else if(axis == 'z'){
    Column[0][0] = cos(angle*2*M_PI/360);
    Column[0][1] = -sin(angle*2*M_PI/360);
    Column[0][2] = 0;

    Column[1][0] = sin(angle*2*M_PI/360);
    Column[1][1] = cos(angle*2*M_PI/360);
    Column[1][2] = 0;

    Column[2][0] = 0;
    Column[2][1] = 0;
    Column[2][2] = 1;
    }
    else if(axis == 'y'){
    Column[0][0] = cos(angle*2*M_PI/360);
    Column[0][1] = 0;
    Column[0][2] = sin(angle*2*M_PI/360);

    Column[1][0] = 0;
    Column[1][1] = 1;
    Column[1][2] = 0;

    Column[2][0] = -sin(angle*2*M_PI/360);
    Column[2][1] = 0;
    Column[2][2] = cos(angle*2*M_PI/360);
    }
    else std::cout << "RotationMatrix:Podano złą oś obrotu!" << std::endl;
  }