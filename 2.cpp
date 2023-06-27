#include <bits/stdc++.h>
using namespace std;
string s[1001];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==j)continue;
            string f = s[i] + s[j];
            reverse(f.begin(), f.end());
            if (f == s[i] + s[j])
            {
                cout << "Yes" << endl;
                system("pause");
                return 0;
            }
        }
    }
    cout << "No" << endl;
    system("pause");
    return 0;
}