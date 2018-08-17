#include <bits/stdc++.h>
using namespace std;

template <class T> using V=vector<T>;
using ll=long long;
ll const MOD=100003;
int L;
string str;

bool isEqual(int a, int b, int l)
{
    while(l--)
    {
        if(str[a] != str[b]) return false;
        a++;b++;
    }

    return true;
}

bool check(int l)
{
    V<int> mp[MOD];

    ll t=0, power=1;
    for(int i=0;i<l;i++)
    {
        t = (t*2+str[i])%MOD;
        if(i!=l-1) power=(power*2)%MOD;
    }

    mp[t].push_back(0);

    for(int i=1;i+l-1<L;i++)
    {
        ll f=(str[i-1]*power)%MOD;
        t=(t-f+MOD)%MOD;
        t=(t*2+str[i+l-1])%MOD;


        if(mp[t].size())
        {
            for(int j=0;j<mp[t].size();j++)
            {
                if(isEqual(mp[t][j],i,l)) return true;
            }
        }

        mp[t].push_back(i);
    }

    return false;
}

int main()
{
    cin>>L>>str;

    int l=1, r=L, mid, ret=-1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
            ret=mid;
        }
        else r=mid-1;
    }

    if(ret == -1) cout << 0 << endl;
    else cout << ret << endl;

    return 0;
}
