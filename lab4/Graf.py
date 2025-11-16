def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()  # Инициализируем множество посещённых вершин
    
    visited.add(start)  # Помечаем текущую вершину как посещённую
    print(start)        # Выводим вершину (действие при посещении)
    
    # Рекурсивно обходим всех непосещённых соседей
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)  # Рекурсивный вызов для соседа
    
    return visited  # Возвращаем множество всех посещённых вершин