#include <iostream>

unsigned long quickPow(unsigned long b, unsigned long p, unsigned long &k)
{
	b %= k;
	if (p == 1 || p == 0)return b;
	if (p % 2 == 0)
	{
		return quickPow(b * b, p / 2, k);
	}
	else {
		return quickPow(b * b, (p - 1) / 2, k) * b % k;
	}
}

int main()
{
	unsigned long b, p, k;
	std::cin >> b >> p >> k;

	std::cout << b << "^" << p << " mod " << k << "=";
	if (p == 0)
	{
		std::cout << 1 % k;
		return 0;
	}

	std::cout << quickPow(b, p, k);

	return 0;
}