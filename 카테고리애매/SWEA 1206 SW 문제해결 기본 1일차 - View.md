# SWEA [S/W 문제해결 기본 1일차 - View](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh)
`D3` 
---
- 양쪽 2칸의 높이중 최대를 구하고 자신의 높이와 비교하면 되는 문제
- 범위가 크지 않기 때문에 브루트포스 처럼 접근해서 해결함

### 전체코드
```java
//S/W 문제해결 기본 1일차 - View D3
public class S1206 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int t=1; t<=10; t++) {
			int N = Integer.parseInt(br.readLine());
			int building [] = new int[N]; //빌딩 높이
			int ans = 0;
			StringBuilder sb = new StringBuilder("#").append(t).append(" ");
			
			StringTokenizer st= new StringTokenizer(br.readLine(), " ");
			
			for(int i=0; i<N; i++) building[i] = Integer.parseInt(st.nextToken());
			
			for(int i=2; i<N-2; i++) { //2번째 빌딩부터 N-2번째까지 탐색
				int max = 0;
				for(int j=1; j<=2; j++) { //양쪽 2개의 빌딩 중 가장 큰 높이 탐색
					max = Math.max(max, building[i-j]);
					max = Math.max(max, building[i+j]);
				}
				
				if(max > building[i]) continue; //양쪽 2개의 빌딩 중 가장 큰 빌딩이 나보다 크면
				
				ans += building[i] - max;
			}
			
			System.out.println(sb.append(ans));
		}
	}
}
```
