# SWEA 3234 [준환이의 양팔저울](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?contestProbId=AWAe7XSKfUUDFAUw&solveclubId=AX69tP7quW4DFAVm&problemBoxTitle=day0218&problemBoxCnt=1&probBoxId=AX8LHP7KK7cDFAW0)
`D4` `순열` `재귀`
---
- 모든 추를 왼쪽에만 두는 경우가 있기 때문에 결국은 모든 순열을 구해야 한다고 생각해서 우선 순열로 접근함
- 순열로 수들을 한 줄로 나열시키고 거기서 하나씩 왼쪽과 오른쪽에 달아봄
- 왼쪽은 조건이 없으니 항상 추가하고, 오른쪽은 오른쪽에 추가했을 때 왼쪽과 무게를 비교해서 더 작거나 같을 때만 넣어서 재귀 호출해줌
- 추를 왼쪽과 오른쪽 각각에 넣어보는 로직을 어떻게 짜야할지 생각이 안나서 조금 오래 걸렸다(for문을 사용해야 할 것이라 생각함) 그런데 그럴 필요 없이 어차피 cnt번에 뽑힌 수를 가지고 왼쪽에 둘지 오른쪽에 둘지를 고민하는 것이기 때문에 그냥 조건검사하고 재귀호출 해주면 되는 것이었다.

### 전체코드
```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// swea 준환이의 양팔저울 d4
public class S3234 {
	static int N; //추의 개수
	static int numbers[]; //입력받은 추들
	static int select[]; // 선택한 수
	static int ans; //정답
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringBuilder sb = new StringBuilder("#");
			N = Integer.parseInt(br.readLine());
			numbers = new int[N];
			select = new int[N];
			ans=0;
			String [] input = br.readLine().split(" ");
			
			for(int i=0; i<N; i++) numbers[i] = Integer.parseInt(input[i]);
			
			perm(0, 0);
			
			System.out.println(sb.append(t).append(" ").append(ans));
		}
	}
	
	static void perm(int cnt, int flag) {
		if(cnt == N) {
			solve(0, 0, 0);
			return;
		}
		
		for(int i=0; i<N; i++) {
			if((flag & 1<<i) != 0) continue;
			
			select[cnt] = numbers[i];
			perm(cnt+1, flag|1<<i);
		}
	}

	static void solve(int cnt, int left, int right) {
		if(cnt == N) {
			ans++;
			return;
		}
		
		solve(cnt+1, left+select[cnt], right); //왼쪽에는 항상 달아보고
		if(right+select[cnt] <= left) solve(cnt+1, left, right+select[cnt]); //오른쪽은 조건 되면 달아봄
	}
}

```
