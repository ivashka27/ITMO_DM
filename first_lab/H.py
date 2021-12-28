n = int(input())
 
s = "(A0|B0)|(A0|B0)"
 
for i in range(1, n):
    c = str(i)
    s = "(" + s + ")"
    s = "(" + s + "|((A" + c + "|" + "A" + c + ")"
    s += "|(B" + c + "|" + "B" + c + "))"
    s += ")|(A" + c + "|B" + c + ")"
 
print("(" + s + ")")