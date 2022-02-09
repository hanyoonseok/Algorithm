# SWEA 1210 [S/W 문제해결 기본 2일차 - Ladder1](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?contestProbId=AV14ABYKADACFAYh&solveclubId=AX69tP7quW4DFAVm&problemBoxTitle=day0209&problemBoxCnt=2&probBoxId=AX7dC-faxGoDFAVm)
`D4` `BFS` 
---
- 처음 보자마자 1을 따라서 탐색하는 bfs로 접근해야겠다고 생각함.
- bfs풀면서 항상 유의할점은 `범위 유효성` `체크 여부` `종료조건` 이고, 이를 빠뜨리지 않아야 함.
- 일반적인 bfs와 동일하나 하나 다른점은 4방향이 아닌 좌,우,아래 방향으로만 이동한다는 점이고, 이 또한 좌우로 갈 수 있는 경우가 있다면 윗방향으로는 가지 않음.

### 처음코드
```jsx
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
 
//S/W 문제해결 기본 2일차 - Ladder1
public class Solution {
 
    static int[][] map = new int[100][100];
    static int[][] d = { { 0, 1 }, { 0, -1 }, { 1, 0 } };
    static boolean flag;
 
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int t = 0; t < 10; t++) {
            int tc = Integer.parseInt(br.readLine());
            flag = false;
            for (int i = 0; i < 100; i++) {
                String[] numbers = br.readLine().split(" ");
                for (int j = 0; j < 100; j++)
                    map[i][j] = Integer.parseInt(numbers[j]);
            }
 
            for (int i = 0; i < 100; i++) {
                if (map[0][i] == 1)
                    bfs(i);
                if (flag) {
                    System.out.println("#" + tc + " " + i);
                    break;
                }
            }
        }
    }
 
    public static void bfs(int num) {
        boolean[][] check = new boolean[100][100];
        check[0][num] = true;
        Queue<Pos> q = new LinkedList<Pos>();
        q.add(new Pos(0, num));
        while (!q.isEmpty()) {
            int r = q.peek().r;
            int c = q.peek().c;
            q.poll();
 
            boolean noSide = true;
            for (int i = 0; i < 3; i++) {
                int r_ = r + d[i][0];
                int c_ = c + d[i][1];
                if (r_ < 0 || c_ < 0 || r_ >= 100 || c_ >= 100 || check[r_][c_] || map[r_][c_]==0 || flag)
                    continue;
 
                if (map[r_][c_] == 2) {
                    flag = true;
                    break;
                } else if (map[r_][c_] == 1) {
                    if(!noSide && i==2) continue;
                     
                    q.add(new Pos(r_, c_));
                    check[r_][c_] = true;
                    noSide=false;
                }
            }
        }
    }
 
    static class Pos {
        int r;
        int c;
 
        public Pos(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}
```

- 수업 종료 전 교수님이 어차피 당첨은 한 개 뿐이니 당첨에서 시작해서 올라가는 것이 더 빠르다고 알려주셔서 그렇게 리팩토링도 해 보았음
- 이 방법으로 해보니 정답을 찾았는지 여부를 알려주던 `flag` 와 시작점을 모두 탐색하는 for문 100번이 제거되었고, 얼마나 코드가 낭비되고 있었는지 알 수 있었음

### 전체코드
```jsx
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

//S/W 문제해결 기본 2일차 - Ladder1
public class S1210 {

	static int[][] map = new int[100][100]; // 맵 정보
	static int[][] d = { { 0, 1 }, { 0, -1 }, { -1, 0 } }; //방향 델타
	static int tc; //테스트케이스

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int t = 0; t < 10; t++) {
			tc = Integer.parseInt(br.readLine());
			int col2 =0; //2가 있는 열. 어차피 2는 99번 행에 존재
			//맵 정보 입력
			for (int i = 0; i < 100; i++) {
				String[] numbers = br.readLine().split(" ");
				for (int j = 0; j < 100; j++) {
					map[i][j] = Integer.parseInt(numbers[j]);
					if(map[i][j] == 2) col2 = j; //2의 위치 파악
				}
			}

			bfs(col2);
		}
	}

	public static void bfs(int num) {
		boolean[][] check = new boolean[100][100];
		Queue<Pos> q = new LinkedList<Pos>();
		q.add(new Pos(99, num));
		while (!q.isEmpty()) {
			int r = q.peek().r;
			int c = q.peek().c;
			q.poll();
			if (r == 0) { //0번 행에 도착했을 때의 열이 정답
				System.out.println("#" + tc + " " + c);
				break;
			}

			boolean noSide = true; //좌우 방향 갔는지 여부
			for (int i = 0; i < 3; i++) {
				int r_ = r + d[i][0];
				int c_ = c + d[i][1];
				//유효성 검사
				if (r_ < 0 || c_ < 0 || r_ >= 100 || c_ >= 100 || check[r_][c_] || map[r_][c_] == 0 || (!noSide&&i==2))
					continue;

				q.add(new Pos(r_, c_));
				check[r_][c_] = true;
				noSide = false; //좌우방향 갔음을 체크
			}
		}
	}

	static class Pos {
		int r;
		int c;

		public Pos(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}
}
```
