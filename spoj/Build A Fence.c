#include<stdio.h>
float peri;
int index,out[500000];

float dist(int p1[3],int p2[3])
{
    return sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2));
}

int main()
{
    int test,Cod[500000][3];
    int i,j;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        peri =  index = 0;
        int n,Starter[3]={1000000,1000000,0};
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d %d",&Cod[j][0],&Cod[j][1]);
            Cod[j][2]=0;
            if(Cod[j][1]<Starter[1])
            {
                Starter[0]=Cod[j][0];
                Starter[1]=Cod[j][1];
                Starter[2]=j;
            }
            else if(Cod[j][1]==Starter[1] && Cod[j][0]<Starter[0])
            {
                Starter[0]=Cod[j][0];
                Starter[1]=Cod[j][0];
                Starter[2]=j;
            }
        }
        BuildFence(Starter,Cod,n,Starter);
        printf("%0.2f\n",peri);
        for(j=0;j<index;j++)
            printf("%d ",out[j]);
        printf("\n\n");
    }
    return 0;
}

void BuildFence(int Starter[3],int Cod[500000][3],int n,int Originals[3])
{
    int positive[3],negative[3],init=0;
    int i,j,AngleCheck;
    Cod[Starter[2]][2]=1;
    out[index++] = Starter[2]+1;
    for(i=0;i<n;i++)
    {
        if(init==0)
        {
            positive[0] = negative[0] = Cod[i][0];
            positive[1] = negative[1] = Cod[i][1];
            positive[2] = negative[2] = i;
            init=1;
        }
        else
        {
            AngleCheck = CrossProd(Starter,i,Cod,positive);
            if(AngleCheck > 0)
            {
                positive[0] = Cod[i][0];
                positive[1] = Cod[i][1];
                positive[2] = i;
            }
            else if(AngleCheck==0 && dist(Starter,Cod[i])>dist(Starter,positive))
            {
                positive[0] = Cod[i][0];
                positive[1] = Cod[i][1];
                positive[2] = i;
            }
            AngleCheck = CrossProd(Starter,i,Cod,negative);
            if(AngleCheck < 0)
            {
                negative[0] = Cod[i][0];
                negative[1] = Cod[i][1];
                negative[2] = i;
            }
            else if(AngleCheck==0 && dist(Starter,Cod[i])>dist(Starter,negative))
            {
                negative[0] = Cod[i][0];
                negative[1] = Cod[i][1];
                negative[2] = i;
            }
        }
    }
    if(Cod[negative[2]][2]==1 && Cod[positive[2]][2]==1)
    {
        peri += dist(Starter,Originals);
        return;
    }
    else if(Cod[negative[2]][2]==0)
    {
        peri += dist(Starter,negative);
        BuildFence(negative,Cod,n,Originals);
    }
    else
    {
        peri += dist(Starter,positive);
        BuildFence(positive,Cod,n,Originals);
    }
}

int CrossProd(int Starter[3],int index,int Cod[500000][3],int Natural[3])
{
    int x1,x2,y1,y2;
    x1 = Starter[0]-Natural[0];
    y1 = Starter[1]-Natural[1];
    x2 = Starter[0]-Cod[index][0];
    y2 = Starter[1]-Cod[index][1];
    return x1*y2-y1*x2;
}
