#include "Patient.h"
#include <iostream>
#include"QuickSort.h"
#include <fstream>
void Patient::Display() const {
    std::cout << "Имя: " << (name ? name : "Неизвестно")
              << ", Возраст: " << age
              << ", Страховка: " << (isInsured ? "Да" : "Нет")
              << ", Количество визитов: " << visitsCount << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient) {
    out << (patient.name ? patient.name : "Неизвестно") << " "
        << patient.age << " "
        << patient.isInsured << " "
        << patient.visitsCount;
    return out;
}

std::istream& operator>>(std::istream& in, Patient& patient) {
    char name[100];
    int age, visitsCount;
    bool isInsured;

    in >> name >> age >> isInsured >> visitsCount;
    patient.SetName(name);
    patient.SetAge(age);
    patient.SetIsInsured(isInsured);
    patient.SetVisitsCount(visitsCount);

    return in;
}
void Patient::ReadDb(Patient*& arr, int& count) {
    std::ifstream dataBase("Patient.txt");
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
    arr = new Patient[count];

    for (int i = 0; i < count; i++) {
        dataBase >> arr[i];
    }
}

void Patient::WriteDB(Patient* arr, int count) {
    std::ofstream dataBase("Patient.txt");
    if (!dataBase) {
        std::cerr << "Файл не открыт!" << std::endl;
        return;
    }

    dataBase << count << std::endl;
    for (int i = 0; i < count; i++) {
        dataBase << arr[i] << std::endl;
    }
}

void Patient::AddPatient(Patient*& arr, int& count, const Patient& newPatient) {
    Patient* temp = new Patient[count + 1];
    for (int i = 0; i < count; i++) {
        temp[i] = arr[i];
    }
    temp[count] = newPatient;
    delete[] arr;
    arr = temp;
    count++;
}

void Patient:: DeletePatient(Patient*& arr, int& count, int index) {
    if (index < 0 || index >= count) {
        std::cerr << "Ошибка: Неверный индекс!" << std::endl;
        return;
    }
    Patient* temp = new Patient[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            temp[j++] = arr[i];
        }
    }
    delete[] arr;
    arr = temp;
    count--;
}

void Patient::EditPatient(Patient& patient) {
    char name[100];
    int age, visitsCount;
    bool isInsured;

    std::cout << "Введите новое имя: ";
    std::cin >> name;
    std::cout << "Введите возраст: ";
    std::cin >> age;
    std::cout << "Есть страховка? (1 - да, 0 - нет): ";
    std::cin >> isInsured;
    std::cout << "Введите количество визитов: ";
    std::cin >> visitsCount;

    patient.SetName(name);
    patient.SetAge(age);
    patient.SetIsInsured(isInsured);
    patient.SetVisitsCount(visitsCount);
}

void Patient:: SortDB(Patient* arr, int count) {
    if (!arr || count <= 0) {
        std::cerr << "Ошибка: пустой массив или неверное количество элементов!" << std::endl;
        return;
    }
    QuickSort(arr, 0, count - 1);
}
