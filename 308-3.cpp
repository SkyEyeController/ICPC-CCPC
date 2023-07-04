#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long double,ll> p;
vector<p> as;
signed main()
{
    ll n;
    cin >> n;
    ll a,b;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a >> b;
        as.push_back({(long double)b/a,i});
    }
    stable_sort(as.begin(), as.end());
    for(ll i=0;i<n;i++)
    {
        cout<<as[i].second<<" ";
    }
    cout << endl;
    system("pause");
    return 0;
}