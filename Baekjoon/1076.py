dic = {
    "black": 0,
    "brown": 1,
    "red": 2,
    "orange": 3,
    "yellow": 4,
    "green": 5,
    "blue": 6,
    "violet": 7,
    "grey": 8,
    "white": 9
}

res = 0
res += dic[input()] * 10
res += dic[input()]
res *= 10**dic[input()]

print(res)
