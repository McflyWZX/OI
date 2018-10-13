// OI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class Ts, class TR>
void quickSort(Ts *s, TR l, TR r)
{
	if (l >= r)return;
	Ts T = s[l], t;
	TR i = l, j = r;
	while (i < j)
	{
		while (T < s[j])j--;
		while (s[i] < T)i++;
		
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
	quickSort(s, l, i - 1);
	quickSort(s, j + 1, r);
	return;
}
int main()
{
	
	return 0;
}
/*#include <iostream>
#include <vector>
#include <memory.h>
//LCA

using namespace std;

struct node {
	vector<int> to;
};

int main()
{
	/*第一行包含三个正整数N、M、S，分别表示树的结点个数、询问的个数和树根结点的序号。
	接下来N-1行每行包含两个正整数x、y，表示x结点和y结点之间有一条直接连接的边（数据保证可以构成树）。
	接下来M行每行包含两个正整数a、b，表示询问a结点和b结点的最近公共祖先。*/

	/*int N, M, S;

	cin >> N >> M >> S;

	int *tree = new int[N + 1];
	memset(tree, 0, (N + 1) * sizeof(int));

	int Ta, Tb;
	for (auto i = 0; i < N - 1; i++)
	{
		cin >> Ta >> Tb;
		tree[Ta] = Tb;
		tree[Tb] = Ta;
	}

	return 0;
}*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
