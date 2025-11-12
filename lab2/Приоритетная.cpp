#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Приоритетная очередь целых чисел (по умолчанию сортировка по убыванию)
    priority_queue<int> pq;

    // Добавление элементов
    pq.push(10);
    pq.push(5);
    pq.push(8);
    pq.push(3);

    // Извлечение элементов (элемент с наибольшим значением будет извлечён первым)
    while (!pq.empty()) {
        cout << pq.top() << " ";  // Вывод: 10 8 5 3
        pq.pop();
    }

    return 0;
}