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
	cin >> s; 
	int result = s[0] - '0';
	for (int i = 1; i < s.length(); i++)
	{
		int num = s[i] - '0';
		//0�� �ƴ� ��쿣 ������ ���ϴ°� ���� ũ�Ƿ�
		if (num <= 1 || result <= 1)
			result += num;
		else
			result *= num;
		
	}
	cout << result << endl;
}