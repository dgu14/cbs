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

ll btoa(string b)
{
    ll ret=0;

    forn(i,b.size())
    {
        ret=2*ret+(b[i]-'0');
    }

    return ret;
}

string atob(ll a)
{
    string ret;
    while(a)
    {
        if(a&1) ret+='1';
        else ret+='0';

        a=a>>1;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string b1,b2;
    cin>>b1>>b2;

    ll a1, a2;
    a1=btoa(b1);
    a2=btoa(b2);

    cout << atob(a1*a2) << endl;

	return 0;
}

