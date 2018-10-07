#include <iostream>
#include <stdio.h>
#include <vector>
//U41360 �����ռ�
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

	/*��һ����������n,m,k��ʾ�������ĵ������,�������,����ߵ�����
	�ڶ�����������a,b��ʾ����˲�Ƶľ���
	��������������wa,wb��ʾ����˲�Ƶ���������
	֮��n��,ÿ������������pos,t��ʾÿ���������ڵ�λ���Լ��������������,����֤pos������ͬ

	֮��k��,ÿ����������u,v��ʾ��u��v��һ�������*/

	return 0;
}