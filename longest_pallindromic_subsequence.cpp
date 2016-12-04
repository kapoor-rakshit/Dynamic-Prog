#include<bits/stdc++.h>
using namespace std;
char chk[100][100];
char a[100];
main()
{
	scanf("%s",a);
	int n=strlen(a);
	int dp[n][n]={0};
	int sm;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) chk[i][j]='d';
	for(int l=1;l<=n;l++)                                     //sets of length 1 2 3 4 5 ... n
	{
		for(int i=0,j=l-1;i<n-(l-1);i++,j++)
		{
			if(l==1) sm=1;	else sm=2;
			if(l!=1)
			{
				if(a[i]==a[i+l-1]&&l!=1) //upper & lower limit of set is same 2+(val from dp of interval bw)

				{sm+=dp[i+1][i+l-2];chk[i][j]='d';}  				
				else
			       	{
					sm=max(dp[i][j-1],dp[i+1][j]);
					if(sm==dp[i][j-1]) chk[i][j]='L';  //max of dp val from left and down 
					else chk[i][j]='D';
				}
			}
			dp[i][j]=sm;
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d ",dp[i][j]);
		printf("\n");
	}
	cout<<endl;
	printf("Length of longest pallindromic subsequence : %d\n",dp[0][n-1]);
	char s[dp[0][n-1]];
	int i=0;
	int j=n-1;
	int sind=0;
	int eind=dp[0][n-1]-1;
	while(sind<=eind)
	{
		if(chk[i][j]=='d') {s[sind++]=a[i];s[eind--]=a[i];i++;j--;}
		else if(chk[i][j]=='L') j--;
		else i++;
	}
	printf("Subsequence is : ");cout<<s;
}
