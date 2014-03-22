def nNeighbour(root,p,minPt,outPt):
    nod=root
    while nod!=None:
        if nod.axis=='y':
            if nod.keyy<minPt[1]:
                nod=nod.right
            else:
                nod=nod.left
        else:
            if nod.key<minPt[0]:
                nod=nod.right
            else:
                nod=nod.left
        nod=nod.parent
        if p>(nod.key-minPt[0])**2+(nod.key-minPt[1])**2:
            p=(nod.key)**2+(nod.key)**2
            outPt[0]=nod.key
            outPt[1]=nod.key
    if root.parent!=None:
        if root.parent.axis=='x':
            if p>minPt[0]-root.parent.key:
                if root==root.parent.left:
                    x=root.parent
                    root.parent.right.parent=None
                    start(root.parent.right,p,minPt,outPt)
                    root.parent.right.parent=x
                else:
                    x=root.parent
                    root.parent.left.parent=None
                    start(root.parent.left,p,minPt,outPt)
                    root.parent.left.parent=x
        else:
            if p>minPt[1]-root.parent.key:
                if root==root.parent.left:
                    x=root.parent
                    root.parent.right.parent=None
                    start(root.parent.right,p,minPt,outPt)
                    root.parent.right.parent=x
                else:
                    x=root.parent
                    root.parent.right.parent=None
                    start(root.parent.left,p,minPt,outPt)
                    root.parent.right.parent=x

def start(root,p,minPt,outPt):
    x=root
    while x!=None:
        if x.axis=='y':
            if x.key<minPt[1]:
                x=x.right
            else:
                x=x.left
        else:
            if x.key<minPt[0]:
                x=x.right
            else:
                x=x.left

    nNeighbour(x,p,minPt,outPt)
