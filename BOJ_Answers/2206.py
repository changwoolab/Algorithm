# blog 설명 주소: https://blog.naver.com/cwyoo01/222619766671

from collections import deque

# 상하좌우 이동 위한 튜플
dx = (1, -1, 0, 0)
dy = (0, 0, -1, 1)

n, m = map(int, input().split())
MAP = [[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
    temp = input()
    for j in range(m):
        MAP[i][j] = int(temp[j])

# visited[벽을 부쉈는가?][행][열]
visited = [[[0 for _ in range(m)] for _ in range(n)] for _ in range(2)]

# 최단거리를 찾아야하므로 BFS 사용, queue = [(행, 열, 벽 부숨 여부)]
queue = deque([(0, 0, 0)])
while queue:
    now = queue.popleft()
    for i in range(4):
        nx = now[0] + dx[i]
        ny = now[1] + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            # 1. 벽이 없는 경우
            if MAP[nx][ny] == 0 and visited[now[2]][nx][ny] == 0:
                queue.append((nx, ny, now[2]))
                visited[now[2]][nx][ny] = visited[now[2]][now[0]][now[1]] + 1
            # 2. 벽이 있는 경우
            elif MAP[nx][ny] == 1 and now[2] == 0:
                queue.append((nx, ny, 1))
                visited[1][nx][ny] = visited[now[2]][now[0]][now[1]] + 1

if n > 1 and m > 1 and max(visited[0][n-1][m-1], visited[1][n-1][m-1]) == 0:
    print("-1")
else:
    if visited[0][n-1][m-1] == 0:
        print(visited[1][n-1][m-1] + 1)
    elif visited[1][n-1][m-1] == 0:
        print(visited[0][n-1][m-1] + 1)
    else:
        print(min(visited[0][n-1][m-1], visited[1][n-1][m-1])+1)

