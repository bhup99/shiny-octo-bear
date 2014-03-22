test=input()
for i in range(test):
    f={}
    f[1]=0
    a=input()
    b=input()
    n=input()
    m=input()
    back=j
    for j in range(1,n+1):
        x=(a*f[j-1]+b)%m
        if f.has_key(x):
            back=j
            break
    
        
