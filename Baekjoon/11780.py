
INF = float("inf")
n = int(input())
m = int(input())

matrix = [[INF for _ in range(n)] for _ in range(n)]
nxt = [[INF for _ in range(n)] for _ in range(n)]  # i~j로가는 최단경로에서 i 다음 정점 저장
for _ in range(m):
    a, b, c = map(int, input().split())
    if matrix[a-1][b-1] > c:
        matrix[a-1][b-1] = c
        nxt[a-1][b-1] = b-1

# 시작도시 != 도착도시
for i in range(n):
    matrix[i][i] = 0

# 반드시 k를 거쳐서 i~j를 가는 경우의 수
for k in range(n):
    for i in range(n):
        for j in range(n):
            if matrix[i][j] > matrix[i][k] + matrix[k][j]:
                matrix[i][j] = matrix[i][k] + matrix[k][j]
                # i~j를 가는 최단경로에 i~k를 가는 최단경로가 포함되어 있으므로 이를 반영
                nxt[i][j] = nxt[i][k]

for i in matrix:
    for j in i:
        print(0 if j == INF else j, end=' ')
    print()
for i in range(n):
    for j in range(n):
        if matrix[i][j] == 0 or matrix[i][j] == INF:
            print(0)
        else:
            now = i
            ans = []
            while now != j:
                ans.append(now+1)
                now = nxt[now][j]
            ans.append(now+1)
            print(len(ans), end=' ')
            print(*ans)
