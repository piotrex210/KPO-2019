#pragma once

#include <iostream>

#include "SMatrix.hh"
#include "SVector.hh"

/**
 * @brief Klasa pochona klasy Matrix3D, opisuje macierz obrotu obiektu względem osi OZ
 * 
 */
class RotationMatrix: public Matrix3D{

  public:

/**
 * @brief Construct a new Rotation Matrix object, wypełnia pola macierzy
 * według wzoru z wykładu dr Kreczmera, wybiera oś OX lub OZ
 * 
 * @param axis - znak char, x lub z,  oś obrotu
 * @param angle kąt obrotu w stopniach
 */
    RotationMatrix(const char axis, const double& angle);


};