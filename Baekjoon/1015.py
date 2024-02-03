n = int(input())
a = list(map(int, input().split()))
ans = [-1 for _ in range(n)]
sortedA = sorted(a)
cnt = 0
for i in sortedA:
    for j in range(n):
        if i == a[j] and ans[j] == -1:
            ans[j] = cnt
            cnt += 1
            break
for i in ans:
    print(i, end=' ')
