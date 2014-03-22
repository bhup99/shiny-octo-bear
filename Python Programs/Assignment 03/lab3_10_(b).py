global mx,hr,hl
class node:
      def __init__(self,da):
            self.right=None
            self.left=None
            self.data=da
            self.id=1
            self.parent=None
def makeoftree(bran,w):
           global mx
           if(bran.left==None):
                  bran.left= node(w)
                  bran.left.parent= bran
           elif(bran.right==None):
                  bran.right= node(w)
                  bran.right.parent= bran
           else:
                  mx=0 
                  height(bran.left,0)
                  hl= mx
                  mx=0  
                  height(bran.right,0)
                  hr= mx
                  if(hl==hr):
                         makeoftree(bran.left,w)
                  else:
                         makeoftree(bran.right,w)
def height(bran,h):                                                           #function to calculate the minimum height of a node
           global mx
           if(bran==None):
                  if(h>mx):
                        mx=h
                  return
           height(bran.right,h+1)

def inorder(bran):                                                            #iterative inorder tree-traversal function
           while(bran!=None):
                     if (bran.id==1 and bran.left!=None and bran.left.id==1):
                            bran=bran.left
                     if(bran.id==1 and bran.left==None):
                            bran.id=0
                            print bran.data 
                            if(bran.right!=None):
                                    bran= bran.right
                            else:
                                    bran= bran.parent
                     if(bran.id==1 and bran.left.id==0):
                            bran.id=0
                            print bran.data 
                            if(bran.right!=None):
                                    bran= bran.right
                            else:
                                    bran= bran.parent

                     if(bran.id==0):
                            bran= bran.parent   
  
def find_right(bran):                                 #function to find the successor of a node
      if(bran.parent.parent!=None):
           if (bran.parent==bran.parent.parent.left):
              
               return bran.parent.parent
      else:
           return
 
      x=find_right(bran.parent)
      return x  

def rLink(bran):                                      #function to link right null pointer of leaf to the successor
      
      if(bran==bran.parent.left):
                   bran.right= bran.parent
                   return 
      if(bran==bran.parent.right):
                   parent= find_right(bran)
                   bran.right=parent
                   return
      else:
                   rLink(bran.left)
                   rLink(bran.right)

def find_left(bran):                                  #function to find the predecessor of the right
      if(bran.parent.parent!=None): 
          if (bran.parent==bran.parent.parent.right):
              return bran.parent.parent
      else:
          return

      x=find_left(bran.parent)
      return x

def lLink(bran):                                      #function to link left null pointer to the predecessor
      if(bran==bran.parent.right):
                   bran.left= bran.parent
                   return 
      elif(bran==bran.parent.left):
                   parent1= find_left(bran)
                   bran.left=parent1
                   return
      else:
                   rLink(bran.left)
                   rLink(bran.right)                                

def link(bran):                                       #function to link left and right null pointers of leaves to successors and predecessor
      if(bran==None):
                return
      if(bran.right==None and bran.left==None):
                 lLink(bran)
                 rLink(bran)
      elif(bran.left==None):
                 lLink(bran)
      elif(bran.right==None):
                 rLink(bran)
      else:
                 link(bran.left)
                 link(bran.right)

num= []
ans='y'
while(ans=='y'):
      x=input('enter a number')
      num.append(x)
      ans=raw_input('\ndo u want to continue(y/n)')     
root=node(num[0])        
for element in num[1:]:
      makeoftree(root,element)
link(root)
inorder(root)

