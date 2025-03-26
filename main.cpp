#include <iostream>
#include <fstream>
#include "Planet.h"
#include "QuickSort.h"


int main() {
    int count = 0;
    Planet* arr = nullptr;
    Planet::ReadDb(arr, count);
    if (!arr || count == 0) {
        std::cerr << "Ошибка: база данных не загружена!" << std::endl;
        return -1;
    }

    int choice;
    do {
        std::cout << "\nМеню:\n1. Вывести БД\n2. Добавить планету\n3. Удалить планету\n4. Редактировать планету\n5. Отсортировать БД\n6. Записать БД в файл\n0. Выход\nВыберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < count; i++) arr[i].Display();
                break;
            case 2: {
                Planet newPlanet;
                std::cout << "Введите данные новой планеты (Имя Диаметр Жизнь Спутники): ";
                std::cin >> newPlanet;
                Planet::AddPlanet(arr, count, newPlanet);
                break;
            }
            case 3: {
                int index;
                std::cout << "Введите индекс планеты для удаления: ";
                std::cin >> index;
                Planet::DeletePlanet(arr, count, index);
                break;
            }
            case 4: {
                int index;
                std::cout << "Введите индекс планеты для редактирования: ";
                std::cin >> index;
                if (index >= 0 && index < count) Planet::EditPlanet(arr[index]);
                else std::cerr << "Неверный индекс!" << std::endl;
                break;
            }
            case 5:
                Planet::SortDB(arr, count);
                break;
            case 6:
                Planet::WriteDB(arr, count);
                break;
        }
    } while (choice != 0);
    
    delete[] arr;
    return 0;
}
