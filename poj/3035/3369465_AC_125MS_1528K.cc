#include<stdio.h>
#include<vector>
using namespace std;
#define maxn 10000
vector<int > a[maxn];
double ans[maxn][120];
int main()
{
	int i,j,k,n,e,l,p;
	while(scanf("%d%d%d",&k,&n,&e)&&(n+k+e))
	{
		for(i=0;i<(1<<n);i++) a[i].clear();
		for(i=0;i<(1<<n);i++) 
		{
			ans[i][1]=1.0/((double)(1<<n));
			for(j=2;j<=k;j++) ans[i][j]=0.0;
		}
		while(e--)
		{
			scanf("%d%d",&i,&j);
			a[i].push_back(j);
			a[j].push_back(i);
		}
		for(i=1;i<k;i++)
		{
			for(j=0;j<(1<<n);j++)
			{
				double y=a[j].size();
				for(l=0;l<a[j].size();l++)
				{
					int x=a[j][l];
					ans[x][i+1]+=ans[j][i]/y;
				}
			}
			double sum;
			for(l=0;l<n;l++)
			{
				sum=0.0;
				for(j=0;j<(1<<n);j++)
				{
					if(j&(1<<l)) sum+=ans[j][i+1];
				}
				if(sum<0.25||sum>0.75) goto line;
			}
		}
line:
		if(i==k) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
	
}