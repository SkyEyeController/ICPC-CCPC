#include <bits/stdc++.h>
using namespace std;
struct nexts // 邻接表
{
    int pos;
    int w;
};
int n, m, d, k; // 房间数，走廊数，总传染天数，初始感染者人数
struct node     // 最短路径队列维护
{
    long long dist;
    int pos;
    int infectday;
    bool operator<(const node &x) const
    {
        return x.dist < dist;
    }
};
vector<nexts> connects[300001];
priority_queue<node> q;
long long dist[300001];   // 最短路径
bool visited[300001];       // 最短路径
bool infectcheck[300001]; // 是否感染
int A[300001];            // 初始感染者位置
long long D[300001];      // 第i天传染力距离
int infectdays[300001];
void initdist()
{
    for (int i = 1; i <= 300001; i++)
    {
        dist[i] = 1e10;
    }
}
void initvisited()
{
    memset(visited, false, sizeof(visited));
}
void Dijkstra_queue(int start)
{
    dist[start] = 0;
    q.push((node){0, start});
    while (!q.empty())
    {
        int location = q.top().pos;
        q.pop();
        if (visited[location])
            continue;
        visited[location] = true;
        for (int i = 0; i < connects[location].size(); i++)
        {
            int v = connects[location][i].pos;
            int w = connects[location][i].w;
            if (dist[v] > dist[location] + w)
            {
                dist[v] = dist[location] + w;
                if (!visited[v])
                    q.push((node){dist[v], v});
            }
        }
    }
    return;
}
void Final_queue(int k)
{
    initdist();
    cin >> d;
    for (int i = 1; i <= d; i++)
        cin >> D[i];
    queue<node> q;
    for (int i = 1; i <= k; i++)
        q.push((node){0, A[i], 0});
    int start = 0;
    int infectday = 0;
    while (!q.empty()) // 存在一种可能，当某一天可感染成员队列为空（第i天无法感染任何人）
    {
        start = q.front().pos;
        infectday = q.front().infectday;
        q.pop();
        infectcheck[start] = true;
        infectdays[start] = infectday;
        if (infectday >= d)
            continue;
        initvisited();
        Dijkstra_queue(start);
        for (int i = 1; i <= n; i++)
        {
            if (!infectcheck[i] && D[infectday + 1] >= dist[i])
            {
                q.push({dist[i], i, infectday + 1});
                infectcheck[i] = true;
                infectdays[i] = infectday + 1;
            }
        }
        if (q.empty() && infectday < d - 1) 
        // 感染队列为空的原因有两种，一是第i天无法感染任何人，需要下一步if；二是天数已满，统计结束，直接跳出.
        // 而当第d-1天的感染者无法感染任何人时，直接跳出；否则要进行手动跨天。
        {
            for (int i = 1; i <= n; i++) // 如果不是第d-1天
            {
                if (!infectcheck[i] && D[infectday + 2] >= dist[i])
                {
                    q.push({dist[i], i, infectday + 2});
                    infectcheck[i] = true;
                    infectdays[i] = infectday + 2;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        connects[u].push_back((nexts){v, w});
        connects[v].push_back((nexts){u, w}); // 邻接表双向图
    }
    cin >> k;
    memset(infectdays, -1, sizeof(infectdays));
    for (int i = 1; i <= k; i++)
        cin >> A[i], infectdays[A[i]]++;
    Final_queue(k);
    for (int i = 1; i <= n; i++)
        cout << infectdays[i] << endl;
    system("pause");
    return 0;
}