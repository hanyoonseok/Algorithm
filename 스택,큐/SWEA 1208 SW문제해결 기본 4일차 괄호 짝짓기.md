# SWEA 1208 [SW문제해결 기본 4일차 괄호 짝짓기](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AX69tP7quW4DFAVm&contestProbId=AV14eWb6AAkCFAYD&probBoxId=AX7Xk6266eYDFAVm&type=PROBLEM&problemBoxTitle=day0208&problemBoxCnt=1)
`D4` `스택`
---
- 비슷한 유형의 문제를 프로그래머스와 백준에서 풀어본 적 있어서 쉽게 풀 수 있었다.
- 원래는 모든 괄호의 검사가 끝나고 스택에 아직 열린 괄호가 남아있을 때에 대한 예외처리를 해줘야 하는데, 이 문제에서는 해주지 않아야 정답이었음.
- 괄호가 짝 지어지는 조건은 닫힌 괄호일 때 스택의 최상단에 있는 괄호가 자신과 짝이어야 함. 짝이라면 스택의 상단 괄호를 제거.

### 전체코드
```jsx
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

//S/W 문제해결 기본 4일차 - 괄호 짝짓기
public class SWEAday4 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Stack<Character> st = new Stack<Character>(); //괄호 담을 스택
		
		for(int t=1; t<=10; t++) {
			int N = Integer.parseInt(br.readLine());
			String info = br.readLine(); //입력받은 괄호들
			int isValid = 1; // 유효성 여부
			
			for(int i=0; i<info.length(); i++) {
				char current =info.charAt(i); //i번째 괄호
				if(current == '}') {
					if(!st.isEmpty() && st.peek() == '{') st.pop(); //스택이 비어있지 않고 최상단 괄호가 자신과 짝이라면 제거
					else { //짝이 아니거나 스택 비어있으면 유효성x
						isValid=0;
						break;
					}
				}else if(current == ']') {
					if(!st.isEmpty() && st.peek() == '[') st.pop();
					else {
						isValid=0;
						break;
					}
				}else if(current == ')') {
					if(!st.isEmpty() && st.peek() == '(') st.pop();
					else {
						isValid=0;
						break;
					}
				}else if(current == '>') {
					if(!st.isEmpty() && st.peek() == '<') st.pop();
					else {
						isValid=0;
						break;
					}
				}else 
					st.push(current);
			}
			System.out.println("#"+t+" " + isValid);
		}
	}
}


```
