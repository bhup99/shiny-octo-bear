#include<stdio.h>
int chocSub,chocBak,style;
int sub[100][100],m,n,test,out[30],choc=0,sor[2],tar[2],h,j,s[100][100];
char inp[100][100];
int main()
{
    int i,k,f,g,l;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        style=i;    out[i]=10000;
        scanf("%d %d",&m,&n);
        for(j=0;j<m;j++)
            scanf("%s",inp[j]);
        for(j=0;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                sub[j][k]=10000;
                if(inp[j][k]=='C')
                    choc++;
                else if(inp[j][k]=='T')
                {
                    sor[0]=j;   sor[1]=k;
                }
                else if(inp[j][k]=='W')
                {
                    tar[0]=j;   tar[1]=k;
                }
            }
        }
        f=sor[0];   g=sor[1];   h=tar[0];   j=tar[1];
        printf("%d\n",choc);
        chocSub=choc;
        chocBak=choc;
        sub[f][g]=0;
        cal2(f,g,0);
        choc=chocBak;   sub[f][g]=0;    cal1(f,g,0);
        choc=chocBak;   sub[f][g]=0;    cal3(f,g,0);
        choc=chocBak;   sub[f][g]=0;    cal4(f,g,0);
        printf("%d %d\n",sub[h][j],out[i]);
        for(j=0;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                printf("%d\t",sub[j][k]);
                sub[j][k]=10000;
            }
            printf("\n");
        }
        choc=0;
    }
    return 0;
}

void cal1(int f,int g,int side)
{
    int i,k;
    if(chocSub!=choc)
    {
        chocSub=choc;
        for(i=0;i<m;i++)
            for(k=0;k<n;k++)
                if(i!=f || k!=g)
                    sub[i][k]=10000;
    }
    printf("One %d %d\n",f,g );
    if(inp[f+1][g]!='#' && f+1<m)
    {
        if(inp[f+1][g]=='C')
        {
            if(sub[f+1][g]==10000 && choc>0)
                choc--;
            sub[f+1][g]=sub[f][g]+1;
            if(chocSub!=choc)
            {
                cal1(f+1,g,1);
                cal2(f+1,g,1);
                cal3(f+1,g,1);
                cal4(f+1,g,1);
            }
            else
            {
                if(side==0)
                {
                cal1(f+1,g,1);
                cal2(f+1,g,1);
                cal3(f+1,g,1);
                cal4(f+1,g,1);}
                else if(side==1)
                {
                    cal2(f+1,g,1);
                    cal3(f+1,g,1);
                    cal1(f+1,g,1);
                }
                else if(side==4)
                {
                    cal2(f+1,g,1);
                    cal3(f+1,g,1);
                    cal4(f+1,g,1);
                }
            }
        }
        else if(inp[f+1][g]=='W')
        {
            if(choc==0 && sub[f+1][g]>sub[f][g]+1)
            {
                sub[f+1][g]=sub[f][g]+1;
            }
            else if(choc!=0)
            {
                sub[f+1][g]=sub[f][g]+1;
                cal1(f+1,g,1);
                cal2(f+1,g,1);
                cal3(f+1,g,1);
                cal4(f+1,g,1);
            }
        }
        else if(inp[f+1][g]=='.' && (sub[h][j]==10000 || choc!=0))
        {
            sub[f+1][g]=sub[f][g]+1;
            cal1(f+1,g,1);
            cal2(f+1,g,1);
            cal3(f+1,g,1);
            cal4(f+1,g,1);
        }
        else if(inp[f+1][g]=='T')
        {
            sub[f+1][g]=sub[f][g]+1;
            cal1(f+1,g,1);
            cal2(f+1,g,1);
            cal3(f+1,g,1);
            cal4(f+1,g,1);
        }
    }
    if(out[style]>sub[h][j] && choc==0)
        out[style]=sub[h][j];
}
void cal2(int f,int g,int side)
{
    int i,k;
    if(chocSub!=choc)
    {
        chocSub=choc;
        for(i=0;i<m;i++)
            for(k=0;k<n;k++)
                if(i!=f || k!=g)
                    sub[i][k]=10000;
    }
    printf("Two %d %d\t",f,g);
    if(inp[f][g+1]!='#' && g+1<n)
    {
        printf("Hi\n");
        if(inp[f][g+1]=='C')
        {
            if(sub[f][g+1]==10000 && choc>0)
                choc--;
            sub[f][g+1]=sub[f][g]+1;
            if(chocSub!=choc)
            {
                cal4(f,g+1,2);
                cal1(f,g+1,2);
                cal2(f,g+1,2);
                cal3(f,g+1,2);
            }
            else
            {
                if(side==0)
                {
                cal4(f,g+1,2);
                cal1(f,g+1,2);
                cal2(f,g+1,2);
                cal3(f,g+1,2);
                }
                else if(side==2)
                {
                    cal4(f,g+1,2);
                cal1(f,g+1,2);
                cal2(f,g+1,2);
                }
                else if(side==4)
                {
                    cal4(f,g+1,2);
                    cal1(f,g+1,2);
                    cal3(f,g+1,2);
                }
            }
        }
        else if(inp[f][g+1]=='W')
        {
            if(choc==0 && sub[f][g+1]>sub[f][g]+1)
            {
                sub[f][g+1]=sub[f][g]+1;
            }
            else if(choc!=0)
            {
                sub[f][g+1]=sub[f][g]+1;
                cal4(f,g+1,2);
                cal1(f,g+1,2);
                cal2(f,g+1,2);
                cal3(f,g+1,2);
            }
        }
        else if(inp[f][g+1]=='.' && (sub[h][j]==10000 || choc!=0))
        {
            sub[f][g+1]=sub[f][g]+1;
            cal4(f,g+1,2);
                cal1(f,g+1,2);
                cal2(f,g+1,2);
                cal3(f,g+1,2);
        }
        else if(inp[f][g+1]=='T')
        {
            sub[f][g+1]=sub[f][g]+1;
            cal4(f,g+1,2);
                cal1(f,g+1,2);
                cal2(f,g+1,2);
                cal3(f,g+1,2);
        }
    }
    if(out[style]>sub[h][j] && choc==0)
        out[style]=sub[h][j];
}

void cal3(int f,int g,int side)
{
    int i,k;
    if(chocSub!=choc)
    {
        chocSub=choc;
        for(i=0;i<m;i++)
            for(k=0;k<n;k++)
                if(i!=f || k!=g)
                    sub[i][k]=10000;
    }
    printf("Three %d %d\n",f,g);
    if(inp[f][g-1]!='#' && g-1>=0)
    {
        if(inp[f][g-1]=='C')
        {
            if(sub[f][g-1]==10000 && choc>0)
                choc--;
            sub[f][g-1]=sub[f][g]+1;
            if(chocSub!=choc)
            {
                cal3(f,g-1,3);
                cal4(f,g-1,3);
                cal1(f,g-1,3);
                cal2(f,g-1,3);
            }
            else
            {
                if(side==0)
                {
                    cal3(f,g-1,3);
                cal4(f,g-1,3);
                cal1(f,g-1,3);
                cal2(f,g-1,3);
                }
                else if(side==2)
                {
                    cal4(f,g-1,3);
                    cal1(f,g-1,3);
                    cal2(f,g-1,3);
                 }
                else if(side==4)
                {
                    cal4(f,g-1,3);
                    cal1(f,g-1,3);
                    cal3(f,g-1,3);
                }
            }
        }
        else if(inp[f][g-1]=='W')
        {
            if(choc==0 && sub[f][g-1]>sub[f][g]+1)
            {
                sub[f][g-1]=sub[f][g]+1;
            }
            else if(choc!=0)
            {
                sub[f][g-1]=sub[f][g]+1;
                cal3(f,g-1,3);
                cal4(f,g-1,3);
                cal1(f,g-1,3);
                cal2(f,g-1,3);
            }
        }
        else if(inp[f][g-1]=='.' && (sub[h][j]==10000 || choc!=0))
        {
            sub[f][g-1]=sub[f][g]+1;
            cal3(f,g-1,3);
                cal4(f,g-1,3);
                cal1(f,g-1,3);
                cal2(f,g-1,3);
        }
        else if(inp[f][g-1]=='T')
        {
            sub[f][g-1]=sub[f][g]+1;
            cal3(f,g-1,3);
                cal4(f,g-1,3);
                cal1(f,g-1,3);
                cal2(f,g-1,3);
        }
    }
    if(out[style]>sub[h][j] && choc==0)
        out[style]=sub[h][j];
}

void cal4(int f,int g,int side )
{
    int i,k;
    for(i=0;i<m;i++)
    {
        for(k=0;k<n;k++)
            printf("%d\t",sub[i][k]);
        printf("\n");
    }
    if(chocSub!=choc)
    {
        chocSub=choc;
        for(i=0;i<m;i++)
            for(k=0;k<n;k++)
                if(i!=f || k!=g)
                    sub[i][k]=10000;
    }
    printf("Four %d %d\n",f,g);
    if(inp[f-1][g]!='#' && f-1>=0)
    {
        if(inp[f-1][g]=='C')
        {
            if(sub[f-1][g]==10000 && choc>0)
                choc--;
            sub[f-1][g]=sub[f][g]+1;
            if(chocSub!=choc)
            {
                cal4(f-1,g,4);
                cal1(f-1,g,4);
                cal2(f-1,g,4);
                cal3(f-1,g,4);
            }
            else
            {
                if(side==0)
                {
                    cal4(f-1,g,4);
                    cal1(f-1,g,4);
                    cal2(f-1,g,4);
                    cal3(f-1,g,4);
                }
                else if(side==1)
                {
                    cal2(f-1,g,4);
                    cal3(f-1,g,4);
                    cal1(f-1,g,4);
                }
                else if(side==4)
                {
                    cal2(f-1,g,4);
                    cal3(f-1,g,4);
                    cal4(f-1,g,4);
                }
            }
        }
        else if(inp[f-1][g]=='W')
        {
            if(choc==0 && sub[f-1][g]>sub[f][g]+1)
            {
                sub[f-1][g]=sub[f][g]+1;
            }
            else if(choc!=0)
            {
                sub[f-1][g]=sub[f][g]+1;
                cal4(f-1,g,4);
                    cal1(f-1,g,4);
                    cal2(f-1,g,4);
                    cal3(f-1,g,4);
            }
        }
        else if(inp[f-1][g]=='.' && (sub[h][j]==10000 || choc!=0))
        {
            sub[f-1][g]=sub[f][g]+1;
            cal4(f-1,g,4);
                    cal1(f-1,g,4);
                    cal2(f-1,g,4);
                    cal3(f-1,g,4);
        }
        else if(inp[f-1][g]=='T')
        {
            sub[f-1][g]=sub[f][g]+1;
            cal4(f-1,g,4);
                    cal1(f-1,g,4);
                    cal2(f-1,g,4);
                    cal3(f-1,g,4);
        }
    }
    if(out[style]>sub[h][j] && choc==0)
        out[style]=sub[h][j];
}

