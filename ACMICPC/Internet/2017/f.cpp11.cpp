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


class vector2
{
public:
    double x, y;

    vector2(double x_, double y_): x(x_), y(y_) {}

    bool operator==(const vector2& rhs) const
    {
        return x==rhs.x && y==rhs.y;
    }

    bool operator<(const vector2& rhs) const
    {
        return x!=rhs.x?x<rhs.x:y<rhs.y;
    }

    vector2 operator+(const vector2& rhs) const
    {
        return vector2(x+rhs.x, y+rhs.y);
    }

    vector2 operator-(const vector2& rhs) const
    {
        return vector2(x-rhs.x, y-rhs.y);
    }

    vector2 operator*(double rhs) const
    {
        return vector2(x*rhs, y*rhs);
    }

    double cross(const vector2& rhs) const
    {
        return x*rhs.y-rhs.x*y;
    }
};

bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x)
{
    double det=(b-a).cross(d-c);
    if(fabs(det)<EPS) return false;

    x=a+(b-a)*((c-a).cross(d-c)/det);
    return true;
}

class stkElem
{
public:
    vector2 pnt;
    ll num;
};

class triple
{
public:
    ll x,y,z;
};

ll maxY, minY, n, m, dy;
triple ulx[100005]; dbl qry[100005];

bool compare(triple a, triple b)
{
    if(a.x-a.y==b.x-b.y) return a.y<b.y;
    return a.x-a.y>b.x-b.y;
}

bool intersect(ll i, ll j, vector2& x)
{
    vector2 a={ulx[i].x, maxY};
    vector2 b={ulx[i].y, minY};

    vector2 c={ulx[j].x, maxY};
    vector2 d={ulx[j].y, minY};

    return lineIntersection(a,b,c,d,x);
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>maxY>>minY>>n;
    forn(i,n) cin>>ulx[i].x>>ulx[i].y, ulx[i].z=i;
    cin>>m; forn(i,m) cin>>qry[i];

    dy=maxY-minY;
    sort(ulx, ulx+n, compare);

    stack<stkElem> stk;
    stk.push({{-LONG_INF, -LONG_INF}, 0});

    forn(i,n)
    {
        if(i==0) continue;

        while(stk.size())
        {
            stkElem t=stk.top();

            vector2 x(0,0);
            if(intersect(t.num, i,x))
            {
                if(t.pnt.y<x.y)
                {
                    stk.push({x, i});
                    break;
                }
                else stk.pop();
            }
            else break;
        }
    }

    vector<dbl> ret;
    vector<ll> nms;
    while(stk.size())
    {
        ret.push_back(stk.top().pnt.y);
        nms.push_back(stk.top().num);
        stk.pop();
    }

    reverse(ret.begin(), ret.end());
    reverse(nms.begin(), nms.end());

    forn(i,m)
    {
        ll pos=upper_bound(ret.begin(), ret.end(), qry[i])-ret.begin();
        cout << ulx[nms[pos-1]].z+1 << endl;
    }

	return 0;
}
