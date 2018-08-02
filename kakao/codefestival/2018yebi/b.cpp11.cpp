#include <bits/stdc++.h>
using namespace std;

class triple
{
public:
    int x,y,z;
};

using ii=pair<int,int>;
int n;
vector<triple> eq, gt, lt;

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


int btoi(char ch)
{
    string st = "ACFJMNRT";
    return st.find(ch);
}


int main()
{
    cin>>n;

    string str;
    for(int i=0;i<n;i++)
    {
        cin>>str;

        if(str[3] == '=') eq.push_back({btoi(str[0]), btoi(str[2]), str[4]-'0'});
        else if(str[3] == '>') gt.push_back({btoi(str[0]), btoi(str[2]), str[4]-'0'});
        else lt.push_back({btoi(str[0]), btoi(str[2]), str[4]-'0'});
    }

    vector<int> arr;
    for(int i=0;i<8;i++) arr.push_back(i);
    int cnt = 0;

    do
    {
        bool test = true;
        for(int i=0;i<eq.size();i++)
        {

            int s = find(arr.begin(), arr.end(), eq[i].x)-arr.begin();
            int e = find(arr.begin(), arr.end(), eq[i].y)-arr.begin();

            if(abs(s-e)-1 == eq[i].z);
            else test = false;
        }

        if(!test) continue;

        for(int i=0;i<gt.size();i++)
        {
            int s = find(arr.begin(), arr.end(), gt[i].x)-arr.begin();
            int e = find(arr.begin(), arr.end(), gt[i].y)-arr.begin();

            if(abs(s-e)-1 > gt[i].z);
            else test = false;
        }

        if(!test) continue;

        for(int i=0;i<lt.size();i++)
        {
            int s = find(arr.begin(), arr.end(), lt[i].x)-arr.begin();
            int e = find(arr.begin(), arr.end(), lt[i].y)-arr.begin();

            if(abs(s-e)-1 < lt[i].z);
            else test = false;
        }

        if(test) cnt ++;

    } while(next_permutation(arr));

    cout << cnt << endl;

    return 0;
}
