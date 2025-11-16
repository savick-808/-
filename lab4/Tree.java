import java.util.*;

public class Dijkstra {
    // Метод реализует алгоритм Дейкстры
    public static Map<String, Integer> dijkstra(Map<String, Map<String, Integer>> graph, String start) {
        // Инициализация расстояний: все = Integer.MAX_VALUE, кроме start
        Map<String, Integer> distances = new HashMap<>();
        for (String vertex : graph.keySet()) {
            distances.put(vertex, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        
        // Приоритетная очередь: сравниваем по расстоянию
        PriorityQueue<Map.Entry<String, Integer>> pq = 
            new PriorityQueue<>(Comparator.comparing(Map.Entry::getValue));
        pq.add(new AbstractMap.SimpleEntry<>(start, 0));
        
        while (!pq.isEmpty()) {  // Пока очередь не пуста
            Map.Entry<String, Integer> current = pq.poll();  // Достаём вершину с мин. расстоянием
            String currentVertex = current.getKey();
            int currentDistance = current.getValue();
            
            // Если текущее расстояние хуже известного — пропускаем
            if (currentDistance > distances.get(currentVertex)) {
                continue;
            }
            
            // Проходим по соседям текущей вершины
            for (Map.Entry<String, Integer> neighbor : graph.get(currentVertex).entrySet()) {
                String neighborVertex = neighbor.getKey();
                int weight = neighbor.getValue();
                int distance = currentDistance + weight;
                
                // Если новое расстояние лучше — обновляем и добавляем в очередь
                if (distance < distances.get(neighborVertex)) {
                    distances.put(neighborVertex, distance);
                    pq.add(new AbstractMap.SimpleEntry<>(neighborVertex, distance));
                }
            }
        }
        
        return distances;  // Возвращаем карту расстояний
    }

