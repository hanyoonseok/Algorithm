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

//���ڿ�������
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int one = 0; //0���� 1�� ��ȯ�Ǵ� ��
	int zero = 0;//1���� 0���� ��ȯ�Ǵ� ��
	
	cin >> s; 
	int flag = s[0]-'0'; //������ �����ϴ� ������

	for (int i = 0; i < s.length(); i++)
	{
		int now = s[i] - '0';
		
		if (flag == 0 && now == 1) //0�� �󸶳� �����ϴ��� 
		{
			flag = 1;
			zero++;
		}
		else if (flag == 1 && now == 0)//1�� �󸶳� �����ϴ���
		{
			flag = 0;
			one++;
		}
	}
	cout << min(zero, one);
}