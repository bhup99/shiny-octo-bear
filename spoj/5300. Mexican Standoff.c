#include<stdio.h>
#include<C:\Users\Bhupesh\Documents\C-Programs\5300. Mexican Standoff backup.h>

int  die[30][20],n[30],copy[30],out[30],che=0;
main()
{
    int test,i,j,k,l,re;
    printf("Enter test cases");
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n[i]);
        copy[i]=n[i];
        for(j=0;j<n[i];j++)
        {
            scanf("%s %s %s",inp[i][j][0],inp[i][j][1],inp[i][j][2]);
            die[i][j]=2;
        }
    }
    for(i=0;i<test;i++)
        merge(i,0,n[i]);
    for(i=0;i<n[0];i++)
    {
        printf("%s %s %s\n",inp[0][i][0],inp[0][i][1],inp[0][i][2]);
        out[i]=1000;
    }

    for(i=0;i<test;i++)
        for(j=0;j<n[i];)
        {
            while(!strcmp(inp[i][j][2],"Y"))
                j++;
            k=stand(i,j);
            if(k<out[i])
                out[i]=k;
        }

    for(i=0;i<copy[0];i++)
        printf("%s will %d\n",inp[0][i][0],die[0][i]);
    printf("Number of round it takes to kill all is %d ",out[0]);
}

int stand(int test,int spe)
{
    int i,j,x,y,z,l,m,hell;
    if(n[test]==2)
    {
        printf("Battleship\n");
        battle(test);
        che+=1;
    }
    else
    {
        printf("Destroyer\n");
        for(i=0;i<n[test];i++)
        {
            x=atoi(inp[test][i][1]);
            if(i!=0)
                y=atoi(inp[test][i-1][1]);
            else
                y=atoi(inp[test][n[test]-1][1]);
            if(i!=n[test]-1)
                z=atoi(inp[test][i+1][1]);
            else
                z=atoi(inp[test][0][1]);
            if(i!=spe && (x<y || x<z))
            {
                y=i;
                if(i==n[test]-1)
                {
                    x=i-1;
                    z=0;
                }
                if(i==0)
                {
                    x=n[test]-1;
                    z=1;
                    die[test][i]=check(test,x,y,y,i,n[i]);
                    if(die[test][i])
                    {
                        j=check(test,z,y,y,i,n[i]);
                        if(j<die[test][i])
                        {
                            die[test][i]=j;
                        }
                    }
                }
                else
                {
                    l=atoi(inp[test][i][1]);
                    m=atoi(inp[test][i-1][1]);
                    if(die[test][i-1])
                    {
                        if(l>m)
                            die[test][i]=0;
                        else
                            die[test][i]=check(test,i+1,i,i,i,n[i]);
                    }
                    else
                        die[test][i]=check(test,i+1,i,i,0 ,n[i]);
                }
            }
        }
        for(i=0;i<n[test];i++)
            printf("%s %s %s will %d\n",inp[0][i][0],inp[0][i][1],inp[0][i][2],die[0][i]);
        hell=collaps(test);
        printf("HELL is %d \n",hell);
        for(i=0;i<n[test];i++)
            printf("%s %s %s will %d\n",inp[0][i][0],inp[0][i][1],inp[0][i][2],die[0][i]);
        if(hell==1 || hell==0)
            return che;
        else
        {
            che+=1;
            stand(test,spe);
        }
    }
}

void battle(int test)
{
    int i,j,k,l;
    k=atoi(inp[test][0][1]);
    l=atoi(inp[test][1][1]);
    if(k>l)
        die[test][0]=0;
    else if(l>k)
        die[test][1]=0;
    else
    {
        die[test][0]=0;
        die[test][1]=0;
    }
}

int collaps(int test)
{
    int i,j,k=0;
    j=0;
    for(i=0;i<n[test];i++)
    {
        if(die[test][i])
            j++;
    }
    if(j==1 || j==0)
        return j;
    else
    {
        for(i=0;i<n[test];i++)
        {
            if(die[test][i])
            {
                strcpy(inp[test][k][0],inp[test][i][0]);
                strcpy(inp[test][k][1],inp[test][i][1]);
                strcpy(inp[test][k][2],inp[test][i][2]);
                die[test][k]=die[test][i];
                die[test][i]=0;
                k++;
            }
        }
        n[test]=n[test]-j;
        return j;
    }
}

int check(int test,int prev,int cur,int lim,int var,int z)
{
    int i,j;
    i=atoi(inp[test][cur][1]);
    j=atoi(inp[test][prev][1]);
    if(cur==lim && var)
        return 1;
    else
    {
        if(i<j)
            return 2;
        else if(i>j)
            return 0;
        else
        {
            if(prev>cur && !var)
                return check(test,prev-1,prev,lim,1,z);
            else if(prev>cur && var)
                return check(test,prev+1,prev,lim,1,z);
            else if(prev<cur && prev)
                return check(test,prev-1,prev,lim,1,z);
            else if(prev<cur && !prev)
                return check(test,z-1,prev,lim,1,z);
        }
    }
}
