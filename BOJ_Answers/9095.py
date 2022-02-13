import sys
input = sys.stdin.readline


def dfs(cnt, n):
    if 0 <= n <= 1:
        return 1
    elif n < 0:
        return 0
    count = 0
    for i in range(1, 4):
        count += dfs(cnt, n-i)
    return count


T = int(input())
for _ in range(T):
    n = int(input())
    cnt = dfs(0, n)
    print(cnt)
