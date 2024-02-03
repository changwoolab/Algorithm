"""
해설: https://blog.naver.com/cwyoo01/222629662218
"""
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())
k = (y2-y1)*(x3-x1) + (y1-y3)*(x2-x1)
if k == 0:
    print(0)
elif k < 0:
    print(1)
else:
    print(-1)
