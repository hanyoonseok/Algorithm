# 프로그래머스 정렬문제 level2 'H-index'
- 처음에 h-index가 꼭 citations 안의 수이어야 하는 줄 알고 아래와 같이 품
- 테스트케이스 1번을 제외하고 모두 실패로 출력

### 처음 작성 코드 (테케 1외 모두 실패)
```jsx
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    vector<int> v(citations);
    sort(v.begin(), v.end()); //정렬
    int answer = 0;
    
    //최대값 구하는 구조와 비슷
    //i번째 벡터의 값보다 큰 수가 v[i]개보다 많거나 크면서, i번째 벡터의 값보다 작은 수가 v[i]개보다 작거나 같으면
    for(int i=0; i<v.size(); i++){
        if(v[i] <= v.size() - i && v[i] >= v.size() - i){
            answer = v[i];
        }
    }
    return answer;
}
```

- h-index는 citations 안의 수가 아니어도 됨.
- 그러므로 정렬했을 때 가장 큰 수까지 돌면서 확인해보아야 함.
- v[i]보다 크거나 같은 수가 몇 번째 인덱스에서 나오는지 구하면 그보다 크거나 같고, 작거나 같은 수들의 수를 쉽게 구할 수 있음.
- O(lgN)의 복잡도를 가지는 lower_bound 사용.
- [0,0,0,0,1]과 같은 배열 나올 수 있으므로 마지막까지 확인해야 함.

### 전체코드
```jsx
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    vector<int> v(citations);
    sort(v.begin(), v.end());
    int answer = 0;
    
    //벡터 내 제일 큰 수까지 탐색
    for(int i=0; i<=v[v.size()-1]; i++){
        // (벡터사이즈 - 벡터 내에서 i보다 크거나 같은 값이 나온 인덱스) 가 i보다 크거나 같고
        if( v.size() - (lower_bound(v.begin(), v.end(), i)-v.begin())  >= i 
          // 벡터 내에서 i보다 크거나 같은 값이 나온 인덱스가 i보다 작거나 같으면
          && (lower_bound(v.begin(), v.end(), i)-v.begin()) <= i){
            answer = i;
        }    
    }
    return answer;
}
```
