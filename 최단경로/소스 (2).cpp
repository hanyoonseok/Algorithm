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
	int table[501][501]; //테이블
	 
	cin >> n >> m;

	for (int i = 0; i < 501; i++)
		fill(table[i], table[i] + 501, 1e9); //모든 간선 무한으로 초기화

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				table[i][j] = 0; //대각선방향. 자기 자신으로 가는 거리 0으로 초기화
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c; //a에서 b로 가는 비용이 c
		table[a][b] = c;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				table[j][k] = min(table[j][k], table[j][i] + table[i][k]); //다른 노드 거쳐서 오는게 가까운지 확인
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
