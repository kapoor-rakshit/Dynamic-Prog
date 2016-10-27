#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	scanf("%d",&n);
	double val[n];
	double wt[n];
	for(int i=0;i<n;i++) scanf("%lf",&val[i]);
	for(int i=0;i<n;i++) scanf("%lf",&wt[i]);
	double twt;
	scanf("%lf",&twt);
	pair<double,pair<double,double> > chk[n];
	for(int i=0;i<n;i++) 
	{                                                             
		chk[i].second.first=val[i];
		chk[i].second.second=wt[i];
		chk[i].first=val[i]/wt[i];
	}
	sort(chk,chk+n);                                               //sort the elements acc to val/wt ratio
	double swt=0;
	double sval=0;
	double answt[n];
	double ansval[n];
	int ind=0;
	for(int i=n-1;i>=0;i--)                                      //start including elements with highest ratio
	{
		if(chk[i].second.second+swt<=twt)
		{
			swt+=chk[i].second.second;
			sval+=chk[i].second.first;
			ansval[ind]=chk[i].second.first;
			answt[ind++]=chk[i].second.second;
			chk[i].second.second=-1;
		}

	}
	int i=n-1;
	while(i>=0)
	{
		if(chk[i].second.second!=-1)     //if total weight is still less than max wt then pick a definite ratio 

		{
			ansval[ind]=((chk[i].second.first)/(chk[i].second.second)*(twt-swt));
			answt[ind++]=twt-swt;
			sval+=ansval[ind-1];              		
			break;
		}
		i--;
	}
	printf("Maximum sum is : %lf\n",sval);
	printf("values and weights are : \n");
	for(int i=0;i<ind;i++)
	{
		printf("%lf %lf\n",ansval[i],answt[i]);
	}
}
