from fractions import *
from copy import *
 
def add(a, b):
    zn = (a[1] * b[1]) // gcd(a[1], b[1])
    res = [a[0] * (zn // a[1]) + b[0] * (zn // b[1]), zn]
    return res
def minus(a, b):
    zn = (a[1] * b[1]) // gcd(a[1], b[1])
    res = [a[0] * (zn // a[1]) - b[0] * (zn // b[1]), zn]
    return res
def mul(a, b):
    ch = a[0] * b[0]
    zn = a[1] * b[1]
    return [ch // gcd(ch, zn), zn // gcd(ch, zn)]
def dev(a, b):
    ch = a[0] * b[1]
    zn = a[1] * b[0]
    return [ch // gcd(ch, zn), zn // gcd(ch, zn)]
 
def to_bin(x):
    res = ""
    while x > 0:
        res = str(x % 2) + res
        x //= 2
    return res
 
def main():
    n = int(input())
    s = input()
    alp = [0]*n
    ln = len(s)
    for i in range(ln):
        alp[ord(s[i]) - ord('a')] += 1
    prb = []
    for i in range(n):
        prb.append([alp[i], ln])
    scan = [[0, 0] for i in range(n)]
    l, r = [0, ln], [ln, ln]
    for i in range(ln):
        num = ord(s[i]) - ord('a')
        x = [0, 0]
        scan[0][0] = l
        cur = minus(r, l)
        cur = mul(cur, prb[0])
        scan[0][1] = add(cur, scan[0][0])
        for j in range(1, n, 1):
            #print(scan[j], scan[j - 1], j, j - 1, '!')
            scan[j][0] = copy(scan[j - 1][1])
            #print(scan[j], scan[j - 1], j, j - 1, '!!')
            cur = minus(r, l)
            cur = mul(cur, prb[j])
            scan[j][1] = add(cur, scan[j][0])
            #print(scan[j][0], scan[j][1], "!!", j, num)
            #print(scan[j], scan[j - 1], j)
        #print(scan[num][0], scan[num][1], num)
        #print(scan[0][0], scan[0][1])
        l = scan[num][0]
        r = scan[num][1]
        #print(num, l, r)
    zn = 1
    ch = 0
    #print(l, r)
    lcm = (l[1] * r[1]) // gcd(l[1], r[1])
    #print(lcm)
    l = [l[0] * (lcm // l[1]), lcm]
    r = [r[0] * (lcm // r[1]), lcm]
    #print(l, r)
     
    cnt = 0
    while 1 == 1:
        cnt += 1
        ll, rr, ans = 0, zn, None
        lr = l[1] * zn // gcd(l[1], zn)
        cur = lr // l[1]
        cl, cr = l[0] * cur, r[0] * cur
        #print(zn)
        while rr - ll > 1:
            m = (ll + rr) // 2
            #print(m)
            tmp = m * (lr // zn)
            #print(tmp, cl, cr)
            if tmp >= cl and tmp < cr:
                ans = m
                break
            if tmp >= cl:
                rr = m
            else:
                ll = m
         
        if ans != None:
            ch = ans
            break
        zn *= 2
    print(n)
    print(*alp)
    if (r[1] == r[0] and l[0] == 0):
        print(0)
    else:
        print(("0" * (cnt - 1 - len(to_bin(ch)))) + to_bin(ch))
     
main()