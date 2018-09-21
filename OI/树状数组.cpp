#include <iostream>
//Ê÷×´Êý×é
#define min(X, Y) (X) < (Y) ? (X) : (Y)
#define max(X, Y) (X) > (Y) ? (X) : (Y)

using namespace std;

inline long lowbit(long x)
{
	return x & (-x);
}

long long sum(long i, long long *tree)
{
	long long ans = 0;

	ans += tree[i];
	while (i != lowbit(i))
	{
		i -= lowbit(i);
		ans += tree[i];
	}
	return ans;
}

int main()
{
	long N, cmd;
	cin >> N >> cmd;
	long long *tree = new long long[N + 1];
	tree[0] = 0;
	long t, TV;
	for (long i = 1; i <= N; i++)
	{
		cin >> TV;
		for (t = i; t <= N; t += lowbit(t))
		{
			tree[t] += TV;
		}
	}

	long cmdType, x, k, y;
	for (long i = 1; i <= cmd; i++)
	{
		cin >> cmdType;

		if (cmdType == 1)
		{
			cin >> x >> k;
			for (; x <= N; x += lowbit(x))
			{
				tree[x] += k;
			}
		}
		else if (cmdType == 2)
		{
			cin >> x >> y;
			cout << sum(y, tree) - sum(x - 1, tree) << endl;
		}
	}
	return 0;
}