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
int arr[1000001] = { 0 };
int arr1[100001] = { 0 };

void binary(int target, int start, int end)
{
	if (start >end)
	{
		cout << "no ";
		return;
	}

	int mid = (start + end) / 2;
	if (arr[mid] == target)
	{
		cout << "yes ";
		return;
	}
	else if (arr[mid] > target)
		binary(target, start, mid - 1);
	else
		binary(target, mid + 1, end);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> arr1[i];

	sort(arr, arr + N);

	for (int i = 0; i < M; i++)
	{
		binary(arr1[i], 0, N-1);
	}
}