#для создания приоритетной очереди на python использоваться 2 алгоритма

# 1 вариант
from queue import PriorityQueue
# Создать приоритетную очередь
q = PriorityQueue()
# Добавить элементы в очередь с приоритетом
q.put((2, 'mid-priority item'))
q.put((1, 'high-priority item'))
q.put((3, 'low-priority item'))
# Удалить и вывести элементы в порядке приоритета
while not q.empty():
 item = q.get()
 print(item)

# 2 вариант
import heapq
customers =
heapq.heappush(customers, (2, "Harry"))
heapq.heappush(customers, (3, "Charles"))
heapq.heappush(customers, (1, "Riya"))
heapq.heappush(customers, (4, "Stacy"))
while customers:
 print(heapq.heappop(customers))