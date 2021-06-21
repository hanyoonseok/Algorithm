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

bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,k;
	int total = 0;

	cin >> n >> k;
	vector<int>v1(n);
	vector<int>v2(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v2[i];
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(),cmp);

	for (int i = 0; i < k; i++)
	{
		int temp = v1[i];
		v1[i] = v2[i];
		v2[i] = temp;
	}
	for (int i = 0; i < n; i++)
	{
		total += v1[i];
	}
	cout << total;
}