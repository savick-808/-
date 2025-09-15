#include <iostream>
#include <list>

using namespace std;

int main() {
    // Создадим пустой список Stack
    list<char> stack;
    
    // Заполним список символами
    stack.push('1');
    stack.push('2');
    stack.push('3');
    stack.push('4');
    stack.push('5');
    stack.push('6');

    
    // Выводим список Stack
    cout << "Список символов: ";
    for (char c : stack) {
        cout << c << " ";
    }
    cout << endl;
    
    return 0;
}