#include "StageObject.hh"


int StageObject::counter = 0;

using namespace std;

Vector3D StageObject::getMax() const {
    Vector3D Max;
    Max[0] = Max[1] = Max[2] = -1000;
    for(unsigned int i = 0; i < points.size(); ++i){
        if(points[i][0] >= Max[0]) Max[0] = points[i][0] + translation[0];
        if(points[i][1] >= Max[1]) Max[1] = points[i][1] + translation[1];
        if(points[i][2] >= Max[2]) Max[2] = points[i][2] + translation[2];   
    }
  return Max;
} 

Vector3D StageObject::getMin() const {
    Vector3D Min;
    Min[0] = Min[1] = Min[2] = 1000;
    for(unsigned int i = 0; i < points.size(); ++i){
        if(points[i][0] < Min[0]) Min[0] = points[i][0] + translation[0];
        if(points[i][1] < Min[1]) Min[1] = points[i][1] + translation[1];
        if(points[i][2] < Min[2]) Min[2] = points[i][2] + translation[2];  
    }
  return Min; 
}
