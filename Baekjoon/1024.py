n, l = map(int, input().split())
ans_s = -1
cnt = 0
for i in range(l, 101):
    temp = (i * i - i) / 2
    if (n - temp) % i == 0 and (n - temp) // i >= 0:
        ans_s = (n - temp) // i
        cnt = i
        break
if ans_s == -1:
    print(-1)
else:
    for i in range(cnt):
        print(int(ans_s + i), end=' ')
