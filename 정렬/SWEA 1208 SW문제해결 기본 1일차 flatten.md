# SWEA #1208 [S/W문제해결 기본 1일차 - Flatten](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AX69tP7quW4DFAVm&contestProbId=AV139KOaABgCFAYh&probBoxId=AX7C26xKL7sDFAVm&type=PROBLEM&problemBoxTitle=day0204&problemBoxCnt=4)
`D3` `정렬` `구현`
---

- 최고높이와 최저높이만 알고있다면 쉽게 풀 수 있는 문제여서 비효율적이지만 매 반복마다 Array의 내장 sort를 사용함
- 매 반복마다 최고높이-최저높이를 구하고 1인 경우가 아니라면 각각에 1씩을 더하고 빼주어 높이를 맞춘다.
- 루프 종료 후 **한번 더** 정렬을 해준 후 최고높이-최저높이를 출력해야 모든 테케 통과

### 전체코드
```jsx
public class SWEA1208 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int t=1; t<=10; t++) {
			Integer [] height = new Integer[100]; // 높이정보
			int dump = sc.nextInt(); //덤프 횟수
			int gap = 0; //최고높이와 최소높이의 차
			
			for(int i=0; i<100; i++)
				height[i] = sc.nextInt();
			
			for(int i=0; i<dump; i++) {
				Arrays.sort(height); //오름차순
				gap = height[99]-height[0];
				
				if(gap==1)
					break;
				
				height[0]++;
				height[99]--;
			}
			Arrays.sort(height); //마지막에 한번 더 정렬해주어야 함
			System.out.println("#"+t+" " + (height[99]-height[0]));
		}
	}
}

```
