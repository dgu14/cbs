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

void traverse(int i, int j, int mv, V<V<bool>>& vst, int min_a)
{
    vst[i][j]=true;
    if(mp[i][j]=='K' || mp[i][j]=='P') ck++;

    for(int k=0;k<8;k++)
    {
        int cx=i+dx[k], cy=j+dy[k];
        if(cx>=0 && cx<n && cy>=0 && cy<n && !vst[cx][cy] && val[cx][cy]>=min_a && val[cx][cy]<=min_a+mv)
        {
            traverse(cx, cy, mv, vst, min_a);
        }
    }
}

bool canGoEvery(int mv)
{
    forn(i,n)
    {
        forn(j,n)
        {
            ck=0;
            V<V<bool>> vst(55, V<bool>(55, false));
            traverse(i,j,mv,vst,val[i][j]);
            if(ck==totk+1) return true;
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

