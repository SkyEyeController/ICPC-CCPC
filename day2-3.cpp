#include<bits/stdc++.h>
using namespace std;
char g[101][101];
int main()
{
    int h,w;
    cin>>h>>w;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin>>g[i][j];
        }
        for(int j=1;j<w;j++)
        {
            if(g[i][j]==g[i][j+1]&&g[i][j]=='T')
            {
                g[i][j++]='P';
                g[i][j]='C';
            }
        }
        for(int j=1;j<=w;j++)
        {
            cout<<g[i][j];
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}