// 비밀 메뉴2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
int patten1[3001];
int patten2[3001];
int Arr[3001];
bool Select[3001];

bool findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0, patternHash = 0, power = 1;
	for (int i = 0; i <= parentSize - patternSize; i++) {
		if (i == 0) {
			for (int j = 0; j < patternSize; j++) {
				parentHash = parentHash +
					parent[patternSize - 1 - j] * power;
				patternHash = patternHash +
					pattern[patternSize - 1 - j] * power;
				if (j < patternSize - 1) power = power * 2;
			}
		}
		else {
			parentHash = 2 * (parentHash - parent[i - 1] * power) +
				parent[patternSize - 1 + i];
		}
		if (parentHash == patternHash) {
			bool finded = true;
			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) {
					finded = false;
					break;
				}
			}
			return finded;
			//if (finded) {
			//	printf("%d번째에서 발견했습니다.\n", i + 1);
			//}
		}
	}
}
string s_pattern1;
string s_pattern2;

/*
void Print(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (Select[i] == true)
		{
			//cout << s_pattern2[i] << " ";
			s_temp += s_pattern2[i];
		}
	}
	//cout << endl;

}
*/

vector <int> index;
void DFS(int Idx, int Cnt, int n, int dep)
{

	if (Cnt == dep)
	{
		string s_temp;
		for (int i = 0; i < n; i++)
		{
			if (Select[i] == true)
			{
				index.push_back(i);
				//cout << s_pattern2[i] << " ";
				//s_temp += s_pattern2[i];
			}
		}
		return;
	}

	for (int i = Idx; i < n; i++)
	{
		if (Select[i] == true) continue;
		Select[i] = true;

		DFS(i, Cnt + 1,n, dep);
		Select[i] = false;
	}
}



int main()
{
	
	vector<int> cnt;
	
	char   temp;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		s_pattern1 += temp;
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		s_pattern2 += temp;
	}

	
	int size = 0;

	if(n<m)
	{
		size = n;
		swap(s_pattern1, s_pattern2);
	}
	else
	{
		size = n;
	}
	
	//for (int i = 0; i < size; i++) {
		/*
		s_temp  = (s_pattern2[0]);
		if (findString(s_pattern1, s_temp) == true)
		{
			//cnt.push_back(i);
			cout << 0;
		}
		s_temp = (s_pattern2[1]);
		if (findString(s_pattern1, s_temp) == true)
		{
			//cnt.push_back(i);
			cout << 1;
		}
		s_temp = (s_pattern2[2]);
		if (findString(s_pattern1, s_temp) == true)
		{
			//cnt.push_back(i);
			cout << 2;
		}
		s_temp = "23";
		if (findString(s_pattern1, s_temp) == true)
		{
			//cnt.push_back(i);
			cout << 3;
		}
		if (findString(s_pattern1, s_temp) == true)
		{
			//cnt.push_back(i);
			cout << 4;
		}
		s_temp = "31";
		if (findString(s_pattern1, s_temp) == true)
		{
			//cnt.push_back(i);
			cout << 5;
		}
		s_temp = "231";
		if (findString(s_pattern1, s_temp) == true)
		{
			//cnt.push_back(i);
			cout << 6;
		}
		*/
	//}
	for (int i = 0; i < size; i++) { // 0 1 2
		string s_temp;
		DFS(0, 0, size, i+1);

		int k = 0;

		while(k < index.size() )  // 3 6 16
		{
			for (int j = 0; j < 1+i; j++)  // 1 2 3 
			{
				s_temp += s_pattern2[index[k++]];
			}
			
			if (findString(s_pattern1, s_temp) == true)
			{
				cnt.push_back(i+1);
				//cout << 6;
			}
			s_temp.clear();
		}
		index.clear();
		
		
		
	}
	
	cout << *max_element(cnt.begin(), cnt.end());
	

	return 0;
}



