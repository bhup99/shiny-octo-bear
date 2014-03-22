def check(i):
    
        x=i
        j=0
        if isinstance(x[1],int)==0:
                x=x[1]
                j=j+1      
        while len(x)>2 and isinstance(x[2],int)==0:
                if len(x)>2:
                        x=x[2]
                else:
                        x=x[1]
                j=j+1      
        y=i
        k=0
        while len(y)>2 and isinstance(y[2],int)==0:
                y=y[2]
                k=k+1
        if len(x)<3:
                j=j-1
        if j>k:
                return 2
        elif j==k:
                if len(y)<len(x):
                        return 2
                else:
                        return 1
        else:
                return 1
            
def fun(inp,n):
    
            if (len(inp)==1 or len(inp)==2 or len(inp)==0):
                inp.append(n)
                return 0
            else:
                x=isinstance(inp[1],int)
                if(x==1):
                        y=inp[1]
                        inp[1]=[y,n]
                        return 0
                else:
                        if len(inp[1])==2:
                            inp[1].append(n)
                            return 0
                        
                        elif isinstance(inp[2],int)==0 and len(inp[2])==2:
                            inp[2].append(n)
                            return 0
                        elif isinstance(inp[2],int)==1:
                            y=inp[2]
                            inp[2]=[y,n]
                            return 0
                        elif isinstance(inp[2],int)==0 and len(inp[2])==3:
                            z=check(inp)
                            if z==1 or z==2:
                                    fun(inp[z],n)
                            else:
                                    fun(inp[1],n)
                            return z    
            
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
print "Enter the value you want to find out"
find=input()

