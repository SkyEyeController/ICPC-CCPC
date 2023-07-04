#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef struct nodeE
{
    int pos;
    int num;
    int targetnum[3];
} nodeE;
vector<nodeE> M;
vector<nodeE> X;
int a[200001];
int n;
int m[3], x[3];
string s;
int mex(int a,int b,int c)
{
    for(int i=0;i<=3;i++)
    {
        if(a!=i&&b!=i&&c!=i)return i;
    }
    return 3;
}
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        s += c;
        switch (c)
        {
        case 'M':
            m[a[i]]++;
            break;
        case 'E':
            M.push_back(nodeE({i, a[i], {m[0], m[1], m[2]}}));
            break;
        case 'X':
            x[a[i]]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 'M':
            m[a[i]]--;
            break;
        case 'E':
            X.push_back(nodeE({i, a[i], {x[0], x[1], x[2]}}));
            break;
        case 'X':
            x[a[i]]--;
        }
    }
    int ansf=0;
    for(int i=0;i<M.size();i++)
    {
        for(int j=0;j<=2;j++)
        for(int k=0;k<=2;k++)
        {
            ansf+=mex(M[i].num,j,k)*(M[i].targetnum[j])*(X[i].targetnum[k]);
        }
    }
    cout<<ansf<<endl;
    system("pause");
    return 0;
}