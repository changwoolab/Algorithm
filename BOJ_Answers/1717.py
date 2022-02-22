import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def union(aRoot, bRoot):
    if aRoot != bRoot:
        sett[bRoot] = aRoot


def find(now):
    if now == sett[now]:
        return now
    # 현재 노드의 부모 갱신해주기 (트리의 장점을 살리기 위함)
    sett[now] = find(sett[now])
    return sett[now]


n, m = map(int, input().split())
sett = [i for i in range(n+1)]  # 부모 기억
for _ in range(m):
    c, a, b = map(int, input().split())
    aRoot = find(a)
    bRoot = find(b)
    if c == 0:
        union(aRoot, bRoot)
    else:
        print("NO" if bRoot != aRoot else "YES")
