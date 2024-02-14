#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int>nums;
    vector<char>operation;
    for(int i=0;i<n;++i)
    {
        (i&1)?operation.push_back(s[i]):nums.push_back(s[i]-'0');
    }
    int m=nums.size();
    int dp_max[m][m];
    fill(dp_max[0],dp_max[m],0);
    int dp_min[m][m];
    fill(dp_min[0],dp_min[m],0);
    for(int i=0;i<m;++i)
    {
        dp_max[i][i]=nums[i];
        dp_min[i][i]=nums[i];
    }
    for(int len=2;len<=m;++len)//for length of subArray from 2 to m
    {
        for(int i=0;i<=m-len;++i)//for starting index of subArray
        {
            int j=i+len-1;
            dp_max[i][j]=-1e18;
            dp_min[i][j]=1e18;
            for(int k=i;k<j;++k)//for partitioning the subArray into two parts and then finding the max and min value of the subArray from i to j using the partitioned subArray
            {
                auto &precompute_max=dp_max[i][j];
                auto &precompute_min=dp_min[i][j];
                if(operation[k]=='+')//if the operation is addition then we will add the max and min value of the subArray from i to k and k+1 to j
                {
                    precompute_max=max(precompute_max,dp_max[i][k]+dp_max[k+1][j]);//dp[i][k] is the max value of subArray from i to k and dp[k+1][j] is the max value of subArray from k+1 to j
                    precompute_min=min(precompute_min,dp_min[i][k]+dp_min[k+1][j]);//dp[i][k] is the min value of subArray from i to k and dp[k+1][j] is the min value of subArray from k+1 to j
                }
                else
                {
                    precompute_max=max(precompute_max,dp_max[i][k]*dp_max[k+1][j]);//dp[i][k] is the max value of subArray from i to k and dp[k+1][j] is the max value of subArray from k+1 to j
                    precompute_min=min(precompute_min,dp_min[i][k]*dp_min[k+1][j]);//dp[i][k] is the min value of subArray from i to k and dp[k+1][j] is the min value of subArray from k+1 to j
                }
            }
        }
    }
    cout<<dp_min[0][m-1]<<endl;
    cout<<dp_max[0][m-1]<<endl;
}
signed main()
{
    sol();
    return 0;
}