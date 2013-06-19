#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

struct node {
    int x;
    int y;
}set[1001];

int cmp(const void *a,const void *b)
{

    struct node*c=(node *)a;
    struct node*d=(node* )b;
    return c->x-d->x;
}

char temp[100];
double slope[10001];


int main ()

{

    int n;
    int i,j,k;
    int testcase;
    testcase=0;
    int max1;
    int max2;
    int pos;
    int tempmax2;
    for(testcase=1;;testcase++)
    {

        pos=0;
        while(gets(temp))
        {

            if(temp[0]=='-'&&temp[1]=='-')
                break;
            pos++;
            sscanf(temp,"%d%d",&set[pos].x,&set[pos].y);
        }
        n=pos;
        if(n==0)
            break;
        int tempmax=1;
        max1=0;
        qsort(set+1,n,sizeof(set[1]),cmp);
        for(i=2;i<=n;i++)
        {
            if(set[i].x!=set[i-1].x)
                tempmax=1;
            else
                tempmax++;
            if(tempmax>max1)
                max1=tempmax;
        }
        max2=0;
        for(i=1;i<=n;i++)
        {
            pos=0;
            for(j=1;j<=n;j++)
            {

                if(i!=j&&set[i].x!=set[j].x)
                {
                    pos++;
                    slope[pos]=((double)set[j].y-set[i].y)/((double)set[j].x-set[i].x);

                }
            }
            sort(slope+1,slope+1+pos);
            tempmax=1;
            
            tempmax2=0;
            for(j=2;j<=pos;j++)
            {
                

                if(slope[j]!=slope[j-1])
                    tempmax=1;
                else
                    tempmax++;
                if(tempmax>tempmax2)
                    tempmax2=tempmax;
            }
            if(tempmax2>max2)
                max2=tempmax2;
        }
        if(max1>max2)
            printf("%d. %d\n",testcase,max1);
        else
            printf("%d. %d\n",testcase,max2+1);

        }

    return 0;
}
