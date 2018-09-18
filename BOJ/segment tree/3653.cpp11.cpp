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

int n,m, q[100005], bit[200050], pos[200050];

void init()
{
    memset(bit, 0, sizeof(bit));
    memset(pos, 0, sizeof(pos));
}

void update(int idx, int val)
{
    int pos=idx;

    while(pos<=200005)
    {
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

int sum(int idx)
{
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
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt;
    cin>>tt;

    while(tt--)
    {
        cin>>n>>m;
        forn(i,m) cin>>q[i];

        init();

        int t=n+1;

        forn1(i,n)
        {
            pos[i]=n+1-i;
            update(i, 1);
        }

        forn(i,m)
        {
            int sm=sum(pos[q[i]]);
            cout << n-sm << ' ';

            update(pos[q[i]], -1);
            update(t, 1);
            pos[q[i]]=t++;
        }

        cout << '\n';

    }

	return 0;
}

