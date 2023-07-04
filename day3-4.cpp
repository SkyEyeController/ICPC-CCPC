#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 1;
int visited[MAXN];
int a[20];
int n, m, x;
bool tagt = 0;
void bfs()
{
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int location = q.front();
        q.pop();
        if (visited[x]==1)
        {
            tagt = 1;
            return;
        }
        if (location > x || visited[location]==1)
            continue;
        visited[location] = 1;
        for (int i = n; i >= 1; i--)
        {
            if (visited[location + a[i]] != -1)
                q.push(location + a[i]);
        }
    }
    return;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1, trap; i <= m; i++)
        cin >> trap, visited[trap] = -1;
    cin >> x;
    if (visited[x]==-1)
    {
        cout << "No" << endl;
        system("pause");
        return 0;
    }
    bfs();
    if(tagt)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    system("pause");
    return 0;
}