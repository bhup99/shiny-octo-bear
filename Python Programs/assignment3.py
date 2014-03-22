print "Enter the value of n"
n=input()
sub=[]
for i in range(0,n):
    sub.append(0)
print "Enter the input values"
inp=[]
for i in range(0,n):
    inp.append(input())
for i in range(1,n):
    sub[abs(inp[i]-inp[i-1])]=1
for i in range(1,n):
    if sub[i]==0:
        break
if i==n+1:
    print "Not a Jolly Sequence"
else:
    print "A Jolly Sequence ;)"
