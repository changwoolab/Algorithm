import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)


li = []
while True:
    try:
        temp = int(input())
        li.append(temp)
    except:
        break

# 전위순회 = N -> L -> R
def postOrder(left, right):
    if left > right:
        return
    mid = right+1
    for i in range(left+1, right+1):
        if li[i] > li[left]:
            mid = i
            break

    postOrder(left+1, mid-1)
    postOrder(mid, right)
    print(li[left])


postOrder(0, len(li)-1)
