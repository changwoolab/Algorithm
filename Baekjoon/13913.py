from collections import deque

n, k = map(int, input().split())
# dp[i] = 수빈이가 i번째 위치에 있을 때 이전에 있었던 위치
dp = [-1 for _ in range(100001)]
dp[n] = -10
queue = deque([n])
while queue:
    now = queue.popleft()
    if now == k:
        break
    for dx in (now-1, now+1, now*2):
        if 0 <= dx <= 100000 and dp[dx] == -1:
            queue.append(dx)
            dp[dx] = now
ans = []
while k != -10:
    ans.append(k)
    k = dp[k]
print(len(ans)-1)
print(*ans[::-1])
