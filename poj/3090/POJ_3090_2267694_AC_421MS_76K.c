#include<stdio.h>
#include<math.h>
int a[12]={2,3,5,7,11,13,17,19,23,29,31,37};
int oula(int n)
{
	int i,sum=1,k;
	for(i=0;i<12&&n!=1;i++)
	{
		if(n%a[i]==0)
		{
			k=0;
			while(n%a[i]==0)
			{

				n/=a[i];
				k++;
			}
			sum*=(a[i]-1)*pow(a[i],k-1);
		}
	}
	if(n!=1) sum*=(n-1);
	return sum*2;
}
int main()
{
	int c,i,n,sum,j;
	scanf("%d",&c);
	for(i=1;i<=c;i++)
	{
		scanf("%d",&n);
		sum=3;
		for(j=2;j<=n;j++)
			sum+=oula(j);
		printf("%d %d %d\n",i,n,sum);
	}
	return 0;
}