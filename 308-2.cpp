#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> check;
unordered_map<string, int> mp;
string a[101], b[101];
int u;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i],check[a[i]]=0;
    for (int i = 1; i <= m; i++)
        cin >> b[i],check[b[i]]=1;
        cin>>u;
    for(int i=1;i<=m;i++)
    {
        int p;cin>>p;mp[b[i]]=p;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!check[a[i]])ans+=u;
        else ans+=mp[a[i]];
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}