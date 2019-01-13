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

int n,k,w[500000];
ii mv[500000];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k;

    forn(i,n)
    {
        cin>>mv[i].first>>mv[i].second;
    }

    forn(i,k)
    {
        cin>>w[i];
    }

    sort(w, w+k);
    sort(mv, mv+n);
    priority_queue<int, V<int>, less<int>> pq;

    int sz=0;
    ll ret=0;
    forn(i,k)
    {
        while(sz<n && w[i]>=mv[sz].first)
        {
            pq.push(mv[sz].second);
            sz++;
        }

        if(pq.size())
        {
            ret+=pq.top();
            pq.pop();
        }
    }

    cout << ret << endl;

	return 0;
}

