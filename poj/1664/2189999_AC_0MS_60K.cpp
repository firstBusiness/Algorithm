#include<stdio.h>
int sum;
void find(int m,int n)
{
    int i;
    if(m==0)
		sum++;
    else
    {
        for(i=n;i>0;i--)
        {
            if(i>m)
                continue;
            else
                find(m-i,i);   
        }
    }
}
void main()
{
    int n,t,m,i;
	scanf("%d",&t);
	while(t--)
    {
		sum=0;
		scanf("%d %d",&n,&m);
			find(n,m);
		printf("%d\n",sum);
	}
}