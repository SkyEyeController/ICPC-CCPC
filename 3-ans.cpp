#include <bits/stdc++.h>
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define fep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define N 37
using namespace std;

string s;
int ans[N][N];
int ha, wa, hb, wb, hc, wc;
int a[N][N], b[N][N], c[N][N];

int main() {
	scanf("%d%d", &ha, &wa);
	for(int i=1;i<=ha;i++) {
		cin >> s;
		for(int j=0;j<s.size();j++)
			a[i][j + 1] = (s[j] == '#');
	}
	scanf("%d%d", &hb, &wb);
	for(int i=1;i<=hb;i++) {
		cin >> s;
		for(int j=0;j<s.size();j++)
			b[i][j + 1] = (s[j] == '#');
	}
	scanf("%d%d", &hc, &wc);
	for(int i=1;i<=hc;i++) {
		cin >> s;
		for(int j=0;j<s.size();j++)
			c[10 + i][11 + j] = (s[j] == '#');
	}
	for(int i=1;i<=hc+10;i++)
		for(int j=1;j<=wc+10;j++)
			for(int k=1;k<=hc+10;k++)
				for(int l=1;l<=wc+10;l++) {
					memset(ans, 0, sizeof ans);
					rep(p, 1, ha)
						rep(q, 1, wa)
							if (a[p][q])
								ans[i + p - 1][j + q - 1] = 1;
					rep(p, 1, hb)
						rep(q, 1, wb)
							if (b[p][q])
								ans[k + p - 1][l + q - 1] = 1;
					int f = 1;
					rep(p, 1, 30)
						rep(q, 1, 30)
							if (ans[p][q] != c[p][q])
								f = 0;
					if (f)
						return puts("Yes"), 0;
			}
	puts("No");
	return 0;
}
