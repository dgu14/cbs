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

int n,m;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;

    string order; int a,b;
    priority_queue<ii, V<ii>, greater<ii>> pq;

    V<ii> arr;
    forn(i,n)
    {
        cin>>order;

        if(order=="order")
        {
            cin>>a>>b;
            arr.push_back({b,a});

            for(int i=0;i<arr.size();i++)
            {
                cout << arr[i].second << ' ';
            }
            cout << '\n';
        }
        else if(order=="sort")
        {
            sort(arr.begin(), arr.end());

            if(arr.size()==0)
            {
                cout << "sleep" << '\n';
                continue;
            }

            for(int i=0;i<arr.size();i++)
            {
                cout << arr[i].second << ' ';
            }
            cout << '\n';
        }
        else if(order=="complete")
        {
            cin>>a;
            int p;
            forn(i, arr.size())
            {
                if(arr[i].second==a) p=i;
            }
            arr.erase(arr.begin()+p);

            if(arr.size()==0)
            {
                cout << "sleep" << '\n';
                continue;
            }

            for(int i=0;i<arr.size();i++)
            {
                cout << arr[i].second << ' ';
            }
            cout << '\n';
        }
    }
	return 0;
}

