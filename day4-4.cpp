#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef struct node
{
    pair<int, int> uv;
    int w;
    bool operator<(const node &x) const
    {
        return x.w > w;
    }
} node;
#define maxn int(1e7)
int a[501];
int father[501];
int n, m;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
}
int getfather(int x)
{
    if (x == father[x])
        return x;
    else
        return getfather(father[x]);
}
#define mod m
int quickpow(int a, int n)
{
    int e = 1;
    while (n)
    {
        if (n & 1)
            (e *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return e;
}
int calc(int i, int j)
{
    return (quickpow(a[i], a[j]) % mod + quickpow(a[j], a[i]) % mod) % mod;
}
bool visited[501];
int kruskal(priority_queue<node> q)
{
    int ans = 0;
    while (!q.empty())
    {
        node x = q.top();
        q.pop();
        if(getfather(x.uv.first)!=getfather(x.uv.second))
        {
            father[getfather(x.uv.first)]=getfather(x.uv.second);
            ans+=x.w;
        }
    }
    return ans;
}
signed main()
{
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    priority_queue<node> q;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            q.push((node{pair<int, int>(i, j), calc(i, j)}));
        }
    cout<<kruskal(q)<<endl;
    system("pause");
    return 0;
}
