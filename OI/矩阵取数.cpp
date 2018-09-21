#include <iostream>
#include <memory.h>
#include <vector>

#define min(X, Y) (X) < (Y) ? (X) : (Y)
#define max(X, Y) (X) > (Y) ? (X) : (Y)

using namespace std;

vector<int*> mat;
vector<unsigned long*> dp;

unsigned long DP(int l, int r, int i, int n)
{
	if (dp[l][r] != 0)return dp[l][r];
	if (l == r)return mat[n][r] << i;
	else {
		dp[l][r] = max(DP(l + 1, r, i + 1, n) + (mat[n][l] << i), DP(l, r - 1, i + 1, n) + (mat[n][r] << i));
		return dp[l][r];
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		mat.push_back(new int[m]);
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		dp.push_back(new unsigned long[m]);
		memset(dp[i], 0, m * sizeof(unsigned long));
	}
	unsigned long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			memset(dp[j], 0, m * sizeof(unsigned long));
		}

		ans += DP(0, m - 1, 1, i);
	}
	cout << ans;
	return 0;
}