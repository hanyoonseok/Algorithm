# 백준 #5525 [IOIOI](https://www.acmicpc.net/problem/5525)
`실버1` `문자열`
---
- java의 `indexOf(문자열, 시작위치)`를 알면 쉽게 풀 수 있었으나, 이렇게 풀면 50점밖에 못 받음
- 최대 길이가 100만까지이기 때문에 시간초과 나는 듯

### 처음코드 indexOf ver.
```java
public class B5525_IOIOI {
  public static void main(String[] args) {
  	Scanner sc = new Scanner(System.in);
  	int N = sc.nextInt();
  	int len = sc.nextInt();
  	String s = sc.next();
  	String target = ""; // 기준 문자열
  	int ans = 0;

    // N에 따라 기준 문자열 만들기 
  	for(int i=1; i<=N; i++) {
  		if(i == 1) target += "IOI";
  		else target += "OI";
  	}
  	
  	int standard = 0;
  	while(true) {
  		if(standard >= len) break;
  		
  		int idx = s.indexOf(target, standard);
  
  		if(idx < 0 ) break;
  		
  		standard = idx + 2;
  		ans++;
  	}
  	
  	System.out.println(ans);
  }
}
```
- for문 1개만 가지고 풀 수 있는 방법을 고안하던 중, 문자열 패턴이 어차피 `IOIOIOI`처럼 일관되므로, i-2번째에서 I가 나왔고, 바로 직전에 O가 나왔으면 누적 모양의 개수를 저장함
- 만약 누적으로 나온 모양 개수가 N보다 클 때 모양이 만들어진 것이므로 정답에 + 1

### 전체코드 arr ver.
```java
public class B5525_IOIOI {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int len = sc.nextInt();
		String s = sc.next();
		int ans = 0;
		int arr [] = new int [len]; //i번까지 몇 개의 IOI가 나왔나 
		
		for(int i=0; i<len; i++) {
			char c = s.charAt(i);
			
			if(c == 'O') continue;
			
			// 맨 처음에도 I가 나올 수도 있으므로 
			if(i < 2) arr[i] = 1;
			else {
				if(s.charAt(i-1) == 'O' && arr[i-2] > 0) arr[i] = arr[i-2] + 1;
				else arr[i] = 1;
			}
			
			if(arr[i] > N) ans++;
		}
		
		System.out.println(ans);
	}
}
```
