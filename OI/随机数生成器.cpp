#include "pch.h"
#include <iostream>
#include <time.h>
#include <windows.h>

#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) < (Y) ? (Y) : (X))

int l, r, e;

int main()
{
	FILETIME ft;

	std::cout << "��ӭʹ�����ĵ������������" << std::endl;
	std::cout << "�����������������:";
	std::cin >> l;
	std::cout << std::endl << "�����������������:";
	std::cin >> r;
	std::cout << std::endl << "���س���ȡ�����" << std::endl;

	std::cin.get();

	while (std::cin.get())
	{
		GetSystemTimeAsFileTime(&ft);
		srand(ft.dwLowDateTime);
		std::cout << rand() % (r - l + 1) + l << std::endl;
	}

	return 0;
}