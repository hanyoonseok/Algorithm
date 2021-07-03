#define _CTR_SECURE_NO_WARNING
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cctype>
using namespace std;

//문자열뒤집기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int one = 0; //0에서 1로 전환되는 수
	int zero = 0;//1에서 0으로 전환되는 수
	
	cin >> s; 
	int flag = s[0]-'0'; //무엇이 연속하는 중인지

	for (int i = 0; i < s.length(); i++)
	{
		int now = s[i] - '0';
		
		if (flag == 0 && now == 1) //0이 얼마나 연속하는지 
		{
			flag = 1;
			zero++;
		}
		else if (flag == 1 && now == 0)//1이 얼마나 연속하는지
		{
			flag = 0;
			one++;
		}
	}
	cout << min(zero, one);
}