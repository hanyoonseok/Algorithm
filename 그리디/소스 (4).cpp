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

//���ϱ� Ȥ�� ���ϱ�
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
		//0�� �ƴ� ��쿣 ������ ���ϴ°� ���� ũ�Ƿ�
		if (s[i] - '0' == 0)
			continue;
		else
		{
			result *= (s[i] - '0');
		}
	}
	cout << result << endl;
}