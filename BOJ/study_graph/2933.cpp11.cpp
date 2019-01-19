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
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int r,c, cnt;
string mp[105];
int n, arr[105];

int tmp[105][105], ptmp[105][105];
int cnode[10005], cncnt;

void dfs(int a, int b)
{
    ptmp[a][b]=cnt;

    forn(i,4)
    {
        int x=a+dx[i], y=b+dy[i];
        if(x>=0 && x<r && y>=0 && y<c && mp[x][y]=='x' && ptmp[x][y]==0)
        {
            dfs(x,y);
        }
    }
}

int showdown()
{
    bool test=false;

    forn(i,r)
    {
        forn(j,c)
        {
            if(cnode[ptmp[i][j]])
            {
                tmp[i][j]=ptmp[i][j];
            }
        }
    }

    forn(i,r)
    {
        forn(j,c)
        {
            if(i==0) continue;

            if(!cnode[ptmp[i-1][j]] && ptmp[i-1][j] && tmp[i][j])
            {
                cnode[ptmp[i-1][j]]=1;
                cncnt++;
                test=true;
            }
            else if(!cnode[ptmp[i-1][j]] && ptmp[i-1][j]) tmp[i][j]=ptmp[i-1][j];
        }
    }

    forn(i,c)
    {
        if(!cnode[ptmp[r-1][i]] && ptmp[r-1][i])
        {
            cnode[ptmp[r-1][i]]=1;
            cncnt++;
            test=true;
        }
    }

    if(test) return 0;
    else return 1;
}

void solve()
{
    memset(tmp,0,sizeof(tmp));
    memset(ptmp,0,sizeof(ptmp));
    cnt=0;

    forn(i,r)
    {
        forn(j,c)
        {
            if(ptmp[i][j]==0 && mp[i][j]=='x')
            {
                cnt++;
                dfs(i,j);
            }
        }
    }

    cncnt=0;
    memset(cnode, 0, sizeof(cnode));
    while(cncnt<cnt)
    {
        if(showdown())
        {
            memcpy(ptmp, tmp, sizeof(tmp));
        }

        memset(tmp,0,sizeof(tmp));
    }

    forn(i,r)
    {
        forn(j,c)
        {
            if(ptmp[i][j])
            {
                mp[i][j]='x';
            }
            else mp[i][j]='.';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>r>>c;

    forn(i,r)
    {
        cin>>mp[i];
    }

    cin>>n;

    int ff=0;
    forn(i,n)
    {
        cin>>arr[i];

        arr[i]=r-arr[i];

        if(ff)
        {
            rforn(j,c)
            {
                if(mp[arr[i]][j]=='x')
                {
                    mp[arr[i]][j]='.';
                    break;
                }
            }
        }
        else
        {
            forn(j,c)
            {
                if(mp[arr[i]][j]=='x')
                {
                    mp[arr[i]][j]='.';
                    break;
                }
            }
        }

        solve();
        ff=!ff;
    }

    forn(i,r)
    {
        cout << mp[i] << '\n';
    }

	return 0;
}
