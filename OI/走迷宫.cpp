#include "iostream"
#include "vector"

//P1605

int dir[2][4] = { {1, 0, -1, 0}, {0, 1, 0, -1} };
using namespace std;
int M, N, T, SX, SY, FX, FY;
vector<bool *> map;
void dfs(int x, int y, int &ans)
{
	if (x == FX && y == FY)
	{
		ans++;
		return;
	}
	map[x][y] = false;
	for (int i = 0; i < 4; i++)
	{
		if (x + dir[0][i] > 0 && x + dir[0][i] <= M && y + dir[1][i] > 0 && y + dir[1][i] <= N)
		{
			if (map[x + dir[0][i]][y + dir[1][i]])
			{
				dfs(x + dir[0][i], y + dir[1][i], ans);
			}
		}
	}
	map[x][y] = true;
}

int main()
{
	//第一行N、M和T，N为行，M为列，T为障碍总数。第二行起点坐标SX, SY，终点,坐标FX, FY。接下来T行，每行为障碍点的坐标。
	cin >> N >> M >> T >> SX >> SY >> FX >> FY;

	for (int i = 0; i <= M; i++)
	{
		map.push_back(new bool[N]);
		for (int j = 0; j <= N; j++)
		{
			map[i][j] = true;
		}
	}

	int TX, TY;
	for (int i = 0; i < T; i++)
	{
		cin >> TX >> TY;
		map[TX][TY] = false;
	}

	int ans;
	dfs(SX, SY, ans);
	cout << ans;
	return 0;
}