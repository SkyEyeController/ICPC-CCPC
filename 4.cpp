#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<char> s;
    int N;
    cin>>N;
    int leftnum=0;
    int rightnum=0;
    string su;
    cin>>su;
    for(int i=0;i<N;i++)
    {
        switch(su[i])
        {
            case ')':
            if(leftnum==0)s.push_back(')');
            else
            {
                while(!s.empty())
                {
                    if(!s.empty()&&s.back()=='(')break;
                    s.pop_back();
                }
                if(!s.empty()&&s.back()=='('){s.pop_back();leftnum--;}
            }
            break;
            case '(':
            s.push_back(su[i]);
            leftnum++;
            break;
            default:
            s.push_back(su[i]);
        }
    }
    while(!s.empty())
    {
        cout<<s.front();
        s.pop_front();
    }
    system("pause");
    return 0;

}