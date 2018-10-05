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

ll n, m, t;
ll w[100005];
ll x[100], cnt[100], xlen;
map<ll, ll> mp;

ll used[100];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;

    forn(i,n) cin>>w[i];
    forn(i,m) cin>>t, mp[t]++;

    sort(w, w+n);

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        x[xlen]=it->first;
        cnt[xlen++]=it->second;
    }

    rforn(i, xlen)
    {
        forn(j,n)
        {
            ll u=0;
            if(cnt[i]>=w[j]/x[i]) u=(w[j]/x[i]);
            else u=cnt[i];
            w[j]-=x[i]*u;
            used[i]+=u; cnt[i]-=u;
        }
    }

    ll remainder=0;
    rforn(i, xlen)
    {
        if(i==xlen-1) continue;

        rfor1(j,i+1,xlen-1)
        {
            if(cnt[i])
            {
                if(remainder/x[i])
                {
                    ll q=remainder/x[i];

                    if(cnt[i]>=q)
                    {
                        remainder-=x[i]*q;
                        used[i]+=q;
                        cnt[i]-=q;
                    }
                    else
                    {
                        remainder-=x[i]*cnt[i];
                        used[i]+=cnt[i];
                        cnt[i]=0;
                    }
                }

                ll k=x[j]/x[i];
                ll f=(cnt[i]+k-1)/k;

                if(used[j]>=f) used[j]-=f, used[i]+=cnt[i], remainder+=f*x[i+1]-cnt[i]*x[i], cnt[i]=0;
                else used[i]+=k*used[j], cnt[i]-=k*used[j], used[j]=0;
            }
            else break;
        }
    }

    ll ret=0;
    forn(i, xlen)
    {
        ret+=used[i];
    }

    cout << ret << endl;

	return 0;
}


