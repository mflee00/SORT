// 순열 문제.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include<iostream>

#define MAX 3
using namespace std;

int Arr[MAX];
bool Select[MAX];

void Print()
{
	for (int i = 0; i < MAX; i++)
	{
		if (Select[i] == true)
		{
			cout << Arr[i] << " ";
		}
	}
	cout << endl;

}

void DFS(int Idx, int Cnt)
{
	if (Cnt == 2)
	{
		Print();
		return;
	}

	for (int i = Idx; i < MAX; i++)
	{
		if (Select[i] == true) continue;
		Select[i] = true;

		DFS(i, Cnt + 1);
		Select[i] = false;
	}
}

int main(void)
{
	Arr[0] = 1;
	Arr[1] = 2;
	Arr[2] = 3;
	//Arr[3] = 4;
	//Arr[4] = 5;

	DFS(0, 0);
}
