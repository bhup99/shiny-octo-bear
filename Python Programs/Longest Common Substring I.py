p=raw_input()
q=raw_input()
m=0
mat=[[0]*(len(p)+1)]*(len(q)+1)
for i in range(len(p)):
    for j in range(len(q)):
        if i!=0 and j!=0 and p[i]==q[j]:
            mat[i][j]=mat[i-1][j-1]+1;
        elif((i==0 or j==0) and p[i]==q[j]):
            mat[i][j]=1
        if mat[i][j]>m:
            m=mat[i][j]
print m
        
