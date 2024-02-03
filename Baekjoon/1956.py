import sys
import heapq
input = sys.stdin.readline
INF = float("inf")

V, E = map(int, input().split())
floyd = [[INF for _ in range(V)] for _ in range(V)]
graph = [[] for _ in range(V)]
heap = []
for _ in range(E):
    a, b, c = map(int, input().split())
    floyd[a-1][b-1] = c
    graph[a-1].append((b-1, c))
    heapq.heappush(heap, (c, a-1, b-1))
"""
약간 다익스트라 + 플로이드 짬뽕 느낌으로!
힙으로 가중치가 더 작은 애들부터 뽑음으로써
플로이드 인접 행렬에 있는 값들을 업데이트할 때 단순히 순서대로 업데이트하는 것이 아닌
작은 애들부터 업데이트를 할 수 있도록 한다.
이를 통해 플로이트 인접행렬 전체를 구하지 않고도 최단 사이클을 찾을 수 있다.
(= transitive closure를 훨씬 빠르게 수행할 수 있다.)
주의점) 최단 사이클 찾을 때만 힙으로 관리해주는 것이 타당하다.
그 이유는, "모든 중간 정점을 거치는 경우의 수"를 탐색해줘야 최단 경로임이 확실해지기 때문이다.
힙으로 플로이드 알고리즘을 관리한다면 모든 경우의 수에 대해 탐색하지 않기 때문에 부정확한 최단경로들이 도출될 수 있다.
"""
while heap:
    dist, start, mid = heapq.heappop(heap)

    if dist > floyd[start][mid]:
        continue

    if start == mid:
        print(dist)
        break

    # mid를 중간 정점으로 하여 갈 수 있는 정점들 탐색
    for vertex, weight in graph[mid]:
        newDist = dist + weight
        if newDist < floyd[start][vertex]:
            floyd[start][vertex] = newDist
            heapq.heappush(heap, (newDist, start, vertex))
else:
    print(-1)
