#include<bits/stdc++.h>
using namespace std;
int a[9];
bool tag=1;
int main()
{
    for(int i=1;i<=8;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1]||a[i]%25!=0||a[i]>675||a[i]<100){tag=0;}
    }
    if(tag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    system("pause");
    return 0;
}