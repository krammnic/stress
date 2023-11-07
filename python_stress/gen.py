import random as rd

n = rd.randint(10 ** 4, 10 ** 5)
m = rd.randint(10 ** 5, 10 ** 5)

print(n, " ", m)

for i in range(n):
    a = rd.randint(-10**8, 10**8)
    b = rd.randint(-10**8, 10**8)
    while b < a:
        b = rd.randint(-10**8, 10**8)
    print(a, b)

nums = []
for i in range(m):
    nums.append(rd.randint(-10**8, 10**8))
print(" ".join(list(map(str, nums))))
