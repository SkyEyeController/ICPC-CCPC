#include <bits/stdc++.h>
using namespace std;
int f[4001][21];
int cnt = 0;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            f[j][i] = ++cnt;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            cout << j << " " << j + (1 << i) - 1 << endl;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int k = log2(r - l + 1);
        cout << f[l][k] << ' ' << f[r - (1 << k) + 1][k] << endl;
    }
}