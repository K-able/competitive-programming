import networkx as nx

n, k = map(int, input().split())
a = list(map(int, input().split()))


Graph = nx.DiGraph()
node = [i for i in range(1, n+1)]
Graph.add_nodes_from(node)
for i, s in enumerate(a):
    Graph.add_edge(i+1, s)
#for i in a:
print(nx.shortest_path(Graph, source=1, target=1))
#for path in nx.all_simple_paths(Graph, source=2, target=2):
#    print(path)
