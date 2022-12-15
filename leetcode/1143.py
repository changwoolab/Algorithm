class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0 for _ in range(len(text2)+1)] for _ in range(len(text1)+1)]

        for i in range(len(text1)):
            for j in range(len(text2)):
                dp[i+1][j+1] = dp[i][j]+1 if text1[i] == text2[j] else max(dp[i+1][j], dp[i][j+1])
        return max((max(row) for row in dp))
