#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int dp[101][101];       // 집에서 [i][j]까지 올 수 있는 경우의 수
int pud[101][101];      // puddles 격자

int resolve(int row, int col) {
    if (dp[row][col] != -1)     // 이미 있으면 계산 x
        return dp[row][col];
    if (pud[row][col])          // 웅덩이면 갈 수 없음 
        return 0;
    
    int from_up = (row == 1) ? 0 : resolve(row - 1, col) % MOD;
    int from_left = (col == 1) ? 0 : resolve(row, col - 1) % MOD;
    int ret = (from_up + from_left) % MOD;
    
    dp[row][col] = ret;
    return ret;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    // init pud
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            pud[i][j] = 0;
        }
    }
    for (int i = 0; i < puddles.size(); i++) {
        pud[puddles[i][0]][puddles[i][1]] = 1;
    }
    
    // init dp
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    dp[1][1] = 1;
    
    return resolve(m, n);
}

// 1-base
// BFS -> 모든 칸이 다 똑같다고 가정하므로 부적합
// 각 칸마다 올 수 있는 경우의 수 dp