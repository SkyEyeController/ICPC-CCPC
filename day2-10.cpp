#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
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
vector<node> ns;
vector<ll> height, width;
vector<node> List[200005];//行邻接表优化矩阵
int n;
ll N[200005], M[200005]; // N行,M列
int t1,t2;//离散化后矩阵变为t1行t2列
multiset<ll,greater<ll>> U;//去重集合，自动排序
ll ans=0;
signed main()
{

    cin >> n;
    for (int i = 1, u, v, w; i <= n; i++)
    {
        cin >> u >> v >> w;
        ns.push_back((node){u, v, w});
        height.push_back(u);
        width.push_back(v);
    }
    sort(ns.begin(), ns.end(), cmpb);
    sort(width.begin(), width.end());
    t2 = unique(width.begin(), width.end()) - width.begin();
    for (int i = 0; i < n; i++)
    {
        ns[i].b = lower_bound(width.begin(), width.begin() + t2, ns[i].b) - width.begin() + 1;
        M[ns[i].b] += ns[i].c;//列和数组
    }
    sort(ns.begin(), ns.end(), cmpa);
    sort(height.begin(), height.end());
    t1 = unique(height.begin(), height.end()) - height.begin();
    for (int i = 0; i < n; i++)
    {
        ns[i].a = lower_bound(height.begin(), height.begin() + t1, ns[i].a) - height.begin() + 1;
        N[ns[i].a] += ns[i].c;//行和数组
        List[ns[i].a].push_back(ns[i]);//按行索引该行所有点的列序号以及权值
        //U.insert(M[ns[i].b]);//列和集合，降低访问复杂度，自动大小排序
    }
    for(int i=1;i<=t2;i++)
    U.insert(M[i]);//要命的问题，一开始是set可以直接向上面一样去重，但是如果不是set就要自己跑一边。
    //说白了，不需要老想着一个for把所有事情都干了，不嵌套的情况下基本数量级不会变化多少
    for(int i=1;i<=t1;i++)
    {
        int tmp=N[i];
        for(int j=0;j<List[i].size();j++)
        {
            int locationb=List[i][j].b;
            int w=List[i][j].c;
            U.erase(U.lower_bound(M[locationb]));//单纯erase会删掉所有的值，只需要删掉一个，用lower_bound
            //找到一个就行了
            U.insert(M[locationb]-w);
        }
        ans=max(ans,tmp+*U.begin());
        for(int j=0;j<List[i].size();j++)
        {
            int locationb=List[i][j].b;
            int w=List[i][j].c;
            U.erase(U.lower_bound(M[locationb]-w));
            //M[locationb]+=w;
            U.insert(M[locationb]);
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;

}