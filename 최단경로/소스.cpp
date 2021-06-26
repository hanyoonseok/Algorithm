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

int n, m, start;
vector<pair<int, int>>graph[100001]; //���� ���� ���� �迭
int d[100001];//�ּ� �Ÿ�

void dijkstra(int start)
{
	priority_queue<pair<int, int>>pq;
	d[start] = 0;
	pq.push({ 0, start }); //���۳��� �������� ����� 0

	while (!pq.empty())
	{
		int dist = -pq.top().first;//���� �������� �Ÿ�
		int node = pq.top().second; //���� ���
		pq.pop();

		if (d[node] < dist) //�湮���� Ȯ��
			continue;

		for (int i = 0; i < graph[node].size(); i++) //���� ���õ� ��忡�� �� �� �ִ� ������ �˻�
		{
			int cost = graph[node][i].second + dist; //���� ��忡�� �� �� �ִ� �������� �Ÿ� + ����������� �Ÿ�

			if (cost < d[graph[node][i].first]) //���� ����� �ּ� �Ÿ��̸� 
			{
				d[graph[node][i].first] = cost; //�ּҰŸ� �ʱ�ȭ
				pq.push(make_pair(-cost, graph[node][i].first));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> start; //��� ��, ���� ��, ���� ���

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c }); //a���� b�� ���� ����� c
	}
	fill(d, d + 100001, 1e9); //�������� �ʱ�ȭ

	dijkstra(start);

	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 1e9)
			cout << "infinity" << endl;
		else
			cout << d[i] << endl;
	}
}
