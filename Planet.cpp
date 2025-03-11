#include <iostream>
#include <fstream>
#include "Planet.h"
Planet::Planet()
const char *Planet:: GetName(){
    return name; 
}
int Planet::GetDiametr(){
    return diameter;
}
int Planet::GetSatellitesNumber(){
    return satellitesNumber;
}
int Planet::GetLife(){
    return life;
}
void Planet::SetName(char* setName){
    delete[] name;
    name=new char[strlen(setName)+1];
    std::strcpy(name,setName);
}
void Planet::SetDiameter(int setDiameter){
    diameter=setDiameter;
}
void Planet::SetLife(int setLife){
    life=setLife;
}
void Planet::SetSatellitesNumber(int setSatellitesNumber ){
    satellitesNumber=setSatellitesNumber;
}

void Planet::Display() {
    std::cout << "Название: " << (name ? name : "Неизвестно")
              << ", Диаметр: " << diameter
              << ", Наличие жизни: " << life
              << ", Спутники: " << satellitesNumber << std::endl;
}
