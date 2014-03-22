#include<stdio.h>
typedef struct abc
{
    int data;
    struct abc *next,*pre;
}st;
long long out[15];
int main()
{
    st *head=NULL,*tail=NULL,*head1=NULL,*np;
    int test,i,j,n,left,right;
    int m,sum=0,eme=1,l=1,k;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        out[i]=10000000000;
        for(j=0;j<n;j++)
            insert(&head,&tail,j+1);
        cpy(&head1,n,head);
        for(j=1;j<n-1;j++)
        {
            np=head1;
            for(m=1;m<j;m++)
            {
                np=np->next;
            }
            left=np->data-1;
            right=np->data+1;
            if(np->pre==NULL)
            {
                head1=head1->next;
                np=np->next;
            }
            else
                np->pre->next=np->next;
            sum+=j;
            eme=1;
            l++;
            np=head1;
            for(k=0;k<n;k++)
            {
                while(1)
                {
                    if(np->data==left || np->data==right)
                        break;
                    np=np->next;
                    eme++;
                }
                if(np->data==left && left!=0 && left>=0)
                {
                    left--;
                    if(np->pre==NULL)
                    {
                        head1=head1->next;
                        if(head->pre!=NULL)
                            head1->pre=NULL;
                    }
                    else
                    {
                        if(np->next!=NULL)
                            np->next->pre=np->pre;
                        np->pre->next=np->next;
                    }
                    np=head1;
                    sum+=(eme)*(l);
                    l++;
                    eme=1;
                }
                else if(np->data==right && right!=n+1 && right<=n)
                {
                    right++;
                    sum+=(eme)*(l);
                    if(np->pre==NULL)
                    {
                        head1=head1->next;
                        head1->pre=NULL;
                    }
                    else
                    {
                        if(np->next!=NULL)
                            np->next->pre=np->pre;
                        np->pre->next=np->next;
                    }
                    l++;
                    np=head1;
                    eme=1;
                }
                if(left<1 && right>n)
                    break;
                if(np==NULL)
                    np=head1;
            }
            if(out[i]>sum)
                out[i]=sum;
            sum=0;
            l=1;
            head1=NULL;
            cpy(&head1,n,head);
        }
        head=head1=tail=NULL;
    }
    for(i=0;i<test;i++)
        printf("%d\n",out[i]);
}
void cpy(st **head1,int lim,st *head)
{
    st *np,*tail=NULL;
    int i;
    for(i=0;i<lim;i++)
    {
        np=malloc(sizeof(st));
        np->data=head->data;
        if(*head1==NULL)
        {
            *head1=np;
            np->pre=NULL;
            np->next=tail;
            tail=np;
        }
        else
        {
            np->pre=(tail);
            np->next=NULL;
            (tail)->next=np;
            tail=np;
        }
        head=head->next;
    }
}

void show(st *head)
{
    while(head!=NULL)
    {
        printf("%d\n",head->data);
        head=head->next;
    }
}

void insert(st **head,st **tail,int val)
{
    st *np;
    np=malloc(sizeof(st));
    np->data=val;
    if(*head==NULL)
    {
        *head=np;
        np->pre=NULL;
        np->next=*tail;
        *tail=np;
    }
    else
    {
        np->pre=(*tail);
        np->next=NULL;
        (*tail)->next=np;
        *tail=np;
    }
}
