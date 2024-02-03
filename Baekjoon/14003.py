from bisect import bisect_left

# 입력
N = int(input())
A = list(map(int, input().split()))

"""
    dp 및 부분수열 정의
    dp[i] = A[i]를 마지막으로 하는 증가하는 부분 수열 길이
    part: 부분 수열
"""
part = [A[0]]
dp = [0 for _ in range(N)]
length = 0

for i in range(1, N):
    # 1. 마지막 원소보다 더 큰지 확인하기 + dp 저장
    # 2. 더 크지 않다면 이분탐색하여 넣기 + dp 저장
    if A[i] > part[-1]:
        part.append(A[i])
        length += 1
        dp[i] = length
    else:
        # 부분수열로부터 현재 길이를 구해 dp에 넣어준다
        # EX) part = [1 2 3] 이고 A[10] = 2일 때, 2을 마지막으로 하는 길이는 2이므로 dp[10] = 2이다.
        dp[i] = bisect_left(part, A[i])

        # 부분수열을 업데이트 해준다.
        part[dp[i]] = A[i]

print(length+1)
ans = []
for i in range(N-1, -1, -1):
    if dp[i] == length:
        ans.append(A[i])
        length -= 1
print(*ans[::-1])
