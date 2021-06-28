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
int indegree[501]; //��������
vector<int>graph[501]; //��������
int times[501]; //�� ���� �ð�

void topologySort() {
	vector<int>result(501);
	for (int i = 1; i <= v; i++)
		result[i] = times[i];

	queue<int>q;

	//���������� 0�� ��带 ť�� ����
	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		//�ش���ҿ� ����� ������ �������� -1
		for (int i = 0; i < graph[now].size(); i++)
		{
			result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
			indegree[graph[now][i]] -= 1;

			//���Ӱ� �������� 0�Ǵ� ��带 ����
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

		//�ش� ���Ǹ� ��� ���� ���� �����ϴ� ���� ��ȣ �Է�
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
