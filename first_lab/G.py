def to_sys(x):
    res = []
    while x > 0:
        res = [x % 2] + res
        x //= 2
    return res

n = int(input())

value = list(map(int, input().split()))

s = int(input())

if not s:
    print(("~1&1", "1")[not value[0]])
else:

    to_bin, cnt = to_sys(s), 0


    for i in range(len(to_bin)):
        to_bin[i] = int((s >> i) & 1)
        if to_bin[i] == 1:
            cnt += 1


    matr = [[0 for i in range(n)] for i in range(cnt)]
    pos = 0

    for i in range(len(to_bin)):
        if to_bin[i] == 1:
            for j in range(n):
                if ((value[j] >> i) & 1) == 1:
                    matr[pos][j] = 1
                else:
                    matr[pos][j] = 0
            pos += 1

    ans = []
    val = 0

    for i in range(cnt):
        curVal = 0
        for j in range(n):
            if matr[i][j] == 1:
                if (not j):
                    curVal = value[j]
                else:
                    curVal = curVal & value[j]
                ans += [str(j + 1)]
            else:
                if (not j):
                    curVal = ~value[j]
                else:
                    curVal = curVal & ~value[j]
                ans += ["~" + str(j + 1)]
            if j < n - 1:
                ans += ["&"]
        if i < cnt - 1:
            ans += ["|"] 
        val |= curVal

    if val == s:
        print("".join(ans))
    else:
        print("Impossible")

