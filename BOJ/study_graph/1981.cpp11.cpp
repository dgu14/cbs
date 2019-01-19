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

int n, arr[105][105];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int vst[105][105];

void init()
{
    memset(vst, 0, sizeof(vst));
}

void dfs(int a, int b, int s, int d)
{
    vst[a][b]=1;

    forn(i,4)
    {
        if(a+dx[i]>=0 && a+dx[i]<n && b+dy[i]>=0 && b+dy[i]<n && !vst[a+dx[i]][b+dy[i]])
        {
            if(arr[a+dx[i]][b+dy[i]]>=s && arr[a+dx[i]][b+dy[i]]<s+d)
            {
                dfs(a+dx[i], b+dy[i], s, d);
            }
        }
    }
}

bool solve(int s, int d)
{
    init();
    if(arr[0][0]>=s && arr[0][0]<s+d)
    {
        dfs(0,0,s,d);
        if(vst[n-1][n-1])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n;

    forn(i,n)
    {
        forn(j,n)
        {
            cin>>arr[i][j];
        }
    }

    int m_ret=INF;

    forn(i,201)
    {
        int lo=0, hi=250, ret=INF,mid;
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;

            if(solve(i, mid))
            {
                hi=mid-1;
                ret=mid;
            }
            else lo=mid+1;
        }

        m_ret=min(m_ret, ret);
    }

    cout << m_ret-1 << endl;

	return 0;
}
