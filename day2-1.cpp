#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[101],b[101];
int main()
{
    int n,T;
    cin>>n>>T;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i]-a[i-1];
    }
    for(int i=2;i<=n;i++)
    {
        if(b[i]<=T)
        {
            cout<<a[i]<<endl;
            system("pause");
            return 0;
        }
    }
    cout<<-1<<endl;
    system("pause");
    return 0;


}