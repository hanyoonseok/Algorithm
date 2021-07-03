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

//모험가 길드
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int>arr; //모험가 정보 담을 벡터
	int N; //모험가 수

	cin >> N;
	//공포도 입력
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end()); //정렬
	
	int count = 0; //현재 그룹 인원
	int result = 0; //결성된 그룹 수

	for (int i = 0; i < N; i++)
	{
		count++;
		if (count >= arr[i])
		{
			result++;
			count = 0;
		}
	}
	cout << result << endl;
}