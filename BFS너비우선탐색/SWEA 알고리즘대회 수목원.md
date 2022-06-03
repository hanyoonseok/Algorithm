# SWEA 알고리즘 대회 [수목원](https://swexpertacademy.com/main/talk/codeBattle/problemSubmitHistory.do)
`BFS` 
---
- 싸피 방학기간에 진행한 알고리즘 출제 대회 출시작. 각 인원에게 주어진 권리를 가진 나무를 가지고 만들 수 있는 최대의 산책길 점수를 얻는 문제.
- 모든 참가자에 대해서 권리를 가진 나무의 위치에서 BFS 탐색을 시작해서 얻을 수 있는 최대 값을 갱신해주는 식으로 문제 접근
- 동점자가 존재하는 경우 사전순 오름차순으로 출력하기 때문에 입력받을 때 `TreeMap`으로 입력받고 실행
- 모든 사용자가 0점으로 같은 경우를 처음에 아래처럼 구현해서 1시간 넘게 헤맸다;;
- 점수를 내는 조건에 따라서 분기처리만 잘 해주면 생각보단 어렵지 않은 문제인데 군데 군데 귀찮게 하는 요소가 많았던 문제같다.

```
if(maxVal == ansVal) {
  if(ansVal == 0) ansName = name;
  else ansName += " " + name;
}
```

### 전체코드
```java
public class S알고리즘대회_수목원 {

	static int N;
	static Map<String, Character> map;
	static String m [][] = new String[5][8];
	static int d [][] = {{1,0},{0,1},{-1,0},{0,-1}};
	static int ansVal = 0;
	static String ansName = "";
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
			StringBuilder sb = new StringBuilder("#").append(t).append(" ");
			StringTokenizer st;
			map = new TreeMap<>();
			N = Integer.parseInt(br.readLine());
			ansVal = 0;
			ansName = "";
			
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine());
				String name = st.nextToken();
				char type = st.nextToken().charAt(0);
				map.put(name, type);
			}
			
			for(int i=0; i<5; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<8; j++) m[i][j] = st.nextToken();
			}
			
			for(String name : map.keySet()) solve(name);
			
			System.out.println(sb.append(ansName));
		}
	}

	
	static void solve(String name) {
		char type = map.get(name);
		int maxVal = 0;
		
		for(int i=0; i<5; i++) {
			for(int j=0; j<8; j++) {
				if(m[i][j].charAt(0) == type) maxVal = Math.max(maxVal, bfs(i,j,m[i][j]));
			}
		}
		
		if(maxVal == ansVal) {
			if(ansName.equals("")) ansName = name;
			else ansName += " " + name;
		}
		if(maxVal > ansVal) {
			ansVal = maxVal;
			ansName = name;
		}
	}
	
	static int bfs(int r, int c, String start) {
		int score = 0;
		Queue<Node> q = new LinkedList<>();
		q.add(new Node(r, c, start));
		
		while(!q.isEmpty()) {
			Node n = q.poll();
			int len = n.info.length();
			
			//시작과 끝이 같은 경우에만 점수 계산
			if(len >= 4 && n.info.charAt(len-2) == start.charAt(0)) 
				score = Math.max(score, calScore(n.info));
			
			
			for(int i=0; i<4; i++) {
				int nr = n.r + d[i][0];
				int nc = n.c + d[i][1];
				
				if(nr < 0 || nc < 0 || nr >= 5 || nc >= 8 || n.info.charAt(len-1) >= m[nr][nc].charAt(1)) continue;
				
				q.add(new Node(nr, nc, n.info+m[nr][nc]));
			}
		}
		
		return score;
	}
	
	static int calScore(String info) {
		int len = info.length()/2;
		int score = len; //기본점수 주고 시작
		
		if(info.charAt(1) == '1') score += 1;
		if(info.charAt(info.length()-1) == '8') score += 2;

		boolean flag = true;
		for(int i=0; i<info.length(); i+=2) 
			if(info.charAt(i) != info.charAt(0)) flag = false;
		
		if(flag && len >= 4) score += len;
		return score;
	}
	
	static class Node{
		int r,c;
		String info;
		public Node(int r, int c, String info) {
			this.r = r;
			this.c = c;
			this.info = info;
		}
		
	}
}

```
