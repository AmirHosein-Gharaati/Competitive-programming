from collections import defaultdict

def DFS(G,v,seen=None,path=None):
    if seen is None: seen = []
    if path is None: path = [v]

    seen.append(v)

    paths = []
    for t in G[v]:
        if t not in seen:
            t_path = path + [t]
            paths.append(tuple(t_path))
            paths.extend(DFS(G, t, seen[:], t_path))
    return paths


# Define graph by edges
n = int(input())
edges = [input().split() for i in range(n-1)]

# Build graph dictionary
G = defaultdict(list)
for (s,t) in edges:
    G[s].append(t)
    G[t].append(s)

all_paths = []
for node in set(G.keys()):
    for path in DFS(G, node):
        all_paths.append(path)
max_len   =0
for p in all_paths:
    if len(p) > max_len:
        max_len = len(p)
    
if n == 1:
    print(1)
else:
    print(max_len)