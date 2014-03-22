from math import sqrt
prime=[]
prime.append(2)


for i in range(3,40000):
    check=1
    for j in prime:
        if i%j==0:
            check=0
            break
    if check==1:
        prime.append(i)

for i in range(20000):
    check=0
    div=[]
    back=i
    for j in range(1,i+1):
        if i%j==0:
            div.append(j)
    s=0
    for j in div:
        s+=j
    for j in prime:
        if s==j:
            print i,sqrt(i)
            break
    
