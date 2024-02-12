#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    function<int(int,int)>count_array=[&](int n,int k)->int
    {
        int dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i)
        {
            dp[i][1]=1;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=2;j<=k;++j)
            {
                for(int k=i;k<=n;k+=i)
                {
                    dp[k][j]+=(dp[i][j-1])%10000;
                }
            }
        }
        int total=0;
        for(int i=1;i<=n;++i)
        {
            total+=dp[i][k]%10000;
        }
        return total;
    };
    cout<<count_array(n,k)<<endl;
}
signed main()
{
    sol();
    return 0;
}