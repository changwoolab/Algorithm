from collections import deque
from sys import stdin

# 변화량 table
dx = [1, -1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

m, n, h = map(int, stdin.readline().split())

# 3차원 배열로 input 받기
tomato = [[list(map(int, stdin.readline().split())) for _ in range(n)] for _ in range(h)]

# 중복 탐색 방지를 위해 모든 1의 위치를 queue로 찾은 뒤, 이 queue를 통해 BFS를 진행하기
queue = deque([])
for z in range(h):
    for y in range(n):
        for x in range(m):
            if tomato[z][y][x] == 1:
                queue.append((x, y, z))

days = 1
while queue:
    x, y, z = queue.popleft()
    # 6개의 방향으로 움직여서 BFS를 진행
    for i in range(6):
        nx = x + dx[i]
        ny = y + dy[i]
        nz = z + dz[i]
        # 범위 내에 들어온다면,
        if 0 <= nx < m and 0 <= ny < n and 0 <= nz < h:
            # 진입한 곳이 익지 않은 곳이라면 방문했음을 update
            if tomato[nz][ny][nx] == 0:
                tomato[nz][ny][nx] = tomato[z][y][x] + 1
                days = max(days, tomato[nz][ny][nx])
                queue.append((nx, ny, nz))

# 0이 있는지 확인
for z in tomato:
    for y in z:
        for x in y:
            if x == 0:
                print(-1)
                exit()

# 최초 시작을 1부터 했으므로 1을 빼줌.
print(days - 1)
