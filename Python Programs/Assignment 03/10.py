class node:
    def __init__(self,data,nod):
        self.left=None
        self.right=None
        self.parent=nod
        self.da=data
        self.id=1

def height(x,h):        #function to calculate the smallest height
    global ma
    if x==None:
        ma=h
    else:
        height(x.right,h+1)

def insert(x,val):      #function to insert the value according to the convention of full binary tree
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
        if hr<hl:                   #to decide whether to insert in left part or right part
            insert(x.right,val)
        else:
            insert(x.left,val)

def thread(x):                  #after the user has ended up inserting nodes,this function thread the whole tree
    if x.right==None:
        if x==x.parent.left:
            x.right=x.parent
        else:
            y=x.parent
            while y.parent!=None and y!=y.parent.left:
                y=y.parent
            x.right=y.parent
    else:
        thread(x.left)
        thread(x.right)
    
def inorder(x):
    global n
    while n>0:
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
inorder(root)
