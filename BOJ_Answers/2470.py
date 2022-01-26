n = int(input())
fluid = sorted(list(map(int, input().split())))
l, r = 0, n-1
minL, minR, minF = l, r, fluid[l]+fluid[r]
while l < r:
    now = fluid[l] + fluid[r]
    if abs(now) < abs(minF):
        minL, minR, minF = l, r, fluid[l]+fluid[r]
    if now < 0:
        l += 1
    else:
        r -= 1
print(fluid[minL], fluid[minR])
