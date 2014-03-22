




import sys
n=input("Enter the number of input values")     #To know number of input values
print "Enter the input values"                  #to let user input values
inp=[]                                          
for i in range(0,n):
    inp.append(input())
ma,x=-sys.maxint,0                      #ma will get the lowest integer value
                                        # x will be assigned the first day market value    
for i in range(1,n):                
    if inp[i]-inp[x]>ma:
        ma=inp[i]-inp[x]
    if inp[i]<inp[x]:
        x=i
print ma
