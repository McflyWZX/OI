#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Graph {
	vector<int> *node;
	
	Graph(int n, int S)
	{
		node = new vector<int>[n + 1];
	}
	
	void init()
	{
		
	}
};

int main()
{
    ios::sync_with_stdio(false);
    /*第一行包含三个正整数N、M、S，分别表示树的结点个数、询问的个数和树根结点的序号。
	接下来N-1行每行包含两个正整数x、y，表示x结点和y结点之间有一条直接连接的边（数据保证可以构成树）。
	接下来M行每行包含两个正整数a、b，表示询问a结点和b结点的最近公共祖先。*/
	int N, M, S;
	ifstream fin("test2.in");
	ofstream fout("test2.out");
	fin >> N >> M >> S;
	Graph *G = new Graph(N, S); 
	
	int a, b;
	for(int i = 0; i < N - 1; i++)
	{
		fin >> a >> b;
		G->node[a].push_back(b);
		G->node[b].push_back(a);
	}
	
}
