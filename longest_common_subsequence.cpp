#include<bits/stdc++.h>
using namespace std;
char a[10010];
char b[10010];
int dp[100][100];                                              //a 2D matrix to have length of LCS
char chk[100][100];                                           //a 2D matrix to check the character is obtained from which part
                                                             //i.e. diagonal(d) or left(l) or above(u)
main()
{
    scanf("%s%s",a,b);
    int la=strlen(a);
    int lb=strlen(b);
    for(int i=1; i<=la; i++)
    {
        for(int j=1; j<=lb; j++)
        {
            if(a[i-1]==b[j-1])                //if characters at the row and column are same then assign that position 1+value at diagonal
            {
                dp[i][j]=dp[i-1][j-1]+1;
                chk[i][j]='d';
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);     //else value is maximum of the left and right element in matrix.
                if(dp[i][j]==dp[i][j-1]) chk[i][j]='l';
                else chk[i][j]='u';
            }
        }
    }
    for(int i=0; i<=la; i++)
    {
        cout<<endl;
        for(int j=0; j<=lb; j++) cout<<dp[i][j]<<" ";
    }

    cout<<"\n\nLength of longest common subsequence : "<<dp[la][lb]<<endl;

    string s="";
    int i=la;
    int j=lb;
    while(1)                                                     //Backtracking
    {
        if(j==0||i==0) break;
        if(a[i-1]==b[j-1]) s+=a[i-1];
        if(chk[i][j]=='d')
        {
            j--;
            i--;
        }
        else if(chk[i][j]=='u') i--;
        else if(chk[i][j]=='l') j--;
    }
    int sz=s.size();
    cout<<"Longest common subsequence : ";
    for(int i=sz-1;i>=0;i--) cout<<s[i];
    cout<<endl;
}
