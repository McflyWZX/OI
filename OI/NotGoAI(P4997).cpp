#include <iostream>
#include <set>

#define max(X, Y) (X) > (Y) ? (X) : (Y)
#define min(X, Y) (X) < (Y) ? (X) : (Y)

using namespace std;

const int dir[2][4] = { {1, 0, -1, 0}, {0, 1, 0, -1} };
const char pieces[3] = { 'X', 'O', '.' }; //XºÚÆå, O°×Æå, .¿Õ°×
struct NotGoAI
{
	char *(*board); //Y, X
	pair<int, int> *(*UFS); //×ø±ê±àÂë, ÆøÊý
	int L;
	set<int> could;
	/*srand((unsigned)clock());
	rand()*/
	NotGoAI(int L)
	{
		this->L = L;
		this->board = new char *[L];
		this->UFS = new pair<int, int> *[L];
		for (int i = 0; i < L; i++)
		{
			this->board[i] = new char[L];
			this->UFS[i] = new pair<int, int>[L];
		}
	}

	void fillInit(const int &x, const int &y, const char &s)
	{
		board[y][x] = s;
		UFS[y][x] = make_pair(-1, 0);
	}

	void UFSinit()
	{
		for (int y = 0; y < L; y++)
		{
			for (int x = 0; x < L; x++)
			{
				DFSinitUFS(x, y, board[y][x], -1);
			}
		}

		int x1, y1;
		set<int> gone;
		for (int y = 0; y < L; y++)
		{
			for (int x = 0; x < L; x++)
			{
				if (board[y][x] == '.')
				{
					could.insert(y * L + x);
					for (int i = 0; i < 4; i++)
					{
						x1 = x + dir[0][i];
						y1 = y + dir[1][i];
						if (x1 >= 0 && x1 < L && y1 >= 0 && y1 < L && board[y1][x1] != '.' && gone.find(y1 * L + x1) == gone.end())
						{
							gone.insert(y1 * L + x1);
							UFS[UFS[y1][x1].first / L][UFS[y1][x1].first % L].second++;
							//cout << "Point(" << UFS[y1][x1].first / L << ", " << UFS[y1][x1].first % L << ") Qi++" << endl;
						}
					}
					gone.clear();
				}
			}
		}
	}

	void DFSinitUFS(int x0, int y0, const char &type, int Fa)
	{
		if (UFS[y0][x0].first != -1)return;
		if (Fa == -1)Fa = UFS[y0][x0].first = y0 * L + x0;
		else UFS[y0][x0].first = Fa;
		int x1, y1;
		for (int i = 0; i < 4; i++)
		{
			x1 = x0 + dir[0][i];
			y1 = y0 + dir[1][i];
			if (x1 >= 0 && x1 < L && y1 >= 0 && y1 < L && board[y1][x1] == type && UFS[y1][x1].first == -1)
			{
				DFSinitUFS(x1, y1, type, Fa);
			}
		}
	}

	pair<int, int>& UFSfind(int x, int y)
	{

		pair<int, int> &Fa = UFS[UFS[y][x].first / L][UFS[y][x].first % L];
		if (board[y][x] == pieces[2])return Fa;
		while (Fa.second == 0)
		{
			UFS[y][x].first = (Fa = UFS[Fa.first / L][Fa.first % L]).first;
		}
		return Fa;
	}

	char type;
	bool play(bool isw)
	{
		type = pieces[isw];
		bool can;
		set<int> around;
		int x1, y1, x0, y0, space;
		for (set<int>::iterator i = could.begin(); i != could.end(); i++)
		{
			x0 = *i % L;
			y0 = *i / L;
			can = true;
			space = 0;
			around.clear();
			for (int index = 0; index < 4; index++)
			{
				x1 = x0 + dir[0][index];
				y1 = y0 + dir[1][index];
				if (x1 >= 0 && x1 < L && y1 >= 0 && y1 < L)
				{
					if (board[y1][x1] == pieces[!isw] && UFSfind(x1, y1).second == 1)
					{
						can = false;
						break;
					}
					else if (board[y1][x1] != pieces[2])
					{
						around.insert(x1 + y1 * L);
						if (board[y1][x1] == type)space += UFSfind(x1, y1).second - 1;
					}
					else if (board[y1][x1] == pieces[2])
					{
						space++;
					}
				}
			}
			if (can && space > 0)
			{
				UFS[y0][x0].second = space;
				UFS[y0][x0].first = *i;
				board[y0][x0] = type;
				for (set<int>::iterator a = around.begin(); a != around.end(); a++)
				{
					if (board[*a / L][*a % L] == type)
					{
						int TP = UFSfind(*a % L, *a / L).first;
						UFSfind(*a % L, *a / L).first = *i;
						UFS[TP / L][TP % L].second = 0;
					}
					else
					{
						UFSfind(*a % L, *a / L).second--;
					}
				}
				could.erase(i);
				cout << y0 + 1 << " " << x0 + 1 << endl;
				return 1;
			}
		}
		return 0;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	unsigned int L;
	cin >> L;
	NotGoAI *god = new NotGoAI(L);
	//cerr << "Debug";
	char t;
	for (int y = 0; y < L; y++)
	{
		for (int x = 0; x < L; x++)
		{
			cin >> t;
			god->fillInit(x, y, t);
		}
	}

	god->UFSinit();

	unsigned int pc = 0;
	while (god->play((pc++) & 1))
	{
		/*for(int y = 0; y < L; y++)
		{
			for(int x = 0; x < L; x++)
			{
				cout << god->board[y][x] << " ";
				//cout << god->UFS[y][x].first << " ";
			}
			cout << endl;
		}*/
	}
	cout << -1 << " " << -1;


}