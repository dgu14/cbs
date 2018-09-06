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

ll n, a[100005], b[100005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;

    ll t;
    priority_queue<ll> a,b;
    forn(i,n) cin>>t, a.push(t);
    forn(i,n) cin>>t, b.push(t);


    ll sa=0, sb=0;


    forn(i,2*n)
    {

        if(i%2==0)
        {
            // a
            if(!a.size()) b.pop();
            else if(!b.size()) sa+=a.top(), a.pop();
            else
            {
                ll ta=a.top(), tb=b.top();
                if(ta>=tb)
                {
                    sa+=ta; a.pop();
                }
                else b.pop();
            }
        }
        else
        {
            // a
            if(!b.size()) a.pop();
            else if(!a.size()) sb+=b.top(), b.pop();
            else{
                ll ta=a.top(), tb=b.top();
                if(tb>=ta)
                {
                    sb+=tb; b.pop();
                }
                else a.pop();
            }
        }
    }

    cout << sa-sb << endl;


	return 0;
}

