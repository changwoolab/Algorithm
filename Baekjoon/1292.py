a, b = map(int, input().split())
SUM = 0
cnt = 0
n = 1
while cnt < b:
    for i in range(n):
        cnt += 1
        if cnt >= a:
            SUM += n
        if cnt == b:
            break
    n += 1
print(SUM)
