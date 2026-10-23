#include <iostream>
#include <vector>
using namespace std;

int dp[100000][2][2];  // i번째까지 봤을 때 최대합

int resolve(int n, int now_pick, int first_pick, vector<int> &sticker) {
    if (dp[n][now_pick][first_pick] != -1) {
        return dp[n][now_pick][first_pick];
    }
    int result;
    if (now_pick == 1) {   // 선택
        result = resolve(n - 1, 0, first_pick, sticker) + sticker[n];
    }
    else {
        result = resolve(n - 1, 0, first_pick, sticker);
        if (n > 1)
            result = max(result, resolve(n - 1, 1, first_pick, sticker));
    }
    dp[n][now_pick][first_pick] = result;
    return result;
}

int solution(vector<int> sticker)
{
    int answer =0;
    int n = sticker.size();
    
    if (n == 1) return sticker[0];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    
    dp[1][0][0] = 0;
    dp[1][0][1] = sticker[0];
    dp[1][1][0] = sticker[1];
    // dp[1][1][1]은 발생할 수 없으므로 막아줘야 함
    
    for (int i = 2; i < n - 1; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                resolve(i, j, k, sticker);
            }
        }
    }
    
    answer = resolve(n-1, 0, 0, sticker);
    answer = max(answer, resolve(n-1, 0, 1, sticker));
    answer = max(answer, resolve(n-1, 1, 0, sticker));

    return answer;
}

// 크다고 해서 바로 넣는게 이득이 아닐 수 있는 이유는
// 그에 인접한 두 스티커를 넣었을 때 더 이득일 수 있기 때문임

// dp[i][1] 0-i번째까지 봤을 때 + i를 선택한다고 할 때 최대합
    // dp[i][1] = dp[i-1][0] + num[i]
    // dp[i][0] = max(dp[i-1][0], dp[i-1][1])

// struct로? {0번째 넣음? 1 : 0, 최대합}