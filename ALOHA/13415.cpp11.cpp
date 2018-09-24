#include<bits/stdc++.h>
using namespace std;

template <class T, class Q> class duo {public: T x; Q y; bool operator<(duo<T,Q> const& rhs){ return (x==rhs.x?y<rhs.y:x<rhs.x); }};
template <class T, class Q, class U> class triple {public: T x; Q y; U z; bool operator<(triple<T,Q,U> const& rhs){ return (x==rhs.x?(y==rhs.y?z<rhs.z:y<rhs.y):x<rhs.x);}};
template <class T> using V=vector<T>;

using ll=long long;
using dbl=double;
using ii=duo<int,int>;
using lii=duo<ll,ll>;
using iii=triple<int,int,int>;
using liii=triple<ll,ll,ll>;
using dii=duo<dbl,dbl>;
using diii=triple<dbl,dbl,dbl>;

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

int n, arr[100005],k;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n; forn(i,n) cin>>arr[i];
    cin>>k;

    int a, b;

    stack<ii> stk;
    forn(i,k)
    {
        cin>>a>>b;

        while(stk.size())
        {
            if(stk.top().x>a)
            {
                break;
            }

            stk.pop();
        }

        if(stk.size() && stk.top().y==0);
        else stk.push({a, 0});

        while(stk.size())
        {
            if(stk.top().x>b)
            {
                break;
            }

            stk.pop();
        }

        if(stk.size() && stk.top().y==1);
        else stk.push({b,1});
    }

    V<ii> ff;
    V<int> ret, rem;

    while(stk.size())
    {
        ff.push_back(stk.top()); stk.pop();
    }

    reverse(ff.begin(), ff.end());

    int tt=ff[0].x;

    for(int i=1;i<=tt;i++)
    {
        rem.push_back(arr[i-1]);
    }

    sort(rem.begin(), rem.end());
    int cm=rem.size()-1, cn=0;


    for(int i=n;i>=tt+1;i--)
    {
        ret.push_back(arr[i-1]);
    }

    forn(i,ff.size())
    {
        int s=ff[i].x, e=(i==ff.size()-1?0:ff[i+1].x);

        bool isAcs=ff[i].y==0;
        if(isAcs)
        {
            for(int j=e+1;j<=s;j++)
            {
                ret.push_back(rem[cm--]);
            }
        }
        else
        {
            for(int j=e+1;j<=s;j++)
            {
                ret.push_back(rem[cn++]);
            }
        }
    }

    reverse(ret.begin(), ret.end());

    forn(i, ret.size())
    {
        cout << ret[i] << ' ';
    }
    cout << endl;

	return 0;
}

