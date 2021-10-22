# 프로그래머스 x만큼 간격이 있는 n개의 숫자
`level1`
---

### 전체코드
```jsx
vector<long long> solution(int x, int n) {
	vector<long long> answer;
	for (int i = 1; i <= n; i++) 
		answer.push_back(x * i);
	
	return answer;
}
```
