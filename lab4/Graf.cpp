#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

// Функция для обхода графа в глубину
void dfs(const unordered_map<string, vector<string>>& graph,
          const string& start, unordered_set<string>& visited) {
    visited.insert(start);  // Помечаем вершину как посещённую
    cout << start << endl;   // Выводим вершину
    
    // Получаем соседей текущей вершины
    auto it = graph.find(start);
    if (it != graph.end()) {
        for (const string& neighbor : it->second) {  // Обходим соседей
            if (visited.find(neighbor) == visited.end()) {  // Если сосед не посещён
                dfs(graph, neighbor, visited);  // Рекурсивный вызов
            }
        }
    }
}

int main() {
    // Создаём граф (список смежности)
    unordered_map<string, vector<string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"A", "D", "E"}},
        {"C", {"A", "F"}},
        {"D", {"B"}},
        {"E", {"B", "F"}},
        {"F", {"C", "E"}}
    };

    unordered_set<string> visited;  // Множество посещённых вершин
    dfs(graph, "A", visited);   // Запуск обхода с вершины 'A'
    return 0;
}