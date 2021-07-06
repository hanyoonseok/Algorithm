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

//���� #2468 ��������
//bfs �ʺ�켱Ž��

int N; //  N x N ����
int height; //�� ������ ��
int field[101][101] = { 0 }; //���� ���� �迭
bool check[101][101] = { false };
int result = 0; //�ִ� �������� ����
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int maxheight = 0; //���� ���� �ǹ�

void initialize()// ��� check �ʱ�ȭ
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			check[i][j] = false;
		}
	}
}

void bfs(int x, int y, int height) // �� ���� �� ����� ���� ��Ҹ� ����
{
	check[x][y] = true;//�湮 üũ

	for (int i = 0; i < 4; i++)
	{
		int x_ = x + dx[i];
		int y_ = y + dy[i];

		if (x_ >= 0 && x_ < N && y_ >= 0 && y_ < N && field[x_][y_]-height > 0 && !check[x_][y_]) //���� ����
		{
			bfs(x_, y_,height);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> field[i][j];
			maxheight = max(maxheight, field[i][j]);
		}
	}

	for (int h = 0; h <= maxheight; h++)
	{
		int temp = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (field[i][j]-h > 0 && !check[i][j])
				{
					bfs(i, j, h);
					temp++;
				}
			}
		}
		result = max(result, temp); //���� ū ���� ���� ���� ����
		initialize();//check �ʱ�ȭ
	}
	cout << result << endl;
}