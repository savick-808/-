#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

// Тип для представления графа: вершина -> (сосед -> вес)
using Graph = map<string, map<string, int>>;

// Функция реализует алгоритм Дейкстры
map<string, int> dijkstra(const Graph& graph, const string& start) {
    // Инициализация расстояний: все = INT_MAX, кроме start
    map<string, int> distances;
    for (const auto& vertex : graph) {
        distances[vertex.first] = INT_MAX;
    }
    distances[start] = 0;
    
    // Приоритетная очередь: (расстояние, вершина), сортировка по расстоянию
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {  // Пока очередь не пуста
        int currentDistance = pq.top().first;   // Расстояние до текущей вершины
        string currentVertex = pq.top().second; // Название текущей вершины
        pq.pop();  // Удаляем вершину из очереди
        
        // Если текущее расстояние хуже известного — пропускаем
        if (currentDistance > distances[currentVertex]) {
            continue;
        }
        
        // Проходим по соседям текущей вершины
        for (const auto& neighbor : graph.at(currentVertex)) {
            string neighborVertex = neighbor.first;
            int weight = neighbor.second;
            int distance = currentDistance + weight;
            
            // Если новое расстояние лучше — обновляем и добавляем в очередь
            if (distance < distances[neighborVertex]) {
                distances[neighborVertex] = distance;
                pq.push({distance, neighborVertex});
            }
        }
    }
    
    return distances;  // Возвращаем карту расстояний
}
