import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

n = int(input())

I = [-1] + list(map(int, input().split()))
P = [-1] + list(map(int, input().split()))

# iPos: 해당 root가 inorder에서 몇 번째에 있는지 알려줌
iPos = [0]*(n+1)
for i in range(1, n+1):
    iPos[I[i]] = i


def preOrder(Is, Ie, Ps, Pe):
    if Is > Ie or Ps > Pe:
        return
    root = P[Pe]
    print(root, end=' ')

    # PostOrder도 길이를 나눠서 보내야 함. 이를 위해서
    # 왼쪽구간의 길이와 오른쪽 구간의 길이를 Inorder 배열을 통해 구하기
    rightLen = Ie - iPos[root]
    leftLen = iPos[root] - Is

    # Left
    preOrder(Is, iPos[root]-1, Pe-leftLen-rightLen, Pe-rightLen-1)
    # Right
    preOrder(iPos[root]+1, Ie, Pe-rightLen, Pe-1)


preOrder(1, n, 1, n)
