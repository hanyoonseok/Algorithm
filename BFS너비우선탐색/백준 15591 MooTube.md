# 백준 #15591 [MooTube](https://www.acmicpc.net/problem/15591)
`골드5` `BFS`
---
- 문제가 어렵게 되어있는데 쉽게 말하자면 정점 V1에서 정점 V2로 가는 간선의 비용 중 최소값이 K이상인 것의 개수를 구하면 되는 문제였음.
- 정점 V1에서 갈 수 있는 정점들을 찾기 위해서 BFS를 이용하여 탐색했고, 그 과정에서 발견되는 간선의 정보들을 기반으로 도달가능한 수를 저장하여 리턴함
- 처음에는 연결리스트로 풀어보려고 접근했는데 시간초과가 났음.

### 처음코드 간선리스트 ver.
```java
public class Main {

	static int N,Q;
	static int edges [][];
	static boolean visit [];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		edges = new int [N+1][N+1];
		visit = new boolean [N+1];
		
		for(int i=0; i<N-1; i++) {
			st = new StringTokenizer(br.readLine());
			int p = Integer.parseInt(st.nextToken());
			int q = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			edges[p][q] = r;
			edges[q][p] = r;
		}
		
		for(int i=0; i<Q; i++) {
			st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			System.out.println(bfs(k, v));
		}
	}
	
	static int bfs(int k, int v) {
		int cnt = 0;
		visit = new boolean [N+1];
		Queue<Integer> q = new LinkedList<>();
		visit[v] = true;
		
		for(int i=1; i<=N; i++) {
			if(edges[v][i] >= k) {
				q.add(i);
				visit[i] = true;
				cnt++;
			}
		}
		
		while(!q.isEmpty()) {
			int cur = q.poll();

			for(int i=1; i<=N; i++) {
				if(visit[i] || edges[cur][i] < k) continue;
				
				visit[i] = true;
				cnt++;
				q.add(i);
			}
		}
		
		return cnt;
	}
}
```

- 이를 2차원 배열로 변경하니 솔브됨
### 전체코드
```java
public class B15591_MooTube {

	static int N,Q;
	static LinkedList<Edge> edges[];
	static boolean visit [];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		edges = new LinkedList [N+1];
		visit = new boolean [N+1];
		
		for(int i=1; i<=N; i++) edges[i] = new LinkedList<>();
		
		for(int i=0; i<N-1; i++) {
			st = new StringTokenizer(br.readLine());
			int p = Integer.parseInt(st.nextToken());
			int q = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			edges[p].add(new Edge(q, r));
			edges[q].add(new Edge(p, r));
		}
		
		for(int i=0; i<Q; i++) {
			st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			System.out.println(bfs(k, v));
		}
	}
	
	static int bfs(int k, int v) {
		int cnt = 0;
		visit = new boolean [N+1];
		Queue<Integer> q = new LinkedList<>();
		visit[v] = true;
		
		for(Edge e : edges[v]) {
			if(e.r >= k) {
				q.add(e.to);
				visit[e.to] = true;
				cnt++;
			}
		}
		
		while(!q.isEmpty()) {
			int cur = q.poll();
			int size = edges[cur].size();
			
			for(int i=0; i<size; i++) {
				Edge e = edges[cur].get(i);
				
				if(visit[e.to] || e.r < k) continue;
				
				visit[e.to] = true;
				cnt++;
				q.add(e.to);
			}
		}
		
		return cnt;
	}
	
	static class Edge{
		int to, r;
		public Edge(int to, int r) {
			this.to = to;
			this.r = r;
		}
	}
}

```
