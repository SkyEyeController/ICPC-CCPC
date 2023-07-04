#include<bits/stdc++.h>
using namespace std;
void print_sub(int n)
{
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    print_sub(n);
    system("pause");

}