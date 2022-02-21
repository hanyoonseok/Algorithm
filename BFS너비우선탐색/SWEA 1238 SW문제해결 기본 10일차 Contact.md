# SWEA 1238 [[S/W 문제해결 기본 10일차] - Contact](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?contestProbId=AV15B1cKAKwCFAYD&solveclubId=AX69tP7quW4DFAVm&problemBoxTitle=day0221&problemBoxCnt=1&probBoxId=AX8agV3aLG0DFAW0)
`D4` `BFS`
---
- BFS 문제를 많이 풀어봤는데 자바로는 노드의 연결 상태를 표현하는 것이 까다로운 것 같다. ArrayList를 배열로 만들 수 없어 클래스에 담아서 배열화 해주었다.
- bfs를 도는 depth를 기록해둘 필요가 있어서 이를 또 나타내는 `Info` 클래스도 선언해주고 사용했다. 한 노드에서 다른 자식노드로 전진할 때 이번 depth에서 나온 최대값을 갱신해주고, 새로운 depth가 갱신될 때 또한 최대값을 갱신한 값으로 바꿔주었다.
- 최대값 갱신과 maxDepth 관련 로직이 복잡해서 조금 헤매긴 했는데 그래도 bfs로 이 문제를 해결하는 것이 직관적이어서 해결 가능하긴 했다.

### 전체코드 BFS ver.
```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

//SWEA 1238 SW 문제해결 기본 10일차 - Contact
public class S1238 {
	static int N,S; //입력받을 수, 시작 노드
	static boolean check []; //사용 여부
	static Node [] nodes; //노드 배열
	static int ans = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int t=1; t<=1; t++) {
			String [] NS = br.readLine().split(" ");
			StringBuilder sb = new StringBuilder("#");
			N = Integer.parseInt(NS[0]);
			S = Integer.parseInt(NS[1]);
			nodes = new Node[101];
			check = new boolean[101];
			
			for(int i=0; i<101; i++) nodes[i] = new Node();
			
			String [] input = br.readLine().split(" ");
			
			for(int i=0; i<N; i+=2) {
				int start = Integer.parseInt(input[i]);
				int end = Integer.parseInt(input[i+1]);
				nodes[start].list.add(end); // start번 노드의 리스트에 end 넣기. start->end
			}
			
			bfs(S);
			
			System.out.println(sb.append(t).append(" ").append(ans));
		}
	}
	
	static void bfs(int s) {
		Queue<Info> q = new LinkedList<>();
		q.add(new Info(s, 0));
		check[s] = true;
		ans = s; //이번 depth에서 최대값
		int maxDepth = 0; //이번 depth
		
		while(!q.isEmpty()) {
			Info current = q.poll();
			
			if(maxDepth < current.depth) { //새로운 depth 진입시 갱신
				maxDepth = current.depth;
				ans = current.num;
			}
			ans = Math.max(ans,  current.num);
			for(int i=0; i<nodes[current.num].list.size(); i++) {
				int next = nodes[current.num].list.get(i);
				if(check[next]) continue;
				
				q.add(new Info(next, current.depth+1));
				check[next]=true;
			}
		}
	}
	
	static class Node{
		ArrayList<Integer> list = new ArrayList<>();
	}
	
	static class Info{
		int num, depth;
		public Info(int num, int depth) {
			this.num = num;
			this.depth = depth;
		}
	}

}
```
