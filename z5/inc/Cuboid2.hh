#pragma once

#include "Obstacle.hh"
#include <string>

const std::string kModelCuboid2("../solid/prostopadloscian2.dat"); // plik do wczytania punktów przeszkody


/**
 * @brief opisuje klasę prostopadłościanu jako przeszkodę, brak możliwości obrotu, itp., pochodna klasy Obstacle
 * 
 */
class Cuboid2: public Obstacle{
  public:
/**
 * @brief Get the Name object class
 * 
 * @return std::string  - class name
 */
    std::string getName() const override { return "Prostopadloscian!"; }

/**
 * @brief Construct a new Cuboid2 object
 * 
 */
  Cuboid2();

/**
 * @brief Get the Max vector with max(x), max(y), max(z) coordinates of whole object
 * 
 * @return Vector3D 
 */
  Vector3D getMax() const override;

  /**
   * @brief Get the Min vector with min(x), min(y) and min(z) coordinates of whole object
   * 
   * @return Vector3D 
   */
  Vector3D getMin() const override;


};