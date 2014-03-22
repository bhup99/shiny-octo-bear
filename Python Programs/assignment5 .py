def fun(start):
    if start==len(cryp):
        return 1
    subAlpha=[]
    for i in range(0,26):
        subAlpha.append(alpha[i])
    for i in range(0,n):
        if len(dic[i])==len(cryp[start]):
            for j in range(0,len(dic[i])):
                subs=1
                if alpha[ord(cryp[start][j])-97]=='NULL':
                    alpha[ord(cryp[start][j])-97]=ord(dic[i][j])-97
                    continue
                elif alpha[ord(cryp[start][j])-97]!=ord(dic[i][j])-97:
                    subs=0
                    break
            if subs==1:
                x=fun(start+1)
                if x==1:
                    for k in range(0,26):
                        subAlpha[k]=alpha[k]
                    return 1
            else:
                for k in range(0,26):
                    alpha[k]=subAlpha[k]
                

print "Enter the number of dictionary words"
n=input()
print "Enter the dictionary words"
dic=[]
for i in range(0,n):
    dic.append(raw_input())
print "Enter the crypted line"
cryp=[]
cryp=raw_input()
cryp=cryp.split(' ')
alpha=[]
for i in range(0,26):
    alpha.append('NULL')
fun(0)
s=0
for i in range(0,len(cryp)):
    for j in range(0,len(cryp[i])):
        if alpha[ord(cryp[i][j])-97]=='NULL':
            s=1
            break
        
if s==1:
    for i in range(0,len(cryp)):
        for j in range(0,len(cryp[i])):
            print '*',
        print ' ',
else:
    for i in range(0,len(cryp)):
        for j in range(0,len(cryp[i])):
            print chr(alpha[ord(cryp[i][j])-97]+97),
        print ' ',
