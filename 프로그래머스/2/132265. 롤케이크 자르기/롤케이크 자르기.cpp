#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

multiset<int> lefts, rights;

int left_unq = 0, right_unq = 0;

int solution(vector<int> topping) {
    int answer = 0;
    
    // 일단 오른쪽에 다 넣기
    for (int t : topping) {
        // 이전에 없던 토핑이면 토핑 종류 개수 + 1
        if (rights.find(t) == rights.end())
            right_unq++;
        rights.insert(t);
    }
    
    // cout << left_unq << " " << right_unq << " " << rights.size() << '\n';
    
    
    // 순차적으로 왼쪽으로 하나씩 가져가기
    for (int t : topping) {
        // 하나만 삭제. 반드시 있음
        rights.erase(rights.find(t));
        // 다시 오른쪽에서 찾았을 때 없으면 토핑 종류 개수 - 1
        if (rights.find(t) == rights.end())
            right_unq--;
        // 넣기 전에 왼쪽에서 찾았을 때 없으면 토핑 종류 개수 + 1
        if (lefts.find(t) == lefts.end())
            left_unq++;
        lefts.insert(t);
        
        // 토핑 종류의 개수가 같으면 방법의 수 + 1
        if (left_unq == right_unq) answer++;
        
        // cout << left_unq << " " << right_unq << " " << rights.size() << '\n';
    }
    
    
    return answer;
}

// 한 번만 자르기
// 최대 10,000가지의 토핑
