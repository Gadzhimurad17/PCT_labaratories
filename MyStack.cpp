#include "MyStack.h"
#include <iostream>

void Multipliers(int n, MyStack<int>& stack) {
    if (n == 0) {
        return; 
    }
    if (n < 0) {
        stack.push(-1);
        n = std::abs(n);
    }
    if (n == 1) {
        return; 
    }
    int num = n;
    for (int i = 2; i <= num; ++i) {
        while (num % i == 0) {
            stack.push(i);
            num /= i;
        }
    }
}

int main() {
    int N;
    std::cout << "Введите число: ";
    std::cin >> N;

    MyStack<int> factors;
    Multipliers(N, factors);

    if (N == 0) {
        std::cout << "Ошибка: 0 не имеет множителей." << std::endl;
        return 0;
    }
    
    std::cout << N << " = " << factors <<std::endl;
    std::cout << N << " = ";
    factors.printReversed(std::cout);
    std::cout << std::endl;
    MyStack<char> charStack1;
    charStack1.push('a');
    charStack1.push('b');
    charStack1.push('c');
    MyStack<char> charStack2(charStack1); 
    std::cout << "Копия (конструктор): " << charStack2 << std::endl;


    MyStack<char> charStack3;
    charStack3 = charStack1;
    std::cout << "Копия (присваивание): " << charStack3 << std::endl;

    return 0;
}
