import sys
import heapq
import math
input = sys.stdin.readline


# start 정점을 시작으로하여, 다익스트라 알고리즘을 통해 최소경로들을 구하기
def dijkstra(start):
    heap = [(0, start)]
    distance = [math.inf for _ in range(N)]
    distance[start] = 0

    while heap:
        currDist, currVertex = heapq.heappop(heap)

        # 이전에 찍어둔 최소 거리가 지금 찍을 최소 거리보다 작으면 continue
        if distance[currVertex] < currDist:
            continue

        for weightToNext, nextVertex in graph[currVertex]:
            # 지금 구한 최소거리가 이미 구한 최소거리보다 짧으면 Heap에 추가
            if weightToNext + currDist < distance[nextVertex]:
                heapq.heappush(heap, (weightToNext + currDist, nextVertex))
                distance[nextVertex] = weightToNext + currDist
    return distance


N, E = map(int, input().split())

# 인접 그래프
graph = [[] for _ in range(N)]
for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a-1].append((c, b - 1)) # (간선 가중치, 도달 정점)
    graph[b-1].append((c, a - 1))

mid = list(map(int, input().split()))

# 해당 정점을 시작으로 다익스트라 알고리즘을 통해 최소경로들을 구하기
d1 = dijkstra(0)
d2 = dijkstra(mid[0] - 1)
d3 = dijkstra(mid[1] - 1)

# 가능한 경로
# 1. 0 -> V1 -> V2 -> Vn
dist1 = d1[mid[0]-1] + d2[mid[1]-1] + d3[N-1]
# 2. 0 -> V2 -> V1 -> Vn
dist2 = d1[mid[1]-1] + d3[mid[0]-1] + d2[N-1]

print(min(dist1, dist2) if min(dist1, dist2) < math.inf else -1)

