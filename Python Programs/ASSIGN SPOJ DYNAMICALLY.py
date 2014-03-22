LastHope=[[[[[[0]*32]*32]*32]*32]*20]*20


def CalAssign(InpMat, sub, row,col, BlockedCol, index):
    
    a=16*BlockedCol[4]+8*BlockedCol[3]+4*BlockedCol[2]+2*BlockedCol[1]+BlockedCol[0];
    b=16*BlockedCol[9]+8*BlockedCol[8]+4*BlockedCol[7]+2*BlockedCol[6]+BlockedCol[5];
    c=16*BlockedCol[14]+8*BlockedCol[13]+4*BlockedCol[12]+2*BlockedCol[11]+BlockedCol[10];
    d=16*BlockedCol[19]+8*BlockedCol[18]+4*BlockedCol[17]+2*BlockedCol[16]+BlockedCol[15];

    if(LastHope[row][col][a][b][c][d]>0):
        sub[row][col]=LastHope[row][col][a][b][c][d];
        return 0;
        
    sub[row][col]=0;

    if(row==index-2):
        for i in range(index):
            if(BlockedCol[i]==0):
                sub[row][col]+=InpMat[row+1][i];
        
    elif(row==index-1):
        for i in range(index):
            if(BlockedCol[i]==0):
                sub[row][col]=InpMat[row][i];
    
    else:
        for j in range(index):
            if BlockedCol[j]==0 and InpMat[row+1][j]!=0:
                BlockedCol[j]=1;
                CalAssign(InpMat,sub,row+1,j,BlockedCol,index);
                BlockedCol[j]=0;
        
        sub[row][col]=0;
        for j in range(index):
            if(BlockedCol[j]==0):
                sub[row][col]+=sub[row+1][j];

        LastHope[row][col][a][b][c][d]=sub[row][col];




def negatify(row,col,BlockedCol,index,LHCol):

    if(LHCol==index):
        a=16*BlockedCol[4]+8*BlockedCol[3]+4*BlockedCol[2]+2*BlockedCol[1]+BlockedCol[0];
        b=16*BlockedCol[9]+8*BlockedCol[8]+4*BlockedCol[7]+2*BlockedCol[6]+BlockedCol[5];
        c=16*BlockedCol[14]+8*BlockedCol[13]+4*BlockedCol[12]+2*BlockedCol[11]+BlockedCol[10];
        d=16*BlockedCol[19]+8*BlockedCol[18]+4*BlockedCol[17]+2*BlockedCol[16]+BlockedCol[15];

        LastHope[row][col][a][b][c][d]=-66;
        return 0
    
    for i in range(2):
        BlockedCol[LHCol]=i
        negatify(row,col,BlockedCol,index,LHCol+1)
    



def main():

    
    sub=[[0]*20]*20
    test=input()
    InpMat=[[0]*20]*20

    for i in range(test):
        BlockedCol=[0]*20
        index=input()
        side=[range(20)]
        
        for j in range(index):
            side=raw_input().split(' ')
            for k in range(index):    
                InpMat[j][k]=int(side[k])
                sub[j][k]=0;
                negatify(j,k,BlockedCol,index,0)
            

        for l in range(index):
            BlockedCol[l]=1
            if InpMat[0][l]!=0:
                CalAssign(InpMat,sub,0,l,BlockedCol,index)
            BlockedCol[l]=0
        
        out=0
        for j in range(index):
            for k in range(index):
                print sub[j][k],
            print 
        for k in range(index):
            out+=sub[0][k]
        
        print out
    
    return 0;

main()
    


