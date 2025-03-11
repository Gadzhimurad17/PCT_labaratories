#include <iostream>
#include <fstream>
#include "Planet.h"

void ReadDb(Planet*& arr) { 
    std::ifstream dataBase("Planet.txt");
    if (!dataBase) {
        std::cerr << "file was not open" << std::endl;
        return;
    }

    int count;
    dataBase >> count;
    arr = new Planet[count];

    for (int i = 0; i < count; i++) {
        char name[20];
        int diameter;
        int life;
        int satellitesNumber;

        dataBase >> name >> diameter >> life >> satellitesNumber;

        arr[i].SetName(name);
        arr[i].SetDiameter(diameter);
        arr[i].SetLife(life);
        arr[i].SetSatellitesNumber(satellitesNumber);
    }

    dataBase.close();
}
void WriteDB(){
    std::ofstream dataBase;
    dataBase.open("Planet.txt");
    if (!dataBase){
        std::cerr<<"File was not open";
        return;
    }
    
} 
int main() {
    Planet* arr = nullptr;
    ReadDb(arr);

    if (arr) {
        std::cout << "\nВывод базы данных планет:\n";
        for (int i = 0; arr[i].GetName() != nullptr; i++) {
            arr[i].Display();
        }
        delete[] arr;
    }

    return 0;
}
