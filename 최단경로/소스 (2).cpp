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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int table[501][501]; //���̺�
	 
	cin >> n >> m;

	for (int i = 0; i < 501; i++)
		fill(table[i], table[i] + 501, 1e9); //��� ���� �������� �ʱ�ȭ

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				table[i][j] = 0; //�밢������. �ڱ� �ڽ����� ���� �Ÿ� 0���� �ʱ�ȭ
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c; //a���� b�� ���� ����� c
		table[a][b] = c;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				table[j][k] = min(table[j][k], table[j][i] + table[i][k]); //�ٸ� ��� ���ļ� ���°� ������� Ȯ��
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (table[i][j] == 1e9)
				cout << "inf ";
			else
				cout << table[i][j] << ' ';
		}
		cout << endl;
	}
}
