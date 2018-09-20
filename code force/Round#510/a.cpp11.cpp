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

int n,m, a[105];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int max_t=0;
    cin>>n>>m; forn1(i,n) cin>>a[i], max_t=max(max_t, a[i]);

    priority_queue<int, V<int>, greater<int>> pq;
    forn1(i,n) pq.push(a[i]);

    forn1(i,m)
    {
        int t=pq.top(); pq.pop(); pq.push(t+1);
    }

    int max_tt=0;
    forn1(i,n)
    {
        max_tt=max(max_tt, pq.top());
        pq.pop();
    }

    cout << max_tt << " " << max_t+m <<endl;

	return 0;
}

