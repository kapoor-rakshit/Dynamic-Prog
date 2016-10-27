//Problem is to have maximum sum of values but the corresponding sum of weights must be (minimum) less than or equal to
//the given total weight.

#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	scanf("%d",&n);
	int val[n];
	for(int i=0;i<n;i++) cin>>val[i];         //values 
	int wt[n];
	for(int i=0;i<n;i++) cin>>wt[i];          //weights
	int twt;
	scanf("%d",&twt);                        //total weight or sum of all weights should be less than equalto twt

	int dp[n][twt+1];                       //A 2D matrix having no. of rows=no. of elements 
	                                       //and no. of columns=total weight+1

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=twt;j++)
		{
			if(j>=wt[i])            //check if total weight column is greater than element's weight
			{
				if(i==0) dp[i][j]=val[i];          //if it is first row then we have an only option                                                                            //to copy value of first item.                                                                       
				else dp[i][j]=max(dp[i-1][j] , val[i]+dp[i-1][j-wt[i]]); 

//make entry in matrix by choosing the maximum of (value obtained not considering the element , considering the element)
//Here j-wt[i] means move wt[i] steps backwards from current.

			}
			else
			{
				if(i==0) dp[i][j]=0;          //if first row then can't select any item 
				else dp[i][j]=dp[i-1][j];    //else copy the previous value
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		cout<<endl;
		for(int j=0;j<=twt;j++)
			cout<<dp[i][j]<<" ";      //matrix of dp[][]
	}


	int i=n-1;                              //start from last row
	int j=twt;                              //start from last column
	int s=0;
	while(1)
	{
		if(i==0) break;            //if reached at first row break

		if(dp[i][j]==dp[i-1][j])
		{
			i--;              //if previous value and current are same then not included in answer and move up
		}
		else
		{
			j=j-wt[i];       //else move one row up with column at weight steps backwards and is included

			s+=val[i];
			printf("\nValue is %d\nWeight is %d\n",val[i],wt[i]);
			i--;
		}
	}
	printf("\nMaximum sum obtained is : %d\n",s);
}
