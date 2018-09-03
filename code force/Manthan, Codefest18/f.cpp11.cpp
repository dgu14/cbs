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

ll N,K;
ll const MOD=(int)1e9+7;

ll s(ll a, ll d, ll n)
{
    return (2*a+d*(n-1))*n/2;
}

ll findq(ll a, ll d, ll v)
{
    int lo=0, hi=1e6, ret;

    while(lo<=hi)
    {
        int mid=(lo+hi)>>1;

        if(a+d*(mid-1)>v)
        {
            hi=mid-1; ret=mid;
        }
        else lo=mid+1;
    }

    return ret-1;
}

ll sum(ll a, ll d, ll srt, ll ed)
{
    ll na=a+d*srt;
    ll ne=a+d*ed;

    return (na+ne)*(ed-srt+1)/2;
}

ll r[1000005], l[1000005], a[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifdef test
        ofstream fout("a.out");
        ifstream fin("a.in");
    #else
    cin>>N>>K;
    forn(i,N) cin>>a[i];

    forn(i,N) r[i]=i, l[i]=i;

    stack<lii> stk;

    forn(i,N)
    {
        while(stk.size() && stk.top().first<=a[i])
        {
            r[stk.top().second]=i-1;
            stk.pop();
        }

        l[i]=stk.size()?stk.top().second+1:0;
        stk.push({a[i], i});
    }

    while(stk.size())
    {
        r[stk.top().second]=N-1;
        stk.pop();
    }

    ll ret=0;
    forn(i,N)
    {
        ll q=(r[i]-l[i]+1-K)/(K-1);


        if(r[i]-l[i]+1-K<0) continue;

        ll rd=r[i]-i-K+1>=0?(r[i]-i-K+1)/(K-1)+1:0;
        ll ld=i-l[i]+1-K>=0?(i-l[i]+1-K)/(K-1)+1:0;

        ll rtmp=(((2*K + ((K-1)*q)%MOD)*(q+1))%MOD * (MOD+1)/2)%MOD;

        if(rd<=q)
        {
            ll tt1=((q-rd+1)*r[i])%MOD;
            ll tt2=(sum(i+K-1,K-1,rd,q))%MOD;

            if(tt1-tt2<0) tt1=(tt1-tt2+MOD)%MOD;
            else tt1=(tt1-tt2)%MOD;

            rtmp = (rtmp+tt1)%MOD;
        }

        if(ld<=q)
        {
            ll tt1=(sum(i-K+1,1-K,ld,q))%MOD;
            ll tt2=(q-ld+1)*l[i];

            if(tt1-tt2<0) tt1=(tt1-tt2+MOD)%MOD;
            else tt1=(tt1-tt2)%MOD;

            rtmp = (rtmp+tt1)%MOD;
        }

        ret= (ret + (rtmp*a[i])%MOD)%MOD;
    }

    cout << ret << endl;



    #endif

	return 0;
}

