#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using dbl=double;
using ii=pair<int,int>;
using lii=pair<ll,ll>;
template <class T> using V=vector<T>;

#define INF                         (int)1e9
#define EPS                         1e-9
#define LONG_INF                    (1ll << 63 - 1ll)
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forn(i,n) 					for(int i=0;i<(int)n;i++)
#define forn1(i,n)					for(int i=1;i<=(int)n;i++)
#define rforn(i,n)                  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n)                 for(int i=(int)n;i>=1;i--)

/**
    cbs0615/ddolgu14
    AOJ BOJ CODEFORCE CODEGROUND
*/

class triple
{
public:
    int x,y,z;
};


int n, h[1005], bh[1005];
triple rcts[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>n;
    int mr=1, mh=0, sr=10000;
    forn(i,n) cin>>rcts[i].x>>rcts[i].y>>rcts[i].z, rcts[i].y--, mr=max(mr, rcts[i].y), mh=max(mh, rcts[i].z), sr=min(sr, rcts[i].x);

    forn1(i, 1000)
    {
        forn(j,n)
        {
            if(i>=rcts[j].x && i <= rcts[j].y)
            {
                h[i]=max(h[i], rcts[j].z);
            }
        }
    }

    int dy=0;
    int dx=0;

    forn(i, 1000)
    {
        bh[i]=h[i+1];
    }


    int c=0;

    forn(i, 1001)
    {
        if(bh[i] != 0) dx++;

        if(c!=bh[i]) dy+=abs(bh[i]-c);
        c=bh[i];
    }

    char ret[mh][mr];
    forn(i, mh)
    {
        forn(j, mr)
        {
            ret[i][j]='.';
        }
    }

    c=0;
    forn(i, mr)
    {

        if(bh[i+1]<bh[i])
        {
            for(int j=bh[i+1]-1;j<bh[i];j++) ret[j][i]='#';
        }

        if(c<bh[i])
        {
            for(int j=c-1;j<bh[i];j++) ret[j][i]='#';
        }

        ret[bh[i]-1][i]='#';
        c=bh[i];
    }

    cout <<dx + dy << '\n';
    rforn(i, mh)
    {
        for(int j=sr-1;j<mr;j++)
        {
            cout << ret[i][j];
        }
        cout << '\n';
    }

    forn(i, mr-sr+1) cout <<'*';
    cout << '\n';

	return 0;
}
