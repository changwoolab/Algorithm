n = int(input())
a = list(map(int, input().split()))
x = int(input())
cnt = 0
a.sort()
left, right = 0, n-1
while left < right:
    SUM = a[left] + a[right]
    if SUM < x:
        left += 1
    elif SUM > x:
        right -= 1
    else:
        cnt += 1
        left += 1
print(cnt)
