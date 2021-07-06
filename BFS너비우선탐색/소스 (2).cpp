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

//백준 #2468 안전영역
//bfs 너비우선탐색

int N; //  N x N 지역
int height; //비가 내리는 양
int field[101][101] = { 0 }; //정보 담을 배열
bool check[101][101] = { false };
int result = 0; //최대 생성가능 지역
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int maxheight = 0; //가장 높은 건물

void initialize()// 모든 check 초기화
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			check[i][j] = false;
		}
	}
}

void bfs(int x, int y, int height) // 비 왔을 때 잠기지 않은 장소만 들어옴
{
	check[x][y] = true;//방문 체크

	for (int i = 0; i < 4; i++)
	{
		int x_ = x + dx[i];
		int y_ = y + dy[i];

		if (x_ >= 0 && x_ < N && y_ >= 0 && y_ < N && field[x_][y_]-height > 0 && !check[x_][y_]) //범위 제한
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
		result = max(result, temp); //가장 큰 지역 나온 수를 저장
		initialize();//check 초기화
	}
	cout << result << endl;
}