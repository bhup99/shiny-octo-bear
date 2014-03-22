n=input()
inp=[]
strInp=raw_input()
strInp=strInp.split(' ')
for i in range(n):
    inp.append(int(strInp[i]))

q=input()
for i in range(q):
    query=raw_input()
    if query[0]=='Q':
        s=0
        dic={}
        for j in range((int(query[2]))-1,(int(query[4]))):
            if not dic.has_key(inp[j]):
                s+=inp[j]
                dic[inp[j]]=1
        print s
    elif query[0]=='U':
        inp[(int(query[2]))-1]=int(query[4])
