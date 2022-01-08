from collections import deque

# 상하좌우를 이동 위한 tuple
upDownLeftRight = [(-1, 0), (1, 0), (0, -1), (0, 1)]

# input을 받아서 이차원배열로 전환
n, m = map(int, input().split())
MAP = [list(map(int, input().split())) for _ in range(m)]

# 1이 있는 곳은 BFS를 통해 탐색해야 함.
maximum = 1
queue = deque([])
for i in range(m):
    for j in range(n):
        if MAP[i][j] == 1:
            queue.append((i, j))

# BFS 진행
while queue:
    now = queue.popleft()
    for way in upDownLeftRight:
        nextX = now[0] + way[0]
        nextY = now[1] + way[1]
        # 탐색 안한 곳만 탐색하기
        if 0 <= nextX < m and 0 <= nextY < n and MAP[nextX][nextY] == 0:
            queue.append((nextX, nextY))
            # 걸린 날짜를 MAP에 기록
            MAP[nextX][nextY] = MAP[now[0]][now[1]] + 1
            maximum = max(maximum, MAP[nextX][nextY])

# 0이 있으면 print(-1)
for i in MAP:
    for j in i:
        if j == 0:
            print(-1)
            exit()
print(maximum - 1)

