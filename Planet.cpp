#include <iostream>
#include <fstream>
#include "Planet.h"
#include "QuickSort.h"

void Planet::ReadDb(Planet*& arr, int& count) {
    std::ifstream dataBase("Planet.txt");
    if (!dataBase) {
        std::cerr << "Ошибка: не удалось открыть файл!" << std::endl;
        return;
    }

    dataBase >> count;
    if (count <= 0) {
        std::cerr << "Ошибка: Неверное количество записей!" << std::endl;
        return;
    }

    delete[] arr; 
    arr = new Planet[count];

    for (int i = 0; i < count; i++) {
        dataBase >> arr[i];
    }
}

void Planet:: WriteDB(Planet* arr, int count) {
    std::ofstream dataBase("Planet.txt");
    if (!dataBase) {
        std::cerr << "Файл не открыт!" << std::endl;
        return;
    }

    dataBase << count << std::endl;
    for (int i = 0; i < count; i++) {
        dataBase << arr[i] << std::endl;
    }
}

void Planet::AddPlanet(Planet*& arr, int& count, const Planet& newPlanet) {
    Planet* temp = new Planet[count + 1];
    for (int i = 0; i < count; i++) {
        temp[i] = arr[i];
    }
    temp[count] = newPlanet;
    delete[] arr;
    arr = temp;
    count++;
}

void Planet::DeletePlanet(Planet*& arr, int& count, int index) {
    if (index < 0 || index >= count) {
        std::cerr << "Ошибка: Неверный индекс!" << std::endl;
        return;
    }
    Planet* temp = new Planet[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            temp[j++] = arr[i];
        }
    }
    delete[] arr;
    arr = temp;
    count--;
}

void Planet:: EditPlanet(Planet& planet) {
    char name[100];
    int diameter, life, satellitesNumber;
    std::cout << "Введите новое имя: ";
    std::cin >> name;
    std::cout << "Введите новый диаметр: ";
    std::cin >> diameter;
    std::cout << "Введите наличие жизни (1 - есть, 0 - нет): ";
    std::cin >> life;
    std::cout << "Введите количество спутников: ";
    std::cin >> satellitesNumber;

    planet.SetName(name);
    planet.SetDiameter(diameter);
    planet.SetLife(life);
    planet.SetSatellitesNumber(satellitesNumber);
}

void Planet:: SortDB(Planet* arr, int count) {
    if (!arr || count <= 0) {
        std::cerr << "Ошибка: пустой массив или неверное количество элементов!" << std::endl;
        return;
    }
    QuickSort(arr, 0, count - 1);
}

void Planet::Display() const {
    std::cout << "Название: " << (name ? name : "Неизвестно")
              << ", Диаметр: " << diameter
              << ", Наличие жизни: " << life
              << ", Спутники: " << satellitesNumber << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Planet& planet) {
    out << (planet.name ? planet.name : "Неизвестно") << " " 
        << planet.diameter << " " 
        << planet.life << " " 
        << planet.satellitesNumber;
    return out;
}

std::istream& operator>>(std::istream& in, Planet& planet) {
    char name[100];
    in >> name >> planet.diameter >> planet.life >> planet.satellitesNumber;
    planet.SetName(name);
    return in;
}
