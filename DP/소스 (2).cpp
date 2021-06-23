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
    // ���̳��� ���α׷���(Dynamic Programming) ����(���Ҿ�)
    for (int i = 2; i <= x; i++) {
        //��� ��쿡�� -1 ���� ���� �� ����
        d[i] = d[i - 1] + 1;
        // ������ ���� 2�� ������ �������� ���
        if (i % 2 == 0)
            d[i] = min(d[i], d[i / 2] + 1);
        // ������ ���� 3���� ������ �������� ���
        if (i % 3 == 0)
            d[i] = min(d[i], d[i / 3] + 1);
        // ������ ���� 5�� ������ �������� ���
        if (i % 5 == 0)
            d[i] = min(d[i], d[i / 5] + 1);
    }
    cout << d[x] << '\n';
}
