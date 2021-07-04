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

//������ 11-4 ���� �� ���� �ݾ�
//�׸���
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;//������ ����
	vector<int> coin; //�����ִ� ������
	int target = 1; //���� �� ���� ��

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		coin.push_back(a);
	}

	sort(coin.begin(), coin.end());

	for (int i = 0; i < n; i++)
	{
		if (target < coin[i])
			break;
		target += coin[i];
	}
	cout << target << endl;
}