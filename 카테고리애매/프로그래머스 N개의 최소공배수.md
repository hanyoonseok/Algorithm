# 프로그래머스 N개의 최소공배수 level2 
` `
---
- 최소공배수가 어떻게 형성되는지 알면 되는 문제
- N개의 수 들 중 최소공배수는 항상 가장 큰 수의 배수이다.

### 전체코드
```jsx
int solution(vector<int> arr) {
	int answer = 0;
	sort(arr.begin(), arr.end());
	int maxx = arr[arr.size() - 1]; //가장 큰 수

	for (int i = maxx; ; i += maxx) { //가장 큰 수의 배수만 검사
		bool flag = true;
		for (int j = 0; j < arr.size(); j++) {
			if (i % arr[j] != 0) { //하나라도 0으로 나눠떨어지는게 있다면 최소공배수x
				flag = false;
				break;
			}
		}
		if (flag) //모두 나누어떨어지면 최소공배수
		{
			answer = i;
			break;
		}
	}
	return answer;
}
```
