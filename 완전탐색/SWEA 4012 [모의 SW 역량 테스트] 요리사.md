# SWEA 4012 [[모의 SW 역량 테스트] 요리사](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AX69tP7quW4DFAVm&contestProbId=AWIeUtVakTMDFAVH&probBoxId=AX8Aq1jqLIADFAW0&type=PROBLEM&problemBoxTitle=day0216&problemBoxCnt=1)
`조합` 
---
- SWEA에 예시 input 값이 많아서 ...으로 나올 때는 꼭 **파일로 주어진 input**으로 테스트 하자.
- 재료를 절반으로 나눈다는 것을 'N개의 재료 중 절반만큼 뽑는다'로 취급하기로 하고 이를 통해 뽑지 않은 나머지 인덱스를 구하기로 접근
- 절반만큼 뽑았을 때, 뽑지 않은 인덱스를 담은 배열을 만들어주고 두 배열을 모두 돌면서 각 음식에 맛을 더해줌. 그리고 이 둘의 차가 정답보다 작을 때 갱신

### 전체코드
```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class S4012 {

	static int ans; //정답
	static int [][] synergy; //음식 시너지
	static int numbers[]; //가능한 인덱스들
	static int select []; //선택한 인덱스
	static int N; //재료의 개수
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb;
		final int T = Integer.parseInt(br.readLine());

		for(int t=1; t<=T; t++) {
			//init variables
			N = Integer.parseInt(br.readLine());
			ans=Integer.MAX_VALUE;
			numbers = new int[N];
			synergy = new int[N][N];
			select = new int[N/2];
			
			//inputs
			for(int i=0; i<N; i++) {
				numbers[i] = i;
				StringTokenizer st = new StringTokenizer(br.readLine(), " ");
				for(int j=0; j<N; j++) synergy[i][j] = Integer.parseInt(st.nextToken());
			}
			
			combination(0, 0);
			
			sb = new StringBuilder();
			sb.append("#").append(t).append(" ");
			System.out.println(sb.append(ans));
		}
	}

	static void combination(int cnt, int start) {
		if(cnt == N/2) { //주어진 재료중 절반 뽑으면
			int left = 0; //한 음식의 맛의 총 합
			int right =0; //다른 음식의 맛의 총 합
			int rest [] = new int [N/2]; //선택되지 않은 인덱스들
			int idx = 0; // 선택되지 않은 인덱스 도출용
			int idx2 = 0;
			
			//선택되지 않은 인덱스를 배열로 만듬
			for(int i=0; i<N; i++) {
				if(idx < N/2 && i == select[idx]) {
					idx++;
				}else if(idx2 < N/2){
					rest[idx2] = i;
					idx2++;
				}
			}
			
			//재료의 시너들을 모두 더함
			for(int i=0; i<N/2; i++) {
				for(int j=0; j<N/2; j++) {
					if(i==j) continue;
					
					left += synergy[select[i]][select[j]];
					right += synergy[rest[i]][rest[j]];
				}
			}
			
			ans = Math.min(ans, Math.abs(left-right));

			return;
		}
		
		for(int i=start; i<N; i++) {
			select[cnt] = numbers[i];
			combination(cnt+1, i+1);
		}
	}
}

```
