
def checkl(i,q):
    global l
    l=l+1
    if isinstance(i,int)==0:
        if q==0:
            checkl(i[1],1)
        elif len(i)>2:
            checkl(i[2],1)
def checkr(i):
    global r
    r=r+1

    if isinstance(i,int)==0 and len(i)>2:
         checkr(i[2])
     
def fun(inp,n):
    
            if (len(inp)==1 or len(inp)==2 or len(inp)==0):
                inp.append(n)
            else:
                x=isinstance(inp[1],int)
                if(x==1):
                        y=inp[1]
                        inp[1]=[y,n]
                else:
                        if len(inp[1])==2:
                            inp[1].append(n)
                        
                        elif isinstance(inp[2],int)==0 and len(inp[2])==2:
                            inp[2].append(n)
                        elif isinstance(inp[2],int)==1:
                            y=inp[2]
                            inp[2]=[y,n]
                        elif isinstance(inp[2],int)==0 and len(inp[2])==3:
                            global l,r
                            l=0
                            r=0
                            checkl(inp,0)
                            checkr(inp)
                            if l>r:
                                fun(inp[2],n)
                            else:
                                fun(inp[1],n)
l=0
r=0           
inpu=[]
while 1==1:
    print "Do you want to insert more. If yes press y else n"
    per=input()
    if per==1:
        n=input()
        fun(inpu,n)
    else:
        break
print inpu

