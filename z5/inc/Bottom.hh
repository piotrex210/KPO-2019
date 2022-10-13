#pragma once

#include <vector>
#include <string>
#include "SVector.hh"
#include "StageObject.hh"

const std::string kModelBottom("../solid/bottomsurface.dat"); // plik do czytania punktow dna
constexpr int bottomlevel = -500;     // glebokosc dna na wykresie

/**
 * @brief  Klasa pochodna od klasy StageObject, zawiera opis geometryczny dna
 * 
 */
class Bottom: public StageObject{

public:
/**
 * @brief Construct a new Bottom object, wczytuje punkty z pliku kModelBottom
 * 
 */
    Bottom();
/**
 * @brief Zapisuje punkty dna do pliku filename. Tworzy siatke punktów o zakresie x-[-300,300]
 *  y - [-300, 300], z - bottomlevel
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
 * @brief Get the Name object
 * 
 * @return std::string 
 */
    std::string getName() const override { return "Dno!"; }

};