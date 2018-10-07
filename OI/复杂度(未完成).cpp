#include <iostream>
#include <stack>
#include <map>

#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) < (Y) ? (Y) : (X))

using namespace std;

stack<char> program;
map<char, bool> Vused;

int nQ, L;
char buff;

int ffuncation(int d)
{
	char buff[3];
	program.push('p');
	cin >> buff[0] >> buff[1] >> buff[2];
	if ()
}

int main()
{
	cin >> nQ;

	int s;//´Î·½Êý
	while (nQ--)
	{
		cin >> L >> buff >> buff >> buff;
		if (buff == '1')
		{
			cin >> buff;
		}
		else {
			cin >> buff >> s >> buff;
		}

		while (!program.empty())program.pop();

		while (1)
		{
			cin >> buff;
			if (buff = 'F')
			{
				ffuncation(0);
			}
		}
	}

	return 0;
}