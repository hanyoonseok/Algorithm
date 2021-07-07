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

//���� #1753 �ִܰ��
//���̽�Ʈ��

int V, N, K; //������ ����, ������ ����, ���� ������ ��ȣ
vector<pair<int, int>>graph[20001]; //���� ����
int d[20001]; //���������� i��° ���� ���� �ּ� ���

void dijkstra(int start)
{
	priority_queue<pair<int,int>> pq;
	//�ڡڡڡڡڡڼ��� �ٲٸ� �ȉΡڡڡڡڡڡڡڡڡ�
	pq.push(make_pair(0, start)); //start���� ���� ���� ����� 0
	d[start] = 0; //�������� ����� 0

	while (!pq.empty())
	{
		int node = pq.top().second; //������ �ϴ� ���
		int dist = -pq.top().first; //���� ���� ��� -
		pq.pop();

		if (d[node] < dist) //���� ������ �ּҺ�뺸�� ũ�ٸ� �н�
			continue;

		for (int i = 0; i < graph[node].size(); i++) //���� ���õ� ��忡�� �� �� �ִ� ���� �˻�
		{
			//node���� {next}�� ���� ����� cost
			int next = graph[node][i].first; 
			int cost = graph[node][i].second;

			if(d[next]> dist + cost)
			{
				d[next] = cost + dist;
				pq.push(make_pair(-d[next], next)); //�����Ÿ� �����ؾ��ؼ� cost�� -�Ⱥ���
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
		graph[a].push_back(make_pair(b,c)); //a ���� b�� ���� ����� c
	}
	
	//fill(d, d + V+1, 1e9); //�ּҰŸ� �������� �ʱ�ȭ
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