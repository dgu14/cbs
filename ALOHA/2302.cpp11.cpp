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

int n,m,a[50];
int dp2[50];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    forn1(i,m) cin>>a[i];

    dp2[0]=1; dp2[1]=1; dp2[2]=2;
    forn1(i,n)
    {
        if(i==1 || i==2) continue;
        dp2[i]=dp2[i-1]+dp2[i-2];
    }

    int ret=1;
    int c=0, j=1;

    forn1(i,n)
    {
        if(i==a[j]) { ret*=dp2[c]; c=0; j++;}
        else c++;
    }

    ret*=dp2[c];
    cout << ret << endl;

	return 0;
}
