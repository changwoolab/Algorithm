import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)


n = int(input())
w = int(input())
# pos에는 맨 처음 경찰차 위치 저장해두고 그 뒤에 방문할 위치 저장하기
pos = [[1, 1], [n, n]] + [list(map(int, input().split())) for _ in range(w)]
dp = [[-1 for _ in range(w+2)] for _ in range(w+2)]


# dp[i][j] 반환
# dp[i][j] = 경찰차1이 i 위치, 경찰차2는 j 위치를 시작으로 방문할 때 남은 최소거리
def sol(i, j):
    # invalid한 경우는 return
    if i > w or j > w: return 0
    # 이미 방문했던 경우는 계산X
    if dp[i][j] != -1: return dp[i][j]

    # 다음번에 방문할 곳 = (경찰차 1 or 2가 방문한 곳 중 최댓값) + 1
    Next = max(i, j) + 1
    # 경찰차1이 간 경우 + 경찰차2가 간 경우 계산하여 더 작은 값 저장
    ni = sol(Next, j)+abs(pos[Next][0]-pos[i][0])+abs(pos[Next][1]-pos[i][1])
    nj = sol(i, Next)+abs(pos[Next][0]-pos[j][0])+abs(pos[Next][1]-pos[j][1])
    dp[i][j] = min(ni, nj)
    return dp[i][j]


def backtrace(i, j):
    if i > w or j > w: return
    Next = max(i, j) + 1

    # n1 = 경찰차1이 Next 갈 때, Next ~ 경찰차1 거리
    n1 = abs(pos[Next][0]-pos[i][0]) + abs(pos[Next][1]-pos[i][1])
    n2 = abs(pos[Next][0]-pos[j][0]) + abs(pos[Next][1]-pos[j][1])

    # "경찰차1이 Next 이후에 방문할 최소거리 + 현재위치 ~ Next까지의 거리 < 경찰차2"라면, 경찰차1이 간거임.
    if dp[Next][j]+n1 < dp[i][Next]+n2:
        print(1)
        backtrace(Next, j)
    else:
        print(2)
        backtrace(i, Next)


# 경찰차의 맨 처음 위치는 각각 pos[0]과 pos[1]임. 따라서 0과 1을 보내줌
print(sol(0, 1))
backtrace(0, 1)
