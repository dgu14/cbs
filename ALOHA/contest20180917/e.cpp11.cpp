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
int n, val[55][55];
string mp[55];

int dx[]={-1, -1, -1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1, -1, 1, -1, 0, 1};

int ck=0,px,py,totk;
int min_a, max_a;
void traverse(int i, int j, int mv, V<V<bool>>& vst)
{

    int tn=min(min_a, val[i][j]);
    int tm=max(max_a, val[i][j]);

    if(tm-tn>mv) return;

    vst[i][j]=true;

    min_a=tn;
    max_a=tm;

    if(mp[i][j]=='K') ck++;

    for(int k=0;k<8;k++)
    {
        int cx=i+dx[k], cy=j+dy[k];
        if(cx>=0 && cx<n && cy>=0 && cy<n && !vst[cx][cy])
        {
            traverse(cx, cy, mv, vst);
        }
    }
}

bool canGoEvery(int mv)
{
    ck=0; min_a=(int)1e7; max_a=(int)-1e7;
    V<V<bool>> vst(55, V<bool>(55, false));

    traverse(px, py, mv,vst);
    if(ck==totk) return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    forn(i,n)
    {
        cin>>mp[i];
    }

    forn(i,n)
    {
        forn(j,n)
        {
            cin>>val[i][j];

            if(mp[i][j]=='P') px=i, py=j;
            if(mp[i][j]=='K') totk++;
        }
    }

    int lo=0; int hi=1000000;

    int mid, ret;

    while(lo<=hi)
    {
        mid=(lo+hi)>>1;

        if(canGoEvery(mid))
        {
            hi=mid-1;
            ret=mid;
        }
        else lo=mid+1;
    }

    cout << ret << endl;

	return 0;
}

