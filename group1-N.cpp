#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector<int>q;
    for(int i=1,a;i<=n;i++)
    {
        cin>>a;
        q.push_back(a);
    }
    int o;
    scanf("%d",&o);
    while(o--)
    {
        int s;
        cin>>s;
        int k,tar;
        switch(s)
        {
            case 1:
            cin>>k>>tar;
            q[k-1]=tar;
            break;
            case 2:
            cin>>k;
            printf("%d\n",q[k-1]);

        }
    }
    system("pause");
    return 0;


}