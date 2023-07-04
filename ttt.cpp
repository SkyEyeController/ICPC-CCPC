#include <bits/stdc++.h>
using namespace std;
struct node
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
int main()
{
	vector<node> ns;
	vector<int> height,width;
    int n;
    cin >> n;
    for (int i = 1, u, v, w; i <= n; i++)
    {
        cin >> u >> v >> w;
        ns.push_back((node){u, v, w});
		height.push_back(u);
		width.push_back(v);
    }
    sort(ns.begin(), ns.end(), cmpa);
	sort(height.begin(),height.end());
	int t1=unique(height.begin(),height.end())-height.begin();
    for (int i = 0; i < n; i++)
    {
        ns[i].a = lower_bound( height.begin(),  height.begin()+t1,  ns[i].a) -  height.begin()+1;
    }
    sort(ns.begin(), ns.end(), cmpb);
	sort(width.begin(),width.end());
	int t2=unique(width.begin(),width.end())-width.begin();
    for (int i = 0; i < n; i++)
    {
        ns[i].b = lower_bound(width.begin(), width.begin()+t2, ns[i].b) - width.begin()+1;
    }
	int p=1;
	system("pause");
	return 0;
}