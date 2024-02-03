"""
    모든 노드들을 1회 순회하며 부모를 찾으면 됨. -> O(N)
"""

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)


N = int(input())
graph = [[] for _ in range(N+1)]
ans = [-1 for _ in range(N+1)]

for _ in range(N-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)


def dfs(prev, now):
    ans[now] = prev
    for Next in graph[now]:
        if ans[Next] == -1 and Next != prev:
            dfs(now, Next)


dfs(-1, 1)
for i in range(2, N+1):
    print(ans[i])
