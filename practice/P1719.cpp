#include <bits/stdc++.h>
using namespace std;
int s[200][200];
int main()
{
    int n, m;
    cin >> n;
    m = n;
    int ans = -2147483647;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            for (int k = i ; k <= n; k++)
                for (int l = j; l <= m; l++)
                {
                    ans = max(ans, s[k][l] - s[i][l] - s[k][j] + s[i][j]);
                }
        }
    cout << ans << endl;
    system("pause");
    return 0;
}