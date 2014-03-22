test=input()
dic={}
posDic={}
for i in range(test):
    n=input()
    posDic[n+1]=10000000
    inp=[]
    strInp=raw_input()
    strInp=strInp.split(' ')
    for j in range(n):
        inp.append(int(strInp[j]))
        posDic[inp[j]]=j+1
    finOut=10000000000
    for j in range(n):
        outSum=j+1
        dic={}
        left,right=inp[j]-1 ,inp[j]+1
        l=2
        dic[j]=1
        for k in range(n-1):
            eme=0
            if (right>n or left>0) and posDic[left]<posDic[right]:
                for k in dic:
                    if k<posDic[left]:
                        eme+=1
                outSum+=(posDic[left]-eme)*(l)
                l+=1
                dic[posDic[left]]=1
                left-=1
            else:
                for key in sorted(dic):
                    if key<posDic[right]:
                        eme+=1
                    else:
                        break
                outSum+=(posDic[right]-eme)*l
                l+=1
                dic[posDic[right]]=1
                right+=1
        if outSum<finOut:
            finOut=outSum
    print finOut

    
        
