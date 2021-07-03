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

//���谡 ���
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int>arr; //���谡 ���� ���� ����
	int N; //���谡 ��

	cin >> N;
	//������ �Է�
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end()); //����
	
	int count = 0; //���� �׷� �ο�
	int result = 0; //�Ἲ�� �׷� ��

	for (int i = 0; i < N; i++)
	{
		count++;
		if (count >= arr[i])
		{
			result++;
			count = 0;
		}
	}
	cout << result << endl;
}