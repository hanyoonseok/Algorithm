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
vector<pair<int, int>>graph[100001]; //간선 정보 담은 배열
int d[100001];//최소 거리

void dijkstra(int start)
{
	priority_queue<pair<int, int>>pq;
	d[start] = 0;
	pq.push({ 0, start }); //시작노드로 가기위한 비용은 0

	while (!pq.empty())
	{
		int dist = -pq.top().first;//현재 노드까지의 거리
		int node = pq.top().second; //현재 노드
		pq.pop();

		if (d[node] < dist) //방문여부 확인
			continue;

		for (int i = 0; i < graph[node].size(); i++) //현재 선택된 노드에서 갈 수 있는 노드들을 검사
		{
			int cost = graph[node][i].second + dist; //현재 노드에서 갈 수 있는 노드까지의 거리 + 현재노드까지의 거리

			if (cost < d[graph[node][i].first]) //위의 비용이 최소 거리이면 
			{
				d[graph[node][i].first] = cost; //최소거리 초기화
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

	cin >> n >> m >> start; //노드 수, 간선 수, 시작 노드

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c }); //a에서 b로 가는 비용이 c
	}
	fill(d, d + 100001, 1e9); //무한으로 초기화

	dijkstra(start);

	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 1e9)
			cout << "infinity" << endl;
		else
			cout << d[i] << endl;
	}
}
