#include "Drone.hh"

using namespace std;

Drone::Drone(){
    Vector3D localTranslation;
    localTranslation[0] = -47.5;
    localTranslation[1] = -15;
    rightRotor.setLocalTranslation(localTranslation);      // ustawienie lokalnej translacji śrub drona
    localTranslation[1] = 15;
    leftRotor.setLocalTranslation(localTranslation);
}


bool Drone::checkCollision(const StageObject& obstacle){
  Vector3D obsMax = obstacle.getMax();
  Vector3D obsMin = obstacle.getMin();
  Vector3D droneMax;
  Vector3D droneMin;

  Vector3D range;     // wektor zakresu strefy ochronnej
  range[0] = range[1] = -55;
  range[2] = -20;
  droneMax = body.getTranslation() - range;   // strefa kolizji
  droneMin = body.getTranslation() + range; 
    
/* poprzednia wersja, która nie działała
  droneMax[0] = std::max(body.getMax()[0], std::max(leftRotor.getMax()[0], rightRotor.getMax()[0]));
  droneMax[1] = std::max(body.getMax()[1], std::max(leftRotor.getMax()[1], rightRotor.getMax()[1]));
  droneMax[2] = std::max(body.getMax()[2], std::max(leftRotor.getMax()[2], rightRotor.getMax()[2]));

  droneMin[0] = std::min(body.getMin()[0], std::min(leftRotor.getMin()[0], rightRotor.getMin()[0]));
  droneMin[1] = std::min(body.getMin()[1], std::min(leftRotor.getMin()[1], rightRotor.getMin()[1]));
  droneMin[2] = std::min(body.getMin()[2], std::min(leftRotor.getMin()[2], rightRotor.getMin()[2]));
  */

 // sprawdzenie zakresów dla każdego obiektu sceny
  //cout  << "DronMin: " << droneMin << " DronMax: " << droneMax << endl
  //      << "Przeszkoda " << obstacle.getName() <<  "Min: " << obsMin << " Max: " << obsMax << endl << endl;

  // warunek nałożenia na siebie obszarów 3D drona i przeszkody
  return ((droneMin[0] < obsMax[0] && droneMax[0] > obsMin[0]) && 
  (droneMin[1] < obsMax[1] && droneMax[1] > obsMin[1]) && (droneMin[2] < obsMax[2] && droneMax[2] > obsMin[2]));

}