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

int n,m, mat1[55][55], mat2[55][55], ret;
string a;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;

    forn(i,n)
    {
        cin>>a;

        forn(j,m)
        {
            mat1[i][j]=a[j]-'0';
        }
    }

    forn(i,n)
    {
        cin>>a;

        forn(j,m)
        {
            mat2[i][j]=a[j]-'0';
            if(mat1[i][j]!=mat2[i][j])
            {
                mat2[i][j]=1;
            }
            else mat2[i][j]=0;
        }
    }

    forn(i,n)
    {
        forn(j,m)
        {
            if(i+2<n && j+2<m && mat2[i][j]==1)
            {
                forn(k,3)
                {
                    forn(q,3)
                    {
                        mat2[i+k][j+q]=!mat2[i+k][j+q];
                    }
                }

                ret++;
            }
        }
    }

    forn(i,n)
    {
        forn(j,m)
        {
            if(mat2[i][j]==1)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }


    cout << ret << endl;

	return 0;
}

