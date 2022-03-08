"""
    시작 정점이 따로 정해져있지 않으므로
    크루스칼 알고리즘을 사용하여 MST를 구하면 더 쉽다.
"""

import sys
input = sys.stdin.readline

def union(a, b):
    aRoot = find(a)
    bRoot = find(b)
    if aRoot != bRoot:
        sett[aRoot] = bRoot
        return True
    return False

def find(now):
    if now == sett[now]:
        return now
    temp = find(sett[now])
    sett[now] = temp
    return temp


v, e = map(int, input().split())

edge = []
sett = [i for i in range(v+1)]
for i in range(e):
    a, b, c = map(int, input().split())
    edge.append((c, a, b))
edge.sort()
cnt = 0
for weight, v1, v2 in edge:
    if union(v1, v2):
        cnt += weight
print(cnt)
