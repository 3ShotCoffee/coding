#include <string>
#include <vector>
#include <climits>

using namespace std;

int dp[1000001];    // x를 y로 변환하기 위해 필요한 연산

int resolve(int num, int y, int n) {
    if (dp[num] != -1) return dp[num];
    
    int ret = INT_MAX;
    if (num + n <= y) ret = min(ret, resolve(num + n, y, n));
    if (2 * num <= y) ret = min(ret, resolve(2 * num, y, n));
    if (3 * num <= y) ret = min(ret, resolve(3 * num, y, n));
    
    if (ret == INT_MAX)
        dp[num] = INT_MAX;
    else
        dp[num] = ret + 1;
    
    return dp[num];
}

int solution(int x, int y, int n) {
    for (int i = 0; i < 1000001; i++) {
        dp[i] = -1;
    }
    dp[y] = 0;
    
    int answer = resolve(x, y, n);
    
    if (answer == INT_MAX) return -1;
    return answer;
}