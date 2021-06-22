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

int N, M;

void binary(vector<int>dduk)
{
	int start = 0;
	int end = dduk[N - 1];

	while (start <= end)
	{
		int mid = (start + end) / 2;
		long long int total = 0;

		for (int i = 0; i < N; i++)
		{
			if (dduk[i] > mid)
				total += (dduk[i] - mid);
		}

		if (total == M)
		{
			cout << mid;
			break;
		}
		else if (total > M)
		{
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N>>M;
	vector<int>dduk(N);

	for (int i = 0; i < N; i++)
	{
		cin >> dduk[i];
	}

	binary(dduk);
}