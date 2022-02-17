# SWEA #1247 [S/W 문제해결 응용 3일차 - 최적경로](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?contestProbId=AV15OZ4qAPICFAYD&solveclubId=AX69tP7quW4DFAVm&problemBoxTitle=day0217&problemBoxCnt=1&probBoxId=AX8GyiIKWHMDFAW0)
`D5` `순열` `재귀
---
- 백트래킹을 풀고 난 뒤라 이것도 백트래킹으로 풀어야 하나 했는데, 그냥 순열로 모두 다 살펴봐야 한다고 하셔서 순열로 접근
- 다 선택했을 때 선택한 것들로 소요 거리를 측정하고 정답을 갱신해주면 됨
- 이런 비슷한 유형을 푸는 방법에 다익스트라도 있어서 그 방법으로도 풀어봐야겠음.

### 전체코드
```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//SWEA S/W문제해결 응용 3일차 - 최적경로 D5 다익스트라로도 풀어보자
public class S1247 {
	static int N; //고객 수
	static int office[]; //회사 좌표
	static int home[]; //집 좌표
	static int customer[][]; // i번 고객의 좌표 [0][1]
	static int select[]; //i번으로 선택한 고객의 인덱스
	static boolean visit[]; //방문 처리
	static int ans; //정답
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		final int T = Integer.parseInt(br.readLine());
		office = new int[2];
		home = new int[2];
		
		for(int t=1; t<=T; t++) {
			//변수 초기화
			StringBuilder sb = new StringBuilder();
			N = Integer.parseInt(br.readLine());
			String [] inputs = br.readLine().split(" ");
			customer = new int [N][2];
			visit = new boolean[N];
			select = new int[N];
			home = new int[2];
			office = new int[2];
			ans = Integer.MAX_VALUE;
			
			//입력
			for(int i=0; i<4; i++) {
				if(i<2) office[i] = Integer.parseInt(inputs[i]);
				else home[i-2] = Integer.parseInt(inputs[i]);
			}
			for(int i=4; i<inputs.length; i++) customer[i/2- 2][i%2] = Integer.parseInt(inputs[i]);
			
			deliver(0);

			System.out.println(sb.append("#").append(t).append(" ").append(ans));
		}
	}
	
	static void deliver(int cnt) {
		if(cnt == N) {
			int temp = 0;
			for(int i=0; i<N; i++) {
				if(i==0) temp += Math.abs(office[0]-customer[select[i]][0]) + Math.abs(office[1] - customer[select[i]][1]);
				else temp += Math.abs(customer[select[i]][0] - customer[select[i-1]][0]) + Math.abs(customer[select[i]][1] - customer[select[i-1]][1]);
			}
			temp+= Math.abs(home[0] - customer[select[N-1]][0]) + Math.abs(home[1] - customer[select[N-1]][1]);
			ans = Math.min(ans,  temp);
			
			return;
		}
		
		for(int i=0; i<N; i++) {
			if(visit[i]) continue;
			
			select[cnt] = i;
			visit[i]=true;
			deliver(cnt+1);
			visit[i]=false;
		}
	}

}

```
