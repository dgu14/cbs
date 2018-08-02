#include <bits/stdc++.h>
using namespace std;

bool next_permutation(vector<int>& arr)
{
    int n = arr.size();
    int k = -1;
    for(int i=n-1;i>0;i--)
    {
        if(arr[i]>arr[i-1])
        {
            k=i-1;
            break;
        }
    }

    if(k == -1) return false;

    for(int i=n-1;i>0;i--)
    {
        if(arr[i] > arr[k])
        {
            swap(arr[i], arr[k]);
            reverse(arr.begin()+k+1, arr.end());

            break;
        }
    }

    return true;
}

int main()
{

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(4);

    do
    {
        for(int i=0;i<4;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

    } while(next_permutation(arr));



    return 0;
}
