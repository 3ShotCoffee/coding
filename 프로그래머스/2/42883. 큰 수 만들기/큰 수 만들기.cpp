#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int goal_len = number.size() - k;
    
    while (k > 0 && answer.size() < goal_len) {
        auto it = max_element(number.begin(), number.begin() + k + 1);
        int diff = distance(number.begin(), it);
        
        answer += *it;                          // ans에 붙이기
        number.erase(number.begin(), it + 1);   // it까지 삭제

        k -= diff;
    }
    
    if (answer.size() < goal_len)
        answer += number;   // 못 지우면 다 넣어야지
    
    return answer;
}

// 너무 커서 완탐이 불가능
// 가장 앞에서부터 k개 수 중에 가장 큰 게 앞에 와야지.