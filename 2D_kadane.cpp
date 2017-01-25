#include "bits/stdc++.h"
using namespace std;
#define ll long long
int start;
int ed;
ll kadane(ll tp[],int n)
{
    ll cur_max=tp[0];
    ll max_sum=tp[0];
    for(int i=1;i<n;i++)
    {
        cur_max=max(tp[i],cur_max+tp[i]);
        if(cur_max==tp[i]) start=i;
        max_sum=max(cur_max,max_sum);
        if(max_sum==cur_max) ed=i;
    }
    return max_sum;
}
main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        scanf("%lld",&a[i][j]);
        ll mx_sum=INT_MIN;
        ll cur_sum;
        int mx_left;
        int mx_top;
        int mx_right;
        int mx_bottom;
        ll tp[n];
    for(int left=0;left<m;left++)
    {
        for(int right=left;right<m;right++)
        {
            if(right==left)
            {
                for(int i=0;i<n;i++) tp[i]=a[i][right];
                cur_sum=kadane(tp,n);
            }
            else
            {
                for(int i=0;i<n;i++) tp[i]+=a[i][right];
                cur_sum=kadane(tp,n);
            }
            if(cur_sum>mx_sum)
            {
                mx_sum=cur_sum;
                mx_left=left;
                mx_top=start;
                mx_right=right;
                mx_bottom=ed;
            }
        }
    }
    printf("%lld\n",mx_sum);
    printf("\n%d %d\n%d %d",mx_left,mx_top,mx_right,mx_bottom);
}
