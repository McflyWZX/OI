#include <iostream>
#include <stdio.h>
#include <vector>
//U41360 信仰收集
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

using namespace std;

typedef int ui;

struct point {
	ui kamisama;
	ui maxK;
	vector<ui> to;

	point()
	{
		kamisama = 0;
		maxK = -1;
	}
};
point *points;
ui n, m, k, a, b, wa, wb;
ui dfs(ui pos, ui lastStep)
{
	ui ans = 0, maxW = 0;
	if (lastStep == 0 && pos < m)
	{
		if (points[pos].maxK != -1)return points[pos].maxK;
		ans += points[pos].kamisama;
		for (register ui i = 0; i < points[pos].to.size(); i++)
		{
			maxW = max(maxW, -wa + dfs(points[pos].to[i], a - 1));
			maxW = max(maxW, -wb + dfs(points[pos].to[i], b - 1));
		}
		ans += maxW;
		points[pos].maxK = ans;
	}
	else if (lastStep != 0 && pos < m)
	{
		if (points[pos].to.size() > 0)
		{
			ans = dfs(points[pos].to[0], lastStep - 1);
			for (register ui i = 1; i < points[pos].to.size(); i++)
			{
				ans = max(ans, dfs(points[pos].to[i], lastStep - 1));
			}
		}

	}
	return ans;
}

int main()
{
	cin >> n >> m >> k >> a >> b >> wa >> wb;
	points = new point[m];

	ui pos, t;
	for (register ui i = 0; i < n; i++)
	{
		scanf("%d%d", &pos, &t);
		points[--pos].kamisama += t;
	}
	ui u, v;
	for (register ui i = 0; i < k; i++)
	{
		scanf("%d%d", &u, &v);
		points[--u].to.push_back(--v);
	}

	cout << dfs(0, 0);

	/*第一行三个整数n,m,k表示有信仰的点的数量,点的总数,有向边的条数
	第二行两个整数a,b表示两种瞬移的距离
	第三行两个整数wa,wb表示两种瞬移的灵力消耗
	之后n行,每行两个正整数pos,t表示每簇信仰所在的位置以及这簇信仰的数量,不保证pos互不相同

	之后k行,每行两个整数u,v表示从u到v有一条有向边*/

	return 0;
}