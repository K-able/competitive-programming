import sys
import math
import numpy as np
from collections import deque

def I():
  return int(input())
def IS():
  return map(int, input().split())
def IL():
  return [int(x) for x in input().split()]
def ILL(n):
  return [list(map(int, input().split())) for _ in range(n)]
def S():
  return input()
def SS():
  return input().split()

def main():
  N, M = IS()
  to = [[] for _ in range(N)]
  INF = float('inf')
  for i in range(M):
    A, B = IS()
    A -= 1
    B -= 1
    to[A].append(B)
    to[B].append(A) 
  # queue
  q = deque()
  q.append(0)
  # diatance to first room
  dist = [INF] * N
  # previous room
  prev = [-1] * N
 
  #### BFS ####
  while len(q) != 0:
    # pop from queue
    v = q.popleft()
    # seatch room of v's neighboor
    for u in to[v]:
      if prev[u] == -1:
        dist[u] = dist[v] + 1
        prev[u] = v
        q.append(u)
  # print answer
  print("Yes")
  for i in range(1, len(prev)):
    print(prev[i] + 1)

if __name__ == "__main__":
    main()

