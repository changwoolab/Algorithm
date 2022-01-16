# 필요한 숫자들의 개수의 최댓값이 필요한 세트의 개수이다.
# 6과 9는 대체될 수 있으므로, 나올때마다 0.5씩 한 쪽에만 더해주면 된다.

from math import ceil

n = input()
cntOfNeededNums = {"0": 0, "1": 0, "2": 0, "3": 0, "4": 0, "5": 0, "6": 0, "7": 0, "8": 0}
pair = ("6", "9")
for num in n:
    if num in pair:
        cntOfNeededNums["6"] += 0.5
    else:
        cntOfNeededNums[num] += 1
print(ceil(max(cntOfNeededNums.values())))
