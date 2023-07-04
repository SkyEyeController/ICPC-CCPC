#include <bits/stdc++.h>
using namespace std;
#define mod 998244353LL
long long quickpow(int a, int n)
{
    int e = 1;
    while (n)
    {
        if (n & 1)
            (e *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return e;
}
int sum[2000000];
class Integer
{
private:
    string num;
    string multipy(string a, string b)
    {
        string C;
        if (a == "0")
            return a;
        if (b == "0")
            return b;
        int len1 = a.size(), len2 = b.size();
        memset(sum, 0, sizeof(sum));
        string a_(a.rbegin(), a.rend());
        string b_(b.rbegin(), b.rend());
        for (int i = 0; i < len1; i++)
            for (int j = 0; j < len2; j++)
            {
                sum[i + j] += (a_[i] - '0') * (b_[j] - '0');
                sum[i + j + 1] += sum[i + j] / 10;
                sum[i + j] %= 10;
            }
        for (int i = len1 + len2 - 1; i >= 0; i--)
        {
            C = char(sum[i] + '0') + C;
        }
        reverse(C.begin(), C.end());
        C.erase(0, C.find_first_not_of('0'));
        return C;
    }
    long long moder(string num, long long MOD)
    {
        long long ans = 0LL;
        int size = num.size();
        for (int i = 0; i < size; i++)
        {
            (ans = (10 * ans + num[i] - 48)) %= mod;
        }
        (ans += mod) %= mod;
        return ans;
    }

public:
    Integer(){};
    Integer(string s)
    {
        num = s;
    }
    Integer(int a)
    {
        ostringstream ss;
        ss << a;
        num = ss.str();
    }
    Integer operator*(const Integer &b)
    {
        Integer c;
        c.num = multipy(num, b.num);
        return c;
    }
    long long operator%(const long long MOD)
    {
        long long c;
        c = moder(num, MOD);
        return c;
    }
    string get()
    {
        return num;
    }
};
#define Int Integer
string a, b;
int n;
int main()
{
    cin >> n;
    cin >> a >> b;
    for (int i = 0; i < n; i++)
        if (a[i] <= b[i])
        {
            char c = a[i];
            a[i] = b[i];
            b[i] = c;
        }
    Int A = a, B = b;
    long long C = A % mod;
    long long D = B % mod;
    long long answ=(C*D)%mod;
    cout<<answ<<endl;
    system("pause");
    return 0;
}
