#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
using ii = pair<int ,int>;
int m,n;
string M[101];

vector<ii> pos[26];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool dfs(int x, int y, V<V<bool>>& visited, int go, int tc, char f, int c)
{
    for(int i=0;i<4;i++)
    {
        int cx = x+dx[i], cy = y+dy[i];

        while(cx >= 0 && cx < m && cy >= 0 && cy < n && (M[cx][cy] == '.' || M[cx][cy] == f))
        {
            if(M[cx][cy] == f) return true;

            int rx = cx, ry = cy;

            if(i==0||i==1)
            {
                while(rx >= 0 && rx < m && ry >= 0 && ry < n && (M[rx][ry]=='.' || M[rx][ry]==f))
                {
                    if(M[rx][ry]==f) return true;
                    rx = rx+dx[2]; ry = ry+dy[2];
                }

                rx=cx, ry=cy;
                while(rx >= 0 && rx < m && ry >= 0 && ry < n && (M[rx][ry]=='.' || M[rx][ry]==f))
                {
                    if(M[rx][ry]==f) return true;
                    rx = rx+dx[3]; ry = ry+dy[3];
                }
            }
            else
            {
                while(rx >= 0 && rx < m && ry >= 0 && ry < n && (M[rx][ry]=='.' || M[rx][ry]==f))
                {
                    if(M[rx][ry]==f) return true;
                    rx = rx+dx[0]; ry = ry+dy[0];
                }

                rx=cx,ry=cy;
                while(rx >= 0 && rx < m && ry >= 0 && ry < n && (M[rx][ry]=='.' || M[rx][ry]==f))
                {
                    if(M[rx][ry]==f) return true;
                    rx = rx+dx[1]; ry = ry+dy[1];
                }
            }

            cx = cx + dx[i];
            cy = cy + dy[i];
        }
    }

    return false;
}

int main()
{
    cin >> m >> n;
    for(int i=0;i<m;i++) cin >> M[i];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(M[i][j] >= 'A' && M[i][j] <= 'Z')
            {
                pos[M[i][j]-'A'].push_back({i, j});
            }
        }
    }

    string ret;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(!pos[j].size()) continue;

            V<V<bool>> visited(m, V<bool>(n, false));
            if(dfs(pos[j][0].first, pos[j][0].second, visited,  0, 0, 'A'+j, 0))
            {
                ret += 'A' + j;
                M[pos[j][0].first][pos[j][0].second] = '.';
                M[pos[j][1].first][pos[j][1].second] = '.';

                pos[j].pop_back();
                pos[j].pop_back();

                break;
            }
        }
    }

    for(int i=0;i<26;i++)
    {
        if(pos[i].size())
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << ret << endl;

    return 0;
}

/*
3 4
ACCA
....
BDDB
ABCD

*/
