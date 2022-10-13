#pragma once

#include <vector>
#include <string>
#include "SVector.hh"
#include "SMatrix.hh"
#include "Obstacle.hh"
#include "Cuboid.hh"
#include "Prism.hh"

/**
 * @brief opisuje klasę Drone: jako połączenie prostopadloscianu 
 * i dwóch śrub
 * 
 */
class Drone {

public:

  Cuboid body;      //  prostopadloscian
  Prism leftRotor;  //  lewa sruba
  Prism rightRotor; //  prawa sruba

/**
 * @brief metoda sprawdzająca, czy wystąpiła kolizja drona z przeszkodą
 * funkcja zwraca prawdę, gdy dron zbytnio zbliży się do przeszkody
 * @param obstacle  - przeszkoda
 * @return true     - gdy kolizja 
 * @return false    - gdy brak kolizji
 */
  bool checkCollision(const StageObject& obstacle);

/**
 * @brief Construct a new Drone object, ustawia lokalną translacje dla śrub
 * 
 */
  Drone();
  
};