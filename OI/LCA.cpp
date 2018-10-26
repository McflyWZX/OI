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
    /*��һ�а�������������N��M��S���ֱ��ʾ���Ľ�������ѯ�ʵĸ���������������š�
	������N-1��ÿ�а�������������x��y����ʾx����y���֮����һ��ֱ�����ӵıߣ����ݱ�֤���Թ���������
	������M��ÿ�а�������������a��b����ʾѯ��a����b��������������ȡ�*/
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
