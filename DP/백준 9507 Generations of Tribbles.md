# 백준 #9507 [Generations of Tribbles](https://www.acmicpc.net/problem/9507)
`실버3` `DP`
---
- 피보나치를 DP로 해결하는 방식을 범위 4 버전으로 만들어서 해결했다.
- 매 테스트 케이스마다 배열내 값을 초기화하면 반복작업이 많아서 처음에 배열을 한번에 초기화해주고 입력으로 주어지는 인덱스의 값을 출력하는 식으로 구현

### 전체코드
```java
public class B9507_GenerationsOfTribbles {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		long [] k = new long[68];
		k[0] = 1;
		k[1] = 1;
		k[2] = 2;
		k[3] = 4;
		
		for(int i=4; i<=67; i++) k[i] = k[i-1] + k[i-2] + k[i-3] + k[i-4];
		
		for(int i=0; i<t; i++) {
			int n = sc.nextInt();
			System.out.println(k[n]);
		}
	}
}

```
