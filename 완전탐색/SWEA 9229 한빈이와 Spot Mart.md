# SWEA 9229 [한빈이와 Spot Mart](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?contestProbId=AW8Wj7cqbY0DFAXN&solveclubId=AX69tP7quW4DFAVm&problemBoxTitle=day0208&problemBoxCnt=4&probBoxId=AX7Xk6266eYDFAVm)
`D3` `재귀` `조합`
---
- 문제에서 과자를 뽑는 순서를 고려하지 않고 있기 때문에 순열이 아닌 조합으로 접근해야겠다고 생각
- 과자 2개의 합이 한도보다 클 때 과자 1개의 무게만 셈하는 것이 아닌, 꼭 2개의 합 무게로 비교해야 하는 것에 유의
- 일반적인 조합 문제 접근 방식으로 해결하면 풀렸음
- 처음에 재귀 호출시에 `combination(cnt+1, i+1)`인데 i자리에 start를 넣어버려서 한 번 놓침

### 전체코드
```jsx
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//SWEA 9229 한빈이와 spot mart - D3
public class S9229 {
	static int N, M; //과자의 수, 한도 무게
	static int[] snacks; //과자 입력 배열
	static int[] selected; //선택한 과자 2개 무게
	static int answer; //정답

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());

		for (int t = 1; t <= tc; t++) {
			String[] NM = br.readLine().split(" "); //input N, M
			N = Integer.parseInt(NM[0]);
			M = Integer.parseInt(NM[1]);
			snacks = new int[N];
			selected = new int[2];
			answer = -1;

			String[] snackInput = br.readLine().split(" "); //input 과자 무게
			for (int i = 0; i < N; i++) snacks[i] = Integer.parseInt(snackInput[i]);

			combination(0, 0);
			System.out.println("#" + t + " " + answer);
		}
	}

	public static void combination(int cnt, int start) {
		if (cnt == 2) { //2개를 뽑았으면
			int temp = 0;
			for (int i = 0; i < 2; i++) temp += selected[i]; //선택된 과자 무게 합산

			if (temp <= M) //합산이 한도무게보다 작거나 같을 때만 갱신
				answer = Math.max(answer, temp);

			return;
		}

		for (int i = start; i < N; i++) { //조합이기 때문에 다음 과자부터 탐색
			selected[cnt] = snacks[i]; //현재 과자를 선택
			combination(cnt + 1, i + 1); 
		}
	}

}

```
