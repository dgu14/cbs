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

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, a[200]={0,};
    cin>>n;
    V<int> arr(n);


    forn(i,n)
    {
        cin>>arr[i];
        a[arr[i]]++;
    }


    int q=0, mp=-1, qp=-1;

    forn1(i, 100)
    {
        if(a[i]==1) q++;

        else if(a[i]>=3 && mp==-1)
        {
            mp=i;
        }
    }

    if(q%2==1 && mp==-1)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    if(q%2==1) q++;
    else mp=-1;

    bool mpused=true;
    char mpcc;
    if(mp!=-1) mpused=false;

    char cchar='A';

    forn(i,n)
    {
        if(a[arr[i]]==1 || (!mpused && arr[i]==mp))
        {
            cout << cchar;
            if(arr[i]==mp) mpcc=cchar, mpused=true;

            if(cchar=='A') cchar='B';
            else cchar='A';
        }
        else
        {
            if(arr[i]==mp)
            {
                if(mpcc=='A') cout << 'B';
                else cout << 'A';
            }
            else cout << 'A';
        }
    }

	return 0;
}
