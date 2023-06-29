#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set> 
using namespace std;

typedef long long ll;
const int E = 1000 + 11;
const ll MOD = 998244353;

int n, a, b, p, q;
ll f1[E][E]; // f1[i][j] AÎ»ÓÚ i´¦, ×ßÁË j²½µÄ¸ÅÂÊ 
ll f2[E][E]; // ........ B........................ 

ll qpow(ll a, ll b, ll p) {
	ll ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}

int main() {
	scanf("%d%d%d%d%d", &n, &a, &b, &p, &q);
	
	f1[a][0] = 1;
	f2[b][0] = 1;
	
	for (int i = a; i < n; i++) {
		for (int j = 0; j <= n - a; j++) {
			for (int k = 1; k <= p; k++) {
				f1[min(i + k, n)][j + 1] += f1[i][j] * qpow(p, MOD - 2, MOD) % MOD;
				f1[min(i + k, n)][j + 1] = (f1[min(i + k, n)][j + 1] + MOD) % MOD;
			}
		}
	}
	
	for (int i = b; i < n; i++) {
		for (int j = 0; j <= n - b; j++) {
			for (int k = 1; k <= q; k++) {
				f2[min(i + k, n)][j + 1] += f2[i][j] * qpow(q, MOD - 2, MOD) % MOD;
				f2[min(i + k, n)][j + 1] = (f2[min(i + k, n)][j + 1] + MOD) % MOD;
			}
		}
	}
	
	ll ans = 0;
	
	for (int j = 0; j <= n; j++) {
		for (int i = b; i <= n; i++) {
			ans = (ans + f1[n][j] * f2[i][j] % MOD) % MOD;
		}
	}
	
	printf("%lld\n", (ans + MOD) % MOD);
	
	return 0;
}