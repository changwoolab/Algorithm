from collections import deque

# 상하좌우를 이동 위한 tuple
upDownLeftRight = [(-1, 0), (1, 0), (0, -1), (0, 1)]

# input을 받아서 이차원배열로 전환
n, m = map(int, input().split())
MAP = [[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
    temp = input()
    for j in range(m):
        MAP[i][j] = int(temp[j])

# BFS를 위한 Queue 정의
queue = deque([(0, 0)])

# BFS 진행, MAP에 level을 남기면서 진행하기
while queue:
    now = queue.popleft()
    for way in upDownLeftRight:
        nextX = now[0]+way[0]
        nextY = now[1]+way[1]
        if 0 <= nextX < n and 0 <= nextY < m:
            if MAP[nextX][nextY] == 1:
                queue.append((nextX, nextY))
                MAP[nextX][nextY] = MAP[now[0]][now[1]] + 1

print(MAP[n-1][m-1])