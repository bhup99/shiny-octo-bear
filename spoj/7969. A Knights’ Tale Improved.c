#include<stdio.h>
long long src[16][2],tar[16][2];
long long a,b,c,d,dis,y,move=0;
long long minMoves,sorMoves[16][16],x[320000]={0},target[16]={0};
int main()
{
    int n,i,k,l,m;
    int j=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        x[j]=2000000000;
        for(i=0;i<n;i++)
        {
            scanf("%lld %lld",&src[i][0],&src[i][1]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%lld %lld",&tar[i][0],&tar[i][1]);
        }
        for(k=0;k<n;k++)
        {
            for(l=0;l<n;l++)
            {
                a=src[k][0];     b=src[k][1];
                c=tar[l][0];     d=tar[l][1];
                cal(k,l);
                move=0;
            }
        }
        final(j,n);
        j++;
    }
    for(i=0;i<j;i++)
    {
        printf("%d. %lld\n",i+1,x[i]);
    }
    return 0;
}

void final(int test,int n)
{
    int i=0;
    x[test]=0;
    int k,l,min,side[15]={0};
    k=max(n);
    min=sorMoves[0][k];
    while(i<n)
    {
        for(l=0;l<n;l++)
        {
            if(min>sorMoves[l][k])
            {
                min=sorMoves[l][k];
                side[k]=l;
            }
        }
        x[test]+=sorMoves[k][side[k]];
        for(l=0;l<n;l++)
            sorMoves[l][k]=0;
        k=max(n);
        i++;
    }

    for(k=0;k<n;k++)
    {
        x[test]+=sorMoves[k][side[k]];
    }
}

int max(int n)
{
    int k,l,max=0,out;
    out=n;
    for(k=0;k<n;k++)
    {
        for(l=0;l<n;l++)
        {
            if(max<sorMoves[k][l])
            {
                max=sorMoves[k][l];
                out=l;
            }
        }
    }
    return out;
}

int cal(int k,int l)
{
    int nee;
    dis=c-a;
    y=d-b;
    if((dis<=4&&dis>=-4)&&(y>=-1&&y<=1))
    {
        move=move+locDec();
        sorMoves[k][l]=move;
    }
    else if((dis<=1&&dis>=-1)&&(y>=-4&&y<=4))
    {
        move=move+locDec();
        sorMoves[k][l]=move;
    }

    else if(a<=c && b<=d)
    {
        if(dis>y)
        {
            if(dis/4)
                nee=(dis/4);
            else
                nee=dis/2;
            if(nee-1)
                nee--;
            a=a+2*nee;  b=b+nee;
        }
        else
        {
            if(y/4)
                nee=(y/4);
            else
                nee=y/2;
            if(nee-1)
                nee--;
            a=a+nee;  b=b+2*nee;
        }

        move+=nee;
        cal(k,l);
    }
    else if(a<=c && b>=d)
    {
        y=y*(-1);
        if(dis>y)
        {
            if(dis/4)
                nee=(dis/4);
            else
                nee=dis/2;
            if(nee-1)
                nee--;
            a=a+2*nee;  b=b-nee;
        }

        else
        {
            if(y/4)
                nee=(y/4);
            else
                nee=y/2;
            if(nee-1)
                nee--;
            a=a+nee;  b=b-2*nee;
        }

        move+=nee;
        cal(k,l);
    }
    else if(a>=c && b<=d)
    {
        dis=dis*(-1);
        if(dis>y)
        {
            if(dis/4)
                nee=(dis/4);
            else
                nee=dis/2;
            if(nee-1)
                nee--;
            a=a-2*nee;  b=b+nee;
        }
        else
        {
            if(y/4)
                nee=(y/4);
            else
                nee=y/2;
            if(nee-1)
                nee--;
            a=a-nee;  b=b+2*nee;
        }

        move+=nee;
        cal(k,l);
    }
    else if(a>=c && b>=d)
    {
        y=y*(-1);
        dis=dis*(-1);
        if(dis>y)
        {
            if(dis/4)
                nee=(dis/4);
            else
                nee=dis/2;
            if(nee-1)
                nee--;
            a=a-nee*2;  b=b-nee;
        }
        else
        {
            if(y/4)
                nee=(y/4);
            else
                nee=y/2;
            if(nee-1)
                nee--;
            a=a-nee;  b=b-2*nee;
        }

        move+=nee;
        cal(k,l);
    }
}

int locDec()
{
    if(a-c==0 &&(b-d==1 || b-d==-1) || ((a-c==1||a-c==-1) &&b-d==0))
        return 3;
    else if((a-c==-1||a-c==1)&&(b-d==-1||b-d==1))
        return 2;
    else if((a-c==-2||a-c==2)&&(b-d==0))
        return 2;
    else if((a-c==0)&&(b-d==-2||b-d==2))
        return 2;
    else if((a-c==-3||a-c==3)&&b-d==0)
        return 3;
    else if(a-c==0&&(b-d==-3||b-d==3))
        return 3;
    else if((a-c==-2||a-c==2)&&(b-d==-1||b-d==1))
        return 1;
    else if((a-c==-1||a-c==1)&&(b-d==-2||b-d==2))
        return 1;
    else if((a-c==-4||a-c==4)&&(b-d==0))
        return 2;
    else if((a-c==0)&&(b-d==-4||b-d==4))
        return 2;
    else if((a-c==-2||a-c==2)&&(b-d==-2||b-d==2))
        return 4;
     else if((a-c==-1||a-c==1)&&(b-d==-3||b-d==3))
        return 2;
    else if((a-c==-3||a-c==3)&&(b-d==-1||b-d==1))
        return 2;
    else if((a-c==-5||a-c==5)&&(b-d==0))
        return 3;
    else if(a-c==0&&(b-d==-5||b-d==5))
        return 3;
    else if((a-c==-1||a-c==1)&&(b-d==-4||b-d==4))
        return 3;
    else if((a-c==-4||a-c==4)&&(b-d==-1||b-d==1))
        return 3;
    else if((a-c==-2||a-c==2)&&(b-d==-3||b-d==3))
        return 3;
    else if((a-c==-3||a-c==3)&&(b-d==-2||b-d==2))
        return 3;

}


