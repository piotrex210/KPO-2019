#pragma once

#include "Obstacle.hh"
#include <string>

const std::string kModelRod("../solid/pret.dat"); // plik do wczytania punktów przeszkody


/**
 * @brief opisuje klasę pręt, jako przeszkodę, pochodna klasy Obstacle
 * 
 */
class Rod: public Obstacle{
  public:
/**
 * @brief Get the Name object class
 * 
 * @return std::string - name
 */
    std::string getName() const override { return "Pręt!"; }

/**
 * @brief Construct a new Rod object, wczytuje wspolzedne punktów
 * z pliku źródłowego
 * 
 */
  Rod();


};