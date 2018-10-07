#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
//T48748
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

using namespace std;

typedef int ui;

ui n, m, s = 1;
vector< ui* > mat;

void rotate(const ui &x, const ui &y, const ui &r, const ui &z)
{
	for (ui i = 1; i <= r; i++)
	{
		ui *TL = new ui[2 * i];
		memcpy(TL, mat[y + i] + x - i + 1, 2 * i * sizeof TL);
		if (z)
		{
			for (ui j = -i + 1; j <= i; j++)
			{
				mat[y + i][x + j] = mat[y + j][x - i];
			}
			for (ui j = -i + 1; j <= i; j++)
			{
				mat[y + j][x - i] = mat[y - i][x - j];
			}
			for (ui j = -i + 1; j <= i; j++)
			{
				mat[y - i][x - j] = mat[y - j][x + i];
			}
			for (ui j = -i + 1; j <= i; j++)
			{
				mat[y - j][x + i] = TL[j + i - 1];
			}
		}
		else {
			for (ui j = -i + 1; j <= i; j++)
			{
				mat[y + i][x + j] = mat[y - j][x + i];
			}
			for (ui j = -i + 1; j <= i; j++)
			{
				mat[y - j][x + i] = mat[y - i][x - j];
			}
			for (ui j = -i + 1; j <= i; j++)
			{
				mat[y - i][x - j] = mat[y + j][x - i];
			}
			for (ui j = -i + 1; j <= i; j++)
			{
				mat[y + j][x - i] = TL[j + i - 1];
			}
		}
		delete[]TL;
	}
}

int main()
{
	cin >> n >> m;
	for (ui i = 0; i < n; i++)
	{
		mat.push_back(new ui[n]);
		for (ui j = 0; j < n; j++)
		{
			mat[i][j] = s++;
		}
	}
	ui x, y, r, z;
	for (ui i = 0; i < m; i++)
	{
		scanf("%d%d%d%d", &x, &y, &r, &z);//z=0表示顺时针，z=1表示逆时针。
		x--;
		y--;
		rotate(x, y, r, z);
	}

	for (ui i = 0; i < n; i++)
	{
		for (ui j = 0; j < n; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}