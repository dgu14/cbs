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

int n, a[300000], cnvt[300000], t[300000], p[300000];
V<int> adj[300000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifdef test
        ofstream fout("a.out");
        ifstream fin("a.in");
    #else
        cin>>n;
        int pa,pb;
        forn(i, n-1)
        {
            cin>>pa>>pb;
            adj[pa].push_back(pb);
            adj[pb].push_back(pa);
        }

        forn1(i,n) cin>>a[i];

        queue<int> q;
        V<bool> vst(n+1, false);

        q.push(1);
        vst[1]=true;
        int r=0;

        while(q.size())
        {
            r++;
            int qsize=q.size();
            forn(i, qsize)
            {
                int here=q.front(); q.pop();
                cnvt[here]=r;
                for(int there:adj[here])
                {
                    if(!vst[there])
                    {
                        q.push(there);
                        vst[there]=true;
                        p[there]=here;
                    }
                }
            }
        }

        V<int> f(n+1,0);
        forn1(i,n)
        {
            f[i]=cnvt[a[i]];
        }

        forn1(i,n-1)
        {
            if(f[i+1]<f[i])
            {
                cout << "No" << endl;
                return 0;
            }
        }

        forn1(i,n)
        {
            t[a[i]]=i;
            if(i==1) continue;

            if(cnvt[a[i]]!=cnvt[a[i-1]]) continue;

            int pi=p[a[i]],pi1=p[a[i-1]];

            if(t[pi]<t[pi1])
            {
                cout << "No" << endl;
                return 0;
            }
        }

        cout << "Yes" << endl;
    #endif

	return 0;
}

/**
7
1 2
1 3
2 4
2 5
3 6
3 7
1 3 2 7 5 6 4
*/
