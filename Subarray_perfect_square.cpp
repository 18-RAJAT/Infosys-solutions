#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        auto SquareRoot=[&](int value)->int
        {
            int l=0;
            int r=value;
            while(l<r)
            {
                int mid=l+(r-l+1)/2;
                (mid*mid>value)?r=mid-1:l=mid;
            }
            return l;
        };
        int sqrt_sum=SquareRoot(sum);
        for(int j=0;j<=sqrt_sum;j++)
        {
            if(mp.count(sum-j*j)>=1)
            {
                ans+=mp[sum-j*j];
            }
        }
        mp[sum]++;
    }
    assert(mp[0]==1);
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}