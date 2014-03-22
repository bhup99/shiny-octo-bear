def atRank(x,i):                       
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
