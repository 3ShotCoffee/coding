#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[500][500];       // dp[i][j] : 높이 i, 왼쪽에서 j번째 수로 가는 경로 중 가장 큰 "합" (0-base)

int solution(vector<vector<int>> triangle) {
    int depth = triangle.size();
    
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < depth; i++) {
        for (int j = 0; j <= i; j++) {
            int me = triangle[i][j];
            int left = (j == 0) ? -1 : dp[i - 1][j - 1];
            int right = (j == i) ? -1 : dp[i - 1][j];
            
            dp[i][j] = max(me + left, me + right);
        }
    }
    
    int answer = 0;
    for (int j = 0; j < depth; j++) {
        answer = max(answer, dp[depth - 1][j]);
    }
    
    return answer;
}