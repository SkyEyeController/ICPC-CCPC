//TLE
/**/
#include<bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;//无序map哈希表，减少排序时间复杂度
struct node
{
    string a;
    string s;
};
bool check(node s)
{
    if (mp[s.a])
    {
        return true;
    }
    mp[s.a] = 1;
    return false;
}
void swap(string s, int a, int b, string &p)
{
    p = s;
    char c;
    c = p[a];
    p[a] = p[b];
    p[b] = c;
}
string ans = "123456780";
int a[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // d,u,r,l
char o[4] = {'d', 'u', 'r', 'l'};
node answq;
void bfs(node s)
{
    queue<node> q;
    q.push(s);
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        if (mp[top.a])
            continue;
        mp[top.a] = true;
        if (top.a == ans)
        {
            answq = top;
            return;
        };
        int pos = top.a.find('0');
        int x = pos / 3, y = pos % 3;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + a[i][0], ny = y + a[i][1];
            if (nx >= 0 && nx <= 2 && ny >= 0 && ny <= 2)
            {
                int npos = 3 * nx + ny;
                string p;
                swap(top.a, pos, npos, p);
                q.push((node){p, top.s + o[i]});
            }
        }
    }
    answq.s="unsolved";
    return;
}
int main()
{
    string s;
    char c;
    for (int i = 1; i <= 9; i++)
    {
        cin >> c;
        if (c == 'x')
            c = 48;
        s += c;
    }
    node st = {s, ""};
    bfs(st);
    cout<<answq.s<<endl;
    system("pause");
    return 0;
}