#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            cout << 1;
        else
            cout << 0;
    }
    system("pause");
    return 0;
}