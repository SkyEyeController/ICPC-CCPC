#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b;
    for (int i = 0; i < n; i++)
    {
        char _a = a[i];
        char _b = b[i];
        bool tag = 0;
        for (char _c = 'a'; _c <= 'z'; _c++)
        {
            if (min(_a, _c) == _b)
            {
                tag = 1;
                c += _c;
                break;
            }
        }
        if (!tag)
        {
            cout << -1 << endl;
            system("pause");
            return 0;
        }
    }
    cout << c << endl;
    system("pause");
    return 0;
}