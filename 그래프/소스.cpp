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

int v, M; //학생 수, 연산 수
int parent[100001]; //부모 정보

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

		if (a == 0) //0 연산이면 팀 결성
			unionParent(b, c);
		else //1연산이면 같은 팀인지 확인
		{
			if (findParent(b) == findParent(c))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}
