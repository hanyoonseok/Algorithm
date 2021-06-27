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

int v, M; //�л� ��, ���� ��
int parent[100001]; //�θ� ����

int findParent(int x) //���� �� ���� Ȯ��
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) //�� �Ἲ
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
		parent[i] = i; //�ڱ� �ڽ����� �θ� �ʱ�ȭ
	}
	
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0) //0 �����̸� �� �Ἲ
			unionParent(b, c);
		else //1�����̸� ���� ������ Ȯ��
		{
			if (findParent(b) == findParent(c))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}
