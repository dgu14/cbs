#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
string H, N;
int p[1000005];

int main()
{
    getline(cin, H);
    getline(cin, N);


    int h = H.size(), n = N.size();
    vector<int> f;

    int matched = 0;
    for(int i=1;i<n;i++)
    {
        while(matched != 0 && N[i] != N[matched]) matched = p[matched-1];

        if(N[i] == N[matched])
        {
            matched++;
        }

        p[i] = matched;
    }

    matched = 0;

    for(int i=0;i<h;i++)
    {
        while(matched != 0 && H[i] != N[matched]) matched = p[matched-1];

        if(H[i] == N[matched])
        {
            matched++;

            if(matched == n)
            {
                f.push_back(i-n+2);
            }
        }
    }


    cout << f.size() << endl;
    for(int i=0;i<f.size();i++)
    {
        cout << f[i] << '\n';
    }

    return 0;
}
