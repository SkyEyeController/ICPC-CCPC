#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,m;
int a[100001];
signed main()
{
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    m%=sum;
    int p=0;
    int i;
    for(i=1;i<=n;i++)
    {
        p+=a[i];
        if(p>m)
        {
            p-=a[i];
            break;
        }
    }
    if(p==m)cout<<i<<endl;
    else if(p<m)cout<<i<<" "<<m-p<<endl;
    system("pause");
    return 0;
}