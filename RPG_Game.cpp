#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Monster
{
    int Power;
    int Bonus;
};
void sol()
{
    int n,e;
    cin>>n>>e;
    vector<Monster>monsters(n);
    for(int i=0;i<n;++i)
    {
        cin>>monsters[i].Power>>monsters[i].Bonus;
    }
    sort(monsters.begin(),monsters.end(),[&](Monster monster1,Monster monster2)->bool
    {
        return monster1.Bonus>monster2.Bonus?true:false;
    });
    int count_monster=0;
    for(int i=0;i<n;++i)
    {
        while(e<monsters[i].Power)
        {
            e+=monsters[--count_monster].Bonus;//killing the monster and adding the bonus to the energy
            // count_monster--;
        }
        //for checking if we can kill the monster or not
        if(e>=monsters[i].Power)
        {
            count_monster++;
            e-=monsters[i].Power;
        }
    }
    cout<<count_monster<<endl;
}
signed main()
{
    sol();
    return 0;
}