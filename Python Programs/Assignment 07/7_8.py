print "Input values of m,k and maximal number of addresses to check"
m=input()
k=input()
maxNoAdd=input()
h=[0 for i in range(m*k)]
p=701
q=839
global collision
collision=0

def hashing(a):
    global collision
    x=(a%p)%m
    y=(a%q)%m
    j=0
    for i in range(0,k):
        if h[x]==0:
            h[x]=1
        else:
            j+=1
        y=(y+i)%m
        x=(x+y)%m
    if j==k:
        collision+=1

for i in range(maxNoAdd):
    ip=input("Enter the ip address")
    hashing(ip)

print "No of collision detected are",collision
