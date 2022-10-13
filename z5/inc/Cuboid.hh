#pragma once

#include <vector>
#include <string>
#include "SVector.hh"
#include "SMatrix.hh"
#include "StageObject.hh"
#include "Water.hh"
#include "Bottom.hh"

const std::string kModelCuboid("../solid/model.dat");   // plik do czytania punktów obiektu
/**
 * @brief Klasa opisująca prostopadloscian, pochodna kalsy StageObject
 * 
 */
class Cuboid: public StageObject{
    
    double angle; // globalny kąt obrotu prostopadloscianu

public:


/**
 * @brief Construct a new Cuboid object, wczytuje punkty z pliku kModelCuboid
 * 
 */
    Cuboid();
/**
 * @brief Zapisuje wspolrzednie punktow po obrocie i translacji
 * 
 * @param filename - nazwa pliku, do którego zapisujemy dane
 */
    void draw(std::string filename) const override;
/**
 * @brief Przesuń o wektor change, chyba, że dotknie dna, albo wynurzy się
 * 
 * @param change - wektor przesunięcia
 */
    void translate(const Vector3D& change);
/**
 * @brief obrót prostopadłościanu wedlug osi OZ
 * 
 * @param change kąt obrotu
 */
    void turn(const double change){
        angle += change; 
    }
/**
 * @brief zwraca globalny kat obrotu
 * 
 * @return double - kat obrotu
 */
    double getangle() const { return angle; }
/**
 * @brief Wyswietla komunikat w przypadku gdy dotknie dna lub powierzchni
 * 
 */
    void checkDepth();

/**
 * @brief Get the vector with min(x), min(y) and min(z) coordinates of whole object
 * 
 * @return Vector3D 
 */
    Vector3D getMin() const override;

/**
 * @brief Get the Max vector with max(x), max(y), max(z) coordinates of whole object
 * 
 * @return Vector3D 
 */
    Vector3D getMax() const override;
/**
 * @brief Get the Name of object class
 * 
 * @return std::string -    class name
 */
    std::string getName() const override { return "Prostopadloscian!"; }

};