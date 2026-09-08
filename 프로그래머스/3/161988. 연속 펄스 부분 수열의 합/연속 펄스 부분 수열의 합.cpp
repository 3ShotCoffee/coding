#include <string>
#include <vector>
#include <iostream>

using namespace std;

//long long dp[500000];     // dp[i] -> i번 항까지의 합

long long dp[500000][2];   // dp2[i][0] -> i번 항 미포함했을 때 i까지의 최대 부분합
                            // dp2[i][1] -> i번 항 포함했을 때 i까지의 최대 부분합

long long resolve(int i, int inc, const vector<int>& ref) {
    if (dp[i][inc] != -1) {
        return dp[i][inc];
    }
    long long ret;
    if (inc) {  // 나 포함이면 이전 항도 반드시 포함하거나 아예 이전의 모든 항을 포기하거나
        ret = max(resolve(i - 1, 1, ref), (long long)0) + ref[i];
    }
    else {      // 나 미포함이면 이전 항은 상관 없음
        ret = max(resolve(i - 1, 0, ref), resolve(i - 1, 1, ref));
    }
    dp[i][inc] = ret;
    return ret;
}

long long max_partial_sum(const vector<int>& ref) {
    for (int i = 0; i < ref.size(); i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    
    dp[0][1] = ref[0];      // 포함이면 0번항
    dp[0][0] = 0;           // 미포함이면 0
    
    return max(resolve(ref.size() - 1, 1, ref), resolve(ref.size() - 1, 0, ref));
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    int len = sequence.size();
    vector<int> apply1, apply2;
    
    for (int i = 0; i < len; i++) {
        apply1.push_back((i % 2 == 0) ? sequence[i] : -sequence[i]);
        apply2.push_back((i % 2 == 0) ? -sequence[i] : sequence[i]);
    }
    
    long long max1 = max_partial_sum(apply1);
    long long max2 = max_partial_sum(apply2);
    
    return max(max1, max2);
}