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

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, arr[1005];
    cin>>n; forn(i,n) cin>>arr[i];

    int cnt=0;
    int val[1005];
    V<int> ret;

    forn1(i,n)
    {
        cnt=0;
        bool test=true;
        forn(j,n)
        {
            if(cnt!=i)
            {
                val[cnt++]=arr[j]-(j==0?0:arr[j-1]);
            }
            else
            {
                if(arr[j]-arr[j-1]!=val[j%cnt])
                {
                    test=false; break;
                }
            }
        }

        if(test) ret.push_back(i);
    }

    cout << ret.size() << endl;
    forn(i, ret.size())
    {
        cout << ret[i] << ' ';
    }
    cout << endl;

	return 0;
}
