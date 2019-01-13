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

int n,c,m,p,q,r,st[3000],ret;
V<pair<int, ii>> v;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>c>>m;

    forn(i,m)
    {
        cin>>p>>q>>r;
        v.push_back({q,{p,r}});
    }

    sort(v.begin(), v.end());

    forn(i,m)
    {
        int srt=v[i].second.first;
        int dest=v[i].first;
        int cc=v[i].second.second;

        int minc=cc;

        for(int j=srt;j<dest;j++)
        {
            minc=min(minc, c-st[j]);
        }

        for(int j=srt;j<dest;j++)
        {
            st[j]+=minc;
        }

        ret+=minc;
    }

    cout << ret << endl;

	return 0;
}
