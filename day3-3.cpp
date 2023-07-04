#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int t[11];
int ans = 0;
int check[11];
int n, m;//n个数，m个集合
void dfs(int p)
{
    bool tag=1;
    for(int i=1;i<=n;i++)
    {
        if(check[i]==0){tag=0;break;}
    }
    if(tag)ans++;
    if(p>=m)return;
    for(int i=p+1;i<=m;i++)
    {
        for(int j=1;j<=t[i];j++)
        {
            check[a[i][j]]++;
        }
        dfs(i);
        for(int j=1;j<=t[i];j++)
        {
            check[a[i][j]]--;
        }
    }
    return;
    
}
int main()
{

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> t[i];
        for (int j = 1; j <= t[i]; j++)
        {
            cin>>a[i][j];
        }
    }
    dfs(0);
    cout<<ans<<endl;
    system("pause");
    return 0;
}