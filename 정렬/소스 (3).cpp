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

int v;
int indegree[501]; //진입차수
vector<int>graph[501]; //간선정보
int times[501]; //각 강의 시간

void topologySort() {
	vector<int>result(501);
	for (int i = 1; i <= v; i++)
		result[i] = times[i];

	queue<int>q;

	//진입차수가 0인 노드를 큐에 넣음
	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		//해당원소와 연결된 노드들의 진입차수 -1
		for (int i = 0; i < graph[now].size(); i++)
		{
			result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
			indegree[graph[now][i]] -= 1;

			//새롭게 진입차수 0되는 노드를 삽입
			if (indegree[graph[now][i]] == 0) {
				q.push(graph[now][i]);
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		cout << result[i] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v;
	
	for (int i = 1; i <= v; i++)
	{
		int x; 
		cin >> x;
		times[i] = x;

		//해당 강의를 듣기 위해 먼저 들어야하는 강의 번호 입력
		while (true) {
			cin >> x;
			if (x == -1)
				break;
			indegree[i] += 1;
			graph[x].push_back(i);
		}
	}
	topologySort();
}
