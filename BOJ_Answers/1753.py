from sys import stdin
import math
import heapq

V, E = map(int, stdin.readline().split())
k = int(stdin.readline())
graph = [[] for _ in range(V)]

# 다익스트라를 위한 정의
d = [math.inf for _ in range(V)]
visited = [False for _ in range(V)]

# (정점 N까지의 최소 거리, 정점 N) 형태로 최소 힙에 저장하기.
d[k-1] = 0
heap = [(d[k-1], k-1)]

# 그래프 입력받기, graph = (정점, 가중치)
for _ in range(E):
    u, v, w = map(int, stdin.readline().split())
    graph[u-1].append((v-1, w))

while heap:
    currMinD, currVertex = heapq.heappop(heap)
    # 알고보니 방문했던 곳이라면... continue...
    if visited[currVertex]:
        continue

    # 지금 방문한 곳까지 최소임이 확실해졌으므로, 방문처리 해주기
    visited[currVertex] = True

    # 현재 정점으로부터 인접한 정점들까지의 거리 구하기 + 최솟값 반영해주기
    for vertex in graph[currVertex]:
        if not visited[vertex[0]]: # 이미 방문했던 정점이면 방문하지 않는다.
            heapq.heappush(heap, (currMinD + vertex[1], vertex[0]))
            d[vertex[0]] = min(currMinD+vertex[1], d[vertex[0]])


for i in range(V):
    if d[i] == math.inf:
        print("INF")
    else:
        print(d[i])
