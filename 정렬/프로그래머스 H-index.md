# 프로그래머스 정렬문제 level2 'H-index'

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
    
    for(int i=0; i<=v[v.size()-1]; i++){
        if( v.size() - (lower_bound(v.begin(), v.end(), i)-v.begin())  >= i
          && (lower_bound(v.begin(), v.end(), i)-v.begin()) <= i){
            answer = i;
        }    
    }
    
    return answer;
}
```
