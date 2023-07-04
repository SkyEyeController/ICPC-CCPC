#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int n0,m0;
vector<int> connects[200001];
bool visited[200001];
int color[2];
int res[200001];
typedef pair<int, int> p;
set<p>s;
vector<p> ans;
void bfs(int i)
{
    s.clear();
    queue<int> q;
    q.push(i);
    bool tag=0;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        if(visited[top])continue;
        visited[top]=true;
        color[res[top]]++;
        for(int i=0;i<connects[top].size();i++)
        {
            int next=connects[top][i];
            if(next<=top)s.insert({next,top});
            else s.insert({top,next});
            if(!visited[next])
            {
                res[next]=(res[top]+1)%2;
                q.push(next);
            }
            else
            {
                if(res[next]==res[top])tag=1,cout<<"0"<<endl,exit(0);
            }
        }
    }
    if(tag)color[0]=color[1]=0;
    else m0+=s.size();
    return;
}
signed main()
{
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        connects[u].push_back(v);
        connects[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])continue;
        memset(color,0,sizeof(color));
        bfs(i);
        n0+=(color[0]+color[1]);
        ans.push_back({color[0], color[1]});
    }
    int answ=0;
    for(int i=0;i<ans.size();i++)
    {
        answ+=(ans[i].first*ans[i].second)+(ans[i].first+ans[i].second)*(n0-(ans[i].first+ans[i].second));
        n0-=ans[i].first+ans[i].second;
    }
    cout<<answ-m0<<endl;
    system("pause");
    return 0;
}