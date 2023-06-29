#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int h,w,k;
int frac[1000001]={1},inv[1000001]={1},c[1000001];
int quickpow(int a,int n)
{
    int e=1;
    while(n)
    {
        if(n&1)(e*=a)%=mod;
        n>>=1;
        (a*=a)%=mod;
    }
    return e;
}
int C(int n,int m)
{
    if(n<m)return 0;
    return frac[n]*inv[n-m]%mod*inv[m]%mod;
}
void init()
{
    cin>>h>>w>>k;
    for(int i=1;i<=h*w;i++)frac[i]=frac[i-1]*i%mod,inv[i]=inv[i-1]*quickpow(i,mod-2)%mod;
    for(int i=k;i<=h*w;i++)c[i]=C(i,k);
}
int f(int i,int j)
{
    int answ=c[i*j]%mod;
    if(i>1)if((i-1)*j>=k)(answ-=2*c[(i-1)*j])%=mod;
    if(j>1)if((j-1)*i>=k)(answ-=2*c[(j-1)*i])%=mod;
    if(j>2)if((j-2)*i>=k)(answ+=c[(j-2)*i])%=mod;
    if(i>2)if((i-2)*j>=k)(answ+=c[(i-2)*j])%=mod;
    if(i>1&&j>1)if((i-1)*(j-1)>=k)(answ+=4*c[(i-1)*(j-1)])%=mod;
    if(i>1&&j>2)if((i-1)*(j-2)>=k)(answ-=2*c[(i-1)*(j-2)])%=mod;
    if(i>2&&j>1)if((j-1)*(i-2)>=k)(answ-=2*c[(j-1)*(i-2)])%=mod;
    if(i>2&&j>2)if((i-2)*(j-2)>=k)(answ+=c[(j-2)*(i-2)])%=mod;
    //最后一错，组合数不能出现负负得正，(i-2)*(j-2)各项均必须为正
    if(answ<0)(answ+=mod)%=mod;
    return answ;
}
signed main()
{
    init();
    int ans=0;
    for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++)
    {
        (ans+=f(i,j)*i%mod*j%mod*(h-i+1)%mod*(w-j+1)%mod)%=mod;
    }
    (ans*=quickpow(c[h*w],mod-2)%mod)%=mod;
    if(ans<0)(ans+=mod)%=mod;
    cout<<ans<<endl;
    system("pause");
    return 0;
}