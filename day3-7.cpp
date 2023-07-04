#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 300001
int n, m;
int b[maxn], c[maxn];
int max(int a, int b, int c)
{
    return max(a, max(b, c));
}
void mergemax(int i, int l, int r, int &ans, int &lt, int &rt) // 第i件物品
{
    if (l == r || ((lt == l) && (rt == r)))
    {
        return;
    }
    int mid = (l + r) >> 1;
    int lp = c[i] + b[l]; // 左侧人之后买的最高定价
    int rp = c[i] + b[r]; // 右侧人之后买的最高定价
    ans = max(ans, lp * (n - l + 1), rp * (n - r + 1));
    mergemax(i, l, mid, ans, l, r);
    mergemax(i, mid, r, ans, l, r);
    return;
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(b + 1, b + n + 1);
    cout << endl;
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];
        int ans = -1;
        int l = -1, r = -2;
        mergemax(i, 1, n, ans, l, r);
        cout << ans << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}