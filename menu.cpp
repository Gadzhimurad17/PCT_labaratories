#include <iostream>
#include <fstream>
#include "Patient.h"
#include "QuickSort.h"


int main() {
    int count = 0;
    Patient* arr = nullptr;
    Patient::ReadDb(arr, count);
    if (!arr || count == 0) {
        std::cerr << "Ошибка: база данных не загружена!" << std::endl;
        return -1;
    }

    int choice;
    do {
        std::cout << "\nМеню поликлиники:\n1. Вывести список пациентов\n2. Добавить пациента\n3. Удалить пациента\n4. Редактировать данные пациента\n5. Отсортировать по количеству визитов\n6. Сохранить данные\n0. Выход\nВыберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < count; i++) arr[i].Display();
                break;
            case 2: {
                Patient newPatient;
                std::cout << "Введите данные пациента (Имя Возраст Страховка(1/0) Визиты): ";
                std::cin >> newPatient;
                Patient::AddPatient(arr, count, newPatient);
                break;
            }
            case 3: {
                int index;
                std::cout << "Введите индекс пациента для удаления: ";
                std::cin >> index;
                Patient::DeletePatient(arr, count, index);
                break;
            }
            case 4: {
                int index;
                std::cout << "Введите индекс пациента для редактирования: ";
                std::cin >> index;
                if (index >= 0 && index < count) Patient::EditPatient(arr[index]);
                else std::cerr << "Неверный индекс!" << std::endl;
                break;
            }
            case 5:
                Patient::SortDB(arr, count);
                break;
            case 6:
                Patient::WriteDB(arr, count);
                break;
        }
    } while (choice != 0);

    delete[] arr;
    return 0;
}
