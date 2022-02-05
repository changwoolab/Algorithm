import heapq
import sys

input = sys.stdin.readline
INF = float("inf")

n = int(input())
m = int(input())

# 인접그래프 생성
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((c, b))  # (cost, vertex) 순으로 저장
start, end = map(int, input().split())

dp = [INF for _ in range(n+1)]  # 최소비용 저장
visited = [-1 for _ in range(n+1)]  # 이전 정점 저장
heap = [(-10, start)]  # (cost, vertex)순 저장
dp[start] = 0
while heap:
    cost, now = heapq.heappop(heap)

    # 현재 cost가 이미 구해둔 cost보다 크다면 invalid
    if cost > dp[now]:
        continue

    for edgeCost, nVertex in graph[now]:
        # 현재 + edgeCost < nextVertex Cost라면, append
        nCost = dp[now] + edgeCost
        if nCost < dp[nVertex]:
            heapq.heappush(heap, (nCost, nVertex))
            dp[nVertex] = nCost
            visited[nVertex] = now

# 출력
print(dp[end])
ans = [end]
while visited[end] != -1:
    ans.append(visited[end])
    end = visited[end]
print(len(ans))
print(*ans[::-1])
