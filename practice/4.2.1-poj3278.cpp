#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, k;
bool visit[maxn];
struct node
{
    int arrivepos;
    int times;
};
int bfs()
{
    queue<node> q;
    q.push({n, 0});
    while (!q.empty())
    {
        int location = q.front().arrivepos;
        int times = q.front().times;
        q.pop();
        if(location>=maxn)continue;//边界条件需要维护好
        if(visit[location])continue;//节点不重复访问来保证最小
        visit[location] = true;
        if (location == k)
            return times;
        q.push({location + 1, times + 1});
        q.push({location * 2, times + 1});
        q.push({location - 1, times + 1});
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(visit,0,sizeof(visit));
        cin >> n >> k;
        cout << bfs() << endl;
    }
    system("pause");
    return 0;
}