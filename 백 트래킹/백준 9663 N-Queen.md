# 백준 #9663 [N-Queen](https://www.acmicpc.net/problem/9663)
`골드5` `백 트래킹`
---
- 0번 행부터 N번 행까지 재귀를 돌리는데 재귀 호출을 하기 전에 선택된 열에 퀸을 두는 것이 가능한지를 먼저 검사하고 안되면 continue 시켜버리기 때문에 재귀 호출되는 열은 모두 뒀을 대 문제가 없는 열만 들어옴. 그래서 파라미터의 row가 N에 도달했을 때는 그 모든 가능한 경우를 검사하고 도달했다는 것이기 때문에 그냥 정답을 ++ 해주면 됨.
- 퀸을 둘 수 있는 자리인지 검사하는 로직에서 대각선 검사부분 로직이 안 떠올랐는데 `현재 행 - i번 퀸의 행 == |현재 열 - i번째 퀸의 열|` 이면 대각선에 있는 로직임

### 전체코드
```java
import java.util.Scanner;

public class B9663 {
	static int N; //N queen
	static int m[]; //체스판 정보
	static int ans = 0; //정답
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		m = new int[N];
		
		setQueen(0);
		System.out.println(ans);
	}

	static void setQueen(int row) { // row: 현재 행
		if(row == N) { //마지막 행까지 도달하면 퀸을 다 놓을 수 있었다는 것
			ans++;
			return;
		}
		
		for(int i=0; i<N; i++) { //i : column
			if(!canSet(row, i)) continue; //놓을 수 없는 자리면 건너뜀
			
			m[row] = i; //퀸 놓고
			setQueen(row+1); //재귀 호출
		}
	}
	
	static boolean canSet(int row, int col) {
		for(int i=0; i<row; i++) { //같은 열이거나 대각선이면 false
			if(m[i] == col || row-i == Math.abs(col - m[i])) return false;
		}
		
		return true;
	}
}

```
