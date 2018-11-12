#include<bits/stdc++.h>
using namespace std;
template <class T> using V=vector<T>;
using ll=long long;
using dbl=double;
using ii=pair<int,int>;
using lii=pair<ll,ll>;
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

ll n,m,a,b, ret;
ll xx1[100005], yy1[100005], xx2[100005], yy2[100005];

bool compare(lii a, lii b)
{
    if(a.second*b.first-a.first*b.second<0) return true;
    else return false;
}

bool equals(lii a, lii b)
{
    if(a.second*b.first==a.first*b.second) return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    V<lii> rasers;
    cin>>n;
    forn(i,n) cin>>xx1[i]>>yy1[i]>>xx2[i]>>yy2[i];
    cin>>m;
    forn(i,m)
    {
        cin>>a>>b;
        rasers.push_back({a, b});
    }

    sort(rasers.begin(), rasers.end(), compare);

    forn(i,n)
    {
        if(binary_search(rasers.begin(), rasers.end(), (lii){xx1[i], yy1[i]}, compare) ||
           binary_search(rasers.begin(), rasers.end(), (lii){xx2[i], yy2[i]}, compare)) continue;

        int startpnt=lower_bound(rasers.begin(), rasers.end(), (lii){xx1[i], yy1[i]}, compare)-rasers.begin();
        int endpnt=lower_bound(rasers.begin(), rasers.end(), (lii){xx2[i], yy2[i]}, compare)-rasers.begin();

        if(startpnt!=endpnt);
        else
        {
            ret++;
        }
    }

    cout << ret << endl;

	return 0;
}

