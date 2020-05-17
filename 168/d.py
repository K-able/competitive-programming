import numpy as np
from scipy.sparse.csgraph import shortest_path
from scipy.sparse import csr_matrix
import scipy.sparse.csgraph.dijkstra

n, m = map(int, input().split())
l = [[0 for _ in range(n)] for _ in range(n)]
for _ in range(m):
  a, b = map(int, input().split())
  l[a-1][b-1] = 1
  l[b-1][a-1] = 1

csr = csr_matrix(l)
d, p = shortest_path(csr, method='D', indices=0, directed=False, unweighted=True, return_predecessors=True)
#d, p = shortest_path(csr, indices=0, directed=False, unweighted=True, return_predecessors=True)
p += 1
#print(p)
print('Yes')
for i in p:
  if i < 0: continue
  print(i)