from fractions import *
def main():
    n = int(input())
    alp = list(map(int, input().split()))
    ln = sum(alp)
    s = input()
    pos, cnt = 0, 0
    prb = []
    for i in range(n):
        prb.append(Fraction(alp[i], ln))
    scan = [[Fraction(0, ln), prb[0]]]
    for i in range(1, n):
        scan.append([scan[-1][1], scan[-1][1] + prb[i]])
    for i in range(n):
        if alp[i]:
            pos = i
            cnt += 1
    if not cnt:
        print("")
        return
    if not (cnt - 1):
        for i in range(alp[pos]):
            print(chr(pos + ord('a')), end="")
        return
    cur, idx = Fraction(0, 1), 0
    for i in range(len(s) - 1, -1, -1):
        idx = int(s[i])
        cur = Fraction(cur.numerator + cur.denominator * idx, cur.denominator * 2)
    ans = ""
    while len(ans) < ln:
        for i in range(n):
            if cur >= scan[i][0] and cur < scan[i][1]:
                ans += chr(i + ord('a'))
                #print(cur, scan[i][0], scan[i][1])
                cur = (cur - scan[i][0]) / (scan[i][1] - scan[i][0])
                break
    print(ans)    
main()