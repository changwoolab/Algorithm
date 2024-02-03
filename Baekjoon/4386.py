"""
    정점들을 모두 잇는 최소 비용을 구하는 문제이므로,
    MST를 찾는 문제와 같다! -> 크루스칼 알고리즘 or 프림 알고리즘 이용!
    여기서는 크루스칼 알고리즘으로 풀었음
"""

import heapq
import sys
input = sys.stdin.readline

# 같은 집합 아닌 경우 -> True, 같은 집합인 경우 -> False
def union(a, b):
    aRoot = find(a)
    bRoot = find(b)
    if aRoot != bRoot:
        parentof[bRoot] = aRoot
        return True
    return False


# 정점을 받아서 root 찾아주기
def find(now):
    if now == parentof[now]:
        return parentof[now]
    temp = find(parentof[now])
    parentof[now] = temp
    return temp


n = int(input())
star = [list(map(float, input().split())) for _ in range(n)]
heap = []
parentof = [i for i in range(n)]
cnt = 0

# 모든 정점에 대해 정점 ~ 정점 거리 구하기
for i in range(n):
    for j in range(i+1, n):
        # (정점 간 거리, 정점1, 정점2) 순으로 저장
        heapq.heappush(heap, (((star[i][0]-star[j][0])**2+(star[i][1]-star[j][1])**2)**(1/2), i, j))

while heap:
    dist, v1, v2 = heapq.heappop(heap)
    if union(v1, v2):
        cnt += dist

print(round(cnt, 2))
