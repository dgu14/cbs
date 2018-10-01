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

ll const MOD=987654321;
int dvs[1000001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin>>n;


    // 에라토스 테네스의 체를 이용
    // 2부터 n까지의 i를 가장 많이 쓰는것만 넣으면 됨.
    ll ret=1;
    for1(i,2,n)
    {
        if(dvs[i]) continue;

        ll f=i;
        while(f*i<=n) f*=i;

        for(int j=i;j<=n;j+=i)
        {
            dvs[j]=1;
        }

        ret=(ret*f)%MOD;
    }

    cout << ret << endl;
	return 0;
}
