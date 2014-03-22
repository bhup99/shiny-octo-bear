class node:
    def __init__(self,x,y,de):
        self.left=None
        self.right=None
        self.xCor=x
        self.yCor=y
        self.depth=de
        self.parent=None

def find_par_xCor(nod,x,dep):
    if nod!=None:
        if dep%2==0:
            if nod.xCor==x:
                print "Found With depth %d and coordinates %d %d" % (dep,nod.xCor,nod.yCor)
            elif nod.xCor>x:
                find_par_xCor(nod.left,x,dep+1)
            else:
                find_par_xCor(nod.right,x,dep+1)
        else:
            if nod.xCor==x:
                print "Found With depth %d and coordinates %d %d" % (dep,nod.xCor,nod.yCor)
            find_par_xCor(nod.left,x,dep+1)
            find_par_xCor(nod.right,x,dep+1)


def find_par_yCor(nod,y,dep):
    if nod!=None:
        if dep%2==0:
            if nod.yCor==y:
                print "Found With depth %d and coordinates %d %d" % (dep,nod.xCor,nod.yCor)
            elif nod.yCor>y:
                find_par_yCor(nod.left,y,dep+1)
            else:
                find_par_yCor(nod.right,y,dep+1)
        else:
            if nod.yCor==y:
                print "Found With depth %d and coordinates %d %d" % (dep,nod.xCor,nod.yCor)
            find_par_yCor(nod.left,y,dep+1)
            find_par_yCor(nod.right,y,dep+1)


def find(nod,x,y):
    if nod.xCor==x and nod.yCor==y:
        print "Key Found with depth",
        print nod.depth
    elif nod.depth%2==0:
        if nod.xCor<x:
            find(nod.right,x,y)
        else:
            find(nod.left,x,y)
    else:
        if nod.yCor<y:
            find(nod.right,x,y)
        else:
            find(nod.left,x,y)

            


def insert(nod,dep,x,y):
    if dep%2==0:
        if nod.xCor>x and nod.left!=None:
            insert(nod.left,dep+1,x,y)
        elif nod.xCor>x:
            nod.left=node(x,y,nod.depth+1)
            nod.left.parent=nod
        elif nod.xCor<x and nod.right!=None:
            insert(nod.right,dep+1,x,y)
        elif nod.xCor<x:
            nod.right=node(x,y,nod.depth+1)
            nod.right.parent=nod
    else:
        if nod.yCor>y and nod.left!=None:
            insert(nod.left,dep+1,x,y)
        elif nod.yCor>y:
            nod.left=node(x,y,nod.depth+1)
            nod.left.parent=nod
        elif nod.yCor<y and nod.right!=None:
            insert(nod.right,dep+1,x,y)
        elif nod.yCor<y:
            nod.right=node(x,y,nod.depth+1)
            nod.right.parent=nod

def inorder(root):
    if root.left!=None:
        inorder(root.left)
    print root.xCor,root.yCor,root.depth
    if root.right!=None:
        inorder(root.right)
    
x=input("Input x coordinate something to make the root")
y=input("Input y coordinate something to make the root")
root=node(x,y,0)
choice=input("Press\n\t1 to insert\n\t2 to find_exact\n\t3 to find_partial")
while 1==1:
    
    if choice==1:
        x=input("Enter the x coordinate to insert")
        y=input("Enter the y coordinate to insert")
        insert(root,0,x,y)
        inorder(root)
    elif choice==2:
        x=input("Enter the x coordinate value to find")
        y=input("Enter the y coordinate value to find")
        find(root,x,y)
    elif choice==3:
        ch=input("To enter x coordi,press 1\no enter y coordi, press 2")
        if ch==1:
            x=input("Enter x coordi")
            find_par_xCor(root,x,0)
        else:
            y=input("Enter y coordi")
            find_par_yCor(root,y,0)
        
    else:
        break
    choice=input("Press\n\t1 to insert\n\t2 to find_exact\n\t3 to find_partial")
    

