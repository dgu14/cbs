#include <bits/stdc++.h>
using namespace std;

using ll=long long;
class quad
{
public:
    ll x,y,z,u;
};

ll n,m,k,lo[300100],hi[300100], ret[300100];
vector<ll> vt[300100],p[300100];
quad yebo[300100];
ll bit[300100], obj[300100];


ll sum(ll i)
{
    ll ret=0;
    for(ll j=i+1;j!=0;j-=j&-j)
    {
        ret+=bit[j];
    }

    return ret;
}

void update(ll i, ll num)
{
    for(ll j=i+1;j<=m;j+=j&-j)
    {
        bit[j]+=num;
    }
}

ll apply(ll l, ll r, ll gg)
{
    update(l, gg);

    if(r!=m-1)
    update(r+1, -gg);
}

ll applyYebo(ll yIdx)
{
    if(yebo[yIdx].x > yebo[yIdx].y)
    {
        apply(yebo[yIdx].x, m-1, yebo[yIdx].z);
        apply(0, yebo[yIdx].y, yebo[yIdx].z);
    }
    else
    {
        apply(yebo[yIdx].x, yebo[yIdx].y, yebo[yIdx].z);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    ll tt;
    for(int i=0;i<m;i++)
    {
        cin>>tt;
        p[tt-1].push_back(i);
    }

    for(int i=0;i<n;i++)cin>>obj[i];
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>yebo[i].x>>yebo[i].y>>yebo[i].z;
        yebo[i].x--;yebo[i].y--;
    }

    for(int i=0;i<n;i++) ret[i]=-1, hi[i]=k-1;
    int d=1;
    while(d)
    {
        d=0;
        memset(bit, 0, sizeof(bit));

        for(int i=0;i<n;i++)
        {
            if(lo[i] <= hi[i])
            {
                vt[(lo[i]+hi[i])>>1].push_back(i);
            }
        }

        for(int i=0;i<k;i++)
        {
            applyYebo(i);

            while(vt[i].size())
            {
                d=1;
                int cnty = vt[i].back();
                vt[i].pop_back();

                ll test=0;
                for(int r=0;r<p[cnty].size();r++)
                {
                    test+=sum(p[cnty][r]);

                    if(test >= obj[cnty]) break;
                }

                if(obj[cnty] <= test)
                {
                    ret[cnty]=i;
                    hi[cnty]=i-1;
                }
                else lo[cnty]=i+1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(ret[i]==-1) cout << "NIE" << '\n';
        else cout << ret[i]+1 << '\n';
    }

    return 0;
}
