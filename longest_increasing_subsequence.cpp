#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	scanf("%d",&n);
	int a[n];                                               //elements

	int b[n];                                              //keeps track of lengths

	int ans[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) b[i]=1;                           //minimum length can be 1 i.e. element itself

	int i=1;
	int j=0;
	while(i<n)
	{
		while(j<i)
		{
			if(a[j]<=a[i])                          //includes equal elements too
				b[i]=max(b[i],b[j]+1);
			j++;
		}
		j=0;
		i++;
	}
	int mx=INT_MIN;
	for(int i=0;i<n;i++) if(b[i]>mx) {mx=b[i];}

	cout<<endl<<"Length of longest increasing subsequence : "<<mx<<endl;
}
