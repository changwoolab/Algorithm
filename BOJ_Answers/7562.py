from collections import deque

# 나이트 이동 위한 튜플
dx = (2, 1, 2, 1, -2, -1, -2, -1)
dy = (1, 2, -1, -2, 1, 2, -1, -2)

# 테스트 케이스 인풋
t = int(input())
for _ in range(t):
    # 입력 받기
    L = int(input())
    knight = list(map(int, input().split()))
    goal = list(map(int, input().split()))

    # 가중치 없는 최단거리 구하기이므로 BFS 진행
    visited = [[0 for _ in range(L)] for _ in range(L)]
    queue = deque([[knight[0], knight[1]]])
    while queue:
        now = queue.popleft()
        # 도착하면 output 후 break
        if now == goal:
            print(visited[now[0]][now[1]])
            break
        # 총 8개의 방향으로 이동해야 함.
        for i in range(8):
            nx, ny = now[0] + dx[i], now[1] + dy[i]
            if 0 <= nx < L and 0 <= ny < L and visited[nx][ny] == 0:
                queue.append([nx, ny])
                visited[nx][ny] = visited[now[0]][now[1]] + 1
