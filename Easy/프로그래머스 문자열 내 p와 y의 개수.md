# 프로그래머스 문자열 내 p와 y의 개수
`level1`
---

### 전체코드
```jsx
bool solution(string s)
{
	bool answer = true;
	int p=0, y=0;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'p')
			p++;
		else if (s[i] == 'y')
			y++;
	}
	answer = p == y ? true : false;
	return answer;
}
```
