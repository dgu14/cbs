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

int n, m[1005][5];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    forn(i,n)
    {
        forn(j,5)
        {
            cin>>m[i][j];
        }
    }

    int cnt[1005]={0,};

    forn(i,n)
    {
        forn(j,n)
        {
            if(i==j) continue;

            forn(k,5)
            {
                if(m[i][k]==m[j][k])
                {
                    cnt[i]++;
                    break;
                }
            }
        }
    }

    int ret=-1, po=-1;
    forn(i,n)
    {
        if(cnt[i]>ret)
        {
            ret=cnt[i]; po=i;
        }
    }

    cout << po+1<<endl;

	return 0;
}

