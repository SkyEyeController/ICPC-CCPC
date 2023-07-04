#include <bits/stdc++.h>
using namespace std;
string s[501];
bool visited[501][501];
int n, m;
string mod = "esnuk";
typedef pair<int, int> p;
int dis[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
struct node
{
    p pos={0,0};
    int step=0;
    int manhaton=0;
    bool operator<(const node &x) const
    {
        return x.manhaton < manhaton;
    }
    node()
    {};
    node(p pos,int step)
    {
        this->pos=pos;
        this->step=step;
        this->manhaton=abs(pos.first-n)+abs(pos.second-m);
    };
};
void bfs()
{
    priority_queue<node> q;
    q.push(node({1, 1}, 1));
    if (s[1][0] != 's')
    {
        std::cout << "No" << endl;
        return;
    }
    while (!q.empty())
    {
        node top = q.top();
        q.pop();
        if (top.pos == p{n, m})
        {
            std::cout << "Yes" << endl;
            return;
        }
        if (visited[top.pos.first][top.pos.second])
            continue;
        visited[top.pos.first][top.pos.second] = 1;
        for (int i = 0; i < 4; i++)
        {
            node next({top.pos.first + dis[i][0], top.pos.second + dis[i][1]}, top.step + 1);
            if (next.pos.first >= 1 && next.pos.first <= n && next.pos.second >= 1 && next.pos.second <= m)
            {
                if (mod[next.step % 5] == s[next.pos.first][next.pos.second - 1])
                {
                    q.push(next);
                }
            }
        }
    }
    std::cout << "No" << endl;
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    bfs();
    system("pause");
    return 0;
}