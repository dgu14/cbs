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
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int tc, h,w;
string mp[105];
int dst[105][105][3];
void bfs(int a, int b, int idx)
{
    // 0-1 bfs

    deque<ii> dq;
    dst[a][b][idx]=0;
    dq.push_back({a,b});

    while(dq.size())
    {
        ii hr=dq.front(); dq.pop_front();

        forn(i,4)
        {
            int x=hr.first+dx[i], y=hr.second+dy[i];

            if(x>=0 && x<h && y>=0 && y<w && dst[x][y][idx]==INF)
            {
                if(mp[x][y]=='.' || mp[x][y]=='$')
                {
                    dst[x][y][idx]=dst[hr.first][hr.second][idx];
                    dq.push_front({x,y});
                }
                else if(mp[x][y]=='#')
                {
                    dst[x][y][idx]=dst[hr.first][hr.second][idx]+1;
                    dq.push_back({x,y});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>tc;

    while(tc--)
    {
        forn(i,105) mp[i].clear();
        cin>>h>>w;
        forn1(i,h)
        {
            cin>>mp[i];
            mp[i]="."+mp[i]+".";
        }

        h+=2; w+=2;

        forn(i,w)
        {
            mp[0]+='.';
            mp[h-1]+='.';
        }

        // deque

        forn(i,105) forn(j,105) forn(k,3) dst[i][j][k]=INF;
        bfs(0,0,0);
        int cnt=1;
        forn(i,h) forn(j,w) if(mp[i][j]=='$') bfs(i,j,cnt++);

        int m_t=INF;
        forn(i,h)
        {
            forn(j,w)
            {
                if(dst[i][j][0]!=INF && dst[i][j][1]!=INF && dst[i][j][2]!=INF)
                m_t=min(m_t, dst[i][j][0]+dst[i][j][1]+dst[i][j][2]-(mp[i][j]=='#'?2:0));
            }
        }

        cout << m_t << '\n';
    }

	return 0;
}

