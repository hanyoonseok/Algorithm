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

int v, e;
int parent[100001];
vector< pair<int, pair<int, int>>>edges;
int result=0;

int findParent(int x) {
	if (x == parent[x])return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	for (int i = 1; i <= v; i++) //�θ� �ڱ� �ڽ����� �ʱ�ȭ
	{
		parent[i] = i;
	}
	for (int i = 0; i < e; i++) //�����Է�
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edges.push_back({ cost,{a,b} });
	}
	sort(edges.begin(), edges.end()); //������ �������� ����

	//��� ���� Ȯ��
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		//����Ŭ�� �߻����� �ʴ� ��쿡�� ���տ� ����
		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			result += cost;
		}
	}
	cout << result << endl;
}
