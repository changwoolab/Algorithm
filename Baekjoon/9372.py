"""
    주어진 그래프가 연결그래프이므로
    최소 n-1번 연결하면 신장드리가 왼성된다.
"""

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    for i in range(m):
        a, b = input().split()
    print(n-1)
