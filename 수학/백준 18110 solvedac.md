# 백준 #18110 [solved.ac](https://www.acmicpc.net/problem/18110)
`실버4` `수학` `정렬`
---
- 주어진 인원의 15%를 알아야 해서 소수 첫째자리에서 반올림하는 round를 알고있어야 함
- 점수를 가장 낮고, 높게 준 사람들을 제거해야 해서 정렬 필요
- 유효한 사람들의 점수 합을 구할 때 반올림해야 하기 때문에 double형으로 합 구하고 나눠줘야 함

### 전체코드
```java
public class B18110_solvedac {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int range = (int)Math.round(N*0.15);
		int arr [] = new int [N];

		for(int i=0; i<N; i++) arr[i] = Integer.parseInt(br.readLine());
		
		Arrays.sort(arr);
		double sum = 0;
		for(int i=range; i<N-range; i++) sum += arr[i];

		int avg = (int)Math.round(sum / (N-range * 2));
		System.out.println(avg);
	}
}
```
