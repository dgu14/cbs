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
int k,l;
map<string, int> mp;
string out[500050];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>k>>l;

    string str;
    forn1(i,l) { cin>>str; mp[str]=max(i, mp[str]); }

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        out[it->second]=it->first;
    }

    forn(i, 500001)
    {
        if(out[i]!=""){ cout << out[i] << '\n'; k--; if(k==0) break; }
    }

	return 0;
}
