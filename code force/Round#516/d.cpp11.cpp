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

int n,m,r,c,x,y;
string board[2005];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>r>>c>>x>>y;
    forn(i,n) cin>>board[i];
    r--;c--;

    priority_queue<ii, V<ii>, greater<ii>> pq;
    pq.push({0, r*m+c});
    V<int> dist1(2005*2005, 2*INF);

    while(pq.size())
    {
        ii here=pq.top(); pq.pop();
        if(dist1[here.second]<=here.first) continue;
        dist1[here.second]=here.first;

        int cx=here.second/m, cy=here.second%m;
        for(int i=0;i<4;i++)
        {
            if(cx+dx[i]>=0 && cx+dx[i]<n && cy+dy[i]>=0 && cy+dy[i]<m && board[cx+dx[i]][cy+dy[i]]=='.')
            {
                if(i==0)
                {
                    if(dist1[(cx+dx[i])*m+(cy+dy[i])]>here.first+1) pq.push({here.first+1, (cx+dx[i])*m+(cy+dy[i])});
                }
                else if(dist1[(cx+dx[i])*m+(cy+dy[i])]>here.first) pq.push({here.first, (cx+dx[i])*m+(cy+dy[i])});
            }
        }
    }

    pq.push({0, r*m+c});
    V<int> dist2(2005*2005, 2*INF);

    while(pq.size())
    {
        ii here=pq.top(); pq.pop();
        if(dist2[here.second]<=here.first) continue;
        dist2[here.second]=here.first;

        int cx=here.second/m, cy=here.second%m;
        for(int i=0;i<4;i++)
        {
            if(cx+dx[i]>=0 && cx+dx[i]<n && cy+dy[i]>=0 && cy+dy[i]<m && board[cx+dx[i]][cy+dy[i]]=='.')
            {
                if(i==1)
                {
                    if(dist2[(cx+dx[i])*m+(cy+dy[i])]>here.first+1) pq.push({here.first+1, (cx+dx[i])*m+(cy+dy[i])});
                }
                else if(dist2[(cx+dx[i])*m+(cy+dy[i])]>here.first) pq.push({here.first, (cx+dx[i])*m+(cy+dy[i])});
            }
        }
    }

    int ret=0;
    forn(i,n)
    {
        forn(j,m)
        {
            int d=j-c;
            if((dist1[i*m+j]<=y && dist1[i*m+j]-d<=x) || dist2[i*m+j]<=x && dist2[i*m+j]+d<=y)
            {
                ret++;
            }
        }
    }

    cout << ret << endl;

	return 0;
}
