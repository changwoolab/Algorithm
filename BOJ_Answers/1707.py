from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(10**6)


def dfs(graph, now, beforeVertex):
    global visited, isBipartite
    if not isBipartite:
        return False
    # 이미 방문했던 적이 있던 그래프라면, 색깔 판별해주기
    if visited[now] != -1:
        if visited[beforeVertex] == visited[now]:
            isBipartite = False
    # 방문한 적 없다면, 색깔 칠해주고 dfs 진행하기
    else:
        visited[now] = int(not visited[beforeVertex])
        # dfs 진행하기
        for vertex in graph[now]:
            dfs(graph, vertex, now)
            if not isBipartite:
                break


k = int(stdin.readline())
for _ in range(k):
    # isBipartite == True라면, "아직까지는" 이분그래프라는 뜻
    isBipartite = True
    v, e = map(int, stdin.readline().split())
    # 인접리스트 형성
    graph = [[] for _ in range(v+1)]
    for i in range(e):
        v1, v2 = map(int, stdin.readline().split())
        graph[v1].append(v2)
        graph[v2].append(v1)
    # 중복 탐색 방지 및 색깔 칠하기를 위해 visited 관리하기
    # -1이면 아직 색칠 x, 0이면 빨강, 1이면 파랑
    visited = [-1 for _ in range(v + 1)]

    # 모든 정점이 연결된 그래프가 아닐 수 있으므로, 방문 안 된 정점들에 대해 모두 dfs 진행
    for i in range(1, v+1):
        if not isBipartite:
            break
        if visited[i] == -1:
            dfs(graph, i, 0)
    if isBipartite:
        print("YES")
    else:
        print("NO")
