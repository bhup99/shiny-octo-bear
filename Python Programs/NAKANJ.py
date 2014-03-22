side=[[100000 for i in range(9)] for j in range(9)]
sorMoves=[None for i in range(200001)]



def cal2(k,a,b,c,d,val):
    max=1000000
    move=[0 for i in range(8)]
    dis=c-a;
    y=d-b;
    if(a+2<9 and b+1<9 and side[a+2][b+1]>val):
        side[a+2][b+1]=val;
        cal2(k,a+2,b+1,c,d,val+1);
    
    if(a-2>0 and b+1<9 and side[a-2][b+1]>val):
    
        side[a-2][b+1]=val;
        cal2(k,a-2,b+1,c,d,val+1);
    
    if(b-1>0 and a-2>0 and side[a-2][b-1]>val):
    
        side[a-2][b-1]=val;
        cal2(k,a-2,b-1,c,d,val+1);
    
    if(a+2<9 and b-1>0 and side[a+2][b-1]>val):
    
        side[a+2][b-1]=val;
        cal2(k,a+2,b-1,c,d,val+1);
    
    if(a+1<9 and b+2<9 and side[a+1][b+2]>val):
    
        side[a+1][b+2]=val;
        cal2(k,a+1,b+2,c,d,val+1);
    
    if(b-2>0 and a+1<9  and side[a+1][b-2]>val):
    
        side[a+1][b-2]=val;
        cal2(k,a+1,b-2,c,d,val+1);
    
    if(a-1>0 and b-2>0 and side[a-1][b-2]>val):
    
        side[a-1][b-2]=val;
        cal2(k,a-1,b-2,c,d,val+1);
    
    if(b+2<9 and a-1>0 and side[a-1][b+2]>val):
    
        side[a-1][b+2]=val;
        cal2(k,a-1,b+2,c,d,val+1);
    




def main():
    
    n=input()
    for i in range(n):
        s=raw_input()
        f=ord(s[0])-96;
        g=ord(s[1])-48;
        h=ord(s[3])-96;
        j=ord(s[4])-48;
        side[f][g]=0;
        if(f-h==0 and j-g==0):
            side[h][j]=0;
        else:
            cal2(i,f,g,h,j,1);
        sorMoves[i]=side[h][j];
        for j in range(9):
            for k in range(9):
                side[j][k]=10000;
    
    k=0;
    for i in range(n):
        print sorMoves[i]


main()


