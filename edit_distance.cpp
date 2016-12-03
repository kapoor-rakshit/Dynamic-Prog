#include<bits/stdc++.h>
using namespace std;
char a[100];
char b[100];
char chk[100][100];
main()
{
	scanf("%s%s",a,b);
	int la=strlen(a);              //string over which operation to be performed ,kept as columns
	int lb=strlen(b);             //string which is desired ,kept as rows
	int dp[lb+1][la+1];
	for(int i=0;i<lb+1;i++) dp[i][0]=i;   //fill first (extra) row with 012345.....
	for(int j=1;j<la+1;j++) dp[0][j]=j;  //fill first (extra) column with 012345...

	for(int i=0;i<lb;i++) 
		for(int j=0;j<la;j++)
			if(b[i]==a[j]) {dp[i+1][j+1]=dp[i][j];chk[i+1][j+1]='D';}  //same then copy diagonal
			else 
			{
				int mn;int lv;int uv;int dv;
				lv=dp[i+1][j];
				uv=dp[i][j+1];
				dv=dp[i][j];
				mn=min(min(lv,dv),uv);                 //min of left, up, diagonal value
				dp[i+1][j+1]=mn+1;             //min+1
				if(mn==lv) chk[i+1][j+1]='L';
				else if(mn==uv) chk[i+1][j+1]='U';
				else chk[i+1][j+1]='D';
			}
	cout<<endl;
	for(int i=0;i<lb+1;i++)
	{
		for(int j=0;j<la+1;j++) printf("%d ",dp[i][j]);
		printf("\n");
	}
	printf("No. of Operations are : %d",dp[lb][la]);
	printf("\nOperations are : \n");
	int i=lb;
	int j=la;
	while(i>0&&j>0)
	{
		if(a[j-1]==b[i-1]&&chk[i][j]=='D') {i--;j--;}
		else if(a[j-1]!=b[i-1]&&chk[i][j]=='D') {printf("Replace %c in Ist with %c in IInd\n",a[j-1],b[i-1]);i--;j--;}
		else if(chk[i][j]=='L') {printf("Remove %c from Ist string\n",a[j-1]);j--;}
		else if(chk[i][j]=='U') {printf("Add %c to Ist\n",b[i-1]);i--;}
	}
}
