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

//������ 11-5 ����������
//�׸���
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; //������ ��, ������ �ִ빫��
	cin >> N >> M;

	vector<int>ball(N);
	int total = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> ball[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (ball[i] != ball[j])
				total++;
		}
	}
	cout << total << endl;
}