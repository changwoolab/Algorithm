import sys
import heapq
input = sys.stdin.readline


# start에서 시작하여 듀오가 갈 수 있는 최단경로에 대한 정보 반환
def dijkstra(n, graph, start):
    heap = [(0, start)] # (가중치, 정점) 순으로 저장
    distance = [int(1e9) for _ in range(n)]
    distance[start] = 0
    while heap:
        currDist, currVertex = heapq.heappop(heap)

        # 만약 지금의 거리가 이미 저장된 거리보다 크다면 -> continue
        if currDist > distance[currVertex]:
            continue

        # 다익스트라 진행
        for weightToNext, nextVertex in graph[currVertex]:
            # 지금 구하는 것이 기존에 저장된 거리보다 짧다면 진행
            if weightToNext + currDist < distance[nextVertex]:
                heapq.heappush(heap, (weightToNext + currDist, nextVertex))
                distance[nextVertex] = weightToNext + currDist
    return distance


T = int(input())
for i in range(T):
    n, m, t = map(int, input().split()) # 교차로, 도로, 목적지 후보 개수
    s, g, h = map(int, input().split()) # s: 출발지, g ~ h: 듀오가 지나간 곳
    graph = [[] for _ in range(n)] # 인접리스트로 그래프 저장
    goal = [] # 목적지 후보
    for _ in range(m):
        a, b, d = map(int, input().split())
        # (간선 가중치, 정점) 순으로 저장
        graph[a - 1].append((d, b - 1))
        graph[b - 1].append((d, a - 1))
    for _ in range(t):
        goal.append(int(input()))

    # 다익스트라 수행
    dijkstraFromStart = dijkstra(n, graph, s - 1)
    dijkstraFromG = dijkstra(n, graph, g - 1)
    dijkstraFromH = dijkstra(n, graph, h - 1)

    # result 저장 및 출력
    res = []
    for vertex in goal:
        # 만약 s->goal 최소거리 == s->g->h->goal 이거나
        if dijkstraFromStart[vertex-1] == dijkstraFromStart[g-1] + dijkstraFromG[h-1] + dijkstraFromH[vertex-1]:
            res.append(vertex)
        # s->goal 최소거리 == s->h->g->goal 이라면, append
        elif dijkstraFromStart[vertex-1] == dijkstraFromStart[h-1] + dijkstraFromH[g-1] + dijkstraFromG[vertex-1]:
            res.append(vertex)
    print(*sorted(res))
