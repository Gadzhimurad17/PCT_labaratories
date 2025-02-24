#include <iostream>
#include "main.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 1+1="<<mymath::sum(2,2);
    

    return 0;
}
