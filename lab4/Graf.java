import java.util.*;

public class DFS {
    // Метод для обхода графа в глубину
    public static void dfs(Map<String, List<String>> graph, String start, Set<String> visited) {
        visited.add(start);  // Помечаем вершину как посещённую
        System.out.println(start);  // Выводим вершину
        
        // Получаем соседей текущей вершины
        List<String> neighbors = graph.get(start);
        if (neighbors != null) {
            for (String neighbor : neighbors) {  // Обходим соседей
                if (!visited.contains(neighbor)) {  // Если сосед не посещён
                    dfs(graph, neighbor, visited);  // Рекурсивный вызов
                }
            }
        }
    }

    public static void main(String[] args) {
        // Создаём граф (список смежности)
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("A", "D", "E"));
        graph.put("C", Arrays.asList("A", "F"));
        graph.put("D", Arrays.asList("B"));
        graph.put("E", Arrays.asList("B", "F"));
        graph.put("F", Arrays.asList("C", "E"));

        Set<String> visited = new HashSet<>();  // Множество посещённых вершин
        dfs(graph, "A", visited);  // Запуск обхода с вершины 'A'
    }
}