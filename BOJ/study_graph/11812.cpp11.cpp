#include<bits/stdc++.h>
using namespace std;
template <class T> using V=vector<T>;
using ll=long long;
using dbl=double;
using ii=pair<int,int>;
#define INF                         (int)1e9
#define EPS                         1e-9
#define LONG_INF                    (1ll << 63 - 1ll)
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forn(i,n) 					for(int i=0;i<(int)n;i++)
#define forn1(i,n)					for(int i=1;i<=(int)n;i++)
#define rforn(i,n)                  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n)                 for(int i=(int)n;i>=1;i--)
#define for1(i,p,q)                 for(int i=(int)p;i<=q;i++)
#define rfor1(i,p,q)                for(int i=(int)q;i>=p;i--)

ll n,k,q, lmt;
ll xys[100][2], cnt[2];

void ans(ll x, ll idx)
{
    xys[cnt[idx]++][idx]=x;

    while(x!=0)
    {
        x=(x-1)/k;
        xys[cnt[idx]++][idx]=x;
    }
}

ll solve(ll x, ll y)
{
    if(k==1) return (x-y>0?x-y:y-x);

    // 공통 조상을 찾는다
    // x를 위로 타고 올라가고 , y 를 위로타고 올라가서 처음 만나는 곳
    x--; y--;

    cnt[0]=cnt[1]=0;
    ans(x,0); ans(y,1);

    ll idx1=0, idx2=0, lca=-1, xx=0, yy=0;
    while(idx1<cnt[0] && idx2<cnt[1])
    {
        while(idx2<cnt[1] && xys[idx1][0]<xys[idx2][1]) idx2++;

        if(xys[idx1][0]==xys[idx2][1])
        {
            lca=xys[idx1][0];
            xx=idx1, yy=idx2;
            break;
        }

        idx1++;
    }

    return xx+yy;
}

int main()
{
    scanf("%lld%lld%lld", &n,&k,&q);

    ll x,y;
    forn(i,q)
    {
        scanf("%lld%lld", &x, &y);
        printf("%lld\n", solve(x,y));
    }

	return 0;
}

/*
9 3 3
5 8
2 3
5 6
*/
