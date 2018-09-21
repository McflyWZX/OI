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