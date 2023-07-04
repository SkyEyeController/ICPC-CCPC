#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int tag=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='"')tag++;
        if(!(tag&1)&&s[i]==',')s[i]='.';
    }
    cout<<s<<endl;
    system("pause");
    return 0;

}