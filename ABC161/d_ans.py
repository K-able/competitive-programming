import queue

k = int(input())
q = queue.Queue()
x = -1
for i in range(1,10):
    q.put(i)
for i in range(1,k+1):
    x = q.get()
    if x % 10 != 0:
        q.put(10 * x + (x % 10) - 1)
    q.put(10 * x + (x % 10))
    if x % 10 != 9:
        q.put(10 * x + (x % 10) + 1)
print(x)