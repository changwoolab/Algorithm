from collections import deque

n, k = map(int, input().split())
queue = deque([n])
level, cnt = 0, 1
visited = [False for _ in range(100001)]

while queue:
    tCnt = 0
    for i in range(cnt):
        now = queue.popleft()
        if now == k:
            print(level)
            exit()
        # -1, +1, *2를 탐색하되, 이미 방문한 곳은 더 이상 탐색하지 않기
        for dx in (now - 1, now + 1, now * 2):
            if 0 <= dx <= 100000 and not visited[dx]:
                visited[dx] = True
                queue.append(dx)
                tCnt += 1
    cnt = tCnt
    level += 1
