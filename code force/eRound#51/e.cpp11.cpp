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

const ll MOD = 998244353;
ll z1[2000005], z2[2000005], dp[1000005], psum[1000005];
void solveZ(string s, ll z[])
{
    z[0]=0;

    ll L=0, R=0, n=s.size();
    for(ll i=1;i<n;i++)
    {
        if(i>R)
        {
            L=R=i;
            while(R<n && s[R-L]==s[R]) R++;
            z[i]=R-L; R--;
        }
        else
        {
            ll k=i-L;
            if(z[k]<R-i+1) z[i]=z[k];
            else
            {
                L=i;
                while(R<n && s[R-L]==s[R]) R++;
                z[i]=R-L; R--;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string a,l,r;
    cin>>a>>l>>r;

    string la=l+'#'+a;
    string ra=r+'#'+a;

    solveZ(la, z1);
    solveZ(ra, z2);
    ll lsize=l.size();
    ll rsize=r.size();

    ll ls=0, rs=0;
    forn(i,a.size())
    {
        if(i-ls+1<lsize)
        {
            dp[i]=0;
            continue;
        }

        while(i-ls+1!=lsize) ls++;
        while(i-rs+1>rsize) rs++;

        if(i-rs+1==rsize)
        {
            ll matched=z2[rs+rsize+1];

            if(matched!=rsize && a[rs+matched]>r[matched]) rs++;
        }

        if(i-ls+1==lsize)
        {
            ll matched=z1[ls+lsize+1];

            if(matched!=lsize && a[ls+matched]<l[matched])
            {
                if(ls==0) continue;
                else ls--;
            }
        }

        if(rs<=ls)
        {
            if(ls-1<0) dp[i]=1;
            else if(rs-1<0) dp[i]=(dp[i]+psum[ls-1]+1)%MOD;
            else dp[i]=(psum[ls-1]-(rs-2<0?0:psum[rs-2])+MOD)%MOD;


            if(a[i]=='0' && ls==i) dp[i]=(dp[i]+dp[i-1])%MOD;
            if(i!=a.size()-1 && a[i+1]!='0') psum[i]=(psum[i]+(i==0?0:psum[i-1])+dp[i])%MOD;
            else if(i!=0) psum[i]=psum[i-1];
            else psum[i]=0;
        }
    }

    cout << dp[a.size()-1] << endl;

	return 0;
}

