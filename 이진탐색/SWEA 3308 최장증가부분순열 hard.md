# SWEA #3308 [최장 증가 부분 순열 hard](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWBOPZeK6nUDFAWr)
`D5` `이진탐색` `LIS`
---
- 비슷한 문제 [최장 증가 부분 순열]이 있는데, 해당 문제와 동일하게 풀 수 없고 이 문제는 이진탐색으로 시간을 단축해야 함.

### 전체코드
```java
public class S3308_최장증가부분수열 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringBuilder sb = new StringBuilder("#").append(t).append(" ");
			int N = Integer.parseInt(br.readLine());
			int[] arr = new int[N];
			int[] C = new int[N];
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			
			for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
			
			int size = 0;
	        for (int i=0; i < N; i++) {

	            int temp = Arrays.binarySearch(C, 0, size, arr[i]); 
	            temp = Math.abs(temp)-1;//삽입위치
	            C[temp] = arr[i];

	            if (size == temp) {
	                size++;
	            }
	        }
	        System.out.println(sb.append(size));
		}
	}
}

```
