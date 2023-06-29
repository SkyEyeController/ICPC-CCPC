#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int a, b, c;
};
bool cmpa(node a, node b)
{
    return a.a < b.a;
}
bool cmpb(node a, node b)
{
    return a.b < b.b;
}
vector<node> ns;
int main()
{
    int n;
    cin >> n;
    for (int i = 1, u, v, w; i <= n; i++)
    {
        cin >> u >> v >> w;
        ns.push_back((node){u, v, w});
    }
    sort(ns.begin(), ns.end(), cmpb);
    for (int i = 0; i < n; i++)
    {
        ns[i].b = lower_bound(ns.begin(), ns.end(), ns[i].b) - ns.begin();
    }
    sort(ns.begin(), ns.end(), cmpa);
    for (int i = 0; i < n; i++)
    {
        ns[i].a = lower_bound(ns.begin(), ns.end(), ns[i].a) - ns.begin();
    }
}