class node:
    def __init__(self,data):
        self.left=None
        self.right=None
        self.da=data

def insert(inp,x):                  #insert function to first make a binary tree for testing
    if inp<x.da:
        if x.left==None:
            x.left=node(inp)
        else:
            insert(inp,x.left)
    else:
        if x.right==None:
            x.right=node(inp)
        else:
            insert(inp,x.right)
def inorder(root):                  #inorder tree traversal of tree
    if root.left!=None:
        inorder(root.left)
    print root.da
    if root.right!=None:
        inorder(root.right)
def height(x,h):                    #function to calculate the height of tree with ma being the final value of maximum height
    global ma                       #h will be the height of current node x
    if x==None:
        if h>ma:
            ma=h
        
    else:
        height(x.left,h+1)
        height(x.right,h+1)

def check(x):                           
    global ma
    if x==None:
        return 0
    height(x.left,0)
    hl,ma=ma,0
    height(x.right,0)
    hr,ma=ma,0
    print hl,hr,abs(hl-hr)
    if abs(hl-hr)<2:
        check(x.left)
        check(x.right)
    else:
        print "Hello"
        global out
        out=1

    
inp=input("Enter the input value")
ch=input("Press 1 to enter more else 2")
root=node(inp)
while ch==1:
    inp=input("Enter the input value")
    insert(inp,root)
    ch=input("Press 1 to enter more else 2")

inorder(root)
out=0
ma=0
check(root)
print out
if out==1:
    print "Not an AVL tree"
else:
    print "It is an AVL tree"
