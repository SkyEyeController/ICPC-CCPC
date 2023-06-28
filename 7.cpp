#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x7fffffffffffff;
ll a[5001],b[5001],sum,ave,rem;
ll dp[5001][5001];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    ave=sum/n;
    if(ave<=0)ave--;
    rem=sum-ave*n;
    for(int i=1;i<=n;i++)
    {
        b[i]=b[i-1]+a[i]-ave;//假设全变为ave需要调整的次数
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i&&j<=rem;j++)
        {
            if(j==0)dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]);
            dp[i][j]+=abs(b[i]-j);
            //解释一下为什么要b[i]-j
            /*
            本题的最少次数就是一个一个的复位匹配。那么我们在复原的时候，复原每一个数时所产生的副作用
            都会被下一个数所负担，这样就会有负担次数的利滚利。
            而对于前i个数的复原时，本来应该有j个数是ave+1但却复原成为了ave。那么，第一个应该被复原为ave+1
            的数多产生了一次复原的负担并且使下一个数的复原过程时多了一步，下下个数的复原过程又多了一步……
            同理，这j个特殊的数字将会对i后面的每一个数多产生j个数字的负担，而我们现在需要ave+1，
            所以也就需要对后面的每一个数字抵消j次的额外操作负担。
            */
        }
    }
    cout<<dp[n][rem]<<endl;
    system("pause");
    return 0;

}