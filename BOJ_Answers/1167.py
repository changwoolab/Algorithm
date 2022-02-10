"""
    가장 긴 길이의 시작점을 root라 하면,
    1. 내가 root이거나
    2. 내 자식중 하나가 root이거나
"""
ans = -1
V = int(input())
graph = [[] for _ in range(V+1)]

for _ in range(V):
    li = list(map(int, input().split()))
    i = 1
    while li[i] != -1:
        graph[li[0]].append((li[i], li[i+1]))
        i += 2


def dfs(prev, now, c):
    global ans
    li = []
    for Next, cost in graph[now]:
        if Next != prev:
            li.append(dfs(now, Next, cost))
    if li:
        li = sorted(li)
        if len(li) >= 2:
            ans = max(ans, li[-1]+li[-2])
        return c+li[-1]
    return c


ans2 = dfs(-1, 1, 0)
print(max(ans, ans2))
