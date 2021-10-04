# Priority_queue
> queue와 동일하지만 큐에 있는 원소 중에서 가장 큰 값(우선순위가 큰 값)이 top을 유지하도록 설계되어있다.
- 일반적인 큐는 sort()함수를 사용할 수 없기 때문에 자동으로 정렬해주는 `priority_queue`를 사용하자.
`priority_queue<자료형, 컨테이너, 비교함수>`
```jsx
priority_queue<int,vector<int>,less<int>>pq;
```
```jsx
#include <queue>
priority_queue<int>pq;
pq.push(2);
pq.push(3);
pq.push(1);
// pq = {3, 2, 1};
```
- 기본적으로 내림차순으로 작성된다. 
- 오름차순으로 저장하고 싶으면 `priority_queue<int,vector<int>,greater<int>>pq` 처럼 비교함수에 greater를 넣어주면 된다.

- `pair`로 선언할 경우
```jsx
priority_queue<pair<int, int>> pq; // 일반적인 선언
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //pair일 때 오름차순
```
- 비교함수를 직접 만들어서 넣어주는 경우
```jsx
struct cmp { //struct로 선언해줘야 한다.
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		if (a.second == b.second) //
			return a.first > b.first;
		else
			return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int,int>>, cmp>pq;
//{0, 2} {2, 4}, {3, 4}, {1, 6}
```
