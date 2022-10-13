#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include "SVector.hh"
#include "StageObject.hh"

const std::string kModelWater("../solid/waterStageObject.dat");     // plik do czytania punktów obiektu

constexpr int waterlevel = 100;

/**
 * @brief  Klasa pochodna od klasy StageObject, 
 * zawiera opis geometryczny powierzchni wody
 * 
 */
class Water: public StageObject{
public:
/**
 * @brief Construct a new Water object, wczytuje punkty z pliku kModelWater
 */
  Water();
/**
 * @brief Zapisuje punkty dna do pliku filename. Tworzy siatke punktów o zakresie x-[-300,300]
 *  y - [-300, 300], z - waterlevel +- 10,+-10, to imitacja fal 
 * @param filename nazwa pliku, do ktorego beda zapisywane dane
 */
    void draw(std::string filename) const override;
    /**
 * @brief przesuniecie punktuo wektor change
 * 
 * @param change - wektor przesuniecia
 */
    void translate(const Vector3D& change)
    {
        translation = translation + change;
    }

/**
 * @brief Get the Name of object class
 * 
 * @return std::string -    class name
 */
    std::string getName() const override { return "Powierzchnia wody!"; }

};