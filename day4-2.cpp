#include<bits/stdc++.h>
using namespace std;
string s[31];
int ans=0;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            int tag=0;
            for(int t=1;t<=m;t++)
            {
                if(s[i][t-1]=='o'||s[j][t-1]=='o')tag++;
            }
            if(tag==m)ans++;
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}