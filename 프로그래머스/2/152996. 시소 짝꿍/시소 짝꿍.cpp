#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(vector<int> weights) {
    int N = weights.size();
    long long answer = 0;
    int diff;
    
    sort(weights.begin(), weights.end());
    
    for (int i = 0; i < N; i++) {
        int w = weights[i];
        // w : 나보다 뒤에 것만 뽑기
        auto range = equal_range(weights.begin() + i + 1, weights.end(), w);
        diff = range.second - range.first;
        answer += diff;
        // 2w
        range = equal_range(weights.begin(), weights.end(), 2 * w);
        diff = range.second - range.first;
        answer += diff;
        // 3/2w
        if (w % 2 == 0) {
            range = equal_range(weights.begin(), weights.end(), 3 * (w / 2));
            diff = range.second - range.first;
            answer += diff;
        }
        // 4/3w
        if (w % 3 == 0) {
            range = equal_range(weights.begin(), weights.end(), 4 * (w / 3));
            diff = range.second - range.first;
            answer += diff;
        }
    }
    
    return answer;
}

// 두 사람의 쌍 (a, b) (a < b)를 뽑았을 때
// (3, 2), (4, 2), (4, 3) 을 곱해서 같은지 보면 된당
// 몸무게 쌍이 같아도 사람이 다르면 다른 거 아닌가? 일단 그렇게 품.

// 내가 100이면 나의 3/2배, 2배, 4/3배 몸무게가 있는지 찾으면 됨.
// 선형탐색 + 이분탐색이므로 ㄱㅊ

