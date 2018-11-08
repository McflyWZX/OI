#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int M, N;
	cin >> M >> N;
	queue<int> mem;
	set<int> memlist;

	int word;
	long op = 0;
	while (N--)
	{
		cin >> word;
		if (memlist.find(word) == memlist.end())
		{
			//记得set和queue要同步操作
			if (mem.size() == M)
			{
				memlist.erase(mem.front());
				mem.pop();
			}
			mem.push(word);
			memlist.insert(word);
			op++;
		}
	}
	cout << op;
	return 0;
}