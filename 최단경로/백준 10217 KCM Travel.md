# 백준 #10217 KCM Travle 골드1
`다익스트라` `최단경로`
---
- 기존 다익스트라에서 조건 하나가 더 붙어서 기존 1차원 배열로 저장한 최단거리를 2차원 배열로 다루어야 함.
- 메모리 초과 해결이 안되었음.

### 전체코드
```jsx
#define MAX 1000000000

int T, N, M, K; //테케, 공항 수, 지원비용, 티켓정보 수
int u, v, c, d; //출발공항, 도착공항, 비용, 소요시간
int ds[101][10001]; //인천에서 i로 최소비용j로 가는 최단시간
vector<pair<pair<int, int>, int>>route[101]; //[출발공항] { {도착공항, 소요시간}, 비용 }
priority_queue<pair<pair<int, int>,int>>pq; //{ { 시작공항, 소요시간}, 소모된 비용 }

void solve() {
	for (int i = 0; i <= N; i++) //최단거리 초기화
		for (int j = 0; j < 10001; j++)
			ds[i][j] = MAX;

	pq.push(make_pair(make_pair(1,0),0)); //출발지가 항상 인천이기 때문
	ds[1][0] = 0;

	int current, cost ,dist;
	int next, totalCost, nextDist;
	while (!pq.empty()) {
		current = pq.top().first.first;
		cost = pq.top().second;
		dist = -pq.top().first.second;
		pq.pop();

		if (ds[current][cost] < dist)
			continue;

		for (int i = 0; i < route[current].size(); i++) {
			next = route[current][i].first.first;
			totalCost = route[current][i].second + cost;
			nextDist = route[current][i].first.second + dist;

			if (totalCost > M) //지원비용을 넘으면 건너뜀
				continue;
			if (ds[next][totalCost] <= nextDist)
				continue;
			ds[next][totalCost] = nextDist;
			pq.push(make_pair(make_pair(next, -nextDist), totalCost));
		}
	}
	int ans = MAX;
	for (int i = 1; i <= M; i++) {
		ans = min(ans, ds[N][i]);
	}
	ans == MAX ? printf("Poor KCM\n") : printf("%d\n", ans);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d", &T); // 테케

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &M, &K); //공항 수, 지원비용, 티켓정보 수

		for (int j = 0; j < K; j++) {
			scanf("%d %d %d %d", &u, &v, &c, &d);
			route[u].push_back(make_pair(make_pair(v,d),c));
		}

		solve();

		for (int j = 0; j < 101; j++)
			route[j].clear();
		while (!pq.empty())
			pq.pop();
	}
}
```
- printf로 출력도 하고, 가능한 범위를 모두 줄였다고 생각하는데 메모리 초과
