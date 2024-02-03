import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def union(a, b):
    aRoot = find(a)
    bRoot = find(b)
    if aRoot != bRoot:
        sett[bRoot] = aRoot


def find(now):
    if now == sett[now]:
        return now
    sett[now] = find(sett[now])
    return sett[now]


n = int(input())
m = int(input())
sett = [i for i in range(n+1)]
for i in range(n):
    s = list(map(int, input().split()))
    for j in range(n):
        if s[j] == 1:
            union(i, j)

plan = list(map(int, input().split()))
currRoot = find(plan[0]-1)
for i in range(1, m):
    if currRoot != find(plan[i]-1):
        print("NO")
        exit()
print("YES")
