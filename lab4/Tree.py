import heapq  # Импортируем модуль для работы с приоритетной очередью (мини-heap)

def dijkstra(graph, start):
    # Инициализация: расстояния до всех вершин = бесконечность, кроме стартовой
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0  # Расстояние до стартовой вершины = 0
    
    # Приоритетная очередь: (расстояние, вершина)
    priority_queue = [(0, start)]
    
    while priority_queue:  # Пока есть вершины для обработки
        current_distance, current_vertex = heapq.heappop(priority_queue)  # Достаём вершину с мин. расстоянием
        
        # Если текущее расстояние больше известного — пропускаем
        if current_distance > distances[current_vertex]:
            continue
        
        # Проходим по соседям текущей вершины
        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight  # Новое расстояние до соседа
            
            # Если новое расстояние лучше — обновляем и добавляем в очередь
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))
    
    return distances  # Возвращаем словарь расстояний от start до всех вершин