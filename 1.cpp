#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        ll ans=0;
        for(int i=1;i<=7;i++)
        {
            ll s;
            cin>>s;
            ans+=s;
        }
        cout<<ans<<endl;
        
    }
    system("pause");
    return 0;
}