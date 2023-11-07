import os, sys

_, f1, gen, iters = sys.argv

for i in range(int(iters)):
    print('Test', i + 1)
    os.system(f'python3 {gen} > test.txt')
    v1 = os.popen(f'./{f1} < test.txt').read()
    lst = list(map(int, v1.split()))

    for i in lst:
        if i < 0:
            print("BUUUUG -----------------------------")
            sys.exit()

