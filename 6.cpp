#include <bits/stdc++.h>
using namespace std;
struct nexts//邻接表
{
    int pos;
    int w;
};
int n, m,d,k;//房间数，走廊数，总传染天数，初始感染者人数
struct node//最短路径队列维护
{
    long long dist;
    int pos;
    bool operator<(const node &x) const
    {
        return x.dist < dist;
    }
};
struct distn
{
    long long dist;
    int pos;
};
distn distf[300001];
vector<nexts> connects[300001];
priority_queue<node> q;
long long dist[300001];//最短路径
bool visit[300001];//最短路径
int A[300001];//初始感染者位置
long long D[300001];//第i天传染力距离
int infectdays[300001];
void initdist()
{
    for(int i=1;i<=300001;i++)
    {
        dist[i]=1e10;
    }
}
void initvisit()
{
    memset(visit,false,sizeof(visit));
}
void Dijkstra_queue(int start)
{
    dist[start]=0;
    q.push((node){0,start});
    while(!q.empty())
    {
        int location=q.top().pos;
        q.pop();
        if(visit[location])continue;
        visit[location]=true;
        for(int i=0;i<connects[location].size();i++)
        {
            int v=connects[location][i].pos;
            int w=connects[location][i].w;
            if(dist[v]>dist[location]+w)
            {
                dist[v]=dist[location]+w;
                if(!visit[v])q.push((node){dist[v],v});
            }
        }
    }
    return;
}
bool com(distn a,distn b)
{
    return a.dist<b.dist;
}
void Final_Dijkstra(int k)
{
    initdist();
    for(int i=1;i<=k;i++)
    {
        initvisit();
        Dijkstra_queue(A[i]);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        connects[u].push_back((nexts){v,w});
        connects[v].push_back((nexts){u,w});//邻接表双向图
    }
    cin>>k;
    memset(infectdays,-1,sizeof(infectdays));
    for(int i=1;i<=k;i++)cin>>A[i], infectdays[A[i]]++;
    Final_Dijkstra(k);
    for(int i=1;i<=n;i++)
    {
        distf[i]=(distn){dist[i],i};
    }
    sort(distf+1,distf+n+1,com);//标定感染距离从小到大，减少复杂度S
    cin>>d;
    int num=k+1;
    for(int i=1;i<=d;i++)
    {
        cin>>D[i];
        D[i]+=D[i-1];//前缀和，保证传染距离全部是从初始感染点算起，这样可以保证只需要一次Final_Dijkstra
        while(distf[num].dist<=D[i]&&num<=n)
        {
            infectdays[distf[num].pos]=i;
            num++;
        }

    }
    for(int i=1;i<=n;i++)
    {
        cout<<infectdays[i]<<endl;
    }
    system("pause");
    return 0;
}