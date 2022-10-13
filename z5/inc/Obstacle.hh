#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "SVector.hh"
#include "StageObject.hh"


//const std::string kModelObstacle("../solid/prostopadloscian2.dat"); // plik do wczytania punktów przeszkody

/**
 * @brief  Klasa pochodna od klasy StageObject, zawiera opis geometryczny przeszkody
 * 
 */
class Obstacle: public StageObject{

public:
/**
 * @brief Construct a new Obstacle object
 * 
 */
Obstacle() {};

/**
 * @brief Destroy the Obstacle object
 * 
 */
~Obstacle() {};
/**
 * @brief Construct a new Obstacle object, komunikuje powstanie przeszkody, wczytuje współrzędne
 * bazowe przeszkody
 * 
 */

    /**
     * @brief Destroy the Obstacle object, komunikuje zniszczenie obiektu
     * 
     */
 

/**
 * @brief zapisuje dane fo pliku filename uwzględnieniem translacji punktów, pobiera dane z pliku filename
 * 
 * @param filename - nazwa pliku do zapisu danych
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

};