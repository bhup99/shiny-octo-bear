test=input()
for i in range(test):
    strInp=raw_input()
    strInp=strInp.split(' ')
    n=int(strInp[0])
    m=int(strInp[1])
    f=[]
    f.append(0)
    f.append(1)
    out=0
    for j in range(2,n):
        f.append(f[j-1]+f[j-2])
    for k in range(n,m):
        f.append((f[k-1]+f[k-2])%1000000007)
        out+=f[k]
        out=out%1000000007
    print out
        
