// OI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <memory.h>
//区间质数查询
#define min(X, Y) (X) < (Y) ? (X) : (Y)
#define max(X, Y) (X) > (Y) ? (X) : (Y)

using namespace std;

int main()
{
	int R, nQ, maxR = 0;

	cin >> nQ >> R;

	pair<int, int> * Range = new pair<int, int>[nQ];

	long long TR, TL;
	for (int i = 0; i < nQ; i++)
	{
		cin >> TL >> TR;
		if (TR > R || TL < 1)
		{
			Range[i].first = -1;
			Range[i].second = -1;
		}
		else {
			Range[i].first = TL;
			Range[i].second = TR;
			maxR = max(maxR, TR);
		}
	}
	bool *Prime = new bool[maxR + 1];
	long *AddPrime = new long[maxR + 1];

	memset(Prime, 1, maxR + 1);
	Prime[0] = Prime[1] = 0;
	for (int i = 2; i < maxR / 2 + 2; i++)
	{
		if (Prime[i])
		{
			int q = 2, nN = i * q;
			for (; nN <= maxR; q++)
			{
				Prime[nN] = 0;
				nN = i * q;
			}
		}
		else {
			continue;
		}
	}

	AddPrime[0] = 0;
	for (int i = 1; i <= maxR; i++)
	{
		AddPrime[i] = AddPrime[i - 1] + Prime[i];
	}

	for (int i = 0; i < nQ; i++)
	{
		if (Range[i].first == -1)
		{
			cout << "Crossing the line" << endl;
		}
		else {
			cout << AddPrime[Range[i].second] - AddPrime[Range[i].first - 1] << endl;
		}
	}

	return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
