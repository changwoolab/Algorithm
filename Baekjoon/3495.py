lline = ["/", "\\"]
h, w = map(int, input().split())
ASCII = [input() for _ in range(h)]
s = 0
for line in ASCII:
    inside = False
    for each in line:
        if each in lline:
            inside = not inside
            s += 0.5
        elif inside:
            s += 1
print(int(s))
