n = int(input())

value, arg = [], []

for i in range(2 ** n):
    a, b = input().split()
    value += [int(b)]
    arg += [a]

ans = [value[0]]

while len(value) > 0:
    for i in range(len(value) - 1):
        value[i] += value[i + 1]
        value[i] %= 2;
        
    ans.append(value[0])
    value.pop()

for i in range(2 ** n):
    print(arg[i], ans[i])