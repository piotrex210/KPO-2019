#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "gnuplot_link.hh"
#include "SVector.hh"
#include "SMatrix.hh"

/**
 * @brief Wyświetla menu
 * 
 */
void menuShow(); 

/**
 * @brief Funkcja wczytujące dane od użytkownika dotyczące przesunięcia prostopadłościanu
 *  do przodu, z kątem wznoszenia/opadania, oblicza wektor przesunięcia według
 * podanych danych i zapisuje go do obiektu translation
 * @param gobalangle - kąt obrotu prostopadloscianu
 * @param riseangle -  kąt wznoszenia/opadania
 * @param translation  - długość wektora przemieszczenia
 */
void menuForward(const double& gobalangle, double& riseangle, Vector3D& translation); // opcja, na przód

/**
 * @brief Funkcja obracająca prostopadłościan, pyta użytkownika o kąt obrotu
 * 
 * @param turnangle - kat obrotu
 */
void menuTurn(double& turnangle);


