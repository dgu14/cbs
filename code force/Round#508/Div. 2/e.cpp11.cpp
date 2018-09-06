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
   public: ll c1,v,c2;
};
ll n;
triple cvc[105];

const ll s=0, t=9, mdf=10;

ll c[120][120], f[120][120], mr;

ll nf(int src, int sink)
{
    ll ret=0;
    while(true)
    {
        V<int> parent(120, -1);
        parent[src]=src;
        queue<int> q;

        q.push(src);

        while(q.size() && parent[sink] == -1){
            int h = q.front(); q.pop();

            for(int i=0;i<mdf+n;i++)
            {
                if(parent[i]==-1 && c[h][i]-f[h][i]>0)
                {
                    q.push(i);
                    parent[i]=h;

                    if(i==sink) break;
                }
            }
        }

        if(parent[sink] == -1){
            break;
        }

        ll amount=LONG_INF;

        for(int p=sink;p!=parent[p];p=parent[p]) amount=min(c[parent[p]][p]-f[parent[p]][p], amount);
        for(int p = sink;p != parent[p];p = parent[p]){
            f[parent[p]][p] += amount;
            f[p][parent[p]] -= amount;
        }

        ret += amount;
    }

    return ret;
}

int main()
{
    cin>>n;
    forn(i,n) cin>>cvc[i].c1>>cvc[i].v>>cvc[i].c2;

    forn1(i,4)
    {
        c[s][i]=LONG_INF;
    }

    forn(i,n)
    {
        c[cvc[i].c1][i+mdf]=cvc[i].v;
        c[i+mdf][cvc[i].c2]=cvc[i].v;

        c[cvc[i].c2][i+mdf]=cvc[i].v;
        c[i+mdf][cvc[i].c1]=cvc[i].v;

        c[i+mdf][t]=LONG_INF;
    }

    forn(i,n)
    {
        mr=max(mr, nf(s, i+mdf));
    }

    cout << mr << endl;


	return 0;
}

