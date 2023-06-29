#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b,p,q;
int dp1[110][110],dp2[110][110];
#define mod 998244353
int quickpow(int a,int n)
{
    int e=1;
    while(n)
    {
        if(n&1)(e*=a)%=mod;
        (a*=a)%=mod;
        n>>=1;
    }
    return e;
}
signed main()
{
    cin>>n>>a>>b>>p>>q;
    dp1[a][0]=dp2[b][0]=1;//dp[i][j]表示走到i扔了j次筛子的概率
    int invp=quickpow(p,mod-2)%mod;
    int invq=quickpow(q,mod-2)%mod;
    for(int i=a;i<=n;i++)
    {
        for(int j=0;j<=i-a;j++)
        {
            for(int k=1;k<=p;k++)
            {
                (dp1[i+k>n? n:i+k][j+1]+=invp*dp1[i][j]%mod)%=mod;
            }
        }
    }
    for(int i=b;i<=n;i++)
    {
        for(int j=0;j<=i-b;j++)
        {
            for(int k=1;k<=q;k++)
            {
                (dp2[i+k>n? n:i+k][j+1]+=invq*dp2[i][j]%mod)%=mod;
            }
        }
    }
    /**/
    int ans=0;
    for(int j=0;j<=n-a;j++)
    {
        int pa=dp1[n][j]%mod;
        for(int i=b;i<=n;i++)
        {
            (ans+=pa*dp2[i][j]%mod)%=mod;
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
    



}