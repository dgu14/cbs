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

const int bktsz=500;
class triple
{
public:
    int x, y, z;

    bool operator<(triple rhs)
    {
        if(x/bktsz==rhs.x/bktsz) return y<rhs.y;
        return x/bktsz<rhs.x/bktsz;
    }
};

int n,q, arr[100005], a,b, mn;
triple qry[100005];

int cnt[200003], fre[100002], ans[100002];

void init()
{
    memset(cnt, 0, sizeof(cnt));
    memset(fre, 0, sizeof(fre));
    fre[0]=n;
}

void change(int val, int d)
{
    int&v=cnt[val+100000];

    fre[v]--;
    v+=d;

    fre[v]++;

    if(d==1) mn=max(mn, v);
    else if(v+1==mn && fre[v+1]==0) mn--;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(true)
    {
        cin>>n;
        if(n==0) break;

        cin>>q;
        forn(i,n) cin>>arr[i];

        forn(i,q)
        {
            cin>>a>>b;
            qry[i].x=a-1; qry[i].y=b-1; qry[i].z=i;
        }

        sort(qry, qry+q);

        mn=0;
        init();

        int pa=-1, pb=-1;
        forn(i,q)
        {
            a=qry[i].x, b=qry[i].y;

            if(b>pb)
            {
                for1(j, pb+1, b) change(arr[j], 1);
            }

            if(pa>a)
            {
                for1(j, a, pa-1) change(arr[j], 1);
            }

            if(pb>b)
            {
                for1(j, b+1, pb) change(arr[j], -1);
            }

            if(a>pa)
            {
                for1(j, pa, a-1) change(arr[j], -1);
            }

            pa=a, pb=b;
            ans[qry[i].z]=mn;
        }

        forn(i,q)
        {
            cout << ans[i] << '\n';
        }
    }

	return 0;
}

