"""
해설: https://blog.naver.com/cwyoo01/222629196376
"""
def gcd(a, b):
    if (b == 0): return a
    return gcd(b, a%b)

n, m = map(int, input().split())
print(m-gcd(n, m))
