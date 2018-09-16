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

ll n,m,d, b[200500], ret[200500];

lii a[200500];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>d; forn1(i,n) cin>>a[i].first, a[i].second=i; sort(a+1, a+n+1);

    priority_queue<lii, V<lii>, greater<lii>> pq;
    ll c=0;

    forn1(i,n)
    {
        if(i==1)
        {
            pq.push({a[1].first, c}); b[i]=c++;
        }
        else
        {
            lii e=pq.top();
            if(a[i].first-e.first<=d)
            {
                pq.push({a[i].first, c}); b[i]=c++;
            }
            else
            {
                b[i]=e.second;
                pq.pop(); pq.push({a[i].first, e.second});
            }
        }
    }

    cout << c << '\n';

    forn1(i,n)
    {
        ret[a[i].second]=b[i]+1;
    }

    forn1(i,n) cout << ret[i] << ' ';
    cout << endl;


	return 0;
}

/**
4 10000000 5
100000 100005 1000011 100003
3
1 1 2 3
*/

