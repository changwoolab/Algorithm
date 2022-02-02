s1 = [0] + list(input())
s2 = [0] + list(input())

"""
    dp[i][j] = s1을 j번째까지, s2를 i번째까지 탐색했을 때의 LCS 길이
"""
dp = [[0 for _ in range(len(s1))] for _ in range(len(s2))]
i, j = 0, 0
for i in range(1, len(s2)):
    for j in range(1, len(s1)):
        if s1[j] == s2[i]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])

# 출력 및 역추적
ans1 = dp[i][j]
ans2 = []
print(ans1)
while ans1 > 0:
    if i >= 1 and j >= 1 and s2[i] == s1[j]:
        ans2.append(s2[i])
        i, j = i - 1, j - 1
        ans1 -= 1
    elif j > 1 and dp[i][j] == dp[i][j-1]:
        j -= 1
    else:
        i -= 1
for i in ans2[::-1]:
    print(i, end='')
