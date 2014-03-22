class node:
    def __init__(self,data,nod):
        self.left=None
        self.right=None
        self.parent=nod
        self.da=data
        self.id=1
        self.Lleaf=0
        self.Rleaf=0

def height(x,h):
    global ma
    if x==None:
        ma=h
    else:
        height(x.right,h+1)

def insert(x,val):
    if x.left==None:
        x.left=node(val,x)
    elif x.right==None:
        x.right=node(val,x)
    else:
        global ma
        ma=0
        height(x.left,0)
        hl,ma=ma,0
        height(x.right,0)
        hr,ma=ma,0
        if hr<hl:
            insert(x.right,val)
        else:
            insert(x.left,val)

def thread(x):
    if x.right==None:
        if x==x.parent.left:
            x.right=x.parent
        else:
            y=x.parent
            while y.parent!=None and y!=y.parent.left:
                y=y.parent
            x.right=y.parent
    if x.left==None:
        if x==x.parent.right:
            x.left=x.parent
        else:
            y=x.parent
            while y.parent!=None and y!=y.parent.right:
                y=y.parent
            x.left=y.parent
    else:
        thread(x.left)
        thread(x.right)
    
def inorder(x):
    global n
    while n>0:
        if x.left==None:
            x.Lleaf=1
        if x.right==None:
            x.Rleaf=1
            
        if x.left!=None and x.id==1 and x.left.id==1:
            x=x.left
        elif x.id==1 and (x.left==None or x.left.id==0):
            x.id=0
            print x.da
            n=n-1
            if x.right.id==1:
                x=x.right
            else:
                x=x.parent
        elif x.id==0:
            x=x.parent
        

global n
n=1
inp=input("Enter the number to be iserted")
root=node(inp,None)
ch=input("Press 1 to insert more otherwise ")
while ch==1:
    inp=input("Enter the number to be iserted")
    n+=1
    insert(root,inp)
    ch=input("Press 1 to insert more otherwise ")
inorder(root)
thread(root)
