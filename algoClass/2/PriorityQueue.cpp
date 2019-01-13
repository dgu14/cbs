// 2014004193_최범석
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF=(ll) 1e18;
ll n, m, a[100000];

void heapify(int k)
{
    if(2*k>n) return;

    if(2*k+1>n || a[2*k]>a[2*k+1])
    {
        if(a[2*k]>a[k])
        {
            swap(a[2*k], a[k]);
            heapify(2*k);
        }
    }
    else
    {
        if(a[2*k+1]>a[k])
        {
            swap(a[2*k+1], a[k]);
            heapify(2*k+1);
        }
    }
}

void build_max_heap()
{
    for(int i=n;i>=1;i--) heapify(i);
}

ll extract_max()
{
    swap(a[1], a[n]); n--;
    heapify(1);

    return a[n+1];
}

void heapify_up(int k)
{
    if(k==1) return;

    if(a[k]>a[k/2])
    {
        swap(a[k], a[k/2]);
        heapify_up(k/2);
    }
}

void heap_change_key(int k, int val)
{
    if(val>a[k])
    {
        a[k]=val;
        heapify_up(k);
    }
    else if(a[k]>val)
    {
        a[k]=val;
        heapify(k);
    }
}

void insert_key(int val)
{
    a[++n]=-INF;
    heap_change_key(n, val);
}

int main()
{
    cin.tie(0); cout.tie(0);

    int aa,bb,cc;
    vector<int> ret;
    while(true)
    {
        cin>>aa;

        if(aa==0)
        {
            for(int i=0;i<ret.size();i++)
            {
                cout << ret[i] << ' ';
            }
            cout << '\n';

            for(int i=1;i<=n;i++)
            {
                cout << a[i] << ' ';
            }
            cout << '\n';

            break;
        }
        else if(aa==1)
        {
            cin>>bb; insert_key(bb);
        }
        else if(aa==2)
        {
            ret.push_back(extract_max());
        }
        else if(aa==3)
        {
            cin>>bb>>cc;
            heap_change_key(bb, cc);
        }
    }
    return 0;
}
