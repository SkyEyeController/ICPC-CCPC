#include<bits/stdc++.h>
using namespace std;
int lb[3],lr[3],lk;
int main()
{
    char a[9];
    int m=1,n=1,o=0;
    for(int i=1;i<=8;i++)
    {
        cin>>a[i];
        if(a[i]=='B')lb[m++]=i,o+=i;
        if(a[i]=='R')lr[n++]=i;
        if(a[i]=='K')lk=i;
    }
    if(o&1)
    {
        if(lr[1]<lk&&lk<lr[2])
        {
            cout<<"Yes"<<endl;
            system("pause");
            return 0;
        }
    }
    cout<<"No"<<endl;
    system("pause");
    return 0;
}