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

queue = deque([(0, 0)])
level, currAmount, nextAmount = 1, 1, 0
ex = False # Exit code

# BFS 진행
# 각 level별로 방문할 노드의 수들을 Amount에 저장하고 그 Amount를 소진할때마다 level += 1
while len(queue) > 0:
    now = queue.popleft()
    for way in upDownLeftRight:
        nextX = now[0]+way[0]
        nextY = now[1]+way[1]
        # 목표 위치에 도달하면 Exit
        if nextX == n-1 and nextY == m-1:
            ex = True
            break
        if 0 <= nextX < n and 0 <= nextY < m:
            if MAP[nextX][nextY] == 1:
                queue.append((nextX, nextY))
                nextAmount += 1
                MAP[nextX][nextY] = 2
    currAmount -= 1
    if ex:
        break
    if currAmount == 0:
        currAmount = nextAmount
        nextAmount = 0
        level += 1
print(level + 1)