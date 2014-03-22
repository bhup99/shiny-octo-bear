#include<stdio.h>
char a[30][6],b[30][6],sub;
int main()
{
    int i=0,j,k,n=0;
    while(1)
    {
        scanf("%c",&sub);
        if(sub==10)
            break;
        else
        {
            j=0;    k=0;
            while(sub!=32)
            {
                a[n][j]=sub;
                scanf("%c",&sub);
                j++;
            }
            a[n][j]='\0';
            while(1)
            {
                scanf("%c",&sub);
                if(sub==10)
                    break;
                b[n][k]=sub;
                k++;
            }
            b[n][k]='\0';
            n++;
            fflush(stdin);
        }
    }
    for(j=0;j<n;j++)
        printf("%s %s\n",a[j],b[j]);

    printf("N is %d",n);

    for(i=0;i<n;i++)
        calc(i);
}

int calc(int test)
{
    int i,j,k=0,q=0,c=0,d=0;
    for(i=strlen(a[test]);i<=strlen(b[test]);i++)
    {
        if(i==strlen(a[test]) && i!=strlen(b[test]))
        {
            k=one(test);
            printf("K is %d ",k);
        }
        else if(i!=strlen(a[test]) && i==strlen(b[test]))
        {
            q=two(test);
            printf("Q is %d ",q);
        }
        else if(i==strlen(a[test]) && i==strlen(b[test]))
        {
            c=three(test);
            printf("C is %d ",c);
        }
        else if(i!=strlen(a[test]) && i!=strlen(b[test]))
        {
            d=four(test,i);
            printf("D is %d ",d);
        }
    }
    printf("\nOutput is %d",k+q+c+d);
}

int one(int test)
{
    int n=0,i,j,len,sub[7],out=0,x;
    for(i=0;i<7;i++)
        sub[i]=0;
    len=strlen(a[test]);
    i=len-1;
    while(i>=0)
    {
        x='J'-a[test][i];
        if(check(1,i,test))
        {
            if(i==len-1 && x>0)
            {
                if(len>1 && a[test][i]==a[test][i-1] && x>1)
                    sub[n]=x-1;
                else if(len>1 && a[test][i]+1==a[test][i-1] && x>2)
                    sub[n]=x-2;
                else if(len>1 && a[test][i]<a[test][i-1] && x>2)
                    sub[n]=x-3;
                else
                    sub[n]=x;
            }
            else if(i==len-2 && x>0)
            {
                if(i>0 && a[test][i]==a[test][i-1])
                    sub[n]=x-1;
                else if(i>0 && a[test][i]<a[test][i-1])
                    sub[n]=x-3;
                else if(i>0 && a[test][i]+1==a[test][i-1])
                    sub[n]=x-2;
                else
                    sub[n]=x;
                if(sub[n])
                sub[n]=sub[n]*7+1;
            }
            else if(x>0)
            {
                for(j=i;j<len;j++)
                {
                    x=b[test][j]-'A';
                    printf("qwerty is %d",x);
                    if(j==i)
                        sub[n]=x;
                    else if(j==i+1)
                        sub[n]=sub[n]*7+1;
                    else if(b[test][j-2]=='A' || b[test][j-2]=='B')
                        sub[n]=sub[n]*7+1;
                    else
                        sub[n]=sub[n]*7+2;
                }
            }
        }
        n++;
        i--;
    }
    for(i=0;i<n;i++)
    {
        printf("SUB[%d] is %d\n",i,sub[i]);
        out+=sub[i];
    }

    return out;
}
int two(int test)
{
    int n=0,i,j,len,sub[7],out=0,x;
    for(i=0;i<7;i++)
        sub[i]=0;
    len=strlen(b[test]);
    i=len-1;
    while(i>=0)
    {
        x=b[test][i]-'A';
        if(check(2,i,test))
        {
            if(i==len-1 && x>0)
            {
                if(len>1 && b[test][i]==b[test][i-1] && x>1)
                    sub[n]=x-1;
                else if(len>1 && b[test][i]==b[test][i-1]+1 && x>2)
                    sub[n]=x-2;
                else if(len>1 && b[test][i]>b[test][i-1]+1 && x>2)
                    sub[n]=x-3;
                else
                    sub[n]=x;

            }
            else if(i==len-2 && x>0)
            {
                if(i>0 && b[test][i]==b[test][i-1])
                    sub[n]=x-1;
                else if(i>0 && b[test][i]>b[test][i-1])
                    sub[n]=x-3;
                else if(i>0 && b[test][i]==b[test][i-1]+1)
                    sub[n]=x-2;
                else
                    sub[n]=x;
                if(sub[n])
                sub[n]=sub[n]*7+1;
            }
            else if(x>0)
            {
                for(j=i;j<len;j++)
                {
                    x=b[test][j]-'A';
                    printf("qwerty is %d",x);
                    if(j==i)
                        sub[n]=x;
                    else if(j==i+1 && sub[n])
                        sub[n]=sub[n]*7+1;
                    else if(b[test][j-2]=='A' || b[test][j-2]=='B' && sub[n])
                        sub[n]=sub[n]*7+1;
                    else if(sub[n])
                        sub[n]=sub[n]*7+2;
                }
            }
        }
        n++;
        i--;
    }
    for(i=0;i<n;i++)
    {
        printf("SUB[%d] is %d\n",i,sub[i]);
        out+=sub[i];
    }
    return out;
}
int three(int test)
{
    int n=0,i,j,len,sub[7],out=0,x;
    for(i=0;i<7;i++)
        sub[i]=0;
    len=strlen(a[test]);
    i=len-1;
    while(i>=0)
    {
        x=b[test][i]-a[test][i];
        if(check(3,i,test))
        {
            if(i==len-1 && x>0)
            {
                printf("Check returned the value %d",check(4,i,test));
                if(check(4,i,test)==4)
                    sub[n]=x;
                else if(len>1 && (a[test][i]==a[test][i-1] && b[test][i]==b[test][i-1]))
                    sub[n]=x-3;
                else if(len>1 && (a[test][i]==a[test][i-1] && b[test][i]>b[test][i-1]))
                    sub[n]=x-4;
                else if(len>1 && (a[test][i]<a[test][i-1] && b[test][i]==b[test][i-1]))
                    sub[n]=x-4;
                else if(len>1 && (a[test][i]<a[test][i-1] && b[test][i]>b[test][i-1]))
                    sub[n]=x-5;
                else if(len>1 && b[test][i]>b[test][i-1])
                    sub[n]=x-2;
                else if(len>1 && a[test][i]<a[test][i-1])
                    sub[n]=x-2;
                else if(len>1 && a[test][i]==a[test][i-1])
                    sub[n]=x-1;
                else if(len>1 && b[test][i]==b[test][i-1] && x>1)
                    sub[n]=x-1;
                else
                    sub[n]=x-1;
            }
            else if(i==len-2 && x>0)
            {
                if(i>0 && b[test][i]==b[test][i-1])
                    sub[n]=x-1;
                else if(i>0 && b[test][i]>b[test][i-1])
                    sub[n]=x-3;
                else if(i>0 && b[test][i]==b[test][i-1]+1)
                    sub[n]=x-2;
                else
                    sub[n]=x;
                if(sub[n])
                sub[n]=sub[n]*7+1;
            }
            else if(x>0)
            {
                for(j=i;j<len;j++)
                {
                    x=b[test][j]-a[test][j];
                    printf("qwerty is %d",x);
                    if(j==i)
                        sub[n]=x;
                    else if(j==i+1 && sub[n])
                        sub[n]=sub[n]*7+1;
                    else if(b[test][j-2]=='A' || b[test][j-2]=='B' && sub[n])
                        sub[n]=sub[n]*7+1;
                    else if(sub[n])
                        sub[n]=sub[n]*7+2;
                }
            }
        }
        n++;
        i--;
    }
    for(i=0;i<n;i++)
    {
        printf("SUB[%d] is %d\n",i,sub[i]);
        if(sub[i]>0)
            out+=sub[i];
    }

    return out;
}
int four(int test,int len)
{
    int i,j,sub[7],out=0;
    for(i=0;i<7;i++)
        sub[i]=1;
    for(i=0;i<len;i++)
    {
        if(i==0)
            sub[i]=10;
        else
            sub[i]=sub[i]*7+2;
    }
    for(i=0;i<len;i++)
        out+=sub[i];
    return out;
}

int check(int str,int pos,int test)
{
    int i,j;
    if(str==1)
    {
        for(i=1;i<pos;i++)
        {
            if(a[test][i]==a[test][i-1] || a[test][i]==a[test][i-1]+1 || a[test][i]==a[test][i-1]-1)
                return 0;
        }
        return 1;
    }
    else if(str==2)
    {
        for(i=1;i<pos;i++)
        {
            if(b[test][i]==b[test][i-1] || b[test][i]==b[test][i-1]+1 || b[test][i]==b[test][i-1]-1)
                return 0;
        }
        return 1;
    }
    else if(str==3)
    {
        for(i=1;i<pos;i++)
        {
            if(b[test][i]==b[test][i-1] || b[test][i]==b[test][i-1]+1 || b[test][i]==b[test][i-1]-1)
                return 0;
        }
        for(i=1;i<pos;i++)
        {
            if(a[test][i]==a[test][i-1] || a[test][i]==a[test][i-1]+1 || a[test][i]==a[test][i-1]-1)
                return 0;
        }
        return 1;
    }
    else if(str==4)
    {
        for(i=0;i<pos;i++)
        {
            if(b[test][i]>a[test][i])
                return 4;
        }
    }
}

