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

int v, e; //노드 수, 간선 수
int indegree[100001]; //진입차수
vector<int>graph[100001]; //간선 정보

void topologySort()
{
	vector<int>result; //위성정렬 결과 담을 배열
	queue<int>q;

	for (int i = 1; i <= v; i++)
	{
		if (indegree[i] == 0) { //진입차수가 0이면 큐에 담음
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();

		q.pop();
		result.push_back(now);
		
		for (int i = 0; i < graph[now].size(); i++) //선택된 노드와 인접한 노드들의 진입차수를 1씩 낮춤
		{
			indegree[graph[now][i]] -= 1;
			if (indegree[graph[now][i]] == 0) { //진입차수가 0이 된 노드들을 담음
				q.push(graph[now][i]);
			}
		}
	}

	for (int i = 0; i < result.size(); i++) //위상정렬 결과 출력
	{
		cout << result[i] << " ";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); //a에서 b로 이동가능
		indegree[b] += 1; //진입차수 1씩 증가
	}

	topologySort();
}
