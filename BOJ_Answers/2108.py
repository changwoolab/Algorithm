from collections import Counter
import sys
input = sys.stdin.readline

N = int(input())
li = sorted([int(input()) for _ in range(N)])
print(round(sum(li)/N))
print(li[len(li)//2])
m = Counter(li).most_common()
if len(m) >= 2 and m[0][1] == m[1][1]:
    print(m[1][0])
else:
    print(m[0][0])
print(li[-1]-li[0])
