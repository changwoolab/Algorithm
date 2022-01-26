INF = float("inf")

n, s = map(int, input().split())
nums = list(map(int, input().split()))

l, r = 0, 0
minLen = INF
now = 0

while l < n:
    nowLen = r-l
    if now >= s:
        minLen = min(minLen, nowLen)
        now -= nums[l]
        l += 1
    elif r >= n:
        break
    else:
        now += nums[r]
        r += 1

print(minLen if minLen != INF else 0)
