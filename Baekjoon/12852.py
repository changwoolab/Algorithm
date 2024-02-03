from collections import deque

# input 및 정의들
n = int(input())
queue = deque([n])
memory = [0 for _ in range(n+1)]

# /3 or /2 or -1을 해주며 BFS 진행
# 이 때, 시간 단축 및 경로 저장을 위해 memory function에 표시하기
now = 0
while True:
    now = queue.popleft()
    if now == 1:
        break
    if now % 3 == 0 and not memory[now//3]:
        memory[now//3] = 3
        queue.append((now//3))
    if now % 2 == 0 and not memory[now//2]:
        memory[now//2] = 2
        queue.append((now//2))
    if not memory[now-1]:
        memory[now-1] = 1
        queue.append((now-1))

# 답 도출하기
cnt = 0
res = []
while True:
    res.append(now)
    if now == n:
        break
    if memory[now] == 1:
        now += 1
    else:
        now *= memory[now]
    cnt += 1
print(cnt)
print(*res[::-1])
