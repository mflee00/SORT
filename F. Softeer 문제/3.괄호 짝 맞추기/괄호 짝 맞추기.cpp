// 괄호 짝 맞추기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
using namespace std;

int main(void)
{
	char input[50];
	int i, pair1 = 0, pair2 = 0, pair3 = 0;
	//freopen(“input.txt”, “rt”, stdin);
	//gets_s(input);

	for (i = 0; input[i] != '\0'; i++)
	{

		if (input[i] == '(')         pair1++;
		else if (input[i] == '[')    pair2++;
		else if (input[i] == '{')    pair3++;
		else if (input[i] == ')')    pair1--;
		else if (input[i] == ']')    pair2--;
		else if (input[i] == '}')    pair3--;

	}
	if (pair1 == 0 && pair2 == 0 && pair3 == 0) printf(" 괄호의 짝이 맞습니다.");
	else printf("괄호의 짝이 안맞습니다.");

}