#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cost,flip,swap;
    cin>>cost>>flip>>swap;
    function<int(int,int,int,string)>minimizeUgliness=[&](int n,int flip,int swap,string s)->int
    {
        int dp[n+1];
        fill(dp,dp+n+1,1e18);
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
            int ugliness=0;
            for(int j=0;j<i;++j)
            {
                ugliness=ugliness*2+(s[j]-'0');
            }
            if(swap<flip)
            {
                dp[i]=min(dp[i],dp[i-1]+swap);
                ugliness--;
            }
            if(i>=2)
            {
                dp[i]=min(dp[i],dp[i-2]+flip);
                ugliness=ugliness*2+(s[i-1]-'0');//2+(s[i-1]-'0') is the new ugliness after flipping the last two bits of the string s
            }
            dp[i]=min(dp[i],dp[i-1]+abs((s[i-1]-'0')-ugliness));//abs((s[i-1]-'0')-ugliness) is the new ugliness after flipping the last bit of the string s
        }
        return dp[n]-flip;
    };
    cout<<minimizeUgliness(n,flip,swap,s)<<endl;
}
signed main()
{
    sol();
    return 0;
}