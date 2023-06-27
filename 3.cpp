#include <bits/stdc++.h>
using namespace std;
int a[11][11], b[11][11], c[11][11], d[11][11], e[11][11];
int putin(int a[][11], int x, int y)
{
    int ans=0;
    for (int i = 1; i <= x; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            if(s[j] == '#')
            a[i][j + 1] = 1,ans++;
        }
    }
    return ans;
}
void setd()
{
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            d[i][j] = a[i][j];
        }
}
void sete()
{
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            e[i][j] = d[i][j];
        }
}
int ax, ay, bx, by, cx, cy;
int main()
{
    int ans=0,ans2=0;//计数
    cin >> ax >> ay;
    ans+=putin(a, ax, ay);
    cin >> bx >> by;
    ans+=putin(b, bx, by);
    cin >> cx >> cy;
    ans2+=putin(c, cx, cy);
    for (int I = 2 - 10; I <= 10; I++)
        for (int J = 2 - 10; J <= 10; J++) // 启动位置
        {
            int ans1 = ans;
            setd();
            for (int i = I, _i = 1; i < I + 10; i++, _i++) // 注意矩阵叠加问题，找了许久
                for (int j = J, _j = 1; j < J + 10; j++, _j++)
                {
                    if (i >= 1 && j >= 1 && i <= 10 && j <= 10)
                    {
                        d[i][j] += b[_i][_j];
                        if (d[i][j] > 1)
                        {
                            ans1--;
                            d[i][j] = 1;
                        }
                    }
                }

            for (int I_ = 2 - 10; I_ <= 10; I_++)
                for (int J_ = 2 - 10; J_ <= 10; J_++) // 比较矩阵启动位置
                {
                    bool tag = 1;
                    sete();
                    for (int i = I_, _i = 1; i < I_ + 10; i++, _i++)
                        for (int j = J_, _j = 1; j < J_ + 10; j++, _j++)
                        {
                            if (i >= 1 && j >= 1 && i <= 10 && j <= 10)
                            {
                                e[i][j] += c[_i][_j];
                            }
                        }
                    for (int i = 1; i <= 10; i++)
                        for (int j = 1; j <= 10; j++)
                        {
                            if (e[i][j] != 2 * d[i][j])
                            {
                                tag = 0;
                                break;
                            }
                        }
                    if (tag&&ans1==ans2)
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