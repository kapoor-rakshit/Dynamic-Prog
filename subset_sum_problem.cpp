#include<bits/stdc++.h>
using namespace std;
bool dp[100][100];                                //2D matrix having col=sum+1 and row=n
                                                 //row has elements of array and columns have 0 to sum 
main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int sum;
	scanf("%d",&sum);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=sum;j++)              
		{
			if(j==0) dp[i][j]=true;      //if it is col=0 then true we can have empty set for all values

			else if(i==0)               //if it is first row then check if the element is equal to sum(col)
			{
				if(a[i]==j) dp[i][j]=true;
				else dp[i][j]=false;
			}
			else if(j>=a[i])           //if row>0 & col>0 ,check if value above is true then it is also true
			{                         //else check status of above row and col=diff of element and sum(col)
				if(dp[i-1][j]==true) dp[i][j]=true;
				else dp[i][j]=dp[i-1][j-a[i]];
			}
			else                      //if sum(col) < element copy the above status
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<endl;
		for(int j=0;j<=sum;j++) if(dp[i][j]==true) cout<<"T ";else cout<<"F ";
	}
	if(dp[n-1][sum]==true) 
	{
		cout<<"\nSum is possible"<<endl;
		cout<<"Elements which form the sum : ";
		int i=n-1;
		int j=sum;
		while(1)                              //backtracking ,if above value same then not include and move up
			                            //else include and move to row above and col=diff of element and sum(col)
		{
			if(i==0) break;
			if(dp[i-1][j]==dp[i][j]) i--;
			else
			{
				cout<<a[i]<<" ";
				j=j-a[i];
				i--;
			}
		}
	}
	else cout<<"Sum is not possible"<<endl;
}
