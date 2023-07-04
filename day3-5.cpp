#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef pair<P,int> PP;
bool tag[2001];
bool visited[2001][2001];
vector<int> connects[2001];
int n, m;
void init()
{
    memset(visited, 0, sizeof(visited));
    memset(tag, 0, sizeof(tag));
    for (int i = 1; i <= 2000; i++)
    {
        connects[i].clear();
    }
}
void bfs()
{
    queue<PP> q;
    q.push(PP(P(1,n),0));
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int step=q.front().second;
        q.pop();
        if (x == n && y == 1)
        {
            cout << step << endl;
            return;
        }
        if (visited[x][y])
            continue;
        visited[x][y] = true;
        int sx = connects[x].size(), sy = connects[y].size();
        for (int i = 0; i < sx; i++)
        {
            int poserx = connects[x][i];
            for (int j = 0; j < sy; j++)
            {
                int posery = connects[y][j];
                if (tag[poserx] != tag[posery])
                {
                    q.push(PP(P(poserx, posery),step+1));
                }
            }
        }
    }
    cout << "-1" << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        init();
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> tag[i];
        }
        for (int i = 1, u, v; i <= m; i++)
        {
            cin >> u >> v;
            connects[u].push_back(v);
            connects[v].push_back(u);
        }
        bfs();
    }
    system("pause");
    return 0;
}