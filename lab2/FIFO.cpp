#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Добавление элементов в конец
    dq.push_back(1);
    dq.push_back(2);

    // Добавление элементов в начало
    dq.push_front(0);

    // Вывод содержимого
    for(int i : dq) {
        cout << i << " ";
    }
    cout << endl;  // Выведет: 0 1 2

   