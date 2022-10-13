#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include "SVector.hh"
#include "SMatrix.hh"


class StageObject{
  protected:
  // wektor współrzędnych punktów obiektu
    std::vector<Vector3D> points;
// wektor przesunięcia
    Vector3D translation;

public:
/**
 * @brief Construct a new Stage Object object
 * 
 */
StageObject() {};

/**
 * @brief Destroy the Stage Object object
 * 
 */
~StageObject() {};

/**
 * @brief  wirtualna metoda rysowania obiektu
 * 
 * @param filename - nazwa pliku z danymi do zapisu
 */
    virtual void draw(std::string filename) const=0;   

/**
 * @brief Get the Max vector with max(x), max(y), max(z) coordinates of whole object
 * 
 * @return Vector3D 
 */
    virtual Vector3D getMax() const; 

/**
 * @brief Get the vector with min(x), min(y) and min(z) coordinates of whole object
 * 
 * @return Vector3D 
 */
    virtual Vector3D getMin() const; 

/**
 * @brief przesuniecie punktu o wektor change
 * 
 * @param change - wektor przesuniecia
 */
    void translate(const Vector3D& change)
    {
        translation = translation + change;
    }
// zlicza wszystkie obiekty Vector3D
    static int counter;

/**
 * @brief Get the Name of object class
 * 
 * @return std::string -    class name
 */
    virtual std::string getName() const = 0;

/**
 * @brief Get the Translation of object
 * 
 * @return Vector3D - translation
 */
    Vector3D getTranslation()   const   { return translation;  }

};