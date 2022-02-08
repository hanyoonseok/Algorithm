# SWEA 1225 [S/W 문제해결 기본 7일차 - 암호생성기](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AX69tP7quW4DFAVm&contestProbId=AV14uWl6AF0CFAYD&probBoxId=AX7Xk6266eYDFAVm&type=PROBLEM&problemBoxTitle=day0208&problemBoxCnt=3)
`D3` `큐`
---
- 최전방에 있는 숫자를 삭제하고, 최후방에 추가하기 때문에 `Queue` 자료구조 사용하여 접근
- 전방에 있는 숫자를 꺼낸 후 감소시킬 숫자와 합했을 때 0인지 검사해서 해결함
- 큐를 사용할 줄 알면 쉬웠던 문제

### 전체코드
```jsx
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

//S/W 문제해결 기본 7일차 - 암호생성기
public class SWEA1225 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int t=0; t<10; t++) {
			Queue<Integer>q = new LinkedList<>(); //숫자 담을 큐
			int tc = Integer.parseInt(br.readLine()); //테케
			int dec = 1; //감소할 숫자
			String numbers = br.readLine(); //입력받은 숫자들
			StringTokenizer st = new StringTokenizer(numbers, " ");
			while(st.hasMoreTokens()) 
				q.add(Integer.parseInt(st.nextToken())); //큐에 담음
			
			while(true) {
				int top = q.peek(); //큐의 제일 앞에 있는 숫자 
				q.poll();
				if(dec > 5) //숫자가 5를 넘어가면 다시 1부터 초기화
					dec=1;
				if(top - dec <= 0 ) { //감소시켰을 때 0보다 작거나 같다면 종료
					q.add(0);
					break;
				}
				q.add(top-dec); //감소한 숫자 담음
				dec++; //감소할 숫자 증가
			}
			
			System.out.print("#"+tc + " ");
			int len = q.size();
			for(int i=0; i<len; i++) {
				System.out.print(q.peek() + " ");
				q.poll();
			}
			System.out.println();
		}
	}

}

```
