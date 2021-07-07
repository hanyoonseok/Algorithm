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
#define endl "\n"
using namespace std;

//백준 #1753 최단경로
//다이스트라

int V, N, K; //정점의 개수, 간선의 개수, 시작 정점의 번호
vector<pair<int, int>>graph[20001]; //간선 정보
int d[20001]; //시작점에서 i번째 노드로 가는 최소 비용

void dijkstra(int start)
{
	priority_queue<pair<int,int>> pq;
	//★★★★★★순서 바꾸면 안됌★★★★★★★★★
	pq.push(make_pair(0, start)); //start노드로 가기 위한 비용이 0
	d[start] = 0; //시작점의 비용은 0

	while (!pq.empty())
	{
		int node = pq.top().second; //가려고 하는 노드
		int dist = -pq.top().first; //노드로 가는 비용 -
		pq.pop();

		if (d[node] < dist) //만약 기존의 최소비용보다 크다면 패스
			continue;

		for (int i = 0; i < graph[node].size(); i++) //현재 선택된 노드에서 갈 수 있는 노드들 검사
		{
			//node에서 {next}로 가는 비용이 cost
			int next = graph[node][i].first; 
			int cost = graph[node][i].second;

			if(d[next]> dist + cost)
			{
				d[next] = cost + dist;
				pq.push(make_pair(-d[next], next)); //누적거리 저장해야해서 cost에 -안붙임
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> N >> K; 

	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b,c)); //a 에서 b로 가는 비용이 c
	}
	
	//fill(d, d + V+1, 1e9); //최소거리 무한으로 초기화
	for (int i = 1; i <= V; i++)
		d[i] = 1e9;

	dijkstra(K);

	for (int i = 1; i <= V; i++)
	{
		if (d[i] == 1e9)
			cout << "INF" << endl;
		else
		cout << d[i]<<endl;
	}
	return 0;
}