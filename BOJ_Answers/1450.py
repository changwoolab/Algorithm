from bisect import bisect_right


def bruteForceByLevel(c, value, res, level, w):
    if level >= len(value):
        # 현재 무게가 C보다 작을 때만 넣어주기
        if w <= c:
            res.append(w)
        return
    # 넣고 가거나 안넣고 가거나 둘 중 하나.
    bruteForceByLevel(c, value, res, level + 1, w)
    bruteForceByLevel(c, value, res, level + 1, w + value[level])


n, c = map(int, input().split())
cnt = 0
left, right = [], []
value = list(map(int, input().split()))
leftValue, rightValue = value[:n//2], value[n//2:]

# 1. 반으로 나누고 각각을 브루트포스로 탐색
bruteForceByLevel(c, leftValue, left, 0, 0)
bruteForceByLevel(c, rightValue, right, 0, 0)

# 2. 오른쪽 것 정렬하기
right.sort()

# 3. 구해둔 왼쪽 것들을 탐색하며 C-왼쪽 == 오른쪽인 부분을 이분탐색으로 찾아 더하기
for value in left:
    cnt += bisect_right(right, c-value)

print(cnt)
