#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using dbl=double;
using ii=pair<int,int>;
using lii=pair<ll,ll>;
template <class T> using V=vector<T>;

#define INF                         (int)1e9
#define EPS                         1e-9
#define LONG_INF                    (1ll << 63 - 1ll)
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forn(i,n) 					for(int i=0;i<(int)n;i++)
#define forn1(i,n)					for(int i=1;i<=(int)n;i++)
#define rforn(i,n)                  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n)                 for(int i=(int)n;i>=1;i--)

/**
    cbs0615/ddolgu14
    AOJ BOJ CODEFORCE CODEGROUND
*/

int n, bit[500005], arr[500005];
map<int, int> mp;

void update(int idx, int val)
{
    idx++;
    int pos=idx;

    while(pos<=500000)
    {
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

int sum(int idx)
{
    idx++;
    int pos=idx, ret=0;

    while(pos)
    {
        ret+=bit[pos];
        pos-=pos&-pos;
    }

    return ret;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; int a;

    forn1(i, n)
    {
        cin>>a; mp[a]=i;
    }

    int cnt=0;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        arr[it->second]=++cnt;
    }

    forn1(i, n)
    {
        update(arr[i],1);
        cout << i-sum(arr[i]-1) <<'\n';
    }

	return 0;
}
