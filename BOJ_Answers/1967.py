import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

root, maxWeight = 1, 0
n = int(input())
graph = [[] for _ in range(n+1)]

for _ in range(n-1):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))


def dfs(prev, now, weight):
    global root, maxWeight
    if weight > maxWeight:
        root = now
        maxWeight = weight
    for Next, cost in graph[now]:
        if Next != prev:
            dfs(now, Next, weight+cost)


# 1. 가장 먼 노드 구하기
dfs(-1, 1, 0)
# 2. 가장 먼 노드를 root로 하여 가장 먼 노드 다시 구하기 -> 지름!
dfs(-1, root, 0)
print(maxWeight)
