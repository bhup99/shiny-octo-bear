def fun(a,b):
    x=a
    y=a
    for i in range(a,b):
        if line[0][i]==' ' or i==len(line[0])-1:
            if i==len(line[0])-1:
                y=y+1
            if sub[y-x]==1:
                for k in range(0,n):
                    if len(inp[k])==y-x:
                        break
                print k,y,x,i
                for j in range(x,y):
                    dic[line[0][j]]=inp[k][j-x]
            x=y+1
            y=y+1
        else:
            y=y+1
print "Enter the value of n"
n=input()
inp=[]
print "Enter the dictionary words"
ma=0
for i in range(0,n):
    inp.append(raw_input())
    if ma<len(inp[i]):
        ma=len(inp[i])
line=[]
line.append(raw_input())
dic={}
sub=[]
ma=ma+1
for i in range(0,ma):
    sub.append(0)
for i in range(0,n):
    sub[len(inp[i])]=sub[len(inp[i])]+1
x=0
y=0
print sub

fun(0,len(line[0]))
print dic
fin=[]
for i in dic.keys():
    fin.append(i)
print fin
space=0
out={}
for i in range(0,len(fin)):
    x=0
    y=0
    space=0
    print out
    print "Smart"
    print fin
    print y
    for j in range(0,len(line[0])):
        star=[]
        if line[0][j]==' ' or j==len(line[0])-1:
            if j==len(line[0])-1:
                y+=1
            sco=0
            for k in range(x,y):
                if line[0][k]==fin[i]:
                    sco=1
                    break
            print x,y,fin[i]
            print k
            if sco==1:
                for l in range(0,n):
                    if len(inp[l])>k-x:
                        if inp[l][k-x]==dic[fin[i]]:
                            star.append(l)
                if len(star)==1:
                    out[space]=inp[star[0]]
                else:
                    for l in range(x,y):
                        for m in range(0,len(fin)):
                            if fin[m]==line[0][l]:
                                break
                        if m!=len(fin):
                            for m in range(0,len(star)):
                                if dic[line[0][l]]!=inp[m][l-x]:
                                    star.remove(star[m])
                        if len(star)==1:
                            out[space]=star[0]
                            break
            space+=1
                
            y+=1
            x=y
            
        else:
            y+=1
print out
            
                                
                



