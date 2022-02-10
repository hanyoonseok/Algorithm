# 백준 #1260 [DFS와 BFS](https://www.acmicpc.net/problem/1260)
`실버2` `DFS` `BFS` `재귀` `그래프 탐색`
---
- 이미 한 번 풀어봤던 문제이기도 하고 기본적인 DFS와 BFS 문제여서 어렵지 않게 해결하였다.
- 다만 간선의 연결 여부를 c++에서는 `vector`배열로 표현했는데, 자바에서는 어떻게 표현을 할 까 고민하다 `boolean` 타입의 2차원 배열로 해결했다.
- 문제에는 안 나와있지만 간선의 연결 정보가 단방향이 아닌 양방향이기 때문에 `v[from][to]` 와 `v[to][from]` 둘 다 체크해주어야 했다.

### 전체코드
```jsx
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class B1260 {
	static int N;
	static int M;
	static int V;
	static boolean [][] v;
	static boolean [] visit;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); // 정점의 수
		M = sc.nextInt(); // 간선의 수
		V = sc.nextInt(); // 시작 번호
		v = new boolean [N][N];
		visit = new boolean[N];

		// input
		for (int m = 0; m < M; m++) {
			int from = sc.nextInt()-1;
			int to = sc.nextInt()-1;
			v[from][to]=true;
			v[to][from]=true;
		}
		
		dfs(V-1);
		System.out.println();
		bfs(V-1);
	}
	
	static void dfs(int start) {
		visit[start]=true; //방문처리
		System.out.print((start+1)+" ");
		for(int i=0; i<N; i++) { // start와 연결된 다른 노드 탐색
			if(v[start][i] && !visit[i]) { //연결되어 있고 아직 방문하지 않았다면
				dfs(i);
			}
		}
	}
	
	static void bfs(int start) {
		visit = new boolean[N]; //방문여부 초기화
		visit[start]=true; //방문처리
		Queue<Integer>q = new LinkedList<>();
		q.add(start);
		
		while(!q.isEmpty()) {
			int current = q.poll();//현재 노드
			System.out.print((current+1)+ " ");
			for(int i=0; i<N; i++) { //현재 노드와 연결되어있고 방문하지 않은 노드 탐색
				if(v[current][i] && !visit[i]){ 
					q.add(i);
					visit[i]=true;
				}
			}
		}
	}
}

```
