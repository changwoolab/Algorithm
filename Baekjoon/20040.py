import sys
sys.setrecursionlimit(10**9)

input = sys.stdin.readline


def find(now):
    if myRoot[now] == now:
        return now
    realRoot = find(myRoot[now])
    myRoot[now] = realRoot
    return realRoot


def union(r1, r2):
    if r1 == r2:
        return True
    myRoot[r2] = r1
    return False

# 같은 집합 내에 있는 정점끼리 연결되면 사이클이 형성됨을 이용함.
n, m = map(int, input().split())
myRoot = [i for i in range(n)]
i = 0
res = False
for i in range(m):
    a, b = map(int, input().split())
    r1 = find(a)
    r2 = find(b)
    if union(r1, r2):
        res = True
        break

print(i+1 if res else 0)
