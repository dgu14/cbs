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

int a, b,c;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>a>>b>>c;
    int min_t=INF;
    for(int i=a;i<=100;i++)
    {
        for(int j=b;j<=100;j++)
        {
            for(int k=c;k<=100;k++)
            {
                if(i<j+k && j<i+k && k<i+j)
                {
                    min_t=min(min_t, i+j+k-a-b-c);
                }
            }
        }
    }

    cout << min_t << endl;
	return 0;
}
