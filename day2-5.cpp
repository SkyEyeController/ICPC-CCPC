/*#include<bits/stdc++.h>
using namespace std;
long long n,k,a[11];
set<long long> s,q;
int main()
{
    #define int long long
    cin>>n;
    cin>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    while(q.size()<=k)
    {
        int top=*s.begin();
        s.erase(top);
        q.insert(top);
        for(int i=1;i<=n;i++)
        s.insert(top+a[i]);
    }
    for(int i=1;i<k;i++)
    {
        q.erase(*q.begin());
    }
    cout<<*q.begin()<<endl;
    system("pause");
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
map<long long,bool>m;
typedef long long ll;
ll a[11];
ll bfs(ll *a,int n,int k)
{
    priority_queue<ll,vector<ll>,greater<ll>>q;
    int ans=0;
    q.push(0);
    while(!q.empty())
    {
        ll top=q.top();
        if(ans==k)
        {
            return q.top();
        }
        q.pop();
        ans++;
        //一开始将标签m=true放到了这里，不行，因为广搜的时候就可能有相同的数都压入了小顶堆
        for(int i=1;i<=n;i++)
        {
            ll next=top+a[i];
            if(m[next])continue;
            q.push(next);
            m[next]=true;//找了半天错，写成了top
        }
    }
    return 0;
}
signed main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<bfs(a,n,k)<<endl;
    system("pause");
    return 0;
}