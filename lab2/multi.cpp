#include <iostream>
#include <set> // Подключение заголовочного файла
#include <algorithm> // Для std::for_each

int main() {
    // Объявление мультисписка для хранения целых чисел
    std::multiset<int> myMultiset;

    // Вставка элементов 
    myMultiset.insert(5);
    myMultiset.insert(10);
    myMultiset.insert(17);
    myMultiset.insert(22);
    myMultiset.insert(9);

    // Вывод элементов 
    std::cout << "Элементы мультисписка:" << std::endl;
    for (int val : myMultiset) {
        std::cout << val << " ";
    }
    std::cout << std::endl;