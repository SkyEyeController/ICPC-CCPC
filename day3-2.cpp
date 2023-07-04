#include<bits/stdc++.h>
using namespace std;
int a[101],check[101];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    for(int i=1;i<=k;i++)
    {
        int t;cin>>t;
        check[t]=true;
    }
    int rem=0;
    for(int i=1;i<=n;i++)
    {
        if(!check[i])
        {
            for(int j=i;j>=rem+1;j--)cout<<j<<" ";
            rem=i;
        }
        
    }
    cout<<endl;
    system("pause");
    return 0;

}