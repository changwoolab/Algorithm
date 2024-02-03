import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[] for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)


bacon = (9876543210, -1)
for v in range(1, N+1):
    queue = deque([(v, 0)])
    visited = [False for _ in range(N+1)]
    cnt = 0
    while queue:
        now, nowLevel = queue.popleft()
        if visited[now]:
            continue
        visited[now] = True
        cnt += nowLevel
        for nxt in graph[now]:
            if not visited[nxt]:
                queue.append((nxt, nowLevel+1))
    if cnt < bacon[0]:
        bacon = (cnt, v)

print(bacon[1])
