# 백준 #11559 [Puyo Puyo](https://www.acmicpc.net/problem/11559)
`골드5` `BFS` `시뮬레이션` `구현`
---
- 카카오 기출 중 `사천성` 류의 문제와 유사하다.
- 보자마자 bfs로 접근해야겠다고 생각했고, 이전상태의 보존을 위해 copy본을 하나 더 생성해야 했다.
- 터질 수 있는 뿌요들을 저장하고 복사본에서 터트린 뒤, 터트린 위치의 상위 열들을 모두 아래로 내려주었다.
- 역시나 3중 포문까지 들어가서 시간초과가 날 줄 알았지만 시간과 메모리를 넉넉히 준 문제같다.
### 전체코드
```jsx
char field[12][6]; //필드정보
char field_copy[12][6]; //연쇄 후의 필드정보
int ans = 0; //연쇄 수
int flag = true; //터질 수 있는게 있는지
int dx[4] = { 1, 0 ,-1 ,0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>>p; //한 연쇄에서 제거된 뿌요들의 좌표

void bfs() {
	bool check[12][6] = { false }; //방문여부
	flag = false; 
  //모든 필드 탐색
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
      //뿌요이면서 방문 안 한 타일이라면
			if (field[i][j] != '.' && !check[i][j]) {
				queue<pair<int, int>>q; //연결된 뿌요 담을 큐
				vector<pair<int, int>>pos; //연결된 뿌요들의 좌표
				int temp = 1; //연결된 뿌요 개수
				q.push({ i,j });
				check[i][j] = true;
				pos.push_back({ i,j });
				while (!q.empty()) {
					int r = q.front().first;
					int c = q.front().second;
					char color = field[r][c];
					q.pop();

          //4방향 탐색
					for (int k = 0; k < 4; k++) {
						int nr = r + dx[k];
						int nc = c + dy[k];
            //범위체크, 방문여부, 같은 타일인지
						if (nr < 0 || nc < 0 || nr >= 12 || nc >= 6 || field[nr][nc] != color || check[nr][nc])
							continue;
						temp++; //연결된 뿌요 수 증가
						pos.push_back({ nr, nc }); //연결된 뿌요 좌표 저장
						check[nr][nc] = true; //방문체크
						q.push({ nr,nc });
					}
				}
				if (temp >= 4) { //4개 이상 연결되어있으면
					flag = true; //연쇄작용했다고 체크
          //연결된 뿌요 좌표 탐색
					for (int k = 0; k < pos.size(); k++)
					{
            //카피본에 뿌요들 제거 후 한 번의 연쇄에서 제거된 뿌요좌표에 저장. 추 후 중력작용할 때 이용
						field_copy[pos[k].first][pos[k].second] = '.';
						p.push_back({ pos[k].first, pos[k].second });
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> field[i][j];
			field_copy[i][j] = field[i][j];
		}
	}

	while (flag) {
		bfs(); //연쇄 실행
		if (flag) //연쇄로 제거된 뿌요들 있으면
		{
			ans++; //연쇄 추가
      //연쇄로 제거된 뿌요 좌표들 탐색
			for (int i = 0; i < p.size(); i++) {
				int r = p[i].first;
				int c = p[i].second;
				if(r > 0) //범위 체크
        //제거된 뿌요 윗 행들 탐색
				for (int j = r - 1; j >= 0; j--) {
          //다른 뿌요 있으면
					if (field_copy[j][c] != '.') { 
            //해당 칸에서 갈 수 있는 맨 아래칸으로 이동
						for (int k = j; k < 11; k++) {
							if (field_copy[k + 1][c] == '.') { //다음칸이 .일 때만 이동
								field_copy[k + 1][c] = field_copy[k][c];
								field_copy[k][c] = '.';
							}
							else //다음칸이 다른 뿌요이면 멈춤
								break;
						}
					}
				}
			}
      //필드 정보에 연쇄작용 이후의 필드정보 복사
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++)
					field[i][j] = field_copy[i][j];
			}
		}
		p.clear(); //연쇄로 제거된 뿌요 좌표 초기화
	}
	cout << ans << endl;
}
```
