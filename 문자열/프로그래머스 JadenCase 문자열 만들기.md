# 프로그래머스 JadenCase 문자열 만들기 level2
`문자열`
--- 
- 처음엔 `sstream`으로 공백마다 구분지어서 첫 글자만 대문자화 한 후 붙이는 식으로 접근함
- 이 방법으로 했을 경우, 문자열 사이에 공백을 넣어주어야 하고, 마지막 문자열에 공백이 있을 경우의 예외처리가 까다로웠음.
- 그래서 문자열 전체를 소문자화 하고, 공백이 나온 뒤의 문자만 대문자화 하는 방법으로 해결

### 전체코드
```jsx
string solution(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower); //문자열 전체를 소문자화
	s[0] = toupper(s[0]); //첫 글자만 대문자로

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') { //공백이라면
			if (i + 1 < s.length() - 1) //마지막 인덱스가 아니라면
				s[i + 1] = toupper(s[i + 1]); //대문자화
		}
	}
	
	return s;
}
```
