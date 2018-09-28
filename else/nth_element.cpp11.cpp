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

int part(int arr[], int p, int q)
{
    int l=p, r=p;

    while(r<q)
    {
       if(arr[r]<arr[q])
       {

           swap(arr[l], arr[r]);
           l++;
       }

       r++;
    }

    swap(arr[l],arr[q]);
    return l;
}

int select(int arr[], int p, int q, int i)
{
    if(p==q) return arr[p];

    int c=part(arr, p, q);


    if(c-p+1==i) return arr[c];

    if(c-p+1>i) return select(arr, p, c-1, i);
    else return select(arr, c+1, q, i-(c-p+1));
}

int n, k, arr[1000];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>k;

    forn(i,n) cin>>arr[i];

    cout << select(arr, 0, n-1, k) << endl;
	return 0;
}
