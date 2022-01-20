import sys
import math
input = sys.stdin.readline

# 인접행렬 형성
n = int(input())
graph = [[math.inf for _ in range(n)] for _ in range(n)]

# 간선 정의
m = int(input())
for i in range(m):
    a, b, c = map(int, input().split())
    graph[a-1][b-1] = min(graph[a-1][b-1], c)

# diagonal은 0으로 정의
for i in range(n):
    graph[i][i] = 0

# 플로이드-와샬 알고리즘 실행
for k in range(n):
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

# INF라면 없는 경우임
for i in range(n):
    for j in range(n):
        if graph[i][j] == math.inf:
            graph[i][j] = 0

# 출력
for vertices in graph:
    print(*vertices)
