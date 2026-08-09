#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int, vector<int>> PQ;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    for (int i = 0; i < works.size(); i++) {
        PQ.push(works[i]);
    }
    
    while (n > 0) {
        int cur = PQ.top();
        if (cur == 0) break;        // 이미 작업 완료 시 break
        PQ.pop();
        PQ.push(cur - 1);
        n--;
    }
    
    while (!PQ.empty()) {
        int cur = PQ.top(); PQ.pop();   
        answer += cur * cur;
    }
    
    return answer;
}

// 제곱합의 최소화를 위해서는 가장 큰 값부터 줄여야 함
// O(N^2)이 간당간당

// PQ, pop, push를 N만큼