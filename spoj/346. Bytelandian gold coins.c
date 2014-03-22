#include<stdio.h>
int inp[10],x,y,z;
int main()
{
    int i=0,j;
    char a[10],b;
    while(1)
    {
        scanf("%c",&b);

        a[0]=b;
        if(b==10)
            break;
        else
        {
            j=1;
            while(1)
            {
                scanf("%c",&b);
                if(b==10)
                    break;
                a[j]=b;
                j++;
            }
            a[j]='\0';
            inp[i]=atoi(a);
            x=inp[i]/2;
            y=inp[i]/3;
            z=inp[i]/4;
            if((x+y+z)>inp[i])
                inp[i]=x+y+z;
            i++;
        }
        fflush(stdin);
    }
    for(j=0;j<i;j++)
        printf("%d\n",inp[j]);
    return 0;
}
