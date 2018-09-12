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

int n, a,b,c,dgr[4];
multiset<int> e[10];
map<ii, int> rm;

ii idx[]={{0,0},{0,1},{0,2},{0,3},{1,1},{1,2},{1,3},{2,2},{2,3},{3,3}};

void dfs(int src, V<int>& comp, V<bool>& vst)
{
    vst[src]=true;

    forn(i,10)
    {
        if(idx[i].first==src)
        {
            if(e[i].size() && !vst[idx[i].second]) comp[idx[i].second]=comp[src], dfs(idx[i].second, comp, vst);
        }

        if(idx[i].second==src)
        {
            if(e[i].size() && !vst[idx[i].first]) comp[idx[i].first]=comp[src], dfs(idx[i].first, comp, vst);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;

    forn(i,n)
    {
        cin>>a>>b>>c;
        a--;c--; if(a>c) swap(a,c);
        dgr[a]++; dgr[c]++;

        forn(j,10) if(a==idx[j].first && c==idx[j].second) { e[j].insert(b); break; }
    }

    int ret=0;
    forn(i, (1<<10))
    {
        rm.clear();

        forn(j,10)
        {
            if(i&(1<<j))
            {
                if(!e[j].size()) continue;

                dgr[idx[j].first]--; dgr[idx[j].second]--;
                rm[idx[j]]=*(e[j].begin());
                e[j].erase(e[j].begin());
            }
        }

        V<int> comp(4); V<bool> vst(4,false);
        forn(j, 4) comp[j]=j;


        forn(j,4) if(!vst[j]) dfs(j, comp,vst);

        int s[4]={0,}, od[4]={0,}, ev[4]={0,};

        forn(j,4)
        {
            if(dgr[j]%2==0) ev[comp[j]]++;
            else od[comp[j]]++;
        }

        forn(j,4)
        {
            if(od[j]==2 || od[j]==0);
            else s[j]=-999999999;
        }

        forn(j,10)
        {
            int k=comp[idx[j].first];
            for(auto it=e[j].begin();it!=e[j].end();it++) s[k]+=*it;
        }

        forn(j,4) ret=max(ret, s[j]);

        forn(j,10)
        {
            if(i&(1<<j))
            {
                if(!rm[idx[j]]) continue;
                dgr[idx[j].first]++; dgr[idx[j].second]++;
                e[j].insert(rm[idx[j]]);
            }
        }
    }

    cout << ret << endl;

	return 0;
}
