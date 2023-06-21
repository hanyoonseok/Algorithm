# 프로그래머스 [n진수 게임](https://school.programmers.co.kr/learn/courses/30/lessons/17687)
`level2` `문자열` `수학`
---
- java의 `Integer.toString(num, 진수)`의 사용을 모른다면 훨씬 어려워지는 문제
- 입력으로 주어지는 n진수로 m명의 참가자가 t만큼의 숫자를 할당받을 수 있을 때까지 수를 파싱하여 문자열을 만들고
- 이를 p-1번째부터 매 m번째 수를 구하여 더해주면 풀리는 문제

### 전체코드
```java
public class P_n진수게임 {
	static public String solution(int n, int t, int m, int p) {
        String answer = "";
        String parsed = getRadix(n, t, m);
        
        for(int i=p-1; answer.length()!=t; i+=m) answer += Character.toUpperCase(parsed.charAt(i));
        return answer;
  }
	
	/*
	 * @param(n : 진법, t : 미리 구할 숫자의 개수, m : 게임에 참가하는 인원)
	 * */
	static String getRadix(int n, int t, int m) {
		String radix = "";
		int num = 0;
		
		while(radix.length() < t*m) {
			String parsed = Integer.toString(num++, n);
			radix += parsed;
		}
		
		return radix;
	}
}
```
