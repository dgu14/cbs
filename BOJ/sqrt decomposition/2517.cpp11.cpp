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

int n, arr[500050], bucket[40000], s=25000;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; forn1(i,n) cin>>arr[i];

    forn1(i,n)
    {
        // query

        int tot=0;
        forn1(j,arr[i]/40000)
        {
            tot+=bucket[j];
        }

        int s=tot;

        forn(j, arr[i]%40000)
        {
            tot+=bucket[j];
        }


        bucket[arr[i]%40000]++;
    }


	return 0;
}
