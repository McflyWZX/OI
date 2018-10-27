#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Graph {
	vector<int> *node;
	int *Fa;
	int *H;
	int S;

	Graph(int n, int S)
	{
		node = new vector<int>[n + 1];
		Fa = new int[n + 1];
		H = new int[n + 1];
		this->S = S;
	}

	void init()
	{
		findFaAndSetH(-1, S, 0);
	}

	void findFaAndSetH(int fa, int me, int h)
	{
		Fa[me] = fa;
		H[me] = h;
		for (int i = 0; i < node[me].size(); i++)
		{
			if (node[me].at(i) == fa)continue;
			findFaAndSetH(me, node[me].at(i), h + 1);
		}
	}

	int LCA(int u, int v)
	{
		if (H[u] == H[v])
		{
			if (u == v)return u;
			else return LCA(Fa[u], Fa[v]);

		}
		else if (H[u] > H[v])swap(u, v);
		for (; H[v] > H[u]; v = Fa[v]);
		return LCA(u, v);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	/*��һ�а�������������N��M��S���ֱ��ʾ���Ľ�������ѯ�ʵĸ���������������š�
	������N-1��ÿ�а�������������x��y����ʾx����y���֮����һ��ֱ�����ӵıߣ����ݱ�֤���Թ���������
	������M��ÿ�а�������������a��b����ʾѯ��a����b��������������ȡ�*/
	int N, M, S;
	ifstream fin("test2.in");
	ofstream fout("test2.out");
	fin >> N >> M >> S;
	Graph *G = new Graph(N, S);

	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		fin >> a >> b;
		G->node[a].push_back(b);
		G->node[b].push_back(a);
	}
	G->init();

	for (int i = 0; i < M; i++)
	{
		fin >> a >> b;
		fout << G->LCA(a, b) << endl;
	}
}