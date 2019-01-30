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

ll n,m,k, dp[11][500][230];
V<ll> ret;

void solve(ll nn, ll mm, ll c)
{
    if(nn==1)
    {
        ret.push_back(mm);
        return;
    }

    ll rr=c;
    for(ll i=c;i<=mm;i++)
    {
        ll rk=0;

        for(ll j=i;j<=mm;j++)
        {
            rk+=dp[nn-1][mm-i][j];
        }

        k-=rk;

        if(k>0)
        {
            rr=i+1;
        }
        else if(k==0)
        {
            k+=rk;
            break;
        }
        else if(k<0)
        {
            k+=rk;
            break;
        }
    }

    ret.push_back(rr);
    solve(nn-1,mm-rr,rr);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>k;

    forn1(i,m)
    {
        dp[1][i][i]=1;
    }

    forn1(i,n)
    {
        if(i==n) continue;
        forn1(j,m)
        {
            forn1(r,m)
            {
                for(ll q=1;q<=r;q++)
                {
                    dp[i+1][j+q][q]+=dp[i][j][r];
                }
            }
        }
    }

    solve(n,m,1);

    forn(i, ret.size())
    {
        cout << ret[i] << " ";
    }
    cout << endl;

	return 0;
}

/*
4 9 4
1 1 1 6
*/
