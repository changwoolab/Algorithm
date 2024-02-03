n = int(input())
s = list(map(int, input().split()))
y, m = 0, 0
for i in s:
    y += i // 30 * 10 + 10
    m += i // 60 * 15 + 15
if y < m:
    print('Y', y)
elif y > m:
    print('M', m)
else:
    print('Y M', y)
