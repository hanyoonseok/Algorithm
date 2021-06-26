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

int N, M, X, K; //��� �� , ���� ��, ��ǥ ȸ��, �Ұ���ȸ��
int d[101][101] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i <= N; i++) //�������� �ʱ�ȭ
		fill(d[i], d[i] + 101, 1e9);

	for (int i = 1; i <= N; i++) //�ڱ� �ڽ����� ���� ��Ʈ ��� 0 �ʱ�ȭ
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				d[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++) //���� �Է�
	{
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
		d[b][a] = 1;
	}

	cin >> X >> K;

	for (int i = 1; i <= N; i++) //�÷��̵����
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}

	bool flag = true;
	int total = 0;

	//�� �� ������ -1 ���
	d[1][K] != 1e9 ? total += d[1][K] : flag = false;
	d[K][X] != 1e9 ? total += d[K][X] : flag = false;

	if (flag)
		cout << total << endl;
	else
		cout << "-1" << endl;
}
