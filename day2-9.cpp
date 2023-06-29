#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a, b, p, q;
int dp1[110][110], dp2[110][110];
int pa[110], pb[110];
#define mod 998244353
int quickpow(int a, int n)
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
signed main()
{
    cin >> n >> a >> b >> p >> q;
    dp1[a][0] = dp2[b][0] = 1; // dp[i][j]表示走到i扔了j次筛子的概率
    int invp = quickpow(p, mod - 2) % mod;
    int invq = quickpow(q, mod - 2) % mod;
    for (int i = a; i < n; i++)
    {
        for (int j = 0; j <= i - a; j++)
        {
            for (int k = 1; k <= p; k++)
            {
                (dp1[i + k > n ? n : i + k][j + 1] += invp * dp1[i][j] % mod) %= mod;
            }
        }
    }
    for (int i = b; i < n; i++)
    {
        for (int j = 0; j <= i - b; j++)
        {
            for (int k = 1; k <= q; k++)
            {
                (dp2[i + k > n ? n : i + k][j + 1] += invq * dp2[i][j] % mod) %= mod;
            }
        }
    }

    /*for (int i = a; i <= n; i++)
    {
        for (int j = 0; j <= i - a; j++)
        {
            cout << "The popularity of A goes to ";
            cout << i;
            cout << " by throwing ";
            cout << j;
            cout << " times of the die is ";
            cout << dp1[i][j] << endl;
        }
    }
    for (int i = b; i <= n; i++)
    {
        for (int j = 0; j <= i - b; j++)
        {
            cout << "The popularity of B goes to ";
            cout << i;
            cout << " by throwing ";
            cout << j;
            cout << " times of the die is ";
            cout << dp2[i][j] << endl;
        }
    }*/
    /*
    第一次答案不对，第一个样例本应该是655496236却输出了655496237，打表分析发现：
    4 2 3 3 2
    The popularity of A goes to 2 by throwing 0 times of the die is 1
    The popularity of A goes to 3 by throwing 0 times of the die is 0
    The popularity of A goes to 3 by throwing 1 times of the die is 332748118
    The popularity of A goes to 4 by throwing 0 times of the die is 0
    ***The popularity of A goes to 4 by throwing 1 times of the die is 665496236***
    ***The popularity of A goes to 4 by throwing 2 times of the die is 1***
    The popularity of B goes to 3 by throwing 0 times of the die is 1
    The popularity of B goes to 4 by throwing 0 times of the die is 0
    The popularity of B goes to 4 by throwing 1 times of the die is 1
    计算的时候出现了665496236+1，说明我们现在的概率方程允许了第二次扔骰子的发生。
    理论上，A没有扔第二次筛子的机会，因为B随便扔一次就到了，不会再有给A的机会。
    为什么出现了A扔第二次筛子的机会？问题出在了我误以为sum(dp[][])=1.
    首先明确一点,dp[i][j]的含义是扔了j次筛子到i的概率，所以，概率总和为sum(dp[][j])=1,代表意义为扔i次
    骰子的所有可能及概率而不是全部概率总和为1.
    扔j次的概率是多少需要明确——什么时候可能扔第j次，什么时候不可能？

    能扔第j次的充分必要条件是第j-1回合扔后没有人成功到达终点。根据递归思想，如果能扔第j-1回合必然证明第j-2回合没有人
    到达终点，循环论证，所以成立。

    在第j-1回合能到达的所有可能点为全概率事件前提下（sum(dp[][j])=1），第j-1回合扔后没有人成功到达终点的概率是
    （1-pb[j-1])*(1-pa[j-1]),这就是校准的标量。

    但是第二次再次失败。原因和上一次一样，把能扔j-1次当成了必然事件，（1-pb[j-1])*(1-pa[j-1])是在可以扔出第
    j-1次的前提下，所以pre前缀需要累积乘法。

    还是不对

    这说明整体思路上还是有缺陷，需要再次更正。

    再回到关于dp数组的解释，dp1[n][j]表示的是在能扔出第j次的前提下A到达n的概率，
    这也不是针对于完全概率事件的,也需要前缀pre的注释

    需要再加一个前缀累乘。

    还是不对

    对照dp发现到了dp[n][]就不用扔骰子了，for循环不需要等于n


    */
    int ans = 0;
    /*for (int j = 0; j <= n - a; j++)
    {

        for (int i = b; i <= n; i++)
        {
            (pb[j] += dp2[i][j] % mod) %= mod;
        }

    }*/
    
    for (int j = 0; j <= n-a; j++) {
		for (int i = b; i <= n; i++) {
			ans = (ans + dp1[n][j] * dp2[i][j] % mod) % mod;
		}
	}
    cout << ans << endl;
    system("pause");
    return 0;
}