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

int N, M, X, K; //노드 수 , 간선 수, 목표 회사, 소개팅회사
int d[101][101] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i <= N; i++) //무한으로 초기화
		fill(d[i], d[i] + 101, 1e9);

	for (int i = 1; i <= N; i++) //자기 자신으로 가는 루트 비용 0 초기화
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				d[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++) //간선 입력
	{
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
		d[b][a] = 1;
	}

	cin >> X >> K;

	for (int i = 1; i <= N; i++) //플로이드워셜
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

	//갈 수 없으면 -1 출력
	d[1][K] != 1e9 ? total += d[1][K] : flag = false;
	d[K][X] != 1e9 ? total += d[K][X] : flag = false;

	if (flag)
		cout << total << endl;
	else
		cout << "-1" << endl;
}
