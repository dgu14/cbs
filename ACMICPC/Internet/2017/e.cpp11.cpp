#include <bits/stdc++.h>
using namespace std;

template <class T> using V=vector<T>;
using ll=long long;
using dbl=double;
using ii=pair<ll,ll>;

#define forn(i,n)   for(int i=0;i<(int)n;i++)
#define forn1(i,n)  for(int i=1;i<=(int)n;i++)
#define rforn1(i,n) for(int i=(int)n;i>=1;i--)
#define rforn(i,n)  for(int i=(int)n-1;i>=0;i--)
#define for1(i,p,q) for(int i=(int)p;i<=(int)q;i++)
ll const INF=(ll)1e18;
ll n,k,h,m;
ii wall[1005], hole[55], mouse[255];

ll c[500][500];
ll f[500][500];

ll const snk=0, tnk=1; ll const MODF1=2; ll const MODF2=300;

ll nf() {
    ll mf=0;
    while(true) {
        V<ll> parent(500, -1);
        queue<ll> q;

        q.push(snk);
        parent[snk]=snk;

        while(q.size())
        {
            ll here=q.front(); q.pop();

            for1(i,0,500)
            {
                if(parent[i]==-1 && c[here][i]-f[here][i]>0)
                {
                    q.push(i);
                    parent[i]=here;
                }
            }
        }

        if(parent[tnk]==-1) break;

        ll minf=INF;
        for(int p=tnk;p!=parent[p];p=parent[p])
        {
            minf=min(minf, c[parent[p]][p]-f[parent[p]][p]);
        }

        for(int p=tnk;p!=parent[p];p=parent[p])
        {
            f[parent[p]][p]+=minf;
            f[p][parent[p]]-=minf;
        }

        mf+=minf;
    }

    return mf;
}

ll ccw(ii a, ii b)
{
    ll r=a.first*b.second - a.second*b.first;
    if(r>0) return 1;
    else if(r<0) return -1;
    else return 0;
}

ll ccw(ii a, ii b, ii c)
{
    return ccw({b.first-a.first, b.second-a.second}, {c.first-a.first, c.second-a.second});
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k>>h>>m;

    forn(i,n) cin>>wall[i].first>>wall[i].second;
    forn(i,h) cin>>hole[i].first>>hole[i].second;
    forn(i,m) cin>>mouse[i].first>>mouse[i].second;

    forn(i,m)
    {
        forn(j,h)
        {
            c[MODF1+i][MODF2+j]=INF;
            forn(r,n)
            {
                int f=r, t=(r+1)%n;

                ll mh=ccw(mouse[i], hole[j], wall[f]) * ccw(mouse[i], hole[j], wall[t]);
                ll ww=ccw(wall[f], wall[t], mouse[i]) * ccw(wall[f], wall[t], hole[j]);

                if(mh<=0 && ww<=0)
                {
                    if(mh==0 && ww==0)
                    {
                        ii a=mouse[i], b=hole[j], c=wall[f], d=wall[t];
                        if(a>b) swap(a,b); if(c>d) swap(c,d);
                        if(c>b || a>d) continue;
                    }

                    // hole을 포함하는 벽인 경우에는
                    if(ww==0 && mh!=0) continue;
                    if(ww==0 && mh==0 && (hole[j]==wall[f] || hole[j]==wall[t])) continue;
                    c[MODF1+i][MODF2+j]=0; break;
                }
            }
        }
    }

    forn(i,m)
    {
        c[snk][MODF1+i]=1;
    }

    forn(i,h)
    {
        c[MODF2+i][tnk]=k;
    }

    if(nf()==m)
    {
        cout << "Possible" << endl;
    }
    else cout <<"Impossible" << endl;

    return 0;
}

/**

6 1 3 3
0 0
100 0
100 50
40 50
40 70
0 70
0 55
55 50
80 50
15 65
90 10
92 10

6 1 3 3
0 0
100 0
100 50
40 50
40 70
0 70
0 55
55 50
80 50
15 65
90 10
30 66

8 1 2 2
0 0
100 0
100 50
80 50
80 80
50 80
50 100
0 100
50 80
80 50
95 35
95 45

6 1 3 3
0 0
100 0
100 50
40 50
40 70
0 70
0 55
100 50
80 50
15 65
29 49
30 49
*/
