# deque
> queue와 비슷하지만 앞에서 빼고, 뒤로만 넣어야 하는 queue와 달리 앞과 뒤 모두에서 넣고 빼고가 가능하다.

###  Function
```jsx
deque<int>dq;
dq.assign(3, 10) //원소 3개를 10으로 초기화
dq.push_front(5) // {5,10,10,10}
dq.pop_back() //{5,10,10}
dq.insert(2, 4) //2번 위치에 4추가하고, 가리키는 iterator 반환
// {5,10,4,10}
```
