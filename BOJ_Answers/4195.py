import sys
sys.setrecursionlimit(10**9)

input = sys.stdin.readline


def find(now):
    if dic[now] == now:
        return now
    realRoot = find(dic[now])
    dic[now] = realRoot
    return realRoot


def union(r1, r2):
    if r1 == r2:
        return
    counter[r1] += counter[r2]
    dic[r2] = r1


t = int(input())
for _ in range(t):
    f = int(input())
    dic = {}
    counter = {}
    for i in range(f):
        r, t = input().split()
        if r not in dic:
            dic[r] = r
            counter[r] = 1
        if t not in dic:
            dic[t] = t
            counter[t] = 1
        r1 = find(r)
        r2 = find(t)
        union(r1, r2)
        print(counter[r1])
