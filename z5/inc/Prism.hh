#pragma once

#include <vector>
#include <string>
#include "SVector.hh"
#include "SMatrix.hh"
#include "StageObject.hh"
#include "Water.hh"
#include "Bottom.hh"

const std::string kModelPrism("../solid/prismX.dat");   // plik do czytania punktów obiektu
/**
 * @brief Klasa opisująca graniastosłup, pochodna kalsy StageObject, używana do obrazowania śrub
 * 
 */
class Prism: public StageObject{
    
  double angle; // globalny kąt obrotu prostopadloscianu
  double rotangle; // kąt obrotu śruby
  Vector3D localTranslation;



public:

    void rotate(const double change){
        rotangle += change; 
    }

  void setLocalTranslation(const Vector3D& loctrans)  {   localTranslation = loctrans;  }
/**
 * @brief Construct a new Prism object, wczytuje punkty z pliku kModelPrism
 * 
 */
    Prism();
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
 * @brief Get the Max vector with max(x), max(y), max(z) coordinates of whole object
 * 
 * @return Vector3D 
 */
    Vector3D getMax() const override;

/**
 * @brief Get the Min ovector with min(x), min(y) and min(z) coordinates of whole object
 * 
 * @return Vector3D 
 */
    Vector3D getMin() const override;

/**
 * @brief Get the Name of object class
 * 
 * @return std::string - name of class
 */
    std::string getName() const override { return "Sruba!"; }

};