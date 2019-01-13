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

int n,k,a,b,c,arr[1000], nxt[1000], dp[1000];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k;

    forn(i,k) cin>>arr[i];

    forn(i,1000) nxt[i]=INF;
    forn(i,k)
    {
        for(int j=i+1;j<k;j++)
        {
            if(arr[i]==arr[j])
            {
                nxt[i]=j;
                break;
            }
        }
    }

    int sz=0, ret=0;
    ii q[1000];

    forn(i,k)
    {
        if(dp[arr[i]])
        {
            forn(j,n)
            {
                if(arr[i]==q[j].second)
                {
                    q[j].first=nxt[i];
                    break;
                }
            }

            continue;
        }

        if(sz<n)
        {
            dp[arr[i]]=1;
            q[sz++]={nxt[i], arr[i]};
        }
        else
        {
            int mj=-1, mvj=0;
            forn(j,n)
            {
                if(q[j].first>mvj)
                {
                    mj=j;
                    mvj=q[j].first;
                }
            }

            dp[q[mj].second]=0;
            q[mj]={nxt[i], arr[i]};
            dp[q[mj].second]=1;
            ret++;
        }
    }

    cout << ret << endl;

	return 0;
}

