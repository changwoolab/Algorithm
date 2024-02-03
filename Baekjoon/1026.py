import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ans = 0
a.sort()
for i in range(n):
    ans += a[i] * b.pop(b.index(max(b)))

print(ans)
