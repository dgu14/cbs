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

int n,k;
string a, ret;

void solve()
{
    int sz=0;
    int ff[500005];

    rforn(i,n)
    {
        if(sz<n-k)
        {
            ff[sz++]=a[i]-'0';
        }
        else
        {
            int fq=sz-1;
            int tmp=a[i]-'0';
            while(fq>=0 && tmp>=ff[fq])
            {
                swap(ff[fq], tmp);
                fq--;
            }
        }
    }

    rforn(i,sz)
    {
        cout << ff[i];
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k>>a;

    solve();

	return 0;
}

/*
6 2
436436
*/
