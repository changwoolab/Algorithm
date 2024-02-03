import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)


def dfs(now):
    global visited, graph
    if visited[now]:
        return
    visited[now] = True
    for Next in graph[now]:
        if not visited[Next]:
            dfs(Next)


n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
cnt = 0
for v in range(1, n+1):
    if not visited[v]:
        cnt += 1
        dfs(v)
print(cnt)
