#include "bits/stdc++.h"
using namespace std;
#define ll long long
int start;
int ed;
ll kadane(ll tp[],int n)
{
    ll cur_max=tp[0];
    ll max_sum=tp[0];
    start=0;
    ed=0;
    for(int i=1;i<n;i++)
    {
        if(tp[i]>(cur_max+tp[i]))          //operate values
        {
          start=i;
          cur_max=tp[i];
        }
        else cur_max=cur_max+tp[i];      //operate
        if(cur_max>max_sum)
        {
          ed=i;
          max_sum=cur_max;
        }
    }
    if(start>ed) start=ed;             //NOTE
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
    for(int left=0;left<m;left++)                         //left and right pointers
    {
        for(int right=left;right<m;right++)
        {
            if(right==left)                              //if left and right are equal then reset with current column
            {
                for(int i=0;i<n;i++) tp[i]=a[i][right];
                cur_sum=kadane(tp,n);                    //call kadane for maxsum and start and end index
            }
            else
            {
                for(int i=0;i<n;i++) tp[i]+=a[i][right];   //operate values of each column 
                cur_sum=kadane(tp,n);                      //call kadane for maxsum and start and end index
            }
            if(cur_sum>mx_sum)                           //update values
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
