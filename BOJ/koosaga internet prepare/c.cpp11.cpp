#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using dbl = double;
using ii = pair<int,int>;
using lii = pair<ll,ll>;
template <class T> using V = vector<T>;

#define INF                         (int)1e9
#define EPS                         1e-9
#define LONG_INF                    (1ll << 63 - 1ll)
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forn(i,n)                   for(int i=0;i<(int)n;i++)
#define forn1(i,n)                  for(int i=1;i<=(int)n;i++)
#define rforn(i,n)                  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n)                 for(int i=(int)n;i>=1;i--)

ll arr[100010][3];
bool check = true;

int main() {
    int n = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    if(n <= 3) {
        check = true;
    } else {
        ll x1 = arr[0][0], y1 = arr[0][1], z1 = arr[0][2];
        ll x2 = arr[1][0], y2 = arr[1][1], z2 = arr[1][2];
        ll x3, y3, z3;
        int j = 2;
        while(j < n) {
            x3 = arr[j][0], y3 = arr[j][1], z3 = arr[j][2];
            ll t1 = x2 - x1, t2 = y2 - y1, t3 = z2 - z1;
            ll k1 = x3 - x1, k2 = y3 - y1, k3 = z3 - z1;
            if(t1 * k2 == t2 * k1 && t2 * k3 == t3 * k2 && t1 * k3 == t3 * k1)
                j++;
            else
                break;
        }

        ll a = y1 * (z2 - z3) + y2 * (z3 - z1) + y3 * (z1 - z2);
        ll b = z1 * (x2 - x3) + z2 * (x3 - x1) + z3 * (x1 - x2);
        ll c = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
        ll d = x1 * (y2 * z3 - y3 * z2) + x2 * (y3 * z1 - y1 * z3) + x3 * (y1 * z2 - y2 * z1);

        for(int i = j; i < n; i++) {
            ll x = arr[i][0], y = arr[i][1], z = arr[i][2];
            if(a * x + b * y + c * z != d) {
                check = false;
                break;
            }
        }
    }

    if(check) {
        cout << "TAK" << '\n';
    } else {
        cout << "NIE" << '\n';
    }
}
