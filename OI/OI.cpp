// OI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include <vector>
//LCA
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

using namespace std;

struct Log {
	int *lg;//2

	Log(int max)
	{
		lg = new int[max + 1];
		lg[0] = 0;
		for (int i = 1; (1 << i) <= max; i++)
		{
			for (int j = (1 << (i - 1)) + 1; j <= (1 << i) && j <= max; j++)
			{
				lg[j] = i;
			}
		}
	}

	int at(int index)
	{
		return lg[index];
	}
};
Log *lg;
struct Node {
	vector<int> to;
	int father;
	int *grand;
	int depth;

	Node()
	{
		father = -1;
	}

	void initG(Node *G)
	{
		int t = lg->at(depth);
		int t2 = t;
		grand = new int[t];

		int tin;//模拟指针

		tin = grand[0] = father;
		cout << t << " " << depth << endl;
		while (t--)
		{
			tin = G[tin].father;
			if (G[tin].depth >= (1 << (t2 - t - 1))) grand[t2 - t] = G[tin].grand[t2 - t - 1];
			else
			{
				grand[t2 - t] = -1;
			}

			cout << father << "的儿子,向上跳 2^" << t2 - t << "格是:" << tin << endl;
		}
	}
};

void initDepth(Node *ns, int S, int F, int d, int &maxD)//S:源节点 F:父节点
{
	ns[S].father = F;
	ns[S].depth = d;
	maxD = max(d, maxD);
	for (int i = 0; i < ns[S].to.size(); i++)
	{
		if (ns[S].father != ns[S].to[i])initDepth(ns, ns[S].to[i], S, d + 1, maxD);
	}

}

void initGrand(Node *ns, int S)
{
	ns[S].initG(ns);
	for (int i = 0; i < ns[S].to.size(); i++)
	{
		if (ns[S].father != ns[S].to[i])initGrand(ns, ns[S].to[i]);
	}
}

int LCA(int p1, int p2)
{
	return 0;
}

int main()
{
	int N, M, S, maxDepth;//N、M、S，分别表示树的结点个数、询问的个数和树根结点的序号
	cin >> N >> M >> S;
	Node *nodes = new Node[N + 1];

	int x, y;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> x >> y;
		nodes[x].to.push_back(y);
		nodes[y].to.push_back(x);
	}

	initDepth(nodes, S, 0, 0, maxDepth);

	lg = new Log(maxDepth + 1);

	initGrand(nodes, S);
	//for(int i = 0; i < maxDepth; i++)cout << i << " " << lg->at(i) << endl;

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
