import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)


def dfs(prev, now):
    global visited, graph
    # 갔는데 방문했던 곳이라면, 사이클이 있다는 뜻임.
    if visited[now]:
        return False
    visited[now] = True
    res = True
    for Next in graph[now]:
        if Next != prev:
            temp = dfs(now, Next)
            if res:
                res = temp
    return res


case = 0
while True:
    case += 1
    treeCnt = 0
    n, m = map(int, input().split())
    if n == m == 0:
        break
    graph = [[] for _ in range(n+1)]
    visited = [False for _ in range(n+1)]
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    for v in range(1, n+1):
        if not visited[v]:
            if dfs(-1, v):
                treeCnt += 1
    if treeCnt > 1:
        print('Case %d: A forest of %d trees.' % (case, treeCnt))
    elif treeCnt == 1:
        print('Case %d: There is one tree.' % case)
    else:
        print('Case %d: No trees.' % case)
