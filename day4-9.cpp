#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = s.size() - 1;
    if (l == 7)
    {
        if (s[0] >= 'A' && s[0] <= 'Z' && s[1] >= '0' && s[1] <= '9')
        {
            if (s[l] >= 'A' && s[l] <= 'Z' && s[l - 1] >= '0' && s[l - 1] <= '9')
            {
                string t = s.substr(1, l - 1);
                for(int i=0;i<t.size();i++)
                {
                    if(t[i]<'0'||t[i]>'9')
                    {
                        cout<<"No"<<endl;
                        system("pause");
                        return 0;
                    }
                }
                istringstream ss(t);
                int num;
                ss>>num;
                if(num>=100000&&num<=999999)
                {
                    cout<<"Yes"<<endl;
                    system("pause");
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
    system("pause");
    return 0;
}