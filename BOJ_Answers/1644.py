n = int(input())

# 1. 에라토스테네스의 체를 이용하여 n까지의 모든 소수를 찾아 리스트에 저장
isPrime = [True for _ in range(n+1)]
primeNums = []
for num in range(2, int(n**0.5)+1):
    if isPrime[num]:
        for i in range(num*num, n+1, num):
            isPrime[i] = False

for num in range(2, n+1):
    if isPrime[num]:
        primeNums.append(num)

# 2. 투포인터로 연속된 소수 합 찾기
l, r, now, cnt = 0, 0, 0, 0
limit = len(primeNums)
while True:
    if now >= n:
        if now == n:
            cnt += 1
        now -= primeNums[l]
        l += 1
    elif r >= limit:
        break
    else:
        now += primeNums[r]
        r += 1
print(cnt)
