#include <bits/stdc++.h>
using namespace std;
typedef long long ull;
const ull MOD = 998244353;
ull as[10000001];
int main()
{
    int n, m;
    cin >> n >> m;
    ull ans = 1;
    as[1] = m - 1;
    for (int i = 2; i <= n; i++)
        as[i] = ((MOD + as[i - 1]) * (m - 1)) % MOD;
    if (n & 1)
        cout << (as[n] + MOD - (m - 1)) % MOD << endl;
    else
        cout << (as[n] + (m - 1) % MOD) % MOD << endl;

    system("pause");
    return 0;
}