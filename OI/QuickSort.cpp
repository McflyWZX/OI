#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class Ts, class TR>
void quickSort(Ts *s, TR l, TR r)
{
	if (l >= r)return;
	Ts T = s[l], t;
	TR i = l, j = r;
	while (i < j)
	{
		while (T < s[j])j--;
		while (s[i] < T)i++;

		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
	quickSort(s, l, i - 1);
	quickSort(s, j + 1, r);
	return;
}
int main()
{

	return 0;
}