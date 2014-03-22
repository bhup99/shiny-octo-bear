def search(root,t,output):
    if root is None:
        return
    a=[root.lstName,root.fstName,root.age]
    result=1
        for i in range(len(t)):
        if t[i]!=a[i]:
            result=0
    if result==1:
        output.append(root)
    index=root.height%3
    if index<len(t):
        search(root.child[a[index]<t[index]],t,output)
    else:
        search(root.child[1],t,output)
        search(root.child[0],t,output)
        
               
    
        
            
        
            
            
            
    
