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

// a+bt == c+dt
// a-c=(d-b)t
// if(d-b==0 && a-c=0) g+=1;
// else if(a-c/d-b >=0) m[a-c/d-b]++;

/// a+bt == c+dt
/// a+bq == e+fq

/// c+dt-bt == e+fq-bq
/// c+(d-b)t == e+(f-b)q
int N, g;
int a[1000][1000], b[1000][1000];
map<double, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N;

    forn(i,N) forn(j,N) cin>>a[i][j];
    forn(i,N) forn(j,N) cin>>b[i][j];

    /// N=700 -> N^3


	return 0;
}

