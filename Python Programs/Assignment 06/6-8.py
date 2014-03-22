class node:
    def __init__(self,lastName,firstName,age,h):
        self.laNa=lastName
        self.fiNa=firstName
        self.age=age
        self.parent=None
        self.height=h
        self.left=None
        self.right=None
        

def insert(x,np,h):
    if h%3==0:
        if x.laNa<np.laNa:
            if x.right==None:
                x.right=np
                np.parent=x
                np.height=h
            else:
                insert(x.right,np,h+1)
        else:
            if x.left==None:
                x.left=np
                np.parent=x
                np.height=h
            else:
                insert(x.left,np,h+1)
        
    elif h%3==1:
        if x.fiNa<np.fiNa:
            if x.right==None:
                x.right=np
                np.parent=x
                np.height=h
            else:
                insert(x.right,np,h+1)
        else:
            if x.left==None:
                x.left=np
                np.parent=x
                np.height=h
            else:
                insert(x.left,np,h+1)

    elif h%3==2:
        if x.age<np.age:
            if x.right==None:
                x.right=np
                np.parent=x
                np.height=h
            else:
                insert(x.right,np,h+1)
        else:
            if x.left==None:
                x.left=np
                np.parent=x
                np.height=h
            else:
                insert(x.left,np,h+1)
        
def inorder(x):
    if x.left!=None:
        inorder(x.left)
    print x.laNa,x.fiNa,x.age
    if x.right!=None:
        inorder(x.right)


last=raw_input("Enter the last name")
first=raw_input("Enter the first name")
age=input("Enter the age")
root=node(last,first,age,0)
while 1:
    ch=input("Press 1 to continue and anything else to break")
    if ch!=1:
        break
    last=raw_input("Enter the last name")
    first=raw_input("Enter the first name")
    age=input("Enter the age")
    np=node(last,first,age,0)
    insert(root,np,0)

inorder(root)
