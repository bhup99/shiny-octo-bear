#include<stdio.h>
long long int i,n,inp[50000],q,sub[100000][2],side[131072]={0},sum,j;
char jus[100000],std;
int main()
{
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&inp[i]);
    }
    scanf("%lld",&q);
    for(i=0;i<q;i++)
    {
        scanf("%c %c %lld %lld",&std,&jus[i],&sub[i][0],&sub[i][1]);
    }
    for(i=0;i<q;i++)
    {
        if(jus[i]=='Q')
        {
            sum=0;
            for(j=sub[i][0]-1;j<sub[i][1];j++)
            {
                if(!side[inp[j]])
                {
                    sum+=inp[j];
                    side[inp[j]]=1;
                    if(sum>100000)
                        sum=sum%100000;
                }
            }
            printf("%lld\n",sum);;
            for(j=sub[i][0]-1;j<sub[i][1];j++)
                side[inp[j]]=0;
        }
        else if(jus[i]=='U')
        {
            inp[sub[i][0]-1]=sub[i][1];
        }
    }
    return 0;
}
