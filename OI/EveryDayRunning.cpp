#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int UI;

struct graph {
	vector<UI> *node;
	pair<UI, UI> *W;
	UI *Fa;
	UI *H;
	UI S;

	graph(UI n)
	{
		node = new vector<UI>[n + 1];
		W = new pair<UI, UI>[n + 1];
		Fa = new UI[n + 1];
		H = new UI[n + 1];
		S = n / 2 + 1;
	}

	void init()
	{
		setFaAndH(0, S, 0);
	}

	void setFaAndH(UI f, UI me, UI h)
	{
		Fa[me] = f;
		H[me] = h;

		for (UI i = 0; i < node[me].size(); i++)
		{
			if (node[me][i] != Fa[me])setFaAndH(me, node[me][i], h + 1);
		}
	}

	//UI s1 = 0, s2 = 0;
	void watch(UI S, UI T)
	{
		if (S == T)
		{
			if (W[S].first == 0)W[S].second++;
			return;
		}
		vector<UI> s1, s2;
		UI T1 = S, T2 = T;

		s1.push_back(T1);
		s2.push_back(T2);

		while (H[T1] > H[T2])
		{
			T1 = Fa[T1];
			s1.push_back(T1);
		}

		while (H[T1] < H[T2])
		{
			T2 = Fa[T2];
			s2.push_back(T2);
		}

		while (T1 != T2)
		{
			T1 = Fa[T1];
			T2 = Fa[T2];
			s1.push_back(T1);
			s2.push_back(T2);
		}
		s2.pop_back();
		UI t = 0, s2s = s2.size();
		for (; t < s1.size(); t++)
		{
			if (W[s1[t]].first == t)W[s1[t]].second++;
		}

		int count = 0;
		for (int i = s2s - 1; i >= 0; i--, t++)
		{
			if (W[s2[i]].first == t)W[s2[i]].second++;
			count++;
		}
	}
};

int main()
{
	UI n, NoPlayers;
	cin >> n >> NoPlayers;

	graph *G = new graph(n);

	UI t1, t2;
	for (UI i = 1; i < n; i++)
	{
		cin >> t1 >> t2;
		G->node[t1].push_back(t2);
		G->node[t2].push_back(t1);
	}

	G->init();

	for (UI i = 1; i <= n; i++)
	{
		cin >> G->W[i].first;
		G->W[i].second = 0;
	}

	UI ps, pt;
	for (UI i = 0; i < NoPlayers; i++)
	{
		cin >> ps >> pt;
		G->watch(ps, pt);
	}

	for (UI i = 1; i <= n; i++)
	{
		cout << G->W[i].second << " ";
	}
}