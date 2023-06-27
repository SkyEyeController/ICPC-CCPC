#include <bits/stdc++.h>
using namespace std;
int a[40][40], b[40][40], c[40][40], anss[40][40];
int ax, ay, bx, by, cx, cy;
int main()
{
    string s;
    cin >> ax >> ay;
    for (int i = 1; i <= ax; i++)
    {

        cin >> s;
        for (int j = 0; j < s.size(); j++)
            a[i][j + 1] = (s[j] == '#');
    }
    cin >> bx >> by;
    for (int i = 1; i <= bx; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            b[i][j + 1] = (s[j] == '#');
    }

    cin >> cx >> cy;
    for (int i = 1; i <= cx; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            c[10 + i][11 + j] = (s[j] == '#');
    }
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= 20; j++)
            for (int m = 1; m <= 20; m++)
                for (int k = 1; k <= 20; k++)
                {
                    bool tag = 1;
                    memset(anss, 0, sizeof(anss));
                    for (int i_ = 1; i_ <= ax; i_++)
                        for (int j_ = 1; j_ <= ay; j_++)
                        {
                            if (a[i_][j_])
                                anss[i_ - 1 + i][j_ - 1 + j] = 1;
                        }
                    for (int i_ = 1; i_ <= bx; i_++)
                        for (int j_ = 1; j_ <= by; j_++)
                        {
                            if (b[i_][j_])
                                anss[i_ - 1 + m][j_ - 1 + k] = 1;
                        }
                    for (int x = 1; x <= 30; x++)
                        for (int y = 1; y <= 30; y++)
                        {
                            if (anss[x][y] != c[x][y])
                                tag = 0;
                        }
                    if (tag)
                    {
                        cout << "Yes" << endl;
                        system("pause");
                        return 0;
                    }
                }
    cout << "No" << endl;
    system("pause");
    return 0;
}