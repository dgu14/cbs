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


/**
    lca functions
*/

void dfs(int src, V<V<int>>& adj, V<int>& depth, V<bool>& vst)
{
    if(src==0) depth[0]=0;
    for(int there:adj[src]) depth[there]=depth[src]+1, dfs(there, adj, depth, vst);
}

int lca(int a, int b, V<int>& depth, V<V<int>>& p)
{
    if(depth[b]>depth[a]) swap(a,b);

    // equalize the depth a to b
    rforn(i,20)
    {
        if(p[a][i]!=-1 && depth[p[a][i]] >= depth[b]) a=p[a][i];
    }

    if(a==b) return a;

    // find the lca of the same depth node a, b;

    rforn(i,20)
    {
        if(p[a][i]!=-1 && p[b][i]!=-1 && p[a][i]!=p[b][i]) a=p[a][i], b=p[b][i];
    }

    return p[a][0];
}


/**
    graph precalculation
*/


// weight calc

int dfs2(int src, V<V<int>>& adj, V<int>& weight)
{
    int ret=1;
    for(int there:adj[src]) ret+=dfs2(there, adj, weight);
    return weight[src]=ret;
}


void dfs3(int src, V<V<int>>& adj, V<int>& heavyIdx, V<V<int>>& hld, V<V<int>>& p, V<int>& weight)
{
    int prnt=p[src][0];

    if(heavyIdx[src]!=-1)
    {
        int idx=heavyIdx[src];
        hld[idx].push_back(src);
    }
    else
    {
        hld.push_back(V<int> (1, src));
        heavyIdx[src]=hld.size()-1;
    }

    for(int there:adj[src])
    {
        if(weight[there]*2>=weight[src]) heavyIdx[there]=heavyIdx[src];
        dfs3(there, adj, heavyIdx, hld, p, weight);
    }
}


/**
    find nth in a heavy path.
*/
int getNth(int a, V<int>& hld, V<int>& depth)
{
    int b=hld[0];

    return depth[a]-depth[b];
}



/**
    segment tree
*/


int initialize(V<int>& st, V<int>& arr, int lo, int hi, int nd)
{
    if(lo==hi)
    {
        if(lo==0 && arr[lo]==0) return st[nd]=0;
        else return st[nd]=1;
    }

    int mid=(lo+hi)>>1;
    return st[nd]=max(initialize(st, arr, lo, mid, 2*nd), initialize(st, arr, mid+1, hi, 2*nd+1));
}

void init(V<int>& st, V<int>& arr)
{
    int n=arr.size();
    st.resize(4*n);

    initialize(st, arr, 0, n-1, 1);
}

int qseg(V<int>& st, int lo, int hi, int pl, int pr, int nd)
{
    if(lo>pr||hi<pl) return 0;
    if(lo>=pl && hi<=pr) return st[nd];

    int mid=(lo+hi)>>1;
    return max(qseg(st, lo, mid,pl,pr, 2*nd), qseg(st, mid+1, hi, pl, pr, 2*nd+1));
}

int useg(V<int>& st, int lo, int hi, int idx, int val, int nd)
{
    if(lo==hi) return st[nd]=val;

    int mid=(lo+hi)>>1;

    if(idx<=mid) return st[nd]=max(st[2*nd+1], useg(st, lo, mid, idx, val, 2*nd));
    else return st[nd]=max(st[2*nd], useg(st, mid+1, hi, idx, val, 2*nd+1));
}



int query(int a, int b, V<int>& heavyIdx, V<V<int>>& hld, V<int> st[], V<V<int>>& p, V<int>& depth)
{
    int ahidx=heavyIdx[a], bhidx=heavyIdx[b], m_val=0;
    if(ahidx==bhidx)
    {
       int aidx=getNth(a,hld[ahidx], depth)+1, bidx=getNth(b, hld[ahidx], depth);
       if(aidx>bidx) return 0;
       return qseg(st[ahidx], 0, hld[ahidx].size()-1, aidx, bidx, 1);
    }

    int k=hld[bhidx][0];
    m_val=qseg(st[bhidx], 0, hld[bhidx].size()-1, 0, getNth(b, hld[bhidx], depth), 1);
    return m_val=max(m_val, query(a, p[k][0], heavyIdx, hld, st, p, depth));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifdef test
        ofstream fout("a.out");
        ifstream fin("a.in");
    #else
        int tt;
        cin>>tt;

        while(tt--)
        {
            int n,m;
            cin>>n;
            V<V<int>> adj(50005), p(50005, V<int>(20, 0)); V<int> depth(50005, 0);
            forn(i,n) { cin>>p[i][0]; if(p[i][0]!=-1) adj[p[i][0]].push_back(i); };
            cin>>m;

            V<bool> vst(50005, false);
            dfs(0, adj, depth, vst);

            forn1(i, 19)
            {
                forn(j,n)
                {
                    if(p[j][i-1]==-1) p[j][i]=-1;
                    else p[j][i]=p[p[j][i-1]][i-1];
                }
            }

            int cidx=0;
            V<int> heavyIdx(50005,-1), weight(50005,0);
            V<V<int>> hld;

            dfs2(0, adj, weight); // weight
            dfs3(0, adj, heavyIdx, hld, p, weight); // hld

            // seg tree
            V<int> st[50005];
            forn(i, hld.size()) init(st[i], hld[i]);


            // query , update
            string cmd;
            int qa, qb, qc, ret=0;
            while(m--)
            {
                cin>>cmd;

                if(cmd=="update")
                {
                    cin>>qa>>qb>>qc;

                    if(depth[qb]>depth[qa]) swap(qa,qb);
                    int qidx=heavyIdx[qa];
                    useg(st[qidx], 0, hld[qidx].size()-1, getNth(qa,hld[qidx], depth), qc, 1);
                }
                else
                {
                    cin>>qa>>qb;

                    int qt=lca(qa,qb,depth,p);
                    // qt-qa // qt-qb
                    int m_val=max(query(qt,qa,heavyIdx,hld,st,p, depth),
                                   query(qt,qb,heavyIdx,hld,st,p, depth));
                    ret^=m_val;
                }
            }

            cout << ret << '\n';
        }

    #endif

	return 0;
}
