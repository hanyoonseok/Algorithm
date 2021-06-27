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

int v, e; //��� ��, ���� ��
int indegree[100001]; //��������
vector<int>graph[100001]; //���� ����

void topologySort()
{
	vector<int>result; //�������� ��� ���� �迭
	queue<int>q;

	for (int i = 1; i <= v; i++)
	{
		if (indegree[i] == 0) { //���������� 0�̸� ť�� ����
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();

		q.pop();
		result.push_back(now);
		
		for (int i = 0; i < graph[now].size(); i++) //���õ� ���� ������ ������ ���������� 1�� ����
		{
			indegree[graph[now][i]] -= 1;
			if (indegree[graph[now][i]] == 0) { //���������� 0�� �� ������ ����
				q.push(graph[now][i]);
			}
		}
	}

	for (int i = 0; i < result.size(); i++) //�������� ��� ���
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
		graph[a].push_back(b); //a���� b�� �̵�����
		indegree[b] += 1; //�������� 1�� ����
	}

	topologySort();
}
