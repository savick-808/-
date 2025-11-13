Вариант 2
 Метод ближайшего соседа (TSP)
Условие: Дан граф городов с расстояниями. Найти приближённый маршрут коммивояжёра, стартуя из города 0.
Алгоритм: ближайший сосед.
Язык примера: Java
public static List<Integer> tspNearest(int[][] dist) {
 List<Integer> path = new ArrayList<>();
 boolean[] visited = new boolean[dist.length];
 int curr = 0;
 path.add(curr);
 visited[curr] = true;
 // ДОПИСАТЬ: цикл выбора ближайшего непосещённого города
 return path;
}
Что дописать: цикл по всем городам с выбором минимума.

Анализ алгоритма:
