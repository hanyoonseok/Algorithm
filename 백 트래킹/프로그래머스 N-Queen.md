# 프로그래머스 [N-Queen](https://school.programmers.co.kr/learn/courses/30/lessons/12952?language=java)
` level2` `백 트래킹`
---
- N-Queen 문제 한번 더 풀어봄.
- 백 트래킹 사용하는데 굳이 true일 때만 처리할 로직이 따로 없어서 굳이 boolean형을 사용하지 않아도 되었음.
- 놓을 수 있는 위치인지 확인하고 놓을 수 있으면 그 자리를 true로, 백 트랙 후에는 false로 바꾸면 해결. 
- n의 범위가 1~12까지였는데도 잘 통과함.

### 전체코드
```java
public class PNQueen {

	static int gn;
	static int d[][] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
	static boolean map [][];
	static int answer = 0;
	
	public int solution(int n) {
        gn = n;
        map = new boolean [n][n];
        
        backtrack(0);
        
        return answer;
  }
	
	static boolean backtrack(int cnt) {
		if(cnt == gn) {
			answer++;
			return true;
		}
		for(int i=0; i<gn; i++) {
			if(!canSet(cnt, i)) continue;
			
			map[cnt][i] = true;
			backtrack(cnt+1);
			map[cnt][i] = false;
			
		}
		
		return false;
	}
	
	static boolean canSet(int cnt, int idx) {
		if(map[cnt][idx]) return false;
		
		outer:for(int i=0; i<8; i++) {
			int step = 1;
			while(true) {
				int nr = cnt + d[i][0] * step;
				int nc = idx + d[i][1] * step;
				
				if(nr < 0 || nc < 0 || nr >= gn || nc >= gn) continue outer;
				
				if(map[nr][nc]) return false;
				
				step++;
			}
		}
		
		return true;
	}
}

```
