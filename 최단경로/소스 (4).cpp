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

int N, M, C;
vector<pair<int, int>>graph[30001];
int d[30001]; //C에서 i로 가는 비용

void dijkstra(int start)
{
	priority_queue<pair<int, int>>pq;
	pq.push(make_pair(0, start));
	d[start] = 0;

	while (!pq.empty())
	{
		int city = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (d[city] < dist)
			continue;
		for (int i = 0; i < graph[city].size(); i++)
		{
			int cost = dist + graph[city][i].second;

			if (cost < d[graph[city][i].first])
			{
				d[graph[city][i].first] = cost;
				pq.push(make_pair(-cost, graph[city][i].first));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> C;
	int cityNum = 0;
	int maxCost = 0;

	fill(d, d + 30001, 1e9);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c)); //a도시에서 b도시로 보내는 비용이 c
	}

	dijkstra(C);

	for (int i = 1; i <= N; i++)
	{
		if (d[i] == 1e9 || d[i]==0)
			continue;
		else {
			maxCost = max(maxCost, d[i]);
			cityNum++;
		}
	}
	cout << cityNum << " " << maxCost << endl;
}
