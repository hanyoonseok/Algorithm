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


int N, M;//N x M 크기
int field[201][201] = { 0 }; //맵 정보
bool check[201][201] = { false }; //맵 방문 여부
int dx[4] = { 0, 0, -1, 1 }; //한 칸의 4방위를 체크하기 위함
int dy[4] = { 1, -1, 0, 0 };

int bfs()
{
	queue<pair<int, int>>que;

	//처음 시작칸 초기화
	que.push(make_pair(0, 0)); 
	check[0][0] = true;
	field[0][0] = 1;

	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		//한 칸의 4방위 체크
		for (int i = 0; i < 4; i++)
		{
			int x_ = x + dx[i];
			int y_ = y + dy[i];

			//범위 체크
			if (x_ < 0 || x_ >= N || y_ < 0 || y_ >= M)
				continue;
			if (field[x_][y_] != 0 && !check[x_][y_])
			{
				field[x_][y_] = field[x][y] + 1;
				check[x_][y_] = true;
				que.push(make_pair(x_, y_));
			}
			if (x_ == N - 1 && y_ == M - 1) //도착점 도달
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
	
	//맵 정보 입력
	//출발점(0,0)  도착점(N-1,M-1)
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> field[i][j];
			if (field[i][j] == 0) //입력받은 칸이 벽이면 방문 체크하여 다시 방문하지 않도록
				check[i][j] = true;
		}
	}

	cout<<bfs();
}