#include <iostream>
#include <bitset>
#include <cmath>

#define min(X, Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

typedef unsigned int UI;
struct pig
{
	double x;
	double y;
	bool killed;
};

UI dfs(pig *p, const UI &n, UI kills, const UI &m)
{
	if (kills == n)return 0;
	UI ans = 65536;
	bitset<18> operated(0);
	bitset<18> cacled(0);
	double a, b;
	bool deathRun;
	for (UI i = 0; i < n; i++)
	{
		if (!p[i].killed && !cacled[i])
		{
			cacled[i] = 1;
			p[i].killed = 1;
			deathRun = 0;
			for (UI j = 0; j < n; j++)
			{
				if (!p[j].killed && p[i].x != p[j].x && !cacled[j])//i, j limit waiting for cutting
				{

					double x1x2 = p[i].x * p[j].x;
					double x1_x2 = p[i].x - p[j].x;
					double y1x2 = p[i].y * p[j].x;
					double y2x1 = p[j].y * p[i].x;
					a = -(y2x1 - y1x2) / (x1x2 * (x1_x2));

					if (a >= 0)continue;
					cacled[j] = 1;
					deathRun = 1;
					b = (y2x1 * p[i].x - y1x2 * p[j].x) / (x1x2 * (x1_x2));
					p[j].killed = operated[j] = 1;
					UI Tkills = kills + 2;
					for (UI k = 0; k < n; k++)
					{
						if (!p[k].killed && abs(p[k].x * p[k].x * a + p[k].x * b - p[k].y) <= 1e-7 && k != i && k != j)
						{
							p[k].killed = operated[k] = 1;
							cacled[k] = 1;
							Tkills++;
						}
					}
					ans = min(ans, 1 + dfs(p, n, Tkills, m));
					for (UI t = 0; t < n; t++)
					{
						if (operated[t])p[t].killed = false;
					}
					operated.reset();
				}
			}
			if (deathRun == 0)ans = min(ans, 1 + dfs(p, n, kills + 1, m));
			p[i].killed = 0;
		}
	}
	return ans;
}

int main()
{
	UI T, n, m, inter;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		pig *p = new pig[n];
		for (UI i = 0; i < n; i++)
		{
			cin >> p[i].x >> p[i].y;
			p[i].killed = false;
		}
		cout << dfs(p, n, 0, m) << endl;
	}
}