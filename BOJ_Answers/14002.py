
# 입력
N = int(input())
A = list(map(int, input().split()))

# dp 및 before 정의
dp = [1 for _ in range(N)]
before = [-1 for _ in range(N)]

"""
    dp[i]: i번째까지의 가장 긴 증가하는 부분 수열 길이
    길이 뿐만 아니라 실제 가장 긴 증가하는 부분 수열도 구해야만 함.
    따라서, dp[i] = max((k=1~N)dp[k] + 1, dp[i-1])가 되는데
    이 때, dp[k]를 할 때 A[k] < A[i]일 때만 더해준다.
"""
for i in range(1, N):
    for k in range(i):
        if A[k] < A[i]:
            dp[i] = max(dp[i], dp[k] + 1)
            if dp[i] == dp[k] + 1:
                before[i] = k

# ans 저장
ans = []
Idx = dp.index(max(dp))
while Idx >= 0:
    ans.append(A[Idx])
    Idx = before[Idx]

# 출력
print(max(dp))
print(*ans[::-1])
