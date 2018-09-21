#include <iostream>
#include <queue>
#include <map>
#include <cmath>

#define min(X, Y) (X) < (Y) ? (X) : (Y)
#define max(X, Y) (X) > (Y) ? (X) : (Y)

using namespace std;

typedef pair<unsigned int, unsigned short> State;

State IntitialS, FinalS = make_pair(123804765, 0);

char direction[2][4] = { {1, 0, -1, 0}, {0, -1, 0, 1} };

map<int, bool> Walked;
queue<State> TryQ;

int main()
{
	cin >> IntitialS.first;

	IntitialS.second = 0;

	TryQ.push(IntitialS);

	char SMat[3][3];

	while (!TryQ.empty())
	{
		State &NowS = TryQ.front();
		TryQ.pop();
		pair<char, char> zeroP = make_pair(-1, -1); // Y, X
		for (int i = 0; i < 9; i++)//将状态解码
		{
			if ((SMat[i / 3][i % 3] = (NowS.first - ((int)(NowS.first / pow(10, 9 - i))) * pow(10, 9 - i)) / pow(10, 8 - i)) == 0)
			{
				zeroP.first = i / 3;
				zeroP.second = i % 3;
			}
		}
		if (zeroP.first == -1)
		{
			zeroP.first = 0;
			zeroP.second = 0;
		}
		State OutS;
		for (int i = 0; i < 4; i++)
		{
			//遍历零移动的四个方向,并判断可行性
			if (zeroP.first + direction[0][i] >= 0 && zeroP.first + direction[0][i] < 3 && zeroP.second + direction[1][i] >= 0 && zeroP.second + direction[1][i] < 3)
			{
				swap(SMat[zeroP.first][zeroP.second], SMat[zeroP.first + direction[0][i]][zeroP.second + direction[1][i]]);
				OutS.first = 0;
				for (int i = 0; i < 9; i++)//将状态编码
				{
					OutS.first += SMat[i / 3][i % 3] * pow(10, 8 - i);

				}
				swap(SMat[zeroP.first + direction[0][i]][zeroP.second + direction[1][i]], SMat[zeroP.first][zeroP.second]);
				OutS.second = NowS.second + 1;
				if (OutS.first == FinalS.first)
				{
					cout << OutS.second;
					return 0;
				}
				if (Walked.find(OutS.first) == Walked.end())
				{
					Walked[OutS.first] = true;
					TryQ.push(OutS);
				}

			}
		}
	}

	return 0;
}