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
    int d[30001] = { 0 };
    int x;
    cin >> x;
    // 다이나믹 프로그래밍(Dynamic Programming) 진행(보텀업)
    for (int i = 2; i <= x; i++) {
        //모든 경우에서 -1 값을 가질 수 있음
        d[i] = d[i - 1] + 1;
        // 현재의 수가 2로 나누어 떨어지는 경우
        if (i % 2 == 0)
            d[i] = min(d[i], d[i / 2] + 1);
        // 현재의 수가 3으로 나누어 떨어지는 경우
        if (i % 3 == 0)
            d[i] = min(d[i], d[i / 3] + 1);
        // 현재의 수가 5로 나누어 떨어지는 경우
        if (i % 5 == 0)
            d[i] = min(d[i], d[i / 5] + 1);
    }
    cout << d[x] << '\n';
}
