// OI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) < (Y) ? (Y) : (X))
#define SN 1

using namespace std;

bool HarryTime;

struct Room {
	bool isOnlyHarry, isHarryBeenThere, isBoenBeenThere;
	bool W1, W2; //表示是不是要去的点
	long HarryTime, BoenTime;
	vector<pair<int, int> > WayTo; // first toNO. second time;

	Room()
	{
		isHarryBeenThere = isBoenBeenThere = isOnlyHarry = false;
		HarryTime = BoenTime = LONG_MAX;
		W1 = W2 = false;
	}

};

struct cmp {

	bool operator () (const Room *ra, const Room *rb)
	{
		if (!HarryTime)return ra->BoenTime > rb->BoenTime;
		else return ra->HarryTime > rb->HarryTime;
	}
};

long NoR, NoW, Harrys, HT1, HT2, BT1, BT2;

void dijkstra(Room* rooms, char name)
{
	priority_queue<Room*, vector<Room*>, cmp> TQ;
	TQ.push(&(rooms[SN]));

	Room *TR;
	while (!TQ.empty()) {

		TR = TQ.top();
		TQ.pop();

		if (name == 'h')
		{
			if (TR->isHarryBeenThere)
			{
				continue;
			}
			if (TR->W1)
			{
				HT1 = TR->HarryTime;
			}
			else if(TR->W2){
				HT2 = TR->HarryTime;
			} 
			if (HT2 != -1 && HT1 != -1)
			{
				return;
			}
			TR->isHarryBeenThere = true;
			for (int i = 0; i < TR->WayTo.size(); i++)
			{
				if (!rooms[TR->WayTo[i].first].isHarryBeenThere)
				{
					rooms[TR->WayTo[i].first].HarryTime = min(rooms[TR->WayTo[i].first].HarryTime, TR->HarryTime + TR->WayTo[i].second);
					TQ.push(&(rooms[TR->WayTo[i].first]));
				}
			}
		}
		else if (name == 'b')
		{
			if (TR->isBoenBeenThere)
			{
				continue;
			}
			if (TR->W1)
			{
				BT1 = TR->HarryTime;
			}
			else if (TR->W2) {
				BT2 = TR->HarryTime;
			}
			if (BT2 != -1 && BT1 != -1)
			{
				return;
			}
			TR->isBoenBeenThere = true;
			for (int i = 0; i < TR->WayTo.size(); i++)
			{
				if (!(rooms[TR->WayTo[i].first].isBoenBeenThere || rooms[TR->WayTo[i].first].isOnlyHarry))
				{
					rooms[TR->WayTo[i].first].BoenTime = min(rooms[TR->WayTo[i].first].BoenTime, TR->BoenTime + TR->WayTo[i].second);
					TQ.push(&(rooms[TR->WayTo[i].first]));
				}
			}
		}
	}
}

int main()
{
	cin >> NoR >> NoW >> Harrys;

	Room *rooms = new Room[NoR + 1];
	rooms[1].HarryTime = rooms[1].BoenTime = 0;

	int TI;
	for (int i = 0; i < Harrys; i++)
	{
		cin >> TI;
		rooms[TI].isOnlyHarry = true;
	}

	int Tra, Trb, Ttime;
	for (int i = 0; i < NoW; i++)
	{
		cin >> Tra >> Trb >> Ttime;
		rooms[Tra].WayTo.push_back(make_pair(Trb, Ttime));
		rooms[Trb].WayTo.push_back(make_pair(Tra, Ttime));
	}
	cin >> HT1 >> BT1;//这里12等价只是做个零时变量

	rooms[HT1].W1 = true;
	rooms[BT1].W2 = true;

	HT1 = HT2 = BT1 = BT2 = -1;

	HarryTime = true;
	dijkstra(rooms, 'h');
	HarryTime = false;
	dijkstra(rooms, 'b');

	long T = min(max(HT1, HT2), min(max(HT1, BT2), max(HT2, BT1)));

	cout << T;

	return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
