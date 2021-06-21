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


int N, M;//N x M ũ��
int field[201][201] = { 0 }; //�� ����
bool check[201][201] = { false }; //�� �湮 ����
int dx[4] = { 0, 0, -1, 1 }; //�� ĭ�� 4������ üũ�ϱ� ����
int dy[4] = { 1, -1, 0, 0 };

int bfs()
{
	queue<pair<int, int>>que;

	//ó�� ����ĭ �ʱ�ȭ
	que.push(make_pair(0, 0)); 
	check[0][0] = true;
	field[0][0] = 1;

	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		//�� ĭ�� 4���� üũ
		for (int i = 0; i < 4; i++)
		{
			int x_ = x + dx[i];
			int y_ = y + dy[i];

			//���� üũ
			if (x_ < 0 || x_ >= N || y_ < 0 || y_ >= M)
				continue;
			if (field[x_][y_] != 0 && !check[x_][y_])
			{
				field[x_][y_] = field[x][y] + 1;
				check[x_][y_] = true;
				que.push(make_pair(x_, y_));
			}
			if (x_ == N - 1 && y_ == M - 1) //������ ����
				break;
		}
	}
	return field[N - 1][M - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> M;
	
	//�� ���� �Է�
	//�����(0,0)  ������(N-1,M-1)
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> field[i][j];
			if (field[i][j] == 0) //�Է¹��� ĭ�� ���̸� �湮 üũ�Ͽ� �ٽ� �湮���� �ʵ���
				check[i][j] = true;
		}
	}

	cout<<bfs();
}