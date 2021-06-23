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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long d[100];

	d[1] = 1;
	d[2] = 1;
	int n = 50; //50번째까지의 피보나치 구함

	for (int i = 3; i <= 50; i++) //bottom-up 방식
	{
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n] << endl;
}