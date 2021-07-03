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

//곱하기 혹은 더하기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s; 
	int result = s[0] - '0';
	for (int i = 1; i < s.length(); i++)
	{
		int num = s[i] - '0';
		//0이 아닌 경우엔 무조건 곱하는게 가장 크므로
		if (num <= 1 || result <= 1)
			result += num;
		else
			result *= num;
		
	}
	cout << result << endl;
}