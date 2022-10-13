#pragma once

#include "Obstacle.hh"
#include <string>

const std::string kModelSurface("../solid/powierzchnia.dat"); // plik do wczytania punktów przeszkody

/**
 * @brief opisuje klasę powierzchni, jako przeszkodę, pochodna klasy Obstacle
 * 
 */
class Surface: public Obstacle{
  public:
/**
 * @brief Get the Name of object class
 * 
 * @return std::string -    class name
 */
  std::string getName() const override { return "Powierzchnia!"; }

/**
 * @brief Construct a new Surface object, wczytuje punkty z pliku kModelSurface
 * 
 */
  Surface();

};