#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "gnuplot_link.hh"
#include "Cuboid.hh"
#include "SVector.hh"
#include "menu.hh"
#include "Water.hh"
#include "Bottom.hh"
#include "Obstacle.hh"
#include "Prism.hh"
#include "Drone.hh"
#include "Surface.hh"
#include "Rod.hh"
#include "Cuboid2.hh"

using namespace std;

constexpr int framesInAnimation = 60; 


const string kDroneFile("../solid/drone.dat");         // zalaczamy pliki z danymi
const string kWaterFile("../solid/watersurface.dat");
const string kBottomFile("../solid/bottomsurface.dat");
const string kLeftRotorFile("../solid/leftrotor.dat");
const string kRightRotorFile("../solid/rightrotor.dat");
const string kObstacle1File("../solid/obstacle1.dat");  // pliki z danymi przeszkód
const string kObstacle2File("../solid/obstacle2.dat");
const string kObstacle3File("../solid/obstacle3.dat");
const string kObstacle4File("../solid/obstacle4.dat");
const string kObstacle5File("../solid/obstacle5.dat");





/**
 * @brief funkcja rysuje wykres z animacja, uwzglednia przesunięcie i obrót drona
 * 
 * @param obstacles -   lista wskaźników na przeszkody
 * @param drone -       dron
 * @param link -        interfejs
 * @param translation - wektor przesuniecia
 * @param turnangle -   kat obrotu
 */
void drawWithAnimation(Drone& drone, vector<shared_ptr<StageObject>> obstacles, PzG::GnuplotLink link, const Vector3D& translation, const double& turnangle){
    int collision = 0;      // zmienna wskazująca, czy wystąpiła kolizja w danej klatce
    int collision2 = 0;     // zmienna wskazująca, czy wystąpiła kolizja w całym ruchu
    string name = "";       // nazwa przeszkody, z krórą wystąpiła kolizja
      for(int i=0; i < framesInAnimation; ++i){         // ile klatek ma animacja
        collision = 0;

        drone.body.translate(translation/framesInAnimation); // przesunięcie
        drone.rightRotor.translate(translation/framesInAnimation); // przesunięcie
        drone.leftRotor.translate(translation/framesInAnimation); // przesunięcie

        if(turnangle != 0) {
        drone.body.turn(turnangle/framesInAnimation);       // obracanie drona
        drone.rightRotor.turn(turnangle/framesInAnimation); 
        drone.leftRotor.turn(turnangle/framesInAnimation);
          }
        for(auto &Elem: obstacles)
            if(drone.checkCollision(*Elem)) {
                name = Elem->getName();
                    ++collision;
                    ++collision2;
            }
        if(collision > 0){          // zawróć, gdy wystąpiła kolizja
        drone.body.translate(-1.0*translation/framesInAnimation); // przesunięcie
        drone.rightRotor.translate(-1.0*translation/framesInAnimation); // przesunięcie
        drone.leftRotor.translate(-1.0*translation/framesInAnimation); // przesunięcie

        if(turnangle != 0) {        // zawróć, gdy wystąpiła kolizja
        drone.body.turn(-1.0*turnangle/framesInAnimation);       // obracanie drona
        drone.rightRotor.turn(-1.0*turnangle/framesInAnimation); 
        drone.leftRotor.turn(-1.0*turnangle/framesInAnimation);
          }
        }


        drone.leftRotor.rotate(10); 
        drone.rightRotor.rotate(10);  // obracanie śrub


        if(collision <= 0){
            drone.body.draw(kDroneFile);        // rysowanie
            drone.rightRotor.draw(kRightRotorFile);
            drone.leftRotor.draw(kLeftRotorFile);
        }
        std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000/framesInAnimation));    // ile czasu czekamy miedzy klatkami
            link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku                 // czas zmniejszony do 1s, dla ułatwienia sprawdzania
    }
    if(collision2 > 0) cout << endl << "Kolizja z przeszkoda typu: " << name << endl;
    drone.body.checkDepth(); // sprawdzamy czy sie wynurzył albo dotknął dna
    cin.ignore(100000, '\n'); 
}

int main()
{
    PzG::GnuplotLink link;  // Ta zmienna jest potrzebna do wizualizacji
    Drone drone;
    Water water;            // powierzchnia wody
    Bottom bottom;          // powierzchnia dna



    shared_ptr<StageObject> Sur1 = make_shared<Surface>();     // tworzenie nowych wskaźników na przeszkody
    shared_ptr<StageObject> Sur2 = make_shared<Surface>();     // tworzenie nowych wskaźników na przeszkody
    shared_ptr<StageObject> Rod1 = make_shared<Rod>();
    shared_ptr<StageObject> Rod2 = make_shared<Rod>();
    shared_ptr<StageObject> Cub1 = make_shared<Cuboid2>();

    vector<shared_ptr<StageObject>> obstacles;              // tworzenie listy wskaźników

    obstacles.push_back(Sur1);                        // wstawianie wskaźników do listy
    obstacles.push_back(Sur2);
    obstacles.push_back(Rod1);
    obstacles.push_back(Rod2);
    obstacles.push_back(Cub1);



    vector<string> filelist;                    // tworzenie vektora nazw plików
    filelist.push_back(kObstacle1File);         // wstawianie nazw plików do wektora
    filelist.push_back(kObstacle2File);
    filelist.push_back(kObstacle3File);
    filelist.push_back(kObstacle4File);
    filelist.push_back(kObstacle5File);


    link.Init();
    link.AddFilename(kDroneFile.c_str(), PzG::LS_CONTINUOUS, 1);    //wczytanie plikow z danymi
    link.AddFilename(kWaterFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kBottomFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kRightRotorFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kLeftRotorFile.c_str(), PzG::LS_CONTINUOUS, 1);
    


    for(string &Elem : filelist){   // dodanie wszystkich plików z wektora nazw plików przeszkód
        link.AddFilename(Elem.c_str(), PzG::LS_CONTINUOUS, 1);
    }





    link.SetDrawingMode(PzG::DM_3D);        // tryb rysowania
    link.SetRangeX(-300, 300);              // dlugosc osi na wykresie
    link.SetRangeY(-300, 300);
    link.SetRangeZ(-510, 150);

    link.SetRotationXZ(75, 75);             // kierunek patrzenia na wykres
    

    drone.body.draw(kDroneFile);                // rysuj drona
    water.draw(kWaterFile);                 // rysuj pow. wody
    bottom.draw(kBottomFile);               // rysuj dno
    drone.rightRotor.draw(kRightRotorFile);
    drone.leftRotor.draw(kLeftRotorFile);


    Vector3D temp;
    temp[0] = temp[1] = -50;      // wektor przesunięcia przeszkód, by sprawdzić czy wszystko działa
    temp[2] = 250; 
    Rod2->translate(temp);
    temp[0] = 400;
    temp[1] = -200;
    temp[2] = 0;
    Sur2->translate(temp);



    double i = 0;                           // iterator wektora plików
    for(shared_ptr<StageObject> &Elem : obstacles){
        Elem->draw(filelist[i++]);
    }

    link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku


    char c; // wybor uzytkownika z menu
    double turnangle = 0; // kat obrotu
    double riseangle = 0; // kat obrotu

    Vector3D translation, vector0; // vector0 - wertor[0,0,0], translation - wektor przesuniecia drona 

    menuShow();
    
    while(c != 'k'){
        cout << endl << "Aktualna liczba obiektow Vektor3D: " << StageObject::counter << endl;
        cout << endl << "Twoj wybor, m - menu> ";
        cin >> c;
        switch(c) {
            case 'r' : menuForward(drone.body.getangle(), riseangle, translation); 
            drawWithAnimation(drone, obstacles, link, translation, 0);                                        break;
            case 'o' : menuTurn(turnangle);          
            drawWithAnimation(drone, obstacles, link, vector0, turnangle);                                    break;
            case 'm' : menuShow();                                                                  break;
            case 'k' : cout << "Koniec programu" << endl;                                           break;
            default  : cout << "Blad! Nie ma takiej opcji w menu, sprobuj jeszcze raz!" << endl;    break;
        }
    }
}
