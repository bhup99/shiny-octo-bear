class nod:                              
    def __init__(self,data):
        self.da=data
        self.next=None
        self.up=None
        self.down=None
        self.pre=None
        self.rank=None
        
def insert(root,inp,c):                     #function to insert the node in every level in sorted manner
    y=len(root)
    if len(root)<len(c):                    #to extend the level if code length is greater than the length of current list
        for i in range(len(root),len(c)):   #append the nod as the head of extra levels
            root.append(nod(inp))
    if y>len(c):                            #to calculate the levels in which the nod is to be inserted
        y=len(c)
    for i in range(0,y):                    # insert nod at each level
        x=root[i]
        l=0
        box=nod(inp)
        while x!=None:                      #this loop will insert nod at ith level in sorted manner
            if x.da>inp:
                box.next=x
                box.pre=x.pre
                if x.pre!=None:
                    x.pre.next=box
                else:
                    root[i]=box
                x.pre=box
                
                l=1
                break
            else:
                x=x.next
        if l==0:
            x=root[i]
            while x.next!=None:
                x=x.next
            x.next=box
            box.pre=x
            
def prnt(root):                             #print every level of the skip lists
    for i in range(0,len(root)):
        print "Level",
        print i
        x=root[i]
        while x!=None:
            print x.da
            x=x.next
        print
def search(root,val):                   #search starting from the upper level
    x=root[len(root)-1]
    while 1==1:
        if x.da<val and x.next!=None:
            x=x.next
        elif x.da<val and x.next==None and x.up!=None:
            x=x.up
        elif x.da<val and x.up==None:
            print "Not in the list"
            break
        elif x.da==val:
            print "Found"
            break
        elif x.da>val and x.pre!=None and x.pre.up!=None:
            x=x.pre.up
        elif x.da>val and x.up!=None:
            x=x.up
        elif x.da>val:
            print "Not in the list"
            break
def atRank(x,i):                        #searching rankwise from the upper level in O(lgn) time
    if x!=None:
        y=x
        while y!=None:
            y=y.next
        if x.rank<i:
            while x.rank<i and x.next!=None:
                x=x.next
            if x.rank==i:
                print x.da
            elif x.up!=None:
                atRank(x.up,i)
        elif x.rank==i:
            print x.da
        else:
            while x.rank>i and x.pre!=None:
                x=x.pre
            if x.rank==None:
                print x.da
            elif x.up!=None:
                atRank(x.up,i)
    
root=[]
dic={}
while 1==1:
    ch=input("Press 1 to insert 2 to find anything 3 to search rankwise otherwise to exit press anything ")
    if ch==1:
        inp=input("Enter the input value")
        c=raw_input("Enter the code")
        dic[inp]=len(c)
        insert(root,inp,c)
        x=root[0]
        y=1
        while x!=None:
            x.rank=y
            y=y+1
            x=x.next
        x=root[0]
        while x!=None:
            for i in range(0,(dic[x.da])-1):
                y=root[i+1]
                while y.da!=x.da:
                    y=y.next
                z=root[i]
                while z.da!=x.da:
                    z=z.next
                z.down=y
                y.up=z
                y.rank=z.rank
            x=x.next
    elif ch==2:
        se=input("Enter the value to be searched for")
        search(root,se)
    elif ch==3:
        atRank(root[len(root)-1],input("Enter the rank to be searched"))
    else:
        break
prnt(root)
            
    
    
