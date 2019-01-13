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

int n, arr[100000], pos[100000];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    forn(i,100000) pos[i]=-1;

    cin>>n;
    forn(i,n) cin>>arr[i];

    forn(i,n)
    {
        pos[arr[i]]=i;

        if(pos[arr[i]+1]!=-1)
        {
            int a=arr[i];
            int b=arr[pos[arr[i]+1]];
            swap(arr[i], arr[pos[arr[i]+1]]);
            pos[a]=-1;
            pos[b]=-1;
        }
    }

    forn(i,n)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

	return 0;
}
