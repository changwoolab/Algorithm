# 상하좌우를 모두 방문하는 dfs 진행.
# "1"일 때만 탐색을 계속하고 1이 아닌 곳은 이미 방문했거나 0인 곳임.
def dfs(i, j, MAP):
    global cnt, upDownLeftRight
    if 0 <= i < n and 0 <= j < n:
        if MAP[i][j] != 1:
            return 0
        MAP[i][j] = cnt[0] + 2
        cnt[cnt[0]] += 1
        for way in upDownLeftRight:
            dfs(i+way[0], j+way[1], MAP)

# 상하좌우를 이동 위한 tuple
upDownLeftRight = [(-1, 0), (1, 0), (0, -1), (0, 1)]

# input을 받아서 이차원배열로 전환
n = int(input())
MAP = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    temp = input()
    for j in range(n):
        MAP[i][j] = int(temp[j])

# for문을 돌며 새로운 곳 방문할때마다 cnt[0]+=1해주고 dfs
cnt = [1]
for i in range(n):
    for j in range(n):
        if MAP[i][j] == 1:
            cnt.append(1)
            dfs(i, j, MAP)
            cnt[0] += 1

# 정렬 후 출력
cnt = [cnt[0]] + sorted(cnt[1:])
for i in cnt:
    print(i-1)
