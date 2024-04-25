#include <bits/stdc++.h>
#define lol long long
using namespace std;
const int MAXN = 1e3 + 10;
const lol Mod = 1e9 + 7;
const double inf = 1e9 + 1;
double dp[MAXN][MAXN], b[MAXN][MAXN];
lol a[MAXN][MAXN], ans[MAXN][MAXN];

int main()
{
	int n;
	cin >> n;
	for(int i = 1 ;i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
		cin >> a[i][j];
		b[i][j] = log10(a[i][j]);
		}
	for(int i = 0;i < MAXN; i++)
		for(int j = 0;j < MAXN;j++)
			ans[i][j] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(dp[i - 1][j] > dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j] + b[i][j];
				ans[i][j] = (ans[i - 1][j]*a[i][j]) % Mod;
			}
			else
			{
				dp[i][j] = dp[i][j - 1] + b[i][j];
				ans[i][j] = (ans[i][j - 1] * a[i][j]) % Mod;
			}

			if(a[i][j] == 0)
				dp[i][j] = -inf, ans[i][j] = 0;
		}
	cout << ans[n][n] << endl;
	return 0;
}

