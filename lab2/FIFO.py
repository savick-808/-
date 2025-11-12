from queue import Queue
q = Queue()
q.put(1)
q.put(2)
q.put(3)
while not q.empty():
 print(q.get())
# Вывод: 1, 2, 3
