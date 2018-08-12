#include <bits/stdc++.h>
using namespace std;


int N, arr[1000005], a, b, c, sn=1000, bucket[1100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b;

            int s=0;
            while(true)
            {
                b-=bucket[s];
                if(b<=0)
                {
                    b+=bucket[s];
                    break;
                }
                s++;
            }

            int t=0;
            while(true)
            {
                b-=arr[s*sn+t];
                if(b<=0)
                {
                    break;
                }
                t++;
            }
            arr[s*sn+t] -= 1;
            bucket[s] -= 1;

            cout << s*sn+t << '\n';
        }
        else if(a==2)
        {
            cin>>b>>c;
            arr[b]+=c;
            bucket[b/sn]+=c;
        }
    }

    return 0;
}
