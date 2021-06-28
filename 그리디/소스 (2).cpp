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

int v, M; //집의 수, 길의 수
int parent[100001]; //부모 정보
vector<pair<int, pair<int, int>>>edges;
int result = 0;

int findParent(int x) //같은 팀 여부 확인
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) //팀 결성
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

	cin >> v >> M;
	
	for (int i = 1; i <= v; i++)
	{
		parent[i] = i; //자기 자신으로 부모 초기화
	}
	
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} }); //a와 b를 잇는 비용이 c
	}

	sort(edges.begin(), edges.end());

	int last = 0;

	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			result += cost;
			last = cost; //가장 큰 간선 
		}
	}
	cout << result -last << endl;
}
