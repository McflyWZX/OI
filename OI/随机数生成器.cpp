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

	std::cout << "欢迎使用无聊的随机数生成器" << std::endl;
	std::cout << "请输入随机整数下限:";
	std::cin >> l;
	std::cout << std::endl << "请输入随机整数上限:";
	std::cin >> r;
	std::cout << std::endl << "按回车获取随机数" << std::endl;

	std::cin.get();

	while (std::cin.get())
	{
		GetSystemTimeAsFileTime(&ft);
		srand(ft.dwLowDateTime);
		std::cout << rand() % (r - l + 1) + l << std::endl;
	}

	return 0;
}