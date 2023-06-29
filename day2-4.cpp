#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull ans = 0;
void calc(ull a, ull b)
{
    if (b > a)
        calc(b, a);
    if (a == b)
    {
        cout << ans << endl;
        system("pause");
        exit(0);
    }
    ull p = (a / b);
    if (a % b == 0)
        p--;
    ans += p;
    calc(a - b * p, b);
}
int main()
{
    ull a, b;
    cin >> a >> b;
    calc(a, b);
    return 0;
}