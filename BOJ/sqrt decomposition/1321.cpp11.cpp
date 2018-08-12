#include <bits/stdc++.h>
using namespace std;

int N, M, arr[500005], sn, bucket[1000], a,b,c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    sn=sqrt(N);
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        bucket[i/sn]+=arr[i];
    }

    cin>>M;

    for(int i=0;i<M;i++)
    {
        cin >> a;
        if(a==1)
        {
            cin>>b>>c;
            bucket[(b-1)/sn]+=c;
            arr[b-1]+=c;
        }
        else if(a==2)
        {
            cin>>b;
            int g=0;

            while(true)
            {
                b -= bucket[g];
                if(b<=0)
                {
                    b+=bucket[g];
                    break;
                }
                g++;
            }

            int t=0;
            while(true)
            {
                b -= arr[g*sn+t];
                if(b<=0) break;
                t++;
            }

            cout << g*sn+t+1 << '\n';
        }
    }

    return 0;
}
