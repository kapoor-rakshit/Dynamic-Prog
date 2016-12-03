/*Given a BST with its elements and frequency to search each element, find the minimum cost to search 
  with a suitable arrangement.

 Search Cost is calculated as summation(freq_i * level_i)*/

#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int fq[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&fq[i]);
	int dp[n][n]={0};
	int root[n][n];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) root[i][j]=-1;
	for(int l=1;l<=n;l++)
	{
		for(int i=0,j=l-1;i<n-(l-1);i++,j++)
		{
			int sm=0;
			int mn=INT_MAX;
			int c=0;
			for(int m=i;c<l;c++,m++)
			{
				sm+=fq[m];
			}
			int rt=-1;
			if(l!=1)
			{
				int tp;
				c=1;
				for(int k=i;c<=l;k++,c++)
				{
					if(c==1) tp=dp[k+1][i+l-1];
					else if(c==l) tp=dp[i][k-1];
					else tp=dp[i][k-1]+dp[k+1][i+l-1];

					mn=min(mn,tp);
					if(mn==tp) rt=k;
				}
				sm+=mn;
			}
			dp[i][j]=sm;
			root[i][j]=rt;	
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d ",dp[i][j]);
		printf("\n");
	}

	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d ",root[i][j]);
		printf("\n");
	}
	printf("\nOptimal search cost is %d with root at element %d",dp[0][n-1],root[0][n-1]);
}
/*To construct tree traverse root matrix with values a[root[0][j]] where j=n-1
 then for left and right child consider a[root[0][root[0][j]-1]] and a[root[0][root[0][j]+1]]
 ie consider separate intervals for each left and right from root and value of array at that root[0][j]*/
