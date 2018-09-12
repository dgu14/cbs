#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using dbl=double;
using ii=pair<int,int>;
using lii=pair<ll,ll>;
template <class T> using V=vector<T>;

#define INF                         (int)1e9
#define EPS                         1e-9
#define LONG_INF                    (1ll << 63 - 1ll)
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forn(i,n) 					for(int i=0;i<(int)n;i++)
#define forn1(i,n)					for(int i=1;i<=(int)n;i++)
#define rforn(i,n)                  for(int i=(int)n-1;i>=0;i--)
#define rforn1(i,n)                 for(int i=(int)n;i>=1;i--)

/**
    cbs0615/ddolgu14
    AOJ BOJ CODEFORCE CODEGROUND
*/

int n,d;
string str;
const int MAX = 1000044;

string S;
int N, sa[MAX], pos[MAX];

struct SuffixNode{
    int sa;
    ii rank;
    bool operator <(const SuffixNode &O)const{ return rank < O.rank; }
};

void constructSA(){
    N = S.size();
    // node �迭�� �ʱ�ȭ: ó���� 0, 1��° ���ڵ�� rank�� �ű�
    SuffixNode node[MAX], nodeTemp[MAX];
    for(int i=0; i<N; i++){
        node[i].sa = i;
        node[i].rank = ii(S[i]-'a', i<N-1 ? S[i+1]-'a' : -1); // -1�� 1��° ���ڰ� ���� ����� ��
    }
    // ���� ����

    sort(node, node+N);

    // d=2���� 2�辿 �÷����� �Ź� �տ������� d*2�� ���ڵ鸸 ���� ����
    for(int d=2; d<N; d*=2){
        int M = 0, temp = node[0].rank.first;
        node[0].rank.first = pos[node[0].sa] = 0;

        // �ٷ� �� ���̻�� ��ũ ���� �ٸ� ������ �� ��ũ�� �ű�
        for(int i=1; i<N; i++){
            if(ii(temp, node[i-1].rank.second) == node[i].rank) node[i].rank.first = M;
            else{
                temp = node[i].rank.first;
                node[i].rank.first = ++M;
            }
            pos[node[i].sa] = i;
        }
        M++; // ���������� M�� �̹� �������� ������ ���� �ٸ� ��ũ�� ����

        // radix sort�� O(N)�� ����: ��ũ ���� M���� 2�ڸ� ���� ���� �����Ѵ�.
        int cnt[MAX+1] = {0};
        // ���� �� ��° ��ũ�� ������ ����
        for(int i=0; i<N; i++){
            int j = node[i].sa + d;
            // �� ��° ��ũ�� �ش� ���̻��� ���� ��ġ�κ��� d���� �� ���̻��� ��ũ
            node[i].rank.second = (j < N ? node[pos[j]].rank.first : -1);
            cnt[node[i].rank.second+1]++;
        }
        for(int i=1; i<M+1; i++)
            cnt[i] += cnt[i-1];
        for(int i=N-1; i>=0; i--)
            nodeTemp[--cnt[node[i].rank.second+1]] = node[i];

        // ù ��° ��ũ�� ������ ����
        fill(cnt, cnt+M+1, 0);
        for(int i=0; i<N; i++)
            cnt[nodeTemp[i].rank.first]++;
        for(int i=1; i<M; i++)
            cnt[i] += cnt[i-1];
        for(int i=N-1; i>=0; i--)
            node[--cnt[nodeTemp[i].rank.first]] = nodeTemp[i];
    }

    // ���� ���
    for(int i=0; i<N; i++){
        sa[i] = node[i].sa;
        pos[sa[i]] = i;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n; cin>>str;

    bool test=false;
    if(n==1) test=true;
    else
    {
        // suffix array
        S=str+str;
        constructSA();

        int p=0;
        forn(i,N)
        {
            if(pos[i]>=n) continue;
            p=pos[i];
            break;
        }

        if(p==0) test=true;
        else if(S.substr(p, n) == str) test=true;

    }

    if(test) cout << "Yes" << endl;
    else cout << "No" << endl;

	return 0;
}
