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
	int result = 1;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		//0이 아닌 경우엔 무조건 곱하는게 가장 크므로
		if (s[i] - '0' == 0)
			continue;
		else
		{
			result *= (s[i] - '0');
		}
	}
	cout << result << endl;
}