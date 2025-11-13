import java.util.*;

public class TSPNearestNeighbor {
    public static List<Integer> tspNearest(int[][] dist) {
        List<Integer> path = new ArrayList<>();
        boolean[] visited = new boolean[dist.length];
        int curr = 0;
        path.add(curr);
        visited[curr] = true;

        for (int i = 1; i < dist.length; i++) {
            int nearest = -1;
            int minDist = Integer.MAX_VALUE;

            for (int j = 0; j < dist.length; j++) {
                if (!visited[j] && dist[curr][j] < minDist) {
                    nearest = j;
                    minDist = dist[curr][j];
                }
            }

            path.add(nearest);
            visited[nearest] = true;
            curr = nearest;
        }

        return path;
    }

    public static void main(String[] args) {
        // Матрица расстояний между 5 городами (симметричная)
        int[][] distances = {
            {0,  10, 15, 20, 25},
            {10, 0,  35, 25, 30},
            {15, 35, 0,  30, 20},
            {20, 25, 30, 0,  10},
            {25, 30, 20, 10, 0 }
        };

        // Убран вывод матрицы расстояний
        // System.out.println("Матрица расстояний:");
        // for (int[] row : distances) {
        //     System.out.println(Arrays.toString(row));
        // }

        List<Integer> route = tspNearest(distances);

        System.out.println("Найденный маршрут (начиная с города 0):");
        System.out.println(route);

        // Вычисляем общую длину маршрута
        int totalDistance = 0;
        for (int i = 0; i < route.size() - 1; i++) {
            totalDistance += distances[route.get(i)][route.get(i + 1)];
        }
        System.out.println("Общая длина маршрута: " + totalDistance);
    }
}

// Итоговый вывод: Найденный маршрут (начиная с города 0):
//[0, 1, 3, 4, 2]
//Общая длина маршрута: 65
