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

int n,m,M[10][10], T[10][10];
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
int cnt, max_t;

void dfs(int x, int y, bool vst[][10])
{
    if(x==0 || y==0 || x==n+1 || y==m+1) return;
    vst[x][y]=true;
    T[x][y]=2;

    forn(i,4)
    {
        if(!vst[x+dx[i]][y+dy[i]] && M[x+dx[i]][y+dy[i]]!=1)
        {
            dfs(x+dx[i], y+dy[i], vst);
        }
    }
}

int getCnt()
{
    cnt=0;
    forn1(i,n)
    {
        forn1(j,m)
        {
            if(M[i][j]==0 && T[i][j]!=2) cnt++;
        }
    }

    return cnt;
}

bool posible(int k)
{
    return M[(k-1)/m+1][(k-1)%m+1]==0;
}

void check(int k)
{
    M[(k-1)/m+1][(k-1)%m+1]=1;
}

void uncheck(int k)
{
    M[(k-1)/m+1][(k-1)%m+1]=0;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;

    forn1(i,n) forn1(j,m) cin>>M[i][j];

    for1(i,1,n*m)
    {
        for1(j,i+1,n*m)
        {
            for1(k,j+1,n*m)
            {
                if(posible(i) && posible(j) && posible(k))
                {
                    check(i); check(j); check(k);

                    bool vst[10][10]={false, };
                    memset(T, 0, sizeof(T));

                    forn1(p,n)
                    {
                        forn1(q,m)
                        {
                            if(!vst[p][q] && M[p][q]==2) dfs(p, q, vst);
                        }
                    }

                    int ff=getCnt();
                    if(max_t<ff) {
                        max_t=ff;
                    }

                    uncheck(i); uncheck(j); uncheck(k);
                }
            }
        }
    }

    cout << max_t << endl;

	return 0;
}

