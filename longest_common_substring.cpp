#include<bits/stdc++.h>
using namespace std;
char a[10010];
char b[10010];
int dp[100][100];                                        //a 2D matrix to have length of LCS
main()
{
	scanf("%s%s",a,b);
	int la=strlen(a);
	int lb=strlen(b);
	int mx=0;
	int mi;
	int mj;
	for(int i=1; i<=la; i++)
	{
		for(int j=1; j<=lb; j++)
		{
			if(a[i-1]==b[j-1])
	                         //if characters at the row and column are same then assign that position 1+value at diagonal
			{
				dp[i][j]=dp[i-1][j-1]+1;
				if(dp[i][j]>mx) {mx=dp[i][j];mi=i;mj=j;}
			}
			else
			{
				dp[i][j]=0;     //else value is 0
			}
		}
	}
	for(int i=0; i<=la; i++)
	{
		cout<<endl;
		for(int j=0; j<=lb; j++) cout<<dp[i][j]<<" ";
	}

	cout<<"\n\nLength of longest common substring : "<<mx<<endl;

	string s="";
	int i=la;
	int j=lb;
	while(1)                                                     //Backtracking
	{
		if(mj==0||mi==0) break;
		if(a[mi-1]==b[mj-1])
		s+=a[mi-1];
		mi--;
		mj--;
	}
	int sz=s.size();
	cout<<"Longest common substring : ";
	for(int i=sz-1;i>=0;i--) cout<<s[i];
	cout<<endl;
}
